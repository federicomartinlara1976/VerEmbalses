/********************************************************************************
** Form generated from reading UI file 'dlg-select-fechaLDyPWg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DLG_2D_SELECT_2D_FECHALDYPWG_H
#define DLG_2D_SELECT_2D_FECHALDYPWG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include "kdatecombobox.h"

QT_BEGIN_NAMESPACE

class Ui_DialogSelectFecha
{
public:
    QVBoxLayout *verticalLayout_2;
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
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogSelectFecha)
    {
        if (DialogSelectFecha->objectName().isEmpty())
            DialogSelectFecha->setObjectName(QString::fromUtf8("DialogSelectFecha"));
        DialogSelectFecha->setWindowModality(Qt::NonModal);
        DialogSelectFecha->resize(545, 291);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogSelectFecha->sizePolicy().hasHeightForWidth());
        DialogSelectFecha->setSizePolicy(sizePolicy);
        DialogSelectFecha->setMinimumSize(QSize(545, 291));
        DialogSelectFecha->setMaximumSize(QSize(545, 291));
        verticalLayout_2 = new QVBoxLayout(DialogSelectFecha);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lblZona = new QLabel(DialogSelectFecha);
        lblZona->setObjectName(QString::fromUtf8("lblZona"));

        horizontalLayout_4->addWidget(lblZona);

        cmbZona = new QComboBox(DialogSelectFecha);
        cmbZona->setObjectName(QString::fromUtf8("cmbZona"));

        horizontalLayout_4->addWidget(cmbZona);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lblEmbalse = new QLabel(DialogSelectFecha);
        lblEmbalse->setObjectName(QString::fromUtf8("lblEmbalse"));

        horizontalLayout_3->addWidget(lblEmbalse);

        cmbEmbalse = new QComboBox(DialogSelectFecha);
        cmbEmbalse->setObjectName(QString::fromUtf8("cmbEmbalse"));

        horizontalLayout_3->addWidget(cmbEmbalse);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        label = new QLabel(DialogSelectFecha);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        cmbDesde = new KDateComboBox(DialogSelectFecha);
        cmbDesde->setObjectName(QString::fromUtf8("cmbDesde"));

        horizontalLayout->addWidget(cmbDesde);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinAndMaxSize);
        label_2 = new QLabel(DialogSelectFecha);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        cmbHasta = new KDateComboBox(DialogSelectFecha);
        cmbHasta->setObjectName(QString::fromUtf8("cmbHasta"));

        horizontalLayout_2->addWidget(cmbHasta);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(DialogSelectFecha);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(DialogSelectFecha);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogSelectFecha, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogSelectFecha, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogSelectFecha);
    } // setupUi

    void retranslateUi(QDialog *DialogSelectFecha)
    {
        DialogSelectFecha->setWindowTitle(QCoreApplication::translate("DialogSelectFecha", "Seleccionar rango de fechas", nullptr));
        lblZona->setText(QCoreApplication::translate("DialogSelectFecha", "Zona", nullptr));
        lblEmbalse->setText(QCoreApplication::translate("DialogSelectFecha", "Embalse", nullptr));
        label->setText(QCoreApplication::translate("DialogSelectFecha", "Desde:", nullptr));
        label_2->setText(QCoreApplication::translate("DialogSelectFecha", "Hasta:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSelectFecha: public Ui_DialogSelectFecha {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DLG_2D_SELECT_2D_FECHALDYPWG_H
