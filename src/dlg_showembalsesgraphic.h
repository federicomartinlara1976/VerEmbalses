/********************************************************************************
** Form generated from reading UI file 'dlg-show-embalses-graphicrJOiYM.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DLG_2D_SHOW_2D_EMBALSES_2D_GRAPHICRJOIYM_H
#define DLG_2D_SHOW_2D_EMBALSES_2D_GRAPHICRJOIYM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogShowEmbalsesGraphic
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbtGlobal;
    QRadioButton *rbtDetalles;
    QGraphicsView *chartView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogShowEmbalsesGraphic)
    {
        if (DialogShowEmbalsesGraphic->objectName().isEmpty())
            DialogShowEmbalsesGraphic->setObjectName(QString::fromUtf8("DialogShowEmbalsesGraphic"));
        DialogShowEmbalsesGraphic->resize(1068, 705);
        verticalLayout_2 = new QVBoxLayout(DialogShowEmbalsesGraphic);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(DialogShowEmbalsesGraphic);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        rbtGlobal = new QRadioButton(groupBox);
        rbtGlobal->setObjectName(QString::fromUtf8("rbtGlobal"));
        rbtGlobal->setChecked(true);

        horizontalLayout->addWidget(rbtGlobal);

        rbtDetalles = new QRadioButton(groupBox);
        rbtDetalles->setObjectName(QString::fromUtf8("rbtDetalles"));

        horizontalLayout->addWidget(rbtDetalles);


        verticalLayout->addWidget(groupBox);

        chartView = new QGraphicsView(DialogShowEmbalsesGraphic);
        chartView->setObjectName(QString::fromUtf8("chartView"));

        verticalLayout->addWidget(chartView);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(DialogShowEmbalsesGraphic);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(DialogShowEmbalsesGraphic);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogShowEmbalsesGraphic, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogShowEmbalsesGraphic, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogShowEmbalsesGraphic);
    } // setupUi

    void retranslateUi(QDialog *DialogShowEmbalsesGraphic)
    {
        DialogShowEmbalsesGraphic->setWindowTitle(QCoreApplication::translate("DialogShowEmbalsesGraphic", "Mostrar gr\303\241fico", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DialogShowEmbalsesGraphic", "Tipo de gr\303\241fico", nullptr));
        rbtGlobal->setText(QCoreApplication::translate("DialogShowEmbalsesGraphic", "Global", nullptr));
        rbtDetalles->setText(QCoreApplication::translate("DialogShowEmbalsesGraphic", "Detalles", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogShowEmbalsesGraphic: public Ui_DialogShowEmbalsesGraphic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DLG_2D_SHOW_2D_EMBALSES_2D_GRAPHICRJOIYM_H
