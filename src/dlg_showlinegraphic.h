/********************************************************************************
** Form generated from reading UI file 'dlg-show-line-graphicHaLrnh.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DLG_2D_SHOW_2D_LINE_2D_GRAPHICHALRNH_H
#define DLG_2D_SHOW_2D_LINE_2D_GRAPHICHALRNH_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtCharts/QChartView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

using namespace QtCharts;

class Ui_DialogShowLineGraphic
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *containerSelectores;
    QHBoxLayout *containerSelectorY;
    QLabel *lblDatoY;
    QComboBox *cmbDatoY;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPrint;
    QChartView *chartView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogShowLineGraphic)
    {
        if (DialogShowLineGraphic->objectName().isEmpty())
            DialogShowLineGraphic->setObjectName(QString::fromUtf8("DialogShowLineGraphic"));
        DialogShowLineGraphic->resize(1068, 705);
        verticalLayout_2 = new QVBoxLayout(DialogShowLineGraphic);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        containerSelectores = new QHBoxLayout();
        containerSelectores->setObjectName(QString::fromUtf8("containerSelectores"));
        containerSelectores->setSizeConstraint(QLayout::SetFixedSize);
        containerSelectores->setContentsMargins(5, 5, 5, 5);
        containerSelectorY = new QHBoxLayout();
        containerSelectorY->setObjectName(QString::fromUtf8("containerSelectorY"));
        containerSelectorY->setContentsMargins(10, 10, 10, 10);
        lblDatoY = new QLabel(DialogShowLineGraphic);
        lblDatoY->setObjectName(QString::fromUtf8("lblDatoY"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblDatoY->sizePolicy().hasHeightForWidth());
        lblDatoY->setSizePolicy(sizePolicy);

        containerSelectorY->addWidget(lblDatoY);

        cmbDatoY = new QComboBox(DialogShowLineGraphic);
        cmbDatoY->setObjectName(QString::fromUtf8("cmbDatoY"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cmbDatoY->sizePolicy().hasHeightForWidth());
        cmbDatoY->setSizePolicy(sizePolicy1);

        containerSelectorY->addWidget(cmbDatoY);


        containerSelectores->addLayout(containerSelectorY);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        containerSelectores->addItem(horizontalSpacer);

        btnPrint = new QPushButton(DialogShowLineGraphic);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("printer");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        btnPrint->setIcon(icon);

        containerSelectores->addWidget(btnPrint);


        verticalLayout->addLayout(containerSelectores);

        chartView = new QChartView(DialogShowLineGraphic);
        chartView->setObjectName(QString::fromUtf8("chartView"));

        verticalLayout->addWidget(chartView);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(DialogShowLineGraphic);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(DialogShowLineGraphic);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogShowLineGraphic, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogShowLineGraphic, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogShowLineGraphic);
    } // setupUi

    void retranslateUi(QDialog *DialogShowLineGraphic)
    {
        DialogShowLineGraphic->setWindowTitle(QCoreApplication::translate("DialogShowLineGraphic", "Mostrar gr\303\241fico", nullptr));
        lblDatoY->setText(QCoreApplication::translate("DialogShowLineGraphic", "Dato Y", nullptr));
#if QT_CONFIG(tooltip)
        btnPrint->setToolTip(QCoreApplication::translate("DialogShowLineGraphic", "Imprimir", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPrint->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogShowLineGraphic: public Ui_DialogShowLineGraphic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DLG_2D_SHOW_2D_LINE_2D_GRAPHICHALRNH_H
