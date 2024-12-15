/********************************************************************************
** Form generated from reading UI file 'dlg-show-simple-graphicZmnWDG.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DLG_2D_SHOW_2D_SIMPLE_2D_GRAPHICZMNWDG_H
#define DLG_2D_SHOW_2D_SIMPLE_2D_GRAPHICZMNWDG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtCharts/QChartView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

using namespace QtCharts;

class Ui_DialogShowSimpleGraphic
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPrint;
    QPushButton *btnClose;
    QChartView *chartView;

    void setupUi(QDialog *DialogShowSimpleGraphic)
    {
        if (DialogShowSimpleGraphic->objectName().isEmpty())
            DialogShowSimpleGraphic->setObjectName(QString::fromUtf8("DialogShowSimpleGraphic"));
        DialogShowSimpleGraphic->resize(1068, 705);
        verticalLayout_2 = new QVBoxLayout(DialogShowSimpleGraphic);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnPrint = new QPushButton(DialogShowSimpleGraphic);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("printer");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        btnPrint->setIcon(icon);

        horizontalLayout->addWidget(btnPrint);

        btnClose = new QPushButton(DialogShowSimpleGraphic);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("window-close")));
        btnClose->setIcon(icon1);

        horizontalLayout->addWidget(btnClose);


        verticalLayout->addLayout(horizontalLayout);

        chartView = new QChartView(DialogShowSimpleGraphic);
        chartView->setObjectName(QString::fromUtf8("chartView"));

        verticalLayout->addWidget(chartView);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(DialogShowSimpleGraphic);

        QMetaObject::connectSlotsByName(DialogShowSimpleGraphic);
    } // setupUi

    void retranslateUi(QDialog *DialogShowSimpleGraphic)
    {
        DialogShowSimpleGraphic->setWindowTitle(QCoreApplication::translate("DialogShowSimpleGraphic", "Mostrar gr\303\241fico", nullptr));
#if QT_CONFIG(tooltip)
        btnPrint->setToolTip(QCoreApplication::translate("DialogShowSimpleGraphic", "Imprimir", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPrint->setText(QString());
#if QT_CONFIG(tooltip)
        btnClose->setToolTip(QCoreApplication::translate("DialogShowSimpleGraphic", "Cerrar", nullptr));
#endif // QT_CONFIG(tooltip)
        btnClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogShowSimpleGraphic: public Ui_DialogShowSimpleGraphic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DLG_2D_SHOW_2D_SIMPLE_2D_GRAPHICZMNWDG_H
