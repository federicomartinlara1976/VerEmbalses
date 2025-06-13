// application headers
#include "verembalseswindow.hpp"

#include "verembalsesview.hpp"
#include "verembalsesdebug.h"

#include "showtable.hpp"
#include "funciones_ui.hpp"

// KF headers
#include <KActionCollection>
#include <KConfigDialog>

#include <spdlog/spdlog.h>
#include <QStatusBar>

#include <QAction>
#include <QMessageBox>
#include <QtWidgets/QApplication>

#include <memory>


VerEmbalsesWindow::VerEmbalsesWindow()
    : KXmlGuiWindow()
{
    m_verEmbalsesView = new VerEmbalsesView(this);
    setCentralWidget(m_verEmbalsesView);
    
    // Se incluye esta ventana en la lista de objetos a notificar
    m_verEmbalsesView->attach(this);

    KActionCollection* actionCollection = this->actionCollection();
    KStandardAction::preferences(this, SLOT(settingsConfigure()), actionCollection);
    
    QAction* queryByDateAction = new QAction(this);
    queryByDateAction->setText(QApplication::translate("VerEmbalses", "Buscar por fecha", nullptr));
    queryByDateAction->setIcon(QIcon::fromTheme("document-new-symbolic"));
    actionCollection->addAction("query_by_date", queryByDateAction);
    connect(queryByDateAction, &QAction::triggered, this, &VerEmbalsesWindow::queryByDate);

    setupGUI();
}

void VerEmbalsesWindow::updateObserver(const std::string &message) {
    QStatusBar *bar = statusBar();
    bar->showMessage(qtHelper.asQString(message));
}

VerEmbalsesWindow::~VerEmbalsesWindow()
{
    m_verEmbalsesView->detach(this);
    spdlog::debug("VerEmbalsesWindow::~VerEmbalsesWindow()");
}

void VerEmbalsesWindow::queryByDate() {
    spdlog::debug("VerEmbalsesWindow::queryByDate");
    
    AppContext& context = AppContext::getInstance();
    
    unique_ptr<DlgSelectFecha> dlg = getDlgFecha();
    int result = dlg->mostrar(true);
    
    if (result == 1) {
        tuple<QDate, QDate> fechas = dlg->getFechas();
        tuple<string, string> datosEmbalse = dlg->getDatosEmbalse();
        string codZona = get<0>(datosEmbalse);

        if (!codZona.empty()) {
            string codEmbalse = get<1>(datosEmbalse);

            unique_ptr<DlgShowTable> dlgShowTable = nullptr;
            if (!codEmbalse.empty()) {
                Dataframe df = context.getDataframePorEmbalseYRangoFechas(codEmbalse, get<0>(fechas), get<1>(fechas));
                dlgShowTable = unique_ptr<DlgShowTable>{new DlgShowTable(df, codEmbalse, Constants::EMBALSE, this)};
            }
            else {
                Dataframe df = context.getDataframePorZonaYRangoFechas(codZona, get<0>(fechas), get<1>(fechas));
                dlgShowTable = unique_ptr<DlgShowTable>{new DlgShowTable(df, codZona, Constants::ZONA, this)};
            }

            dlgShowTable->setFechas(get<0>(fechas), get<1>(fechas));
            dlgShowTable->mostrar(true);
        }
        else {
            QMessageBox msgBox;
            msgBox.setText("Debe seleccionar una zona");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.exec();
        }
    }
}

void VerEmbalsesWindow::settingsConfigure()
{
    spdlog::debug("VerEmbalsesWindow::settingsConfigure()");
    // The preference dialog is derived from prefs_base.ui
    //
    // compare the names of the widgets in the .ui file
    // to the names of the variables in the .kcfg file
    //avoid to have 2 dialogs shown
    if (KConfigDialog::showDialog(QStringLiteral("settings"))) {
        return;
    }

    KConfigDialog *dialog = new KConfigDialog(this, QStringLiteral("settings"), VerEmbalsesSettings::self());
    QWidget *generalSettingsPage = new QWidget;
    m_settings.setupUi(generalSettingsPage);
    dialog->addPage(generalSettingsPage, i18n("General"), QStringLiteral("package_setting"));
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

unique_ptr<DlgSelectFecha> VerEmbalsesWindow::getDlgFecha() {
    unique_ptr<DlgSelectFecha> dlg = unique_ptr<DlgSelectFecha>{new DlgSelectFecha(this)};
    
    return dlg;
}
