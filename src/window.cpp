#include "window.hpp"

#include <QTimer>
#include <spdlog/spdlog.h>

Window::Window() : KXmlGuiWindow() {
}

void Window::initWindow() {
    this->setup();

    this->connectEvents();

    QTimer::singleShot(0, this, &Window::delayInitialization);
}

void Window::delayInitialization() {
    this->delayedInitialization();
}

