#include "formatter.hpp"

#include <configuration.hpp>
#include <sstream>  // Necesario para std::stringstream

#include <fmt/core.h>
#include <spdlog/spdlog.h>

Formatter::Formatter() {
    std::stringstream ss;
    
    Configuracion& configuracion = Configuracion::getInstance();
    Configuration& configuration = configuracion.getConfiguration();
    
    // Verificar que la propiedad "roundDecimals" exista y no esté vacía
    const auto& properties = configuration.getProperties();
    
    int decimals = std::any_cast<int>(properties["roundDecimals"]);
    
    ss << "{:." << decimals << "f}";
    
    _numberFormat = ss.str();
}

string Formatter::formatNumber(double& num) const {
    return fmt::format(_numberFormat, num);
}

string Formatter::formatNumber(float& num) const {
    return fmt::format(_numberFormat, num);
}
