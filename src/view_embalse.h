/********************************************************************************
** Form generated from reading UI file 'view-embalse.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef VIEW_EMBALSE_H
#define VIEW_EMBALSE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPor_fecha;
    QAction *actionDiaria;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QComboBox *cmbZona;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QComboBox *cmbEmbalse;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_8;
    QLabel *lblNivelMedia;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
    QLabel *lblNivelMinimo;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QLabel *lblNivelMaximo;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_17;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_16;
    QLabel *lblVolumenMedia;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_14;
    QLabel *lblVolumenMinimo;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_10;
    QLabel *lblVolumenMaximo;
    QFrame *line;
    QLabel *lblNombreEmbalse;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *lblCapacidad;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *lblVolumen;
    QLabel *label_4;
    QLabel *lblPercent;
    QVBoxLayout *verticalLayout_15;
    QToolButton *btnVerGrafico;
    QToolButton *btnExportarCSV;
    QMenuBar *menubar;
    QMenu *menuConsulta;
    QMenu *menuEstadisticas;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(575, 530);
        actionPor_fecha = new QAction(MainWindow);
        actionPor_fecha->setObjectName(QString::fromUtf8("actionPor_fecha"));
        actionDiaria = new QAction(MainWindow);
        actionDiaria->setObjectName(QString::fromUtf8("actionDiaria"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 491, 464));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(5, 5, 5, 5);
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_4->addWidget(label_3);

        cmbZona = new QComboBox(verticalLayoutWidget);
        cmbZona->setObjectName(QString::fromUtf8("cmbZona"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cmbZona->sizePolicy().hasHeightForWidth());
        cmbZona->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(cmbZona);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(5, 5, 5, 5);
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_5->addWidget(label_5);

        cmbEmbalse = new QComboBox(verticalLayoutWidget);
        cmbEmbalse->setObjectName(QString::fromUtf8("cmbEmbalse"));
        sizePolicy1.setHeightForWidth(cmbEmbalse->sizePolicy().hasHeightForWidth());
        cmbEmbalse->setSizePolicy(sizePolicy1);

        verticalLayout_5->addWidget(cmbEmbalse);


        horizontalLayout_2->addLayout(verticalLayout_5);


        verticalLayout->addLayout(horizontalLayout_2);

        line_2 = new QFrame(verticalLayoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_12);


        verticalLayout->addLayout(verticalLayout_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(5, 5, 5, 5);
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_10->addWidget(label_9);


        horizontalLayout_3->addLayout(verticalLayout_10);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(5, 5, 5, 5);
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_8->addWidget(label_8);

        lblNivelMedia = new QLabel(verticalLayoutWidget);
        lblNivelMedia->setObjectName(QString::fromUtf8("lblNivelMedia"));
        lblNivelMedia->setFont(font);

        verticalLayout_8->addWidget(lblNivelMedia);


        horizontalLayout_3->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(5, 5, 5, 5);
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_7->addWidget(label_7);

        lblNivelMinimo = new QLabel(verticalLayoutWidget);
        lblNivelMinimo->setObjectName(QString::fromUtf8("lblNivelMinimo"));
        lblNivelMinimo->setFont(font);

        verticalLayout_7->addWidget(lblNivelMinimo);


        horizontalLayout_3->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(5, 5, 5, 5);
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_6->addWidget(label_6);

        lblNivelMaximo = new QLabel(verticalLayoutWidget);
        lblNivelMaximo->setObjectName(QString::fromUtf8("lblNivelMaximo"));
        lblNivelMaximo->setFont(font);

        verticalLayout_6->addWidget(lblNivelMaximo);


        horizontalLayout_3->addLayout(verticalLayout_6);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(5, 5, 5, 5);
        label_17 = new QLabel(verticalLayoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_14->addWidget(label_17);


        horizontalLayout_4->addLayout(verticalLayout_14);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(5, 5, 5, 5);
        label_16 = new QLabel(verticalLayoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_13->addWidget(label_16);

        lblVolumenMedia = new QLabel(verticalLayoutWidget);
        lblVolumenMedia->setObjectName(QString::fromUtf8("lblVolumenMedia"));
        lblVolumenMedia->setFont(font);

        verticalLayout_13->addWidget(lblVolumenMedia);


        horizontalLayout_4->addLayout(verticalLayout_13);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(5, 5, 5, 5);
        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_12->addWidget(label_14);

        lblVolumenMinimo = new QLabel(verticalLayoutWidget);
        lblVolumenMinimo->setObjectName(QString::fromUtf8("lblVolumenMinimo"));
        lblVolumenMinimo->setFont(font);

        verticalLayout_12->addWidget(lblVolumenMinimo);


        horizontalLayout_4->addLayout(verticalLayout_12);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(5, 5, 5, 5);
        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_11->addWidget(label_10);

        lblVolumenMaximo = new QLabel(verticalLayoutWidget);
        lblVolumenMaximo->setObjectName(QString::fromUtf8("lblVolumenMaximo"));
        lblVolumenMaximo->setFont(font);

        verticalLayout_11->addWidget(lblVolumenMaximo);


        horizontalLayout_4->addLayout(verticalLayout_11);


        verticalLayout->addLayout(horizontalLayout_4);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        lblNombreEmbalse = new QLabel(verticalLayoutWidget);
        lblNombreEmbalse->setObjectName(QString::fromUtf8("lblNombreEmbalse"));
        sizePolicy1.setHeightForWidth(lblNombreEmbalse->sizePolicy().hasHeightForWidth());
        lblNombreEmbalse->setSizePolicy(sizePolicy1);
        lblNombreEmbalse->setFont(font);
        lblNombreEmbalse->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblNombreEmbalse);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_2->setContentsMargins(10, 10, 10, 10);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        lblCapacidad = new QLabel(verticalLayoutWidget);
        lblCapacidad->setObjectName(QString::fromUtf8("lblCapacidad"));
        sizePolicy.setHeightForWidth(lblCapacidad->sizePolicy().hasHeightForWidth());
        lblCapacidad->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        lblCapacidad->setFont(font1);
        lblCapacidad->setStyleSheet(QString::fromUtf8("background-color: white; border: 1px solid black;"));
        lblCapacidad->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lblCapacidad);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(10, 10, 10, 10);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        lblVolumen = new QLabel(verticalLayoutWidget);
        lblVolumen->setObjectName(QString::fromUtf8("lblVolumen"));
        sizePolicy.setHeightForWidth(lblVolumen->sizePolicy().hasHeightForWidth());
        lblVolumen->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        lblVolumen->setFont(font2);
        lblVolumen->setStyleSheet(QString::fromUtf8("background-color: white; border: 1px solid black;"));
        lblVolumen->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lblVolumen);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_4);

        lblPercent = new QLabel(verticalLayoutWidget);
        lblPercent->setObjectName(QString::fromUtf8("lblPercent"));
        sizePolicy.setHeightForWidth(lblPercent->sizePolicy().hasHeightForWidth());
        lblPercent->setSizePolicy(sizePolicy);
        lblPercent->setFont(font2);
        lblPercent->setStyleSheet(QString::fromUtf8("background-color: white; border: 1px solid black;"));
        lblPercent->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lblPercent);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(10, 10, 10, 10);
        btnVerGrafico = new QToolButton(verticalLayoutWidget);
        btnVerGrafico->setObjectName(QString::fromUtf8("btnVerGrafico"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("/usr/share/icons/Humanity/categories/22/redhat-office.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnVerGrafico->setIcon(icon);

        verticalLayout_15->addWidget(btnVerGrafico);

        btnExportarCSV = new QToolButton(verticalLayoutWidget);
        btnExportarCSV->setObjectName(QString::fromUtf8("btnExportarCSV"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("/usr/share/icons/gnome/22x22/apps/ksysguard.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExportarCSV->setIcon(icon1);

        verticalLayout_15->addWidget(btnExportarCSV);


        horizontalLayout->addLayout(verticalLayout_15);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 505, 32));
        menuConsulta = new QMenu(menubar);
        menuConsulta->setObjectName(QString::fromUtf8("menuConsulta"));
        menuEstadisticas = new QMenu(menubar);
        menuEstadisticas->setObjectName(QString::fromUtf8("menuEstadisticas"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuConsulta->menuAction());
        menubar->addAction(menuEstadisticas->menuAction());
        menuConsulta->addAction(actionPor_fecha);
        menuEstadisticas->addAction(actionDiaria);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Ver embalse", nullptr));
        actionPor_fecha->setText(QApplication::translate("MainWindow", "Por fecha", nullptr));
        actionDiaria->setText(QApplication::translate("MainWindow", "Diaria", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Zona", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Embalses", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Estad\303\255sticas por zona</p></body></html>", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Niveles (Hm3)</p></body></html>", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Media</p></body></html>", nullptr));
        lblNivelMedia->setText(QApplication::translate("MainWindow", "--", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "M\303\255nimo", nullptr));
        lblNivelMinimo->setText(QApplication::translate("MainWindow", "--", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "M\303\241ximo", nullptr));
        lblNivelMaximo->setText(QApplication::translate("MainWindow", "--", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "Volumen (Hm3)", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "Media", nullptr));
        lblVolumenMedia->setText(QApplication::translate("MainWindow", "--", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "M\303\255nimo", nullptr));
        lblVolumenMinimo->setText(QApplication::translate("MainWindow", "--", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "M\303\241ximo", nullptr));
        lblVolumenMaximo->setText(QApplication::translate("MainWindow", "--", nullptr));
        lblNombreEmbalse->setText(QApplication::translate("MainWindow", "EMBALSE", nullptr));
        label->setText(QApplication::translate("MainWindow", "Capacidad (Hm3)", nullptr));
        lblCapacidad->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Volumen (Hm3)", nullptr));
        lblVolumen->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "porcentaje %", nullptr));
        lblPercent->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnVerGrafico->setToolTip(QApplication::translate("MainWindow", "Ver gr\303\241fico", nullptr));
#endif // QT_NO_TOOLTIP
        btnVerGrafico->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        btnExportarCSV->setToolTip(QApplication::translate("MainWindow", "Exportar a CSV", nullptr));
#endif // QT_NO_TOOLTIP
        btnExportarCSV->setText(QApplication::translate("MainWindow", "...", nullptr));
        menuConsulta->setTitle(QApplication::translate("MainWindow", "Consulta", nullptr));
        menuEstadisticas->setTitle(QApplication::translate("MainWindow", "Estad\303\255sticas", nullptr));
    } // retranslateUi
};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // VIEW_EMBALSE_H
