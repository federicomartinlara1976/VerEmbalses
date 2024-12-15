/********************************************************************************
** Form generated from reading UI file 'dlg-show-simple-graphiczAnsmi.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DLG_2D_SHOW_2D_SIMPLE_2D_GRAPHICZANSMI_H
#define DLG_2D_SHOW_2D_SIMPLE_2D_GRAPHICZANSMI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogShowSimpleGraphic
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGraphicsView *chartView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogShowSimpleGraphic)
    {
        if (DialogShowSimpleGraphic->objectName().isEmpty())
            DialogShowSimpleGraphic->setObjectName(QString::fromUtf8("DialogShowSimpleGraphic"));
        DialogShowSimpleGraphic->resize(1068, 705);
        verticalLayout_2 = new QVBoxLayout(DialogShowSimpleGraphic);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        chartView = new QGraphicsView(DialogShowSimpleGraphic);
        chartView->setObjectName(QString::fromUtf8("chartView"));

        verticalLayout->addWidget(chartView);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(DialogShowSimpleGraphic);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(DialogShowSimpleGraphic);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogShowSimpleGraphic, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogShowSimpleGraphic, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogShowSimpleGraphic);
    } // setupUi

    void retranslateUi(QDialog *DialogShowSimpleGraphic)
    {
        DialogShowSimpleGraphic->setWindowTitle(QCoreApplication::translate("DialogShowSimpleGraphic", "Mostrar gr\303\241fico", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogShowSimpleGraphic: public Ui_DialogShowSimpleGraphic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DLG_2D_SHOW_2D_SIMPLE_2D_GRAPHICZANSMI_H
