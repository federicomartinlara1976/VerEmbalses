#include "tablemodel.hpp"

#include <spdlog/spdlog.h>

TableModelZona::TableModelZona(const FuncionesUi::Dataframe& dataFrame) : TableModel(dataFrame) {
    // La función que se usa para eliminar las filas
    auto lambda = [](const unsigned long &, const double &val1, const double &val2, const double &val3)-> bool {
        return (val1 <= 0.0 && val2 <= 0.0 && val3 <= 0.0);
    };

    this->dataFrame.remove_data_by_sel<double, double, double, decltype(lambda), double, std::string>("MediaNivel", "MinimoNivel", "MaximoNivel", lambda);
}

