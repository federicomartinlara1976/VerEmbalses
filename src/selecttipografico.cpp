#include "selecttipografico.hpp"

DlgSelectTipoGrafico::DlgSelectTipoGrafico(QWidget *parent) : QtDialogWindow(parent) {
    this->initWindow();
}

void DlgSelectTipoGrafico::setup() {
    setupUi(this);
}

void DlgSelectTipoGrafico::connectEvents() {}

void DlgSelectTipoGrafico::delayedInitialization() {}

void DlgSelectTipoGrafico::onClose() {}

void DlgSelectTipoGrafico::onAccept() {
    if (this->rbtLinear->isChecked()) {
        graphType = Constants::GraphType::LINEAR;
    }

    if (this->rbtRelacionNivelVolumen->isChecked()) {
        graphType = Constants::GraphType::RELACION_NIVEL_VOLUMEN;
    }
    
    if (this->rbtRelacionVolumenPorcentaje->isChecked()) {
        graphType = Constants::GraphType::RELACION_VOLUMEN_PORCENTAJE;
    }
}

DlgSelectTipoGrafico::~DlgSelectTipoGrafico() {}
