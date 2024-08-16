/********************************************************************************
** Form generated from reading UI file 'dlg_select-messcWCoA.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DLG_SELECT_2D_MESSCWCOA_H
#define DLG_SELECT_2D_MESSCWCOA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *lblEstado;
    QComboBox *cmbMes;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(348, 131);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(110, 80, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lblEstado = new QLabel(Dialog);
        lblEstado->setObjectName(QString::fromUtf8("lblEstado"));
        lblEstado->setGeometry(QRect(10, 20, 61, 31));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        lblEstado->setFont(font);
        lblEstado->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        cmbMes = new QComboBox(Dialog);
        cmbMes->setObjectName(QString::fromUtf8("cmbMes"));
        cmbMes->setGeometry(QRect(100, 20, 231, 34));

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        lblEstado->setText(QCoreApplication::translate("Dialog", "Mes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSelectMes: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DLG_SELECT_2D_MESSCWCOA_H

