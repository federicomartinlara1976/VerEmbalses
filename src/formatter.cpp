#include "formatter.hpp"

#include <configuration/configuration.hpp>

#include <fmt/core.h>

using namespace std;
using namespace fmt;

Formatter::Formatter() {
    Configuracion& configuracion = Configuracion::getInstance();
    Configuration& configuration = configuracion.getConfiguration();
    
    // Verificar que la propiedad "roundDecimals" exista y no esté vacía
    const auto& properties = configuration.getProperties();
    
    int decimals = std::any_cast<int>(properties["roundDecimals"]);
    
    _numberFormat = "{:." + to_string(decimals) + "f}";
}

string Formatter::formatNumber(double& num) const {
    return format(_numberFormat, num);
}

string Formatter::formatNumber(float& num) const {
    return format(_numberFormat, num);
}
