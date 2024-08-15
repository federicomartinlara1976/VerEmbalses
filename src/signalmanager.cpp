#include "signalmanager.hpp"

#include <spdlog/spdlog.h>

SignalManager* SignalManager::_signalManager = nullptr;

SignalManager* SignalManager::instance() {
    if (_signalManager == nullptr) {
        spdlog::info("Creating SignalManager");
        _signalManager = new SignalManager(); // Create new instance, assign to unique_ptr.
    }
    return _signalManager;
}

void SignalManager::destroyInstance() {
    if (_signalManager != nullptr) {
        spdlog::info("Destroying SignalManager");
        _signalManager = nullptr; // Replaces stored pointer with nullptr, calls deleter on pointed-to instance.
    }
}

SignalManager::~SignalManager() {
    spdlog::info("Destructor called");
    if (_signalManager == nullptr) {
        spdlog::info("* Instance already deleted!");
    }
}

void SignalManager::destroy(SignalManager* instance) {
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}

void SignalManager::sendPercent(int percent, QString message) {
    // Emit the custom signal
    Q_EMIT percentSignal(percent, message);
}

void SignalManager::sendFinished() {
    // Emit the custom signal
    Q_EMIT finishedSignal();
}

void SignalManager::sendStarted() {
    // Emit the custom signal
    Q_EMIT startedSignal();
}
