/********************************************************************************
** Form generated from reading UI file 'dlg-show-tableGdEZMI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DLG_2D_SHOW_2D_TABLEGDEZMI_H
#define DLG_2D_SHOW_2D_TABLEGDEZMI_H

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

QT_BEGIN_NAMESPACE

class Ui_DialogShowTable
{
public:
    QVBoxLayout *verticalLayout_6;
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
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogShowTable)
    {
        if (DialogShowTable->objectName().isEmpty())
            DialogShowTable->setObjectName(QString::fromUtf8("DialogShowTable"));
        DialogShowTable->resize(598, 711);
        verticalLayout_6 = new QVBoxLayout(DialogShowTable);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        lblNombreEmbalse = new QLabel(DialogShowTable);
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
        label_4 = new QLabel(DialogShowTable);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_4);

        lblCapacidad = new QLabel(DialogShowTable);
        lblCapacidad->setObjectName(QString::fromUtf8("lblCapacidad"));
        lblCapacidad->setFont(font);
        lblCapacidad->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lblCapacidad);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(DialogShowTable);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_5);

        lblMen = new QLabel(DialogShowTable);
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
        label = new QLabel(DialogShowTable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        lblDesde = new QLabel(DialogShowTable);
        lblDesde->setObjectName(QString::fromUtf8("lblDesde"));
        lblDesde->setFont(font);
        lblDesde->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lblDesde);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(DialogShowTable);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        lblHasta = new QLabel(DialogShowTable);
        lblHasta->setObjectName(QString::fromUtf8("lblHasta"));
        lblHasta->setFont(font);
        lblHasta->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lblHasta);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(10, 10, 10, 10);
        btnExportarCSV = new QToolButton(DialogShowTable);
        btnExportarCSV->setObjectName(QString::fromUtf8("btnExportarCSV"));

        horizontalLayout_3->addWidget(btnExportarCSV);

        btnVerGrafico = new QToolButton(DialogShowTable);
        btnVerGrafico->setObjectName(QString::fromUtf8("btnVerGrafico"));

        horizontalLayout_3->addWidget(btnVerGrafico);


        verticalLayout->addLayout(horizontalLayout_3);

        tblResultados = new QTableView(DialogShowTable);
        tblResultados->setObjectName(QString::fromUtf8("tblResultados"));

        verticalLayout->addWidget(tblResultados);


        verticalLayout_6->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(DialogShowTable);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout_6->addWidget(buttonBox);


        retranslateUi(DialogShowTable);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogShowTable, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogShowTable, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogShowTable);
    } // setupUi

    void retranslateUi(QDialog *DialogShowTable)
    {
        DialogShowTable->setWindowTitle(QCoreApplication::translate("DialogShowTable", "Datos por fecha", nullptr));
        lblNombreEmbalse->setText(QCoreApplication::translate("DialogShowTable", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("DialogShowTable", "Capacidad (Hm3)", nullptr));
        lblCapacidad->setText(QCoreApplication::translate("DialogShowTable", "--", nullptr));
        label_5->setText(QCoreApplication::translate("DialogShowTable", "MEN (m.s.n.m.)", nullptr));
        lblMen->setText(QCoreApplication::translate("DialogShowTable", "--", nullptr));
        label->setText(QCoreApplication::translate("DialogShowTable", "Desde", nullptr));
        lblDesde->setText(QCoreApplication::translate("DialogShowTable", "--", nullptr));
        label_2->setText(QCoreApplication::translate("DialogShowTable", "Hasta", nullptr));
        lblHasta->setText(QCoreApplication::translate("DialogShowTable", "--", nullptr));
#if QT_CONFIG(tooltip)
        btnExportarCSV->setToolTip(QCoreApplication::translate("DialogShowTable", "Exportar a CSV", nullptr));
#endif // QT_CONFIG(tooltip)
        btnExportarCSV->setText(QCoreApplication::translate("DialogShowTable", "...", nullptr));
#if QT_CONFIG(tooltip)
        btnVerGrafico->setToolTip(QCoreApplication::translate("DialogShowTable", "Ver gr\303\241fico", nullptr));
#endif // QT_CONFIG(tooltip)
        btnVerGrafico->setText(QCoreApplication::translate("DialogShowTable", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogShowTable: public Ui_DialogShowTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DLG_2D_SHOW_2D_TABLEGDEZMI_H
