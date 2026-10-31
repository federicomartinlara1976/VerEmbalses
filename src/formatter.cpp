#include "formatter.hpp"

#include <configuration/configuration.hpp>

#include <fmt/core.h>

using namespace std;

Formatter::Formatter() {
    Configuracion& configuracion = Configuracion::getInstance();
    Configuration& configuration = configuracion.getConfiguration();
    
    // Verificar que la propiedad "roundDecimals" exista y no esté vacía
    const auto& properties = configuration.getProperties();
    
    int decimals = std::any_cast<int>(properties["roundDecimals"]);
    
    _numberFormat = "{:." + to_string(decimals) + "f}";
}

string Formatter::formatNumber(double& num) const {
    /**
     * fmt::runtime() es una función que le dice a {fmt} que la cadena que le pasas no es un literal conocido en tiempo de compilación, por lo que debe posponer la
     * validación al tiempo de ejecución. Esto es exactamente lo que necesitas para una cadena de formato construida dinámicamente.
     */
    return fmt::format(fmt::runtime(_numberFormat), num);
}

string Formatter::formatNumber(float& num) const {
    return fmt::format(fmt::runtime(_numberFormat), num);
}
