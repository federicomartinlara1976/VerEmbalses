#include "formatter.hpp"

#include <configuration.hpp>
#include <sstream>  // Necesario para std::stringstream

#include <fmt/core.h>
#include <spdlog/spdlog.h>

Formatter::Formatter() {
    std::stringstream ss;
    
    Configuracion& configuracion = Configuracion::getInstance();
    Configuration& configuration = configuracion.getConfiguration();
    
    Q_ASSERT(!configuration.getProperties().empty());
    Q_ASSERT(!configuration.getProperties()["roundDecimals"].empty());
    
    string decimals = configuration.getProperties()["roundDecimals"];
    
    ss << "{:." << decimals << "f}";
    
    _numberFormat = ss.str();
}

string Formatter::formatNumber(double& num) {
    return fmt::format(_numberFormat, num);
}

string Formatter::formatNumber(float& num) {
    return fmt::format(_numberFormat, num);
}
