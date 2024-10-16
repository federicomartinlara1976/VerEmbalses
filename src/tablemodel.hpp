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
    FuncionesUi::Dataframe dataframe;
    
    VerEmbalsesAppHelper helper;
    
public:
    TableModel(const FuncionesUi::Dataframe& dataframe, QObject* parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    ~TableModel();
};

#endif
