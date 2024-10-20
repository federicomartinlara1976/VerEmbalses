#include <spdlog/spdlog.h>
#include <iostream>
#include <fmt/format.h>

#include "constants.hpp"
#include "tablemodel.hpp"

using namespace std;

TableModel::TableModel(const FuncionesUi::StringDataframe& dataFrame, QObject* parent) : QStandardItemModel(parent) {
    this->dataFrame = dataFrame;
    auto shape = this->dataFrame.shape();
    
    setRowCount(shape.first);

    // Hay que añadir la columna de las fechas
    setColumnCount(shape.second+1);
    setHeaderData(0, Qt::Horizontal, "Fecha", Qt::DisplayRole);
    
    auto columnsInfo = this->dataFrame.get_columns_info<double>();
    
    int i = 1;
    for (auto citer: columnsInfo)  {
        setHeaderData(i, Qt::Horizontal, std::get<0>(citer).c_str(), Qt::DisplayRole);
        i++;
    }
}

int TableModel::rowCount(const QModelIndex &) const {
    auto shape = this->dataFrame.shape();
    return shape.first;
}

/**
 * Devuelve el número de columnas del dataframe
 * (sin contar el índice)
 */
int TableModel::columnCount(const QModelIndex &) const {
    auto shape = this->dataFrame.shape();
    return shape.second;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        // Si el numero de columna es 0, ponemos el índice del dataframe
        if (index.column() == 0) {
            std::vector<string> svec = dataFrame.get_index();
            return QString(svec[index.row()].c_str());
        }

        // Este va a ser el número de columna a pasar al dataframe
        int columnIndex = index.column() - 1;
        auto column = helper.getColumn(dataFrame, columnIndex);
        
        if (std::get<2>(column) == type_index(typeid(double))) {
            std::vector<double> dvec = dataFrame.get_column<double>(columnIndex);
            std::string sValue = fmt::format(Constants::NUMBER_FORMAT, dvec[index.row()]);
            return QString(sValue.c_str());
        }
    }
    return QVariant();
}

TableModel::~TableModel() {}
