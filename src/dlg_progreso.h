/********************************************************************************
** Form generated from reading UI file 'dlg_progresoyEahoN.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DLG_PROGRESOYEAHON_H
#define DLG_PROGRESOYEAHON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogProgreso
{
public:
    QVBoxLayout *verticalLayout;
    QProgressBar *progressBar;
    QLabel *lblEstado;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogProgreso)
    {
        if (DialogProgreso->objectName().isEmpty())
            DialogProgreso->setObjectName(QString::fromUtf8("DialogProgreso"));
        DialogProgreso->resize(413, 131);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogProgreso->sizePolicy().hasHeightForWidth());
        DialogProgreso->setSizePolicy(sizePolicy);
        DialogProgreso->setMinimumSize(QSize(413, 131));
        DialogProgreso->setMaximumSize(QSize(413, 131));
        verticalLayout = new QVBoxLayout(DialogProgreso);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        progressBar = new QProgressBar(DialogProgreso);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        QFont font;
        font.setBold(false);
        font.setUnderline(false);
        progressBar->setFont(font);
        progressBar->setValue(41);

        verticalLayout->addWidget(progressBar);

        lblEstado = new QLabel(DialogProgreso);
        lblEstado->setObjectName(QString::fromUtf8("lblEstado"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        lblEstado->setFont(font1);
        lblEstado->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblEstado);

        buttonBox = new QDialogButtonBox(DialogProgreso);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogProgreso);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogProgreso, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogProgreso, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogProgreso);
    } // setupUi

    void retranslateUi(QDialog *DialogProgreso)
    {
        DialogProgreso->setWindowTitle(QCoreApplication::translate("DialogProgreso", "Dialog", nullptr));
        lblEstado->setText(QCoreApplication::translate("DialogProgreso", "--", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogProgreso: public Ui_DialogProgreso {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DLG_PROGRESOYEAHON_H
