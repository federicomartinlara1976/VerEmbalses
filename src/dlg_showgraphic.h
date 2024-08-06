/********************************************************************************
** Form generated from reading UI file 'dlg-show-graphic.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DLG_SHOWGRAPHIC_H
#define DLG_SHOWGRAPHIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtCharts/QChartView>

QT_BEGIN_NAMESPACE

using namespace QtCharts;

class Ui_DialogShowGraphic
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *cmbDatoX;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *cmbDatoY;
    QChartView *chartView;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        
        Dialog->resize(1068, 705);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 660, 1051, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(Dialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 1051, 641));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 10, 10, 10);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        cmbDatoX = new QComboBox(verticalLayoutWidget);
        cmbDatoX->setObjectName(QString::fromUtf8("cmbDatoX"));

        horizontalLayout_2->addWidget(cmbDatoX);


        horizontalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(10, 10, 10, 10);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        cmbDatoY = new QComboBox(verticalLayoutWidget);
        cmbDatoY->setObjectName(QString::fromUtf8("cmbDatoY"));

        horizontalLayout_3->addWidget(cmbDatoY);


        horizontalLayout->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout);

        chartView = new QChartView(verticalLayoutWidget);
        chartView->setObjectName(QString::fromUtf8("ChartView"));
        chartView->setRenderHint(QPainter::Antialiasing);

        verticalLayout->addWidget(chartView);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Mostrar gr\303\241fico", nullptr));
        label->setText(QApplication::translate("Dialog", "Dato X", nullptr));
        label_2->setText(QApplication::translate("Dialog", "Dato Y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogShowGraphic: public Ui_DialogShowGraphic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DLG_SHOWGRAPHIC_H
