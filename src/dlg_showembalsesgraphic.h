/********************************************************************************
** Form generated from reading UI file 'dlg-show-embalses-graphicfyYUry.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DLG_2D_SHOW_2D_EMBALSES_2D_GRAPHICFYYURY_H
#define DLG_2D_SHOW_2D_EMBALSES_2D_GRAPHICFYYURY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtCharts/QChartView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

using namespace QtCharts;

class Ui_DialogShowEmbalsesGraphic
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *rbtGlobal;
    QRadioButton *rbtDetalles;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPrint;
    QPushButton *btnClose;
    QChartView *chartView;

    void setupUi(QDialog *DialogShowEmbalsesGraphic)
    {
        if (DialogShowEmbalsesGraphic->objectName().isEmpty())
            DialogShowEmbalsesGraphic->setObjectName(QString::fromUtf8("DialogShowEmbalsesGraphic"));
        DialogShowEmbalsesGraphic->resize(1068, 705);
        verticalLayout_2 = new QVBoxLayout(DialogShowEmbalsesGraphic);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        groupBox_2 = new QGroupBox(DialogShowEmbalsesGraphic);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        rbtGlobal = new QRadioButton(groupBox_2);
        rbtGlobal->setObjectName(QString::fromUtf8("rbtGlobal"));
        rbtGlobal->setChecked(true);

        horizontalLayout_3->addWidget(rbtGlobal);

        rbtDetalles = new QRadioButton(groupBox_2);
        rbtDetalles->setObjectName(QString::fromUtf8("rbtDetalles"));

        horizontalLayout_3->addWidget(rbtDetalles);


        horizontalLayout_2->addWidget(groupBox_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnPrint = new QPushButton(DialogShowEmbalsesGraphic);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("printer");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        btnPrint->setIcon(icon);

        horizontalLayout_2->addWidget(btnPrint);

        btnClose = new QPushButton(DialogShowEmbalsesGraphic);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("window-close")));
        btnClose->setIcon(icon1);

        horizontalLayout_2->addWidget(btnClose);


        verticalLayout->addLayout(horizontalLayout_2);

        chartView = new QChartView(DialogShowEmbalsesGraphic);
        chartView->setObjectName(QString::fromUtf8("chartView"));

        verticalLayout->addWidget(chartView);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(DialogShowEmbalsesGraphic);

        QMetaObject::connectSlotsByName(DialogShowEmbalsesGraphic);
    } // setupUi

    void retranslateUi(QDialog *DialogShowEmbalsesGraphic)
    {
        DialogShowEmbalsesGraphic->setWindowTitle(QCoreApplication::translate("DialogShowEmbalsesGraphic", "Mostrar gr\303\241fico", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DialogShowEmbalsesGraphic", "Tipo de gr\303\241fico", nullptr));
        rbtGlobal->setText(QCoreApplication::translate("DialogShowEmbalsesGraphic", "Global", nullptr));
        rbtDetalles->setText(QCoreApplication::translate("DialogShowEmbalsesGraphic", "Detalles", nullptr));
#if QT_CONFIG(tooltip)
        btnPrint->setToolTip(QCoreApplication::translate("DialogShowEmbalsesGraphic", "Imprimir", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPrint->setText(QString());
#if QT_CONFIG(tooltip)
        btnClose->setToolTip(QCoreApplication::translate("DialogShowEmbalsesGraphic", "Cerrar", nullptr));
#endif // QT_CONFIG(tooltip)
        btnClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogShowEmbalsesGraphic: public Ui_DialogShowEmbalsesGraphic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DLG_2D_SHOW_2D_EMBALSES_2D_GRAPHICFYYURY_H
