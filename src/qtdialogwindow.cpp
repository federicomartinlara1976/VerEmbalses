#include "qtdialogwindow.hpp"

#include <QTimer>
#include <spdlog/spdlog.h>

QtDialogWindow::QtDialogWindow(QWidget *parent) : QDialog(parent) {
}

void QtDialogWindow::initWindow() {
    this->setup();

    this->connectEvents();

    QTimer::singleShot(0, this, &QtDialogWindow::delayInitialization);
}

int QtDialogWindow::mostrar(bool modal) {
    if (modal) {
        setModal(true);
    }
    
    return exec();
}

void QtDialogWindow::delayInitialization() {
    this->delayedInitialization();
}

