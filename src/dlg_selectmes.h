/********************************************************************************
** Form generated from reading UI file 'dlg_select-mesXUEyLo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DLG_SELECT_2D_MESXUEYLO_H
#define DLG_SELECT_2D_MESXUEYLO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogSelectMes
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lblEstado;
    QComboBox *cmbMes;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogSelectMes)
    {
        if (DialogSelectMes->objectName().isEmpty())
            DialogSelectMes->setObjectName(QString::fromUtf8("DialogSelectMes"));
        DialogSelectMes->resize(348, 131);
        verticalLayout = new QVBoxLayout(DialogSelectMes);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        lblEstado = new QLabel(DialogSelectMes);
        lblEstado->setObjectName(QString::fromUtf8("lblEstado"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        lblEstado->setFont(font);
        lblEstado->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(lblEstado);

        cmbMes = new QComboBox(DialogSelectMes);
        cmbMes->setObjectName(QString::fromUtf8("cmbMes"));

        horizontalLayout->addWidget(cmbMes);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(DialogSelectMes);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogSelectMes);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogSelectMes, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogSelectMes, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogSelectMes);
    } // setupUi

    void retranslateUi(QDialog *DialogSelectMes)
    {
        DialogSelectMes->setWindowTitle(QCoreApplication::translate("DialogSelectMes", "Dialog", nullptr));
        lblEstado->setText(QCoreApplication::translate("DialogSelectMes", "Mes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSelectMes: public Ui_DialogSelectMes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DLG_SELECT_2D_MESXUEYLO_H
