/********************************************************************************
** Form generated from reading UI file 'dlg-show-table.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DLG_SHOWTABLE_H
#define DLG_SHOWTABLE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogShowTable
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *lblNombreEmbalse;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QLabel *lblCapacidad;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLabel *lblMen;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *lblDesde;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *lblHasta;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *btnExportarCSV;
    QToolButton *btnVerGrafico;
    QTableView *tblResultados;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(598, 711);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 660, 581, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(Dialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 591, 641));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        lblNombreEmbalse = new QLabel(verticalLayoutWidget);
        lblNombreEmbalse->setObjectName(QString::fromUtf8("lblNombreEmbalse"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        lblNombreEmbalse->setFont(font);
        lblNombreEmbalse->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblNombreEmbalse);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 10, 10, 10);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_4);

        lblCapacidad = new QLabel(verticalLayoutWidget);
        lblCapacidad->setObjectName(QString::fromUtf8("lblCapacidad"));
        lblCapacidad->setFont(font);
        lblCapacidad->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lblCapacidad);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_5);

        lblMen = new QLabel(verticalLayoutWidget);
        lblMen->setObjectName(QString::fromUtf8("lblMen"));
        lblMen->setFont(font);
        lblMen->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lblMen);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        lblDesde = new QLabel(verticalLayoutWidget);
        lblDesde->setObjectName(QString::fromUtf8("lblDesde"));
        lblDesde->setFont(font);
        lblDesde->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lblDesde);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        lblHasta = new QLabel(verticalLayoutWidget);
        lblHasta->setObjectName(QString::fromUtf8("lblHasta"));
        lblHasta->setFont(font);
        lblHasta->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lblHasta);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(10, 10, 10, 10);
        btnExportarCSV = new QToolButton(verticalLayoutWidget);
        btnExportarCSV->setObjectName(QString::fromUtf8("btnExportarCSV"));
        horizontalLayout_3->addWidget(btnExportarCSV);

        btnVerGrafico = new QToolButton(verticalLayoutWidget);
        btnVerGrafico->setObjectName(QString::fromUtf8("btnVerGrafico"));

        horizontalLayout_3->addWidget(btnVerGrafico);


        verticalLayout->addLayout(horizontalLayout_3);

        tblResultados = new QTableView(verticalLayoutWidget);
        tblResultados->setObjectName(QString::fromUtf8("tblResultados"));

        verticalLayout->addWidget(tblResultados);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Datos por fecha", nullptr));
        lblNombreEmbalse->setText(QApplication::translate("Dialog", "TextLabel", nullptr));
        label_4->setText(QApplication::translate("Dialog", "Capacidad (Hm3)", nullptr));
        lblCapacidad->setText(QApplication::translate("Dialog", "--", nullptr));
        label_5->setText(QApplication::translate("Dialog", "MEN (m.s.n.m.)", nullptr));
        lblMen->setText(QApplication::translate("Dialog", "--", nullptr));
        label->setText(QApplication::translate("Dialog", "Desde", nullptr));
        lblDesde->setText(QApplication::translate("Dialog", "--", nullptr));
        label_2->setText(QApplication::translate("Dialog", "Hasta", nullptr));
        lblHasta->setText(QApplication::translate("Dialog", "--", nullptr));
#ifndef QT_NO_TOOLTIP
        btnExportarCSV->setToolTip(QApplication::translate("Dialog", "Exportar a CSV", nullptr));
#endif // QT_NO_TOOLTIP
        btnExportarCSV->setText(QApplication::translate("Dialog", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        btnVerGrafico->setToolTip(QApplication::translate("Dialog", "Ver gr\303\241fico", nullptr));
#endif // QT_NO_TOOLTIP
        btnVerGrafico->setText(QApplication::translate("Dialog", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogShowTable: public Ui_DialogShowTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DLG_SHOWTABLE_H
