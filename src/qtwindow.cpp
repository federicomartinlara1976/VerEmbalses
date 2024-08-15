#include "qtwindow.hpp"

#include <QTimer>
#include <spdlog/spdlog.h>

QtWindow::QtWindow(QWidget *parent) : QMainWindow(parent) {
}

void QtWindow::initWindow() {
    spdlog::info("Setup");
    this->setup();

    spdlog::info("Connect events");
    this->connectEvents();

    spdlog::info("Delayed initialization");
    QTimer::singleShot(0, this, &QtWindow::delayInitialization);
}

void QtWindow::delayInitialization() {
    this->delayedInitialization();
}

