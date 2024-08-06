#include <spdlog/spdlog.h>
#include <qttools/config.hpp>

#include "selectfecha.hpp"

using namespace std;

DlgSelectFecha::DlgSelectFecha(QWidget *parent) : QtDialogWindow(parent) {
    this->initWindow();
}

DlgSelectFecha::DlgSelectFecha(string codZona, string codEmbalse, QWidget *parent) : QtDialogWindow(parent) {
    this->initWindow();
    
    this->codZona = codZona;
    this->codEmbalse = codEmbalse;
}

void DlgSelectFecha::setup() {
    setupUi(this);
}

void DlgSelectFecha::connectEvents() {
    connect(cmbZona, QOverload<int>::of(&QComboBox::activated), this, &DlgSelectFecha::cmbZonasIndexChanged);
    connect(cmbEmbalse, QOverload<int>::of(&QComboBox::activated), this, &DlgSelectFecha::cmbEmbalsesIndexChanged);
}

void DlgSelectFecha::delayedInitialization() {
    try {
        AppContext& context = AppContext::getInstance();
        
        context.populateZonas(cmbZona);
        
        context.setZonaDefecto(codZona, cmbZona, cmbEmbalse);
        context.setEmbalseDefecto(codEmbalse, cmbEmbalse);
        
        if (!codZona.empty()) {
            cmbZona->setDisabled(true);
        }
        
        if (!codEmbalse.empty()) {
            this->cmbEmbalse->setDisabled(true);
        }
        
    } catch (const exception& e) {
        spdlog::error("ERROR delayedInitialization: {}", e.what());
        throw e;
    }
}

void DlgSelectFecha::cmbZonasIndexChanged(int index) {
    AppContext& context = AppContext::getInstance();
    context.populateEmbalses(helper.getStringValue(cmbZona, index), cmbEmbalse);
    
    codZona = helper.getStringValue(cmbZona);
    codEmbalse = helper.getStringValue(cmbEmbalse, 0);
}

void DlgSelectFecha::cmbEmbalsesIndexChanged(int index) {
    codEmbalse = helper.getStringValue(cmbEmbalse, index);
}

tuple<QDate, QDate> DlgSelectFecha::getFechas() {
    return make_tuple(cmbDesde->date(), cmbHasta->date());
}

tuple<string, string> DlgSelectFecha::getDatosEmbalse() {
    return make_tuple(codZona, codEmbalse);
}

DlgSelectFecha::~DlgSelectFecha() { 
    spdlog::info("DlgSelectFecha liberado de la memoria");
}
