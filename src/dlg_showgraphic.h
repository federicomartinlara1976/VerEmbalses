/********************************************************************************
** Form generated from reading UI file 'dlg-show-graphicMqIELT.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DLG_2D_SHOW_2D_GRAPHICMQIELT_H
#define DLG_2D_SHOW_2D_GRAPHICMQIELT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtCharts/QChartView>

QT_BEGIN_NAMESPACE

class Ui_DialogShowGraphic
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *containerSelectores;
    QHBoxLayout *containerSelectorY;
    QLabel *lblDatoY;
    QComboBox *cmbDatoY;
    QSpacerItem *horizontalSpacer;
    QChartView *chartView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogShowGraphic)
    {
        if (DialogShowGraphic->objectName().isEmpty())
            DialogShowGraphic->setObjectName(QString::fromUtf8("DialogShowGraphic"));
        DialogShowGraphic->resize(1068, 705);
        verticalLayout_2 = new QVBoxLayout(DialogShowGraphic);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        containerSelectores = new QHBoxLayout();
        containerSelectores->setObjectName(QString::fromUtf8("containerSelectores"));
        containerSelectores->setSizeConstraint(QLayout::SetFixedSize);
        containerSelectores->setContentsMargins(10, 10, 10, 10);
        containerSelectorY = new QHBoxLayout();
        containerSelectorY->setObjectName(QString::fromUtf8("containerSelectorY"));
        containerSelectorY->setContentsMargins(10, 10, 10, 10);
        lblDatoY = new QLabel(DialogShowGraphic);
        lblDatoY->setObjectName(QString::fromUtf8("lblDatoY"));
        sizePolicy.setHeightForWidth(lblDatoY->sizePolicy().hasHeightForWidth());
        lblDatoY->setSizePolicy(sizePolicy);

        containerSelectorY->addWidget(lblDatoY);

        cmbDatoY = new QComboBox(DialogShowGraphic);
        cmbDatoY->setObjectName(QString::fromUtf8("cmbDatoY"));
        sizePolicy1.setHeightForWidth(cmbDatoY->sizePolicy().hasHeightForWidth());
        cmbDatoY->setSizePolicy(sizePolicy1);

        containerSelectorY->addWidget(cmbDatoY);


        containerSelectores->addLayout(containerSelectorY);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        containerSelectores->addItem(horizontalSpacer);


        verticalLayout->addLayout(containerSelectores);

        chartView = new QChartView(DialogShowGraphic);
        chartView->setObjectName(QString::fromUtf8("ChartView"));
        chartView->setRenderHint(QPainter::Antialiasing);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(chartView->sizePolicy().hasHeightForWidth());
        chartView->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(chartView);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(DialogShowGraphic);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(DialogShowGraphic);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogShowGraphic, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogShowGraphic, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogShowGraphic);
    } // setupUi

    void retranslateUi(QDialog *DialogShowGraphic)
    {
        DialogShowGraphic->setWindowTitle(QCoreApplication::translate("DialogShowGraphic", "Mostrar gr\303\241fico", nullptr));
        lblDatoY->setText(QCoreApplication::translate("DialogShowGraphic", "Dato Y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogShowGraphic: public Ui_DialogShowGraphic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DLG_2D_SHOW_2D_GRAPHICMQIELT_H
