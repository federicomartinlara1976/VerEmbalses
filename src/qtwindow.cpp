#include "qtwindow.hpp"

#include <QTimer>
#include <spdlog/spdlog.h>

QtWindow::QtWindow(QWidget *parent) : QMainWindow(parent) {
}

void QtWindow::initWindow() {
    this->setup();

    this->connectEvents();

    QTimer::singleShot(0, this, &QtWindow::delayInitialization);
}

void QtWindow::delayInitialization() {
    this->delayedInitialization();
}

