/********************************************************************************
** Form generated from reading UI file 'dlg_select-tipo-graficoIkJwpD.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DLG_SELECT_2D_TIPO_2D_GRAFICOIKJWPD_H
#define DLG_SELECT_2D_TIPO_2D_GRAFICOIKJWPD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogSelectGrafico
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *rbtLinear;
    QRadioButton *rbtRelacionNivelVolumen;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogSelectGrafico)
    {
        if (DialogSelectGrafico->objectName().isEmpty())
            DialogSelectGrafico->setObjectName(QString::fromUtf8("DialogSelectGrafico"));
        DialogSelectGrafico->resize(320, 147);
        verticalLayout = new QVBoxLayout(DialogSelectGrafico);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(DialogSelectGrafico);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        rbtLinear = new QRadioButton(groupBox);
        rbtLinear->setObjectName(QString::fromUtf8("rbtLinear"));
        rbtLinear->setChecked(true);

        verticalLayout_3->addWidget(rbtLinear);

        rbtRelacionNivelVolumen = new QRadioButton(groupBox);
        rbtRelacionNivelVolumen->setObjectName(QString::fromUtf8("rbtRelacionNivelVolumen"));

        verticalLayout_3->addWidget(rbtRelacionNivelVolumen);


        verticalLayout_2->addWidget(groupBox);


        verticalLayout->addLayout(verticalLayout_2);

        buttonBox = new QDialogButtonBox(DialogSelectGrafico);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogSelectGrafico);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogSelectGrafico, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogSelectGrafico, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogSelectGrafico);
    } // setupUi

    void retranslateUi(QDialog *DialogSelectGrafico)
    {
        DialogSelectGrafico->setWindowTitle(QCoreApplication::translate("DialogSelectGrafico", "Tipo de gr\303\241fico", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DialogSelectGrafico", "Tipo de gr\303\241fico", nullptr));
        rbtLinear->setText(QCoreApplication::translate("DialogSelectGrafico", "Linear por fecha", nullptr));
        rbtRelacionNivelVolumen->setText(QCoreApplication::translate("DialogSelectGrafico", "Relaci\303\263n Nivel - Volumen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSelectGrafico: public Ui_DialogSelectGrafico {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DLG_SELECT_2D_TIPO_2D_GRAFICOIKJWPD_H
