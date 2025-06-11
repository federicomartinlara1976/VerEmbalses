// application headers
#include "verembalseswindow.hpp"

#include "verembalsesview.hpp"
#include "verembalsesdebug.h"

// KF headers
#include <KActionCollection>
#include <KConfigDialog>

#include <spdlog/spdlog.h>
#include <QStatusBar>


VerEmbalsesWindow::VerEmbalsesWindow()
    : KXmlGuiWindow()
{
    m_verEmbalsesView = new VerEmbalsesView(this);
    setCentralWidget(m_verEmbalsesView);
    
    // Se incluye esta ventana en la lista de objetos a notificar
    m_verEmbalsesView->attach(this);

    KActionCollection* actionCollection = this->actionCollection();
    KStandardAction::preferences(this, SLOT(settingsConfigure()), actionCollection);

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
