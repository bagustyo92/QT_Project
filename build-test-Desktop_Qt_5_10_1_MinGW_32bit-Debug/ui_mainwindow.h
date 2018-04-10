/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_menuUtama;
    QVBoxLayout *verticalLayout;
    QFrame *line;
    QPushButton *pushButton_cuciSetrika;
    QPushButton *pushButton_cuciLipat;
    QPushButton *pushButton_cuciKering;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_ambilCucian;
    QPushButton *pushButton_controlMesin;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(472, 353);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_menuUtama = new QLabel(centralWidget);
        label_menuUtama->setObjectName(QStringLiteral("label_menuUtama"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_menuUtama->sizePolicy().hasHeightForWidth());
        label_menuUtama->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label_menuUtama->setFont(font);
        label_menuUtama->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_menuUtama);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        pushButton_cuciSetrika = new QPushButton(centralWidget);
        pushButton_cuciSetrika->setObjectName(QStringLiteral("pushButton_cuciSetrika"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_cuciSetrika->sizePolicy().hasHeightForWidth());
        pushButton_cuciSetrika->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_cuciSetrika);

        pushButton_cuciLipat = new QPushButton(centralWidget);
        pushButton_cuciLipat->setObjectName(QStringLiteral("pushButton_cuciLipat"));
        sizePolicy1.setHeightForWidth(pushButton_cuciLipat->sizePolicy().hasHeightForWidth());
        pushButton_cuciLipat->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_cuciLipat);

        pushButton_cuciKering = new QPushButton(centralWidget);
        pushButton_cuciKering->setObjectName(QStringLiteral("pushButton_cuciKering"));
        sizePolicy1.setHeightForWidth(pushButton_cuciKering->sizePolicy().hasHeightForWidth());
        pushButton_cuciKering->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_cuciKering);


        verticalLayout_2->addLayout(verticalLayout);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        line_2->setFont(font1);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        pushButton_ambilCucian = new QPushButton(centralWidget);
        pushButton_ambilCucian->setObjectName(QStringLiteral("pushButton_ambilCucian"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_ambilCucian->sizePolicy().hasHeightForWidth());
        pushButton_ambilCucian->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(pushButton_ambilCucian);

        pushButton_controlMesin = new QPushButton(centralWidget);
        pushButton_controlMesin->setObjectName(QStringLiteral("pushButton_controlMesin"));
        sizePolicy1.setHeightForWidth(pushButton_controlMesin->sizePolicy().hasHeightForWidth());
        pushButton_controlMesin->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_controlMesin);


        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 472, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_menuUtama->setText(QApplication::translate("MainWindow", "MENU UTAMA", nullptr));
        pushButton_cuciSetrika->setText(QApplication::translate("MainWindow", "CUCI SETRIKA", nullptr));
        pushButton_cuciLipat->setText(QApplication::translate("MainWindow", "CUCI LIPAT", nullptr));
        pushButton_cuciKering->setText(QApplication::translate("MainWindow", "CUCI KERING", nullptr));
        pushButton_ambilCucian->setText(QApplication::translate("MainWindow", "AMBIL CUCIAN", nullptr));
        pushButton_controlMesin->setText(QApplication::translate("MainWindow", "CONTROL MESIN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
