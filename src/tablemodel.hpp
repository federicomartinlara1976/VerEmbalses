#ifndef _TABLEMODEL_HPP_
#define _TABLEMODEL_HPP_

#include <QVariant>
#include <QStandardItemModel>

#include "VerEmbalsesAppHelper.hpp"
#include "funciones_ui.hpp"

using namespace FuncionesUi;

class TableModel : public QStandardItemModel {
    Q_OBJECT
    
private:
    VerEmbalsesAppHelper helper;

protected:
    FuncionesUi::StringDataframe dataFrame;
    
public:
    TableModel(const FuncionesUi::StringDataframe& dataframe, QObject* parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    FuncionesUi::StringDataframe getDataframe() { return this->dataFrame; };
    ~TableModel();
};

class TableModelEmbalse : public TableModel {
public:
    TableModelEmbalse(const FuncionesUi::StringDataframe& dataFrame);
};

class TableModelZona : public TableModel {
public:
    TableModelZona(const FuncionesUi::StringDataframe& dataFrame);
};

class TableModelEmbalses : public TableModel {
public:
    TableModelEmbalses(const FuncionesUi::StringDataframe& dataFrame);
};



#endif
