#include <spdlog/spdlog.h>
#include <iostream>
#include <fmt/format.h>

#include "constants.hpp"
#include "tablemodel.hpp"

using namespace std;

TableModel::TableModel(const FuncionesUi::Dataframe& dataframe, QObject* parent) : QStandardItemModel(parent) {
    this->dataframe = dataframe;
    auto shape = this->dataframe.shape();
    
    setRowCount(shape.first);
    setColumnCount(shape.second);
    
    auto columnsInfo = this->dataframe.get_columns_info<int, double, std::string>();
    
    int i = 0;
    for (auto citer: columnsInfo)  {
        setHeaderData(i, Qt::Horizontal, std::get<0>(citer).c_str(), Qt::DisplayRole);
        i++;
    }
    
    spdlog::info("TableModel: [{}, {}]", shape.first, shape.second);
}

int TableModel::rowCount(const QModelIndex &) const {
    auto shape = this->dataframe.shape();
    return shape.first;
}

int TableModel::columnCount(const QModelIndex &) const {
    auto shape = this->dataframe.shape();
    return shape.second;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        auto column = helper.getColumn(dataframe, index.column());
        
        if (std::get<2>(column) == type_index(typeid(string))) {
            std::vector<string> svec = dataframe.get_column<string>(index.column());
            return QString(svec[index.row()].c_str());
        }
        
        if (std::get<2>(column) == type_index(typeid(double))) {
            std::vector<double> dvec = dataframe.get_column<double>(index.column());
            
            std::string sValue = {};
            if (index.column() == 3) {
                sValue = fmt::format(Constants::PERCENT_FORMAT, dvec[index.row()]);
            }
            else {
                sValue = fmt::format(Constants::NUMBER_FORMAT, dvec[index.row()]);
            }
            
            return QString(sValue.c_str());
        }
    }
    return QVariant();
}

TableModel::~TableModel() {
    spdlog::info("TableModel liberado de la memoria");
}
