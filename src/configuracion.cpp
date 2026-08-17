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
    Q_ASSERT(_configuracion != nullptr);
    _configuracion.reset(nullptr); // Replaces stored pointer with nullptr, calls deleter on pointed-to instance.
}

std::map<std::string, std::any> Configuracion::getProperties() {
    return configuration->getProperties();
}

Configuracion::~Configuracion() {}

void Configuracion::destroy(Configuracion* instance) {
    Q_ASSERT(instance != nullptr);
    delete instance;
    instance = nullptr;
}

Configuration& Configuracion::getConfiguration() { 
    Q_ASSERT(configuration != nullptr);
    return *configuration; 
}

std::unique_ptr<Configuration> VerEmbalsesConfigurationFactory::createConfiguration() const {
    std::unique_ptr<Configuration> configuration = std::unique_ptr<Configuration>{new Configuration()};
    
    std::string server = qtHelper.asString(VerEmbalsesSettings::server());
    std::string dbName = qtHelper.asString(VerEmbalsesSettings::dbName());
    std::string zonaSelected = qtHelper.asString(VerEmbalsesSettings::zonaSelected());
    std::string embalseSelected = qtHelper.asString(VerEmbalsesSettings::embalseSelected());
    int roundDecimals = VerEmbalsesSettings::roundDecimals();
    
    configuration->getProperties()["server"] = server;
    configuration->getProperties()["dbName"] = dbName;
    configuration->getProperties()["zonaSelected"] = zonaSelected;
    configuration->getProperties()["embalseSelected"] = embalseSelected;
    configuration->getProperties()["roundDecimals"] = roundDecimals;
    
    return configuration;
}

