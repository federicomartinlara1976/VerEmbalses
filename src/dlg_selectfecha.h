/********************************************************************************
** Form generated from reading UI file 'dlg-select-fecha.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DLG_SELECTFECHA_H
#define DLG_SELECTFECHA_H                                                                                                       1

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "kdatecombobox.h"

QT_BEGIN_NAMESPACE

class Ui_DialogSelectFecha
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lblZona;
    QComboBox *cmbZona;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblEmbalse;
    QComboBox *cmbEmbalse;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    KDateComboBox *cmbDesde;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    KDateComboBox *cmbHasta;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(518, 248);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 200, 501, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(Dialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 501, 206));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lblZona = new QLabel(verticalLayoutWidget);
        lblZona->setObjectName(QString::fromUtf8("lblZona"));

        horizontalLayout_4->addWidget(lblZona);

        cmbZona = new QComboBox(verticalLayoutWidget);
        cmbZona->setObjectName(QString::fromUtf8("cmbZona"));

        horizontalLayout_4->addWidget(cmbZona);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lblEmbalse = new QLabel(verticalLayoutWidget);
        lblEmbalse->setObjectName(QString::fromUtf8("lblEmbalse"));

        horizontalLayout_3->addWidget(lblEmbalse);

        cmbEmbalse = new QComboBox(verticalLayoutWidget);
        cmbEmbalse->setObjectName(QString::fromUtf8("cmbEmbalse"));

        horizontalLayout_3->addWidget(cmbEmbalse);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        cmbDesde = new KDateComboBox(verticalLayoutWidget);
        cmbDesde->setObjectName(QString::fromUtf8("cmbDesde"));

        horizontalLayout->addWidget(cmbDesde);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinAndMaxSize);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        cmbHasta = new KDateComboBox(verticalLayoutWidget);
        cmbHasta->setObjectName(QString::fromUtf8("cmbHasta"));

        horizontalLayout_2->addWidget(cmbHasta);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Seleccionar rango de fechas", nullptr));
        lblZona->setText(QApplication::translate("Dialog", "Zona", nullptr));
        lblEmbalse->setText(QApplication::translate("Dialog", "Embalse", nullptr));
        label->setText(QApplication::translate("Dialog", "Desde:", nullptr));
        label_2->setText(QApplication::translate("Dialog", "Hasta:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSelectFecha: public Ui_DialogSelectFecha {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DLG_SELECTFECHA_H
