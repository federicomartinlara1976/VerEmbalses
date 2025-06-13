/*
Copyright (C) %{CURRENT_YEAR} by %{AUTHOR} <%{EMAIL}>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of
the License or (at your option) version 3 or any later version
accepted by the membership of KDE e.V. (or its successor approved
by the membership of KDE e.V.), which shall act as a proxy 
defined in Section 14 of version 3 of the license.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// application header

// KF headers
#include <KCrash>
#include <KConfig>

#include <KCrash>
#include <KDBusService>
#include <KAboutData>
#include <KLocalizedString>

// Qt headers
#include <QApplication>
#include <QCommandLineParser>
#include <QIcon>
#include <QTranslator>
#include <QFile>
#include <qthelper.hpp>

#include <spdlog/spdlog.h>
#include <memory>

#include "verembalseswindow.hpp"

using namespace std;

int main(int argc, char **argv) {
    try {
        QApplication application(argc, argv);
        
        QtHelper qtHelper;
        
        QTranslator translator;
        // Obtener el idioma del sistema (ej. "es_ES")
        QString systemLocale = QLocale::system().name(); // "es", "en_US", etc.
        spdlog::info("El idioma local es: {}", qtHelper.asString(systemLocale));
        
        /*
        if (translator.load(QLocale(), "verembalses", "_", ":/translations")) {
            application.installTranslator(&translator);
            spdlog::info("Traducciones cargadas correctamente");
        }
        else {
            spdlog::error("No se han podido cargar las traducciones");
        }
        */
        
        QString appName = "verembalses";  
        QStringList paths = QStandardPaths::locateAll(
            QStandardPaths::GenericDataLocation,
            appName + "/translations",
            QStandardPaths::LocateDirectory);

        // Buscar en rutas como /usr/share/locale, ~/.local/share/locale, etc.
        for (const QString &path : paths) {
            QString fullPath = path + "/" + appName + "_" + systemLocale + ".qm";
            spdlog::info("Buscando en: {}", qtHelper.asString(fullPath));
            if (QFile::exists(fullPath)) {
                if (translator.load(fullPath)) {
                    application.installTranslator(&translator);
                    spdlog::info("Traducción cargada desde: {}", qtHelper.asString(fullPath));
                    break;
                }
            }
        }

        // i18n
        KLocalizedString::setApplicationDomain("verembalses");
        
        // Inicializa manejador de errores no controlados
        KCrash::initialize();

        // Ventana de información de copyright
        KAboutData aboutData( QStringLiteral("verembalses"),
                          i18n("VerEmbalses"),
                          QStringLiteral("1.0"),
                          i18n("Monitoriza datos de los embalses de la Cuenca Hidrográfica del Guadalquivir"),
                          KAboutLicense::GPL,
                          i18n("Copyright 2025, Federico Martín Lara <federicomartinlara1976@gmail.com>"));

        aboutData.addAuthor(i18n("Federico Martín Lara"),i18n("Author"), QStringLiteral("federicomartinlara1976@gmail.com"));
        aboutData.setOrganizationDomain("chronos.bounceme.net");
        aboutData.setDesktopFileName(QStringLiteral("net.bounceme.chronos.verembalses"));

        KAboutData::setApplicationData(aboutData);
        
        // Icono de la aplicación
        application.setWindowIcon(QIcon::fromTheme(QStringLiteral("verembalses")));

        QCommandLineParser parser;
        aboutData.setupCommandLine(&parser);

        parser.process(application);
        aboutData.processCommandLine(&parser);

        // Bus de KDE
        KDBusService appDBusService(KDBusService::Multiple | KDBusService::NoExitOnFailure);

        // Ventana principal
        VerEmbalsesWindow *window = new VerEmbalsesWindow;
        window->show();

        return application.exec();
    } catch (const exception& e) {
        spdlog::error("FATAL: {}", string(e.what()));
        return 1;
    }
}
