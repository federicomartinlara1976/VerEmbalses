#include "constants.hpp"
#include "tablemodel.hpp"

TableModel::TableModel(const FuncionesUi::Dataframe& dataFrame, QObject* parent) : QStandardItemModel(parent) {
    this->dataFrame = dataFrame;
    auto shape = this->dataFrame.shape();
    
    setRowCount(shape.first);
    setColumnCount(shape.second+1);

    auto columnsInfo = this->dataFrame.get_columns_info<double, std::string>();
    setHeaderData(0, Qt::Horizontal, QStringLiteral("Indice"), Qt::DisplayRole);
    
    int i = 1;
    for (auto citer : columnsInfo)  {
        const QVariant& value = QVariant(std::get<0>(citer));
        setHeaderData(i, Qt::Horizontal, value, Qt::DisplayRole);
        i++;
    }
}

int TableModel::rowCount(const QModelIndex &) const {
    auto shape = this->dataFrame.shape();
    return shape.first;
}

/**
 * Devuelve el número de columnas del dataframe
 */
int TableModel::columnCount(const QModelIndex &) const {
    auto shape = this->dataFrame.shape();
    return shape.second+1;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        // Si el numero de columna es 0, ponemos el índice del dataframe
        if (index.column() == 0) {
            std::vector<ulong> svec = dataFrame.get_index();
            return QString::fromStdString(std::to_string(svec[index.row()]));
        }
        else {
            // Este va a ser el número de columna a pasar al dataframe
            int columnDataframeIndex = index.column()-1;
            auto column = helper.getColumn(dataFrame, columnDataframeIndex);

            if (std::get<2>(column) == type_index(typeid(double))) {
                std::vector<double> dvec = dataFrame.get_column<double>(columnDataframeIndex);
                std::string sValue = formatter.formatNumber(dvec[index.row()]);
                return QString::fromStdString(sValue);
            }

            if (std::get<2>(column) == type_index(typeid(std::string))) {
                std::vector<string> svec = dataFrame.get_column<string>(columnDataframeIndex);
                return QString::fromStdString(svec[index.row()]);
            }
        }
    }

    return QVariant();
}

TableModel::~TableModel() {}
