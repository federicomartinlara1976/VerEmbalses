#ifndef __CONFIGURACION_HPP__
#define __CONFIGURACION_HPP__

// La configuración se gestiona con un singleton

#include <memory>
#include <configuration.hpp>

#include <qthelper.hpp>


class Configuracion {
private:
    static std::unique_ptr<Configuracion> _configuracion;
    
    Configuracion();
    static void destroy(Configuracion* instance);
    
    Configuration* configuration;

public:
    static Configuracion& getInstance();
    static void destroyInstance();
    
    std::map<std::string, std::string> getProperties();
    Configuration& getConfiguration();
    
    virtual ~Configuracion();
};

class VerEmbalsesConfigurationFactory : public ConfigurationAbstractFactory {
private:
    QtHelper qtHelper;
    
public:
    Configuration* createConfiguration() const override;
};

#endif
