#include "progreso.hpp"

#include "signalmanager.hpp"

#include <QThread>

using namespace std;

DlgProgreso::DlgProgreso(QWidget *parent) : QtDialogWindow(parent) {
    this->initWindow();
    
    setWindowTitle("Progreso");
    setModal(false);  // Make the dialog non-blocking

    // Set dialog always on top of its parent
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    
    visible = false;
}

void DlgProgreso::setup() {
    setupUi(this);
}

void DlgProgreso::connectEvents() {
    connect(SignalManager::instance(), QOverload<int, QString>::of(&SignalManager::percentSignal), this, &DlgProgreso::percentChanged);
    connect(SignalManager::instance(), &SignalManager::startedSignal, this, &DlgProgreso::started);
    connect(SignalManager::instance(), &SignalManager::finishedSignal, this, &DlgProgreso::finished);
}

void DlgProgreso::delayedInitialization() {
}

void DlgProgreso::percentChanged(int percent, QString message) {
    this->lblEstado->setText(message);
    this->progressBar->setValue(percent);
}

void DlgProgreso::started() {
    this->lblEstado->setText("Inicio");
    this->progressBar->setValue(0);
    this->buttonBox->setEnabled(false);
}

void DlgProgreso::finished() {
    this->lblEstado->setText("Finalizado");
    this->progressBar->setValue(100);
    QThread::sleep(1);
    this->accept();
    
    Q_EMIT unblockingDialogDispatched();
}

void DlgProgreso::show() {
    QDialog::show();
    raise();  // Make sure the dialog is on top
    activateWindow();  // Bring the dialog to the foreground
    
    visible = true;
}

DlgProgreso::~DlgProgreso() {}

