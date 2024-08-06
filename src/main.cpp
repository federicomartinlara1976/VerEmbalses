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

// Qt headers
#include <QApplication>
#include <spdlog/spdlog.h>
#include <memory>

#include "verembalses.hpp"

using namespace std;

int main(int argc, char **argv) {
    try {
        unique_ptr<QApplication> application = unique_ptr<QApplication>{new QApplication(argc, argv)};
        spdlog::info("Application {}", application->applicationDisplayName().toStdString());
        
        KCrash::initialize();
        
        unique_ptr<VerEmbalses> w = unique_ptr<VerEmbalses>{new VerEmbalses()};
        w->show();

        return application->exec();
    } catch (const exception& e) {
        spdlog::error("FATAL: {}", string(e.what()));
        return 1;
    }
}
