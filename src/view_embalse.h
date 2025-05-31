/********************************************************************************
** Form generated from reading UI file 'ver_embalsesbevHaK.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef VER_EMBALSESBEVHAK_H
#define VER_EMBALSESBEVHAK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDiaria;
    QAction *actionMes;
    QAction *actionPor_fecha;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tabEmbalses;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QComboBox *cmbZona;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QComboBox *cmbEmbalse;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lblZona;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btnVerEmbalses;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
    QLabel *lblNivelMedia;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_9;
    QLabel *lblNivelMinimo;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_11;
    QLabel *lblNivelMaximo;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_13;
    QLabel *lblVolumenMedia;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_15;
    QLabel *lblVolumenMinimo;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_17;
    QLabel *lblVolumenMaximo;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_8;
    QLabel *lblVolumenTotal;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_12;
    QLabel *lblTotalCapacidadZona;
    QVBoxLayout *verticalLayout_14;
    QLabel *label;
    QLabel *lblPorcentajeVolumenTotal;
    QVBoxLayout *verticalLayout_15;
    QLabel *lblNombreEmbalse;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_19;
    QLabel *lblCapacidad;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_21;
    QLabel *lblVolumen;
    QLabel *label_23;
    QLabel *lblPercent;
    QVBoxLayout *verticalLayout_11;
    QPushButton *btnVerGrafico;
    QPushButton *btnExportarCSV;
    QSpacerItem *verticalSpacer;
    QWidget *tabPluviometria;
    QVBoxLayout *verticalLayout_19;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_2;
    QComboBox *cmbPlvZona;
    QVBoxLayout *verticalLayout_21;
    QLabel *label_14;
    QComboBox *cmbPuntoControl;
    QHBoxLayout *horizontalLayout_9;
    QTableView *tableView;
    QMenuBar *menubar;
    QMenu *menuConsulta;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1041, 762);
        MainWindow->setMinimumSize(QSize(840, 600));
        actionDiaria = new QAction(MainWindow);
        actionDiaria->setObjectName(QString::fromUtf8("actionDiaria"));
        actionMes = new QAction(MainWindow);
        actionMes->setObjectName(QString::fromUtf8("actionMes"));
        actionPor_fecha = new QAction(MainWindow);
        actionPor_fecha->setObjectName(QString::fromUtf8("actionPor_fecha"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(10, 10, 10, 10);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabEmbalses = new QWidget();
        tabEmbalses->setObjectName(QString::fromUtf8("tabEmbalses"));
        verticalLayout_18 = new QVBoxLayout(tabEmbalses);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_4->setContentsMargins(5, 5, 5, 5);
        label_3 = new QLabel(tabEmbalses);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(label_3);

        cmbZona = new QComboBox(tabEmbalses);
        cmbZona->setObjectName(QString::fromUtf8("cmbZona"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cmbZona->sizePolicy().hasHeightForWidth());
        cmbZona->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(cmbZona);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        label_4 = new QLabel(tabEmbalses);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(label_4);

        cmbEmbalse = new QComboBox(tabEmbalses);
        cmbEmbalse->setObjectName(QString::fromUtf8("cmbEmbalse"));
        sizePolicy1.setHeightForWidth(cmbEmbalse->sizePolicy().hasHeightForWidth());
        cmbEmbalse->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(cmbEmbalse);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_18->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(5, 5, 5, 5);
        label_10 = new QLabel(tabEmbalses);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_10->setFont(font);

        horizontalLayout_5->addWidget(label_10);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        lblZona = new QLabel(tabEmbalses);
        lblZona->setObjectName(QString::fromUtf8("lblZona"));
        lblZona->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(lblZona);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        btnVerEmbalses = new QPushButton(tabEmbalses);
        btnVerEmbalses->setObjectName(QString::fromUtf8("btnVerEmbalses"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("applications-graphics");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        btnVerEmbalses->setIcon(icon);

        horizontalLayout_6->addWidget(btnVerEmbalses);


        horizontalLayout_5->addLayout(horizontalLayout_6);


        verticalLayout_18->addLayout(horizontalLayout_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_4->setContentsMargins(5, 5, 5, 5);
        label_5 = new QLabel(tabEmbalses);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label_5);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(5, 5, 5, 5);
        label_7 = new QLabel(tabEmbalses);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        verticalLayout_7->addWidget(label_7);

        lblNivelMedia = new QLabel(tabEmbalses);
        lblNivelMedia->setObjectName(QString::fromUtf8("lblNivelMedia"));
        sizePolicy.setHeightForWidth(lblNivelMedia->sizePolicy().hasHeightForWidth());
        lblNivelMedia->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        lblNivelMedia->setFont(font1);

        verticalLayout_7->addWidget(lblNivelMedia);


        horizontalLayout_4->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(5, 5, 5, 5);
        label_9 = new QLabel(tabEmbalses);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(label_9);

        lblNivelMinimo = new QLabel(tabEmbalses);
        lblNivelMinimo->setObjectName(QString::fromUtf8("lblNivelMinimo"));
        sizePolicy.setHeightForWidth(lblNivelMinimo->sizePolicy().hasHeightForWidth());
        lblNivelMinimo->setSizePolicy(sizePolicy);
        lblNivelMinimo->setFont(font1);

        verticalLayout_6->addWidget(lblNivelMinimo);


        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(5, 5, 5, 5);
        label_11 = new QLabel(tabEmbalses);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(label_11);

        lblNivelMaximo = new QLabel(tabEmbalses);
        lblNivelMaximo->setObjectName(QString::fromUtf8("lblNivelMaximo"));
        sizePolicy.setHeightForWidth(lblNivelMaximo->sizePolicy().hasHeightForWidth());
        lblNivelMaximo->setSizePolicy(sizePolicy);
        lblNivelMaximo->setFont(font1);

        verticalLayout_5->addWidget(lblNivelMaximo);


        horizontalLayout_4->addLayout(verticalLayout_5);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_3->setContentsMargins(5, 5, 5, 5);
        label_6 = new QLabel(tabEmbalses);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_6);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(5, 5, 5, 5);
        label_13 = new QLabel(tabEmbalses);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);

        verticalLayout_10->addWidget(label_13);

        lblVolumenMedia = new QLabel(tabEmbalses);
        lblVolumenMedia->setObjectName(QString::fromUtf8("lblVolumenMedia"));
        sizePolicy.setHeightForWidth(lblVolumenMedia->sizePolicy().hasHeightForWidth());
        lblVolumenMedia->setSizePolicy(sizePolicy);
        lblVolumenMedia->setFont(font1);

        verticalLayout_10->addWidget(lblVolumenMedia);


        horizontalLayout_3->addLayout(verticalLayout_10);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(5, 5, 5, 5);
        label_15 = new QLabel(tabEmbalses);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);

        verticalLayout_9->addWidget(label_15);

        lblVolumenMinimo = new QLabel(tabEmbalses);
        lblVolumenMinimo->setObjectName(QString::fromUtf8("lblVolumenMinimo"));
        sizePolicy.setHeightForWidth(lblVolumenMinimo->sizePolicy().hasHeightForWidth());
        lblVolumenMinimo->setSizePolicy(sizePolicy);
        lblVolumenMinimo->setFont(font1);

        verticalLayout_9->addWidget(lblVolumenMinimo);


        horizontalLayout_3->addLayout(verticalLayout_9);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(5, 5, 5, 5);
        label_17 = new QLabel(tabEmbalses);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);

        verticalLayout_8->addWidget(label_17);

        lblVolumenMaximo = new QLabel(tabEmbalses);
        lblVolumenMaximo->setObjectName(QString::fromUtf8("lblVolumenMaximo"));
        sizePolicy.setHeightForWidth(lblVolumenMaximo->sizePolicy().hasHeightForWidth());
        lblVolumenMaximo->setSizePolicy(sizePolicy);
        lblVolumenMaximo->setFont(font1);

        verticalLayout_8->addWidget(lblVolumenMaximo);


        horizontalLayout_3->addLayout(verticalLayout_8);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(5, 5, 5, 5);
        label_8 = new QLabel(tabEmbalses);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_17->addWidget(label_8);

        lblVolumenTotal = new QLabel(tabEmbalses);
        lblVolumenTotal->setObjectName(QString::fromUtf8("lblVolumenTotal"));
        lblVolumenTotal->setFont(font1);

        verticalLayout_17->addWidget(lblVolumenTotal);


        horizontalLayout_3->addLayout(verticalLayout_17);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(5, 5, 5, 5);
        label_12 = new QLabel(tabEmbalses);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_7->addWidget(label_12);

        lblTotalCapacidadZona = new QLabel(tabEmbalses);
        lblTotalCapacidadZona->setObjectName(QString::fromUtf8("lblTotalCapacidadZona"));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        lblTotalCapacidadZona->setFont(font2);
        lblTotalCapacidadZona->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(lblTotalCapacidadZona);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(5, 5, 5, 5);
        label = new QLabel(tabEmbalses);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_14->addWidget(label);

        lblPorcentajeVolumenTotal = new QLabel(tabEmbalses);
        lblPorcentajeVolumenTotal->setObjectName(QString::fromUtf8("lblPorcentajeVolumenTotal"));
        lblPorcentajeVolumenTotal->setFont(font1);
        lblPorcentajeVolumenTotal->setStyleSheet(QString::fromUtf8("background-color: white; border: 1px solid black;"));
        lblPorcentajeVolumenTotal->setAlignment(Qt::AlignCenter);

        verticalLayout_14->addWidget(lblPorcentajeVolumenTotal);


        horizontalLayout_7->addLayout(verticalLayout_14);


        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_18->addLayout(verticalLayout);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_15->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_15->setContentsMargins(5, 5, 5, 5);
        lblNombreEmbalse = new QLabel(tabEmbalses);
        lblNombreEmbalse->setObjectName(QString::fromUtf8("lblNombreEmbalse"));
        sizePolicy.setHeightForWidth(lblNombreEmbalse->sizePolicy().hasHeightForWidth());
        lblNombreEmbalse->setSizePolicy(sizePolicy);
        lblNombreEmbalse->setFont(font1);
        lblNombreEmbalse->setAlignment(Qt::AlignCenter);

        verticalLayout_15->addWidget(lblNombreEmbalse);


        verticalLayout_18->addLayout(verticalLayout_15);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(5, 5, 5, 5);
        label_19 = new QLabel(tabEmbalses);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);
        label_19->setFont(font1);
        label_19->setAlignment(Qt::AlignCenter);

        verticalLayout_13->addWidget(label_19);

        lblCapacidad = new QLabel(tabEmbalses);
        lblCapacidad->setObjectName(QString::fromUtf8("lblCapacidad"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblCapacidad->sizePolicy().hasHeightForWidth());
        lblCapacidad->setSizePolicy(sizePolicy2);
        lblCapacidad->setFont(font2);
        lblCapacidad->setStyleSheet(QString::fromUtf8("background-color: white; border: 1px solid black;"));
        lblCapacidad->setAlignment(Qt::AlignCenter);

        verticalLayout_13->addWidget(lblCapacidad);


        horizontalLayout_2->addLayout(verticalLayout_13);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_12->setContentsMargins(5, 5, 5, 5);
        label_21 = new QLabel(tabEmbalses);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        sizePolicy.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy);
        label_21->setFont(font1);
        label_21->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label_21);

        lblVolumen = new QLabel(tabEmbalses);
        lblVolumen->setObjectName(QString::fromUtf8("lblVolumen"));
        sizePolicy2.setHeightForWidth(lblVolumen->sizePolicy().hasHeightForWidth());
        lblVolumen->setSizePolicy(sizePolicy2);
        lblVolumen->setFont(font2);
        lblVolumen->setStyleSheet(QString::fromUtf8("background-color: white; border: 1px solid black;"));
        lblVolumen->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(lblVolumen);

        label_23 = new QLabel(tabEmbalses);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        sizePolicy.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy);
        label_23->setFont(font1);
        label_23->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label_23);

        lblPercent = new QLabel(tabEmbalses);
        lblPercent->setObjectName(QString::fromUtf8("lblPercent"));
        sizePolicy2.setHeightForWidth(lblPercent->sizePolicy().hasHeightForWidth());
        lblPercent->setSizePolicy(sizePolicy2);
        lblPercent->setFont(font2);
        lblPercent->setStyleSheet(QString::fromUtf8("background-color: white; border: 1px solid black;"));
        lblPercent->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(lblPercent);


        horizontalLayout_2->addLayout(verticalLayout_12);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_11->setContentsMargins(5, 5, 5, 5);
        btnVerGrafico = new QPushButton(tabEmbalses);
        btnVerGrafico->setObjectName(QString::fromUtf8("btnVerGrafico"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnVerGrafico->sizePolicy().hasHeightForWidth());
        btnVerGrafico->setSizePolicy(sizePolicy3);
        btnVerGrafico->setLayoutDirection(Qt::LeftToRight);
        btnVerGrafico->setIcon(icon);

        verticalLayout_11->addWidget(btnVerGrafico);

        btnExportarCSV = new QPushButton(tabEmbalses);
        btnExportarCSV->setObjectName(QString::fromUtf8("btnExportarCSV"));
        sizePolicy3.setHeightForWidth(btnExportarCSV->sizePolicy().hasHeightForWidth());
        btnExportarCSV->setSizePolicy(sizePolicy3);
        QIcon icon1;
        iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        btnExportarCSV->setIcon(icon1);

        verticalLayout_11->addWidget(btnExportarCSV);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_11);


        verticalLayout_18->addLayout(horizontalLayout_2);

        tabWidget->addTab(tabEmbalses, QString());
        tabPluviometria = new QWidget();
        tabPluviometria->setObjectName(QString::fromUtf8("tabPluviometria"));
        verticalLayout_19 = new QVBoxLayout(tabPluviometria);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(5, 5, 5, 5);
        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        verticalLayout_20->setContentsMargins(5, 5, 5, 5);
        label_2 = new QLabel(tabPluviometria);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        verticalLayout_20->addWidget(label_2);

        cmbPlvZona = new QComboBox(tabPluviometria);
        cmbPlvZona->setObjectName(QString::fromUtf8("cmbPlvZona"));
        sizePolicy1.setHeightForWidth(cmbPlvZona->sizePolicy().hasHeightForWidth());
        cmbPlvZona->setSizePolicy(sizePolicy1);

        verticalLayout_20->addWidget(cmbPlvZona);


        horizontalLayout_8->addLayout(verticalLayout_20);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setObjectName(QString::fromUtf8("verticalLayout_21"));
        verticalLayout_21->setContentsMargins(5, 5, 5, 5);
        label_14 = new QLabel(tabPluviometria);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy);

        verticalLayout_21->addWidget(label_14);

        cmbPuntoControl = new QComboBox(tabPluviometria);
        cmbPuntoControl->setObjectName(QString::fromUtf8("cmbPuntoControl"));
        sizePolicy1.setHeightForWidth(cmbPuntoControl->sizePolicy().hasHeightForWidth());
        cmbPuntoControl->setSizePolicy(sizePolicy1);

        verticalLayout_21->addWidget(cmbPuntoControl);


        horizontalLayout_8->addLayout(verticalLayout_21);


        verticalLayout_16->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(5, 5, 5, 5);
        tableView = new QTableView(tabPluviometria);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout_9->addWidget(tableView);


        verticalLayout_16->addLayout(horizontalLayout_9);


        verticalLayout_19->addLayout(verticalLayout_16);

        tabWidget->addTab(tabPluviometria, QString());

        verticalLayout_2->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1041, 32));
        menuConsulta = new QMenu(menubar);
        menuConsulta->setObjectName(QString::fromUtf8("menuConsulta"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuConsulta->menuAction());
        menuConsulta->addAction(actionPor_fecha);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Ver embalse", nullptr));
        actionDiaria->setText(QApplication::translate("MainWindow", "Diaria", nullptr));
        actionMes->setText(QApplication::translate("MainWindow", "Mensual", nullptr));
        actionPor_fecha->setText(QApplication::translate("MainWindow", "Por fecha", nullptr));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("MainWindow", "Zona", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Embalses", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Estad\303\255sticas por zona", nullptr));
        lblZona->setText(QApplication::translate("MainWindow", "--", nullptr));
#ifndef QT_NO_TOOLTIP
        btnVerEmbalses->setToolTip(QApplication::translate("MainWindow", "Ver embalses", nullptr));
#endif // QT_NO_TOOLTIP
        btnVerEmbalses->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Niveles (Hm3)", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Media", nullptr));
        lblNivelMedia->setText(QApplication::translate("MainWindow", "--", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "M\303\255nimo", nullptr));
        lblNivelMinimo->setText(QApplication::translate("MainWindow", "--", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "M\303\241ximo", nullptr));
        lblNivelMaximo->setText(QApplication::translate("MainWindow", "--", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Volumen (Hm3)", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Media", nullptr));
        lblVolumenMedia->setText(QApplication::translate("MainWindow", "--", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "M\303\255nimo", nullptr));
        lblVolumenMinimo->setText(QApplication::translate("MainWindow", "--", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "M\303\241ximo", nullptr));
        lblVolumenMaximo->setText(QApplication::translate("MainWindow", "--", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Total", nullptr));
        lblVolumenTotal->setText(QApplication::translate("MainWindow", "--", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Total capacidad", nullptr));
        lblTotalCapacidadZona->setText(QApplication::translate("MainWindow", "--", nullptr));
        label->setText(QApplication::translate("MainWindow", "Porcentaje %", nullptr));
        lblPorcentajeVolumenTotal->setText(QApplication::translate("MainWindow", "--", nullptr));
        lblNombreEmbalse->setText(QApplication::translate("MainWindow", "EMBALSE", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "Capacidad (Hm3)", nullptr));
        lblCapacidad->setText(QString());
        label_21->setText(QApplication::translate("MainWindow", "Volumen (Hm3)", nullptr));
        lblVolumen->setText(QString());
        label_23->setText(QApplication::translate("MainWindow", "Porcentaje %", nullptr));
        lblPercent->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnVerGrafico->setToolTip(QApplication::translate("MainWindow", "Ver gr\303\241fico", nullptr));
#endif // QT_NO_TOOLTIP
        btnVerGrafico->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnExportarCSV->setToolTip(QApplication::translate("MainWindow", "Exportar a CSV", nullptr));
#endif // QT_NO_TOOLTIP
        btnExportarCSV->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabEmbalses), QApplication::translate("MainWindow", "Embalses", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Zona", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Punto de control", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabPluviometria), QApplication::translate("MainWindow", "Pluviometr\303\255a", nullptr));
        menuConsulta->setTitle(QApplication::translate("MainWindow", "Consulta", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // VER_EMBALSESBEVHAK_H
