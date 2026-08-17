#ifndef __CONFIGURACION_HPP__
#define __CONFIGURACION_HPP__

// La configuración se gestiona con un singleton

#include <memory>
#include <configuration.hpp>

#include <qthelper.hpp>

#include <memory>
#include <any>

using namespace chronos::configuration;

class Configuracion {
private:
    static std::unique_ptr<Configuracion> _configuracion;
    
    Configuracion();
    static void destroy(Configuracion* instance);
    
    std::unique_ptr<Configuration> configuration;

public:
    static Configuracion& getInstance();
    static void destroyInstance();
    
    std::map<std::string, std::any> getProperties();
    Configuration& getConfiguration();
    
    virtual ~Configuracion();
};

class VerEmbalsesConfigurationFactory : public ConfigurationAbstractFactory {
private:
    QtHelper qtHelper;
    
public:
    std::unique_ptr<Configuration> createConfiguration() const override;
};

#endif
