#include "tablemodel.hpp"

#include <spdlog/spdlog.h>

TableModelEmbalse::TableModelEmbalse(const FuncionesUi::StringDataframe& dataFrame) : TableModel(dataFrame) {
    // Remove the columns MEN and Capacidad
    this->dataFrame.remove_column<double>("MEN");
    this->dataFrame.remove_column<double>("Capacidad");
}
