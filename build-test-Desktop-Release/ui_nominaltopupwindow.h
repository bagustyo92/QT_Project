/********************************************************************************
** Form generated from reading UI file 'nominaltopupwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOMINALTOPUPWINDOW_H
#define UI_NOMINALTOPUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NominalTopUpWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_logo;
    QSpacerItem *verticalSpacer_4;
    QFrame *line;
    QSpacerItem *verticalSpacer_7;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_20rb;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_50rb;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_100rb;
    QSpacerItem *horizontalSpacer_19;
    QPushButton *pushButton_150rb;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_200rb;
    QSpacerItem *horizontalSpacer_20;
    QPushButton *pushButton_300rb;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *pushButton_500rb;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QFrame *line_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_keluar;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *NominalTopUpWindow)
    {
        if (NominalTopUpWindow->objectName().isEmpty())
            NominalTopUpWindow->setObjectName(QStringLiteral("NominalTopUpWindow"));
        NominalTopUpWindow->resize(802, 860);
        QPalette palette;
        QBrush brush(QColor(238, 238, 236, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(108, 167, 191, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush3(QColor(190, 190, 190, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        NominalTopUpWindow->setPalette(palette);
        centralwidget = new QWidget(NominalTopUpWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_3);

        label_logo = new QLabel(centralwidget);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_logo->sizePolicy().hasHeightForWidth());
        label_logo->setSizePolicy(sizePolicy);
        label_logo->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_logo);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_4);

        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_7);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(25);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_20rb = new QPushButton(centralwidget);
        pushButton_20rb->setObjectName(QStringLiteral("pushButton_20rb"));
        pushButton_20rb->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_20rb->sizePolicy().hasHeightForWidth());
        pushButton_20rb->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(25);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_20rb->setFont(font1);

        horizontalLayout->addWidget(pushButton_20rb);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_50rb = new QPushButton(centralwidget);
        pushButton_50rb->setObjectName(QStringLiteral("pushButton_50rb"));
        sizePolicy1.setHeightForWidth(pushButton_50rb->sizePolicy().hasHeightForWidth());
        pushButton_50rb->setSizePolicy(sizePolicy1);
        pushButton_50rb->setFont(font1);

        horizontalLayout->addWidget(pushButton_50rb);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_100rb = new QPushButton(centralwidget);
        pushButton_100rb->setObjectName(QStringLiteral("pushButton_100rb"));
        sizePolicy1.setHeightForWidth(pushButton_100rb->sizePolicy().hasHeightForWidth());
        pushButton_100rb->setSizePolicy(sizePolicy1);
        pushButton_100rb->setFont(font1);

        horizontalLayout_5->addWidget(pushButton_100rb);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_19);

        pushButton_150rb = new QPushButton(centralwidget);
        pushButton_150rb->setObjectName(QStringLiteral("pushButton_150rb"));
        sizePolicy1.setHeightForWidth(pushButton_150rb->sizePolicy().hasHeightForWidth());
        pushButton_150rb->setSizePolicy(sizePolicy1);
        pushButton_150rb->setFont(font1);

        horizontalLayout_5->addWidget(pushButton_150rb);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButton_200rb = new QPushButton(centralwidget);
        pushButton_200rb->setObjectName(QStringLiteral("pushButton_200rb"));
        sizePolicy1.setHeightForWidth(pushButton_200rb->sizePolicy().hasHeightForWidth());
        pushButton_200rb->setSizePolicy(sizePolicy1);
        pushButton_200rb->setFont(font1);

        horizontalLayout_6->addWidget(pushButton_200rb);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_20);

        pushButton_300rb = new QPushButton(centralwidget);
        pushButton_300rb->setObjectName(QStringLiteral("pushButton_300rb"));
        sizePolicy1.setHeightForWidth(pushButton_300rb->sizePolicy().hasHeightForWidth());
        pushButton_300rb->setSizePolicy(sizePolicy1);
        pushButton_300rb->setFont(font1);

        horizontalLayout_6->addWidget(pushButton_300rb);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_13);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_15);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_17);

        pushButton_500rb = new QPushButton(centralwidget);
        pushButton_500rb->setObjectName(QStringLiteral("pushButton_500rb"));
        sizePolicy1.setHeightForWidth(pushButton_500rb->sizePolicy().hasHeightForWidth());
        pushButton_500rb->setSizePolicy(sizePolicy1);
        pushButton_500rb->setFont(font1);

        horizontalLayout_4->addWidget(pushButton_500rb);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_18);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_16);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_14);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_12);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_5);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);

        pushButton_keluar = new QPushButton(centralwidget);
        pushButton_keluar->setObjectName(QStringLiteral("pushButton_keluar"));
        pushButton_keluar->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_keluar);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_2);

        NominalTopUpWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NominalTopUpWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 802, 26));
        NominalTopUpWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(NominalTopUpWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        NominalTopUpWindow->setStatusBar(statusbar);

        retranslateUi(NominalTopUpWindow);
        QObject::connect(pushButton_keluar, SIGNAL(clicked()), NominalTopUpWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(NominalTopUpWindow);
    } // setupUi

    void retranslateUi(QMainWindow *NominalTopUpWindow)
    {
        NominalTopUpWindow->setWindowTitle(QApplication::translate("NominalTopUpWindow", "MainWindow", Q_NULLPTR));
        label_logo->setText(QApplication::translate("NominalTopUpWindow", "TextLabel", Q_NULLPTR));
        label->setText(QApplication::translate("NominalTopUpWindow", "PILIH NOMINAL TOP-UP", Q_NULLPTR));
        pushButton_20rb->setText(QApplication::translate("NominalTopUpWindow", "Rp 20.000,-", Q_NULLPTR));
        pushButton_50rb->setText(QApplication::translate("NominalTopUpWindow", "Rp 50.000,-", Q_NULLPTR));
        pushButton_100rb->setText(QApplication::translate("NominalTopUpWindow", "Rp 100.000,-", Q_NULLPTR));
        pushButton_150rb->setText(QApplication::translate("NominalTopUpWindow", "Rp 150.000,-", Q_NULLPTR));
        pushButton_200rb->setText(QApplication::translate("NominalTopUpWindow", "Rp 200.000,-", Q_NULLPTR));
        pushButton_300rb->setText(QApplication::translate("NominalTopUpWindow", "Rp 300.000,-", Q_NULLPTR));
        pushButton_500rb->setText(QApplication::translate("NominalTopUpWindow", "Rp 500.000,-", Q_NULLPTR));
        pushButton_keluar->setText(QApplication::translate("NominalTopUpWindow", "<  KEMBALI/KELUAR", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NominalTopUpWindow: public Ui_NominalTopUpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOMINALTOPUPWINDOW_H
