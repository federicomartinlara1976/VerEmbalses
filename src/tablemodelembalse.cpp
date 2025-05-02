#include "tablemodel.hpp"

TableModelEmbalse::TableModelEmbalse(const FuncionesUi::Dataframe& dataFrame) : TableModel(dataFrame) {
    // Remove the columns MEN and Capacidad
    this->dataFrame.remove_column<double>("MEN");
    this->dataFrame.remove_column<double>("Capacidad");
}
