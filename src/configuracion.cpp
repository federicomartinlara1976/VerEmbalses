#include "configuracion.hpp"

#include "VerEmbalsesSettings.h"

#include <spdlog/spdlog.h>

std::unique_ptr<Configuracion> Configuracion::_configuracion = nullptr;

Configuracion& Configuracion::getInstance() {
    if (_configuracion == nullptr) {
        _configuracion.reset(new Configuracion()); // Create new instance, assign to unique_ptr.
    }
    return *_configuracion;
}

Configuracion::Configuracion() {
    spdlog::debug("Init configuration");
    ConfigurationAbstractFactory* factory = new VerEmbalsesConfigurationFactory();
    configuration = factory->createConfiguration();
}


void Configuracion::destroyInstance() {
    if (_configuracion != nullptr) {
        _configuracion.reset(nullptr); // Replaces stored pointer with nullptr, calls deleter on pointed-to instance.
    }
}

std::map<std::string, std::string> Configuracion::getProperties() {
    return configuration->getProperties();
}

Configuracion::~Configuracion() {
    if (_configuracion == nullptr) {
        //spdlog::info("* Instance already deleted!");
    }
}

void Configuracion::destroy(Configuracion* instance) {
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}

Configuration* VerEmbalsesConfigurationFactory::createConfiguration() const {
    Configuration* configuration = new Configuration();
    
    std::string server = qtHelper.asString(VerEmbalsesSettings::server());
    std::string dbName = qtHelper.asString(VerEmbalsesSettings::dbName());
    std::string zonaSelected = qtHelper.asString(VerEmbalsesSettings::zonaSelected());
    std::string embalseSelected = qtHelper.asString(VerEmbalsesSettings::embalseSelected());
    int roundDecimals = VerEmbalsesSettings::roundDecimals();
    
    configuration->getProperties().insert(par("server", server));
    configuration->getProperties().insert(par("dbName", dbName));
    configuration->getProperties().insert(par("zonaSelected", zonaSelected));
    configuration->getProperties().insert(par("embalseSelected", embalseSelected));
    configuration->getProperties().insert(par("roundDecimals", std::to_string(roundDecimals)));
    
    return configuration;
}
