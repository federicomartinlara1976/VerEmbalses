#include "selectmes.hpp"
#include <spdlog/spdlog.h>

using namespace std;

DlgSelectMes::DlgSelectMes(QWidget *parent) : QtDialogWindow(parent) {
    this->initWindow();
}

void DlgSelectMes::setup() {
    setupUi(this);
}

void DlgSelectMes::connectEvents() {
    connect(cmbMes, QOverload<int>::of(&QComboBox::activated), this, &DlgSelectMes::cmbMesIndexChanged);
}

void DlgSelectMes::delayedInitialization() {
    helper.populateMeses(cmbMes);
    int index = cmbMes->currentIndex();
    
    string nombre = helper.asString(cmbMes->currentText());
    int value = cmbMes->itemData(index).toInt();
    
    selected = make_tuple(value, nombre);
}

void DlgSelectMes::cmbMesIndexChanged(int index) {
    string nombre = helper.asString(cmbMes->currentText());
    int value = cmbMes->itemData(index).toInt();
    
    selected = make_tuple(value, nombre);
}

DlgSelectMes::~DlgSelectMes() { 
    spdlog::info("DlgSelectMes liberado de la memoria");
}

