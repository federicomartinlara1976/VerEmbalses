#include <spdlog/spdlog.h>
#include <iostream>
#include <fmt/format.h>

#include "constants.hpp"
#include "tablemodel.hpp"

using namespace std;

TableModel::TableModel(const FuncionesUi::Dataframe& dataFrame, QObject* parent) : QStandardItemModel(parent) {
    this->dataFrame = dataFrame;
    auto shape = this->dataFrame.shape();
    
    setRowCount(shape.first);
    setColumnCount(shape.second);
    
    auto columnsInfo = this->dataFrame.get_columns_info<int, double, std::string>();
    
    int i = 0;
    for (auto citer: columnsInfo)  {
        setHeaderData(i, Qt::Horizontal, std::get<0>(citer).c_str(), Qt::DisplayRole);
        i++;
    }
}

int TableModel::rowCount(const QModelIndex &) const {
    auto shape = this->dataFrame.shape();
    return shape.first;
}

int TableModel::columnCount(const QModelIndex &) const {
    auto shape = this->dataFrame.shape();
    return shape.second;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        auto column = helper.getColumn(dataFrame, index.column());
        
        if (std::get<2>(column) == type_index(typeid(string))) {
            std::vector<string> svec = dataFrame.get_column<string>(index.column());
            return QString(svec[index.row()].c_str());
        }
        
        if (std::get<2>(column) == type_index(typeid(double))) {
            std::vector<double> dvec = dataFrame.get_column<double>(index.column());
            
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

TableModel::~TableModel() {}
