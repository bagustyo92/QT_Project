/********************************************************************************
** Form generated from reading UI file 'tapcard_window.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAPCARD_WINDOW_H
#define UI_TAPCARD_WINDOW_H

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

class Ui_TapCard_Window
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_logo;
    QSpacerItem *verticalSpacer_2;
    QFrame *line;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_action;
    QSpacerItem *verticalSpacer_4;
    QFrame *line_2;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *back_button;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TapCard_Window)
    {
        if (TapCard_Window->objectName().isEmpty())
            TapCard_Window->setObjectName(QStringLiteral("TapCard_Window"));
        TapCard_Window->resize(786, 488);
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
        TapCard_Window->setPalette(palette);
        centralwidget = new QWidget(TapCard_Window);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        label_logo = new QLabel(centralwidget);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        label_logo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_logo);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_2);

        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_3);

        label_action = new QLabel(centralwidget);
        label_action->setObjectName(QStringLiteral("label_action"));
        QFont font;
        font.setFamily(QStringLiteral("Monospace"));
        font.setPointSize(25);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        font.setKerning(false);
        label_action->setFont(font);
        label_action->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_action);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_4);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        back_button = new QPushButton(centralwidget);
        back_button->setObjectName(QStringLiteral("back_button"));
        QFont font1;
        font1.setPointSize(25);
        back_button->setFont(font1);

        horizontalLayout->addWidget(back_button);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_6);

        TapCard_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TapCard_Window);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 786, 26));
        TapCard_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(TapCard_Window);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TapCard_Window->setStatusBar(statusbar);

        retranslateUi(TapCard_Window);
        QObject::connect(back_button, SIGNAL(clicked()), TapCard_Window, SLOT(close()));

        QMetaObject::connectSlotsByName(TapCard_Window);
    } // setupUi

    void retranslateUi(QMainWindow *TapCard_Window)
    {
        TapCard_Window->setWindowTitle(QApplication::translate("TapCard_Window", "MainWindow", Q_NULLPTR));
        label_logo->setText(QApplication::translate("TapCard_Window", "Logo", Q_NULLPTR));
        label_action->setText(QApplication::translate("TapCard_Window", "SILAHKAN TAP KARTU ANDA!", Q_NULLPTR));
        back_button->setText(QApplication::translate("TapCard_Window", "<   KEMBALI", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TapCard_Window: public Ui_TapCard_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAPCARD_WINDOW_H
