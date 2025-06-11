#ifndef _VEREMBALSESWINDOW_HPP_
#define _VEREMBALSESWINDOW_HPP_

#include <KXmlGuiWindow>

#include "ui_settings.h"
#include "VerEmbalsesSettings.h"
#include "observer.hpp"

#include <qthelper.hpp>

#include <QStatusBar>

class VerEmbalsesView;

/**
 * This class serves as the main window for testkdecompleto.  It handles the
 * menus, toolbars and status bars.
 *
 * @short Main window class
 * @author %{AUTHOR} <%{EMAIL}>
 * @version %{VERSION}
 */
class VerEmbalsesWindow : public KXmlGuiWindow, public IObserver
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    VerEmbalsesWindow();
    
    void updateObserver(const std::string &message) override;

    /**
     * Default Destructor
     */
    ~VerEmbalsesWindow() override;

private Q_SLOTS:
    /**
     * Open the settings dialog
     */
    void settingsConfigure();
    
private:
    // this is the name of the root widget inside our Ui file
    // you can rename it in designer and then change it here
    Ui::Settings m_settings;
    VerEmbalsesView *m_verEmbalsesView;
    
    QtHelper qtHelper;
};

#endif
