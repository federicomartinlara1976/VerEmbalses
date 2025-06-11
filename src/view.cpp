#include "view.hpp"

#include <QTimer>
#include <spdlog/spdlog.h>

View::View(QWidget *parent) : QWidget(parent) {
}

void View::initView() {
    this->setup();

    this->connectEvents();

    QTimer::singleShot(0, this, &View::delayInitialization);
}

void View::delayInitialization() {
    this->delayedInitialization();
}
