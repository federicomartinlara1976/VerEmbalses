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
    Q_ASSERT_X(
        properties.find("roundDecimals") != properties.end() && 
        !properties.at("roundDecimals").empty(),
        "Formatter", 
        "La propiedad 'roundDecimals' no existe o está vacía."
    );
    
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
