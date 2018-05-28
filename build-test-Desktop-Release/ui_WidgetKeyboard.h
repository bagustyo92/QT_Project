/********************************************************************************
** Form generated from reading UI file 'WidgetKeyboard.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETKEYBOARD_H
#define UI_WIDGETKEYBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetKeyboard
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_9;
    QToolButton *btnEsc;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *btnF1;
    QToolButton *btnF2;
    QToolButton *btnF3;
    QToolButton *btnF4;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *btnF5;
    QToolButton *btnF6;
    QToolButton *btnF7;
    QToolButton *btnF8;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_8;
    QToolButton *btnF9;
    QToolButton *btnF10;
    QToolButton *btnF11;
    QToolButton *btnF12;
    QHBoxLayout *horizontalLayout_10;
    QToolButton *btnPrint;
    QToolButton *btnHome_2;
    QToolButton *btnPgU_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QToolButton *btnIns;
    QToolButton *btnHome;
    QToolButton *btnPgU;
    QToolButton *btnDel;
    QToolButton *btnEnd;
    QToolButton *btnPgD;
    QCheckBox *checkBoxShowNumPad;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_2;
    QToolButton *btnArrowU;
    QToolButton *btnArrowL;
    QToolButton *btnArrowD;
    QToolButton *btnArrowR;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QToolButton *btnTilt;
    QToolButton *btn1;
    QToolButton *btn2;
    QToolButton *btn3;
    QToolButton *btn4;
    QToolButton *btn5;
    QToolButton *btn6;
    QToolButton *btn7;
    QToolButton *btn8;
    QToolButton *btn9;
    QToolButton *btn0;
    QToolButton *btnHiphen;
    QToolButton *btnAssign;
    QToolButton *btnBackSpace;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *btnCaps;
    QToolButton *btnA;
    QToolButton *btnS;
    QToolButton *btnD;
    QToolButton *btnF;
    QToolButton *btnG;
    QToolButton *btnH;
    QToolButton *btnJ;
    QToolButton *btnK;
    QToolButton *btnL;
    QToolButton *btnSemiColon;
    QToolButton *btnSp;
    QToolButton *btnReturn;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *btnShiftLeft;
    QToolButton *btnZ;
    QToolButton *btnX;
    QToolButton *btnC;
    QToolButton *btnV;
    QToolButton *btnB;
    QToolButton *btnN;
    QToolButton *btnM;
    QToolButton *btnComma;
    QToolButton *btnPeriod;
    QToolButton *btnBcwdSlash;
    QToolButton *btnShiftRight;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *btnCtrlLeft;
    QToolButton *btnAltLeft;
    QToolButton *btnSpace;
    QSlider *sliderOpacity;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *btnTab;
    QToolButton *btnQ;
    QToolButton *btnW;
    QToolButton *btnE;
    QToolButton *btnR;
    QToolButton *btnT;
    QToolButton *btnY;
    QToolButton *btnU;
    QToolButton *btnI;
    QToolButton *btnO;
    QToolButton *btnP;
    QToolButton *btnStartSquare;
    QToolButton *btnCloseSquare;
    QToolButton *btnFwdSlash;
    QFrame *frameNumPad;
    QGridLayout *layoutNumPad;
    QToolButton *btnDivide;
    QToolButton *btnMultiply;
    QToolButton *btnSubtraction;
    QToolButton *btnNum7;
    QToolButton *btnNum8;
    QToolButton *btnNum9;
    QToolButton *btnNum4;
    QToolButton *btnNum5;
    QToolButton *btnNum6;
    QToolButton *btnSum;
    QToolButton *btnNum1;
    QToolButton *btnNum2;
    QToolButton *btnNum3;
    QToolButton *btnNum0;
    QToolButton *btnNumDot;
    QToolButton *btnEnter;
    QToolButton *btnNumLock;

    void setupUi(QWidget *WidgetKeyboard)
    {
        if (WidgetKeyboard->objectName().isEmpty())
            WidgetKeyboard->setObjectName(QStringLiteral("WidgetKeyboard"));
        WidgetKeyboard->resize(780, 185);
        verticalLayout_2 = new QVBoxLayout(WidgetKeyboard);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(2);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        btnEsc = new QToolButton(WidgetKeyboard);
        btnEsc->setObjectName(QStringLiteral("btnEsc"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnEsc->sizePolicy().hasHeightForWidth());
        btnEsc->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(8);
        btnEsc->setFont(font);
        btnEsc->setAutoRepeat(true);

        horizontalLayout_9->addWidget(btnEsc);

        horizontalSpacer = new QSpacerItem(50, 22, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(2);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        btnF1 = new QToolButton(WidgetKeyboard);
        btnF1->setObjectName(QStringLiteral("btnF1"));
        sizePolicy.setHeightForWidth(btnF1->sizePolicy().hasHeightForWidth());
        btnF1->setSizePolicy(sizePolicy);
        btnF1->setFont(font);
        btnF1->setAutoRepeat(true);

        horizontalLayout_6->addWidget(btnF1);

        btnF2 = new QToolButton(WidgetKeyboard);
        btnF2->setObjectName(QStringLiteral("btnF2"));
        sizePolicy.setHeightForWidth(btnF2->sizePolicy().hasHeightForWidth());
        btnF2->setSizePolicy(sizePolicy);
        btnF2->setFont(font);
        btnF2->setAutoRepeat(true);

        horizontalLayout_6->addWidget(btnF2);

        btnF3 = new QToolButton(WidgetKeyboard);
        btnF3->setObjectName(QStringLiteral("btnF3"));
        sizePolicy.setHeightForWidth(btnF3->sizePolicy().hasHeightForWidth());
        btnF3->setSizePolicy(sizePolicy);
        btnF3->setFont(font);
        btnF3->setAutoRepeat(true);

        horizontalLayout_6->addWidget(btnF3);

        btnF4 = new QToolButton(WidgetKeyboard);
        btnF4->setObjectName(QStringLiteral("btnF4"));
        sizePolicy.setHeightForWidth(btnF4->sizePolicy().hasHeightForWidth());
        btnF4->setSizePolicy(sizePolicy);
        btnF4->setFont(font);
        btnF4->setAutoRepeat(true);

        horizontalLayout_6->addWidget(btnF4);


        horizontalLayout_9->addLayout(horizontalLayout_6);

        horizontalSpacer_2 = new QSpacerItem(50, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(2);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        btnF5 = new QToolButton(WidgetKeyboard);
        btnF5->setObjectName(QStringLiteral("btnF5"));
        sizePolicy.setHeightForWidth(btnF5->sizePolicy().hasHeightForWidth());
        btnF5->setSizePolicy(sizePolicy);
        btnF5->setFont(font);
        btnF5->setAutoRepeat(true);

        horizontalLayout_7->addWidget(btnF5);

        btnF6 = new QToolButton(WidgetKeyboard);
        btnF6->setObjectName(QStringLiteral("btnF6"));
        sizePolicy.setHeightForWidth(btnF6->sizePolicy().hasHeightForWidth());
        btnF6->setSizePolicy(sizePolicy);
        btnF6->setFont(font);
        btnF6->setAutoRepeat(true);

        horizontalLayout_7->addWidget(btnF6);

        btnF7 = new QToolButton(WidgetKeyboard);
        btnF7->setObjectName(QStringLiteral("btnF7"));
        sizePolicy.setHeightForWidth(btnF7->sizePolicy().hasHeightForWidth());
        btnF7->setSizePolicy(sizePolicy);
        btnF7->setFont(font);
#ifndef QT_NO_ACCESSIBILITY
        btnF7->setAccessibleName(QStringLiteral("0x01000036"));
#endif // QT_NO_ACCESSIBILITY
        btnF7->setAutoRepeat(true);

        horizontalLayout_7->addWidget(btnF7);

        btnF8 = new QToolButton(WidgetKeyboard);
        btnF8->setObjectName(QStringLiteral("btnF8"));
        sizePolicy.setHeightForWidth(btnF8->sizePolicy().hasHeightForWidth());
        btnF8->setSizePolicy(sizePolicy);
        btnF8->setFont(font);
        btnF8->setAutoRepeat(true);

        horizontalLayout_7->addWidget(btnF8);


        horizontalLayout_9->addLayout(horizontalLayout_7);

        horizontalSpacer_3 = new QSpacerItem(50, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(2);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        btnF9 = new QToolButton(WidgetKeyboard);
        btnF9->setObjectName(QStringLiteral("btnF9"));
        sizePolicy.setHeightForWidth(btnF9->sizePolicy().hasHeightForWidth());
        btnF9->setSizePolicy(sizePolicy);
        btnF9->setFont(font);
        btnF9->setAutoRepeat(true);

        horizontalLayout_8->addWidget(btnF9);

        btnF10 = new QToolButton(WidgetKeyboard);
        btnF10->setObjectName(QStringLiteral("btnF10"));
        sizePolicy.setHeightForWidth(btnF10->sizePolicy().hasHeightForWidth());
        btnF10->setSizePolicy(sizePolicy);
        btnF10->setFont(font);
        btnF10->setAutoRepeat(true);

        horizontalLayout_8->addWidget(btnF10);

        btnF11 = new QToolButton(WidgetKeyboard);
        btnF11->setObjectName(QStringLiteral("btnF11"));
        sizePolicy.setHeightForWidth(btnF11->sizePolicy().hasHeightForWidth());
        btnF11->setSizePolicy(sizePolicy);
        btnF11->setFont(font);
        btnF11->setAutoRepeat(true);

        horizontalLayout_8->addWidget(btnF11);

        btnF12 = new QToolButton(WidgetKeyboard);
        btnF12->setObjectName(QStringLiteral("btnF12"));
        sizePolicy.setHeightForWidth(btnF12->sizePolicy().hasHeightForWidth());
        btnF12->setSizePolicy(sizePolicy);
        btnF12->setFont(font);
        btnF12->setAutoRepeat(true);

        horizontalLayout_8->addWidget(btnF12);


        horizontalLayout_9->addLayout(horizontalLayout_8);


        gridLayout_5->addLayout(horizontalLayout_9, 0, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(3);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        btnPrint = new QToolButton(WidgetKeyboard);
        btnPrint->setObjectName(QStringLiteral("btnPrint"));
        btnPrint->setEnabled(true);
        sizePolicy.setHeightForWidth(btnPrint->sizePolicy().hasHeightForWidth());
        btnPrint->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(6);
        btnPrint->setFont(font1);
        btnPrint->setAutoRepeat(true);

        horizontalLayout_10->addWidget(btnPrint);

        btnHome_2 = new QToolButton(WidgetKeyboard);
        btnHome_2->setObjectName(QStringLiteral("btnHome_2"));
        btnHome_2->setEnabled(false);
        sizePolicy.setHeightForWidth(btnHome_2->sizePolicy().hasHeightForWidth());
        btnHome_2->setSizePolicy(sizePolicy);
        btnHome_2->setFont(font1);
        btnHome_2->setAutoRepeat(true);

        horizontalLayout_10->addWidget(btnHome_2);

        btnPgU_2 = new QToolButton(WidgetKeyboard);
        btnPgU_2->setObjectName(QStringLiteral("btnPgU_2"));
        btnPgU_2->setEnabled(false);
        sizePolicy.setHeightForWidth(btnPgU_2->sizePolicy().hasHeightForWidth());
        btnPgU_2->setSizePolicy(sizePolicy);
        btnPgU_2->setFont(font1);
        btnPgU_2->setAutoRepeat(true);

        horizontalLayout_10->addWidget(btnPgU_2);


        gridLayout_5->addLayout(horizontalLayout_10, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(3);
        gridLayout->setVerticalSpacing(0);
        btnIns = new QToolButton(WidgetKeyboard);
        btnIns->setObjectName(QStringLiteral("btnIns"));
        sizePolicy.setHeightForWidth(btnIns->sizePolicy().hasHeightForWidth());
        btnIns->setSizePolicy(sizePolicy);
        btnIns->setFont(font1);
        btnIns->setCheckable(false);
        btnIns->setAutoRepeat(true);

        gridLayout->addWidget(btnIns, 0, 0, 1, 1);

        btnHome = new QToolButton(WidgetKeyboard);
        btnHome->setObjectName(QStringLiteral("btnHome"));
        sizePolicy.setHeightForWidth(btnHome->sizePolicy().hasHeightForWidth());
        btnHome->setSizePolicy(sizePolicy);
        btnHome->setFont(font1);
        btnHome->setAutoRepeat(true);

        gridLayout->addWidget(btnHome, 0, 1, 1, 1);

        btnPgU = new QToolButton(WidgetKeyboard);
        btnPgU->setObjectName(QStringLiteral("btnPgU"));
        sizePolicy.setHeightForWidth(btnPgU->sizePolicy().hasHeightForWidth());
        btnPgU->setSizePolicy(sizePolicy);
        btnPgU->setFont(font1);
        btnPgU->setAutoRepeat(true);

        gridLayout->addWidget(btnPgU, 0, 2, 1, 1);

        btnDel = new QToolButton(WidgetKeyboard);
        btnDel->setObjectName(QStringLiteral("btnDel"));
        sizePolicy.setHeightForWidth(btnDel->sizePolicy().hasHeightForWidth());
        btnDel->setSizePolicy(sizePolicy);
        btnDel->setFont(font1);
        btnDel->setAutoRepeat(true);

        gridLayout->addWidget(btnDel, 1, 0, 1, 1);

        btnEnd = new QToolButton(WidgetKeyboard);
        btnEnd->setObjectName(QStringLiteral("btnEnd"));
        sizePolicy.setHeightForWidth(btnEnd->sizePolicy().hasHeightForWidth());
        btnEnd->setSizePolicy(sizePolicy);
        btnEnd->setFont(font1);
        btnEnd->setAutoRepeat(true);

        gridLayout->addWidget(btnEnd, 1, 1, 1, 1);

        btnPgD = new QToolButton(WidgetKeyboard);
        btnPgD->setObjectName(QStringLiteral("btnPgD"));
        sizePolicy.setHeightForWidth(btnPgD->sizePolicy().hasHeightForWidth());
        btnPgD->setSizePolicy(sizePolicy);
        btnPgD->setFont(font1);
        btnPgD->setAutoRepeat(true);

        gridLayout->addWidget(btnPgD, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        checkBoxShowNumPad = new QCheckBox(WidgetKeyboard);
        checkBoxShowNumPad->setObjectName(QStringLiteral("checkBoxShowNumPad"));
        checkBoxShowNumPad->setChecked(true);

        verticalLayout->addWidget(checkBoxShowNumPad);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btnArrowU = new QToolButton(WidgetKeyboard);
        btnArrowU->setObjectName(QStringLiteral("btnArrowU"));
        sizePolicy.setHeightForWidth(btnArrowU->sizePolicy().hasHeightForWidth());
        btnArrowU->setSizePolicy(sizePolicy);
        btnArrowU->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/myresources/upIcon"), QSize(), QIcon::Normal, QIcon::Off);
        btnArrowU->setIcon(icon);
        btnArrowU->setAutoRepeat(true);

        gridLayout_2->addWidget(btnArrowU, 0, 1, 1, 1);

        btnArrowL = new QToolButton(WidgetKeyboard);
        btnArrowL->setObjectName(QStringLiteral("btnArrowL"));
        sizePolicy.setHeightForWidth(btnArrowL->sizePolicy().hasHeightForWidth());
        btnArrowL->setSizePolicy(sizePolicy);
        btnArrowL->setFont(font);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/myresources/leftIcon"), QSize(), QIcon::Normal, QIcon::Off);
        btnArrowL->setIcon(icon1);
        btnArrowL->setAutoRepeat(true);

        gridLayout_2->addWidget(btnArrowL, 1, 0, 1, 1);

        btnArrowD = new QToolButton(WidgetKeyboard);
        btnArrowD->setObjectName(QStringLiteral("btnArrowD"));
        sizePolicy.setHeightForWidth(btnArrowD->sizePolicy().hasHeightForWidth());
        btnArrowD->setSizePolicy(sizePolicy);
        btnArrowD->setFont(font);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/myresources/downIcon"), QSize(), QIcon::Normal, QIcon::Off);
        btnArrowD->setIcon(icon2);
        btnArrowD->setAutoRepeat(true);

        gridLayout_2->addWidget(btnArrowD, 1, 1, 1, 1);

        btnArrowR = new QToolButton(WidgetKeyboard);
        btnArrowR->setObjectName(QStringLiteral("btnArrowR"));
        sizePolicy.setHeightForWidth(btnArrowR->sizePolicy().hasHeightForWidth());
        btnArrowR->setSizePolicy(sizePolicy);
        btnArrowR->setFont(font);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/myresources/rightIcon"), QSize(), QIcon::Normal, QIcon::Off);
        btnArrowR->setIcon(icon3);
        btnArrowR->setAutoRepeat(true);

        gridLayout_2->addWidget(btnArrowR, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        gridLayout_5->addLayout(verticalLayout, 1, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnTilt = new QToolButton(WidgetKeyboard);
        btnTilt->setObjectName(QStringLiteral("btnTilt"));
        sizePolicy.setHeightForWidth(btnTilt->sizePolicy().hasHeightForWidth());
        btnTilt->setSizePolicy(sizePolicy);
        btnTilt->setFont(font);
        btnTilt->setAutoRepeat(true);

        horizontalLayout->addWidget(btnTilt);

        btn1 = new QToolButton(WidgetKeyboard);
        btn1->setObjectName(QStringLiteral("btn1"));
        sizePolicy.setHeightForWidth(btn1->sizePolicy().hasHeightForWidth());
        btn1->setSizePolicy(sizePolicy);
        btn1->setFont(font);
        btn1->setAutoRepeat(true);

        horizontalLayout->addWidget(btn1);

        btn2 = new QToolButton(WidgetKeyboard);
        btn2->setObjectName(QStringLiteral("btn2"));
        sizePolicy.setHeightForWidth(btn2->sizePolicy().hasHeightForWidth());
        btn2->setSizePolicy(sizePolicy);
        btn2->setFont(font);
        btn2->setAutoRepeat(true);

        horizontalLayout->addWidget(btn2);

        btn3 = new QToolButton(WidgetKeyboard);
        btn3->setObjectName(QStringLiteral("btn3"));
        sizePolicy.setHeightForWidth(btn3->sizePolicy().hasHeightForWidth());
        btn3->setSizePolicy(sizePolicy);
        btn3->setFont(font);
        btn3->setAutoRepeat(true);

        horizontalLayout->addWidget(btn3);

        btn4 = new QToolButton(WidgetKeyboard);
        btn4->setObjectName(QStringLiteral("btn4"));
        sizePolicy.setHeightForWidth(btn4->sizePolicy().hasHeightForWidth());
        btn4->setSizePolicy(sizePolicy);
        btn4->setFont(font);
        btn4->setAutoRepeat(true);

        horizontalLayout->addWidget(btn4);

        btn5 = new QToolButton(WidgetKeyboard);
        btn5->setObjectName(QStringLiteral("btn5"));
        sizePolicy.setHeightForWidth(btn5->sizePolicy().hasHeightForWidth());
        btn5->setSizePolicy(sizePolicy);
        btn5->setFont(font);
        btn5->setAutoRepeat(true);

        horizontalLayout->addWidget(btn5);

        btn6 = new QToolButton(WidgetKeyboard);
        btn6->setObjectName(QStringLiteral("btn6"));
        sizePolicy.setHeightForWidth(btn6->sizePolicy().hasHeightForWidth());
        btn6->setSizePolicy(sizePolicy);
        btn6->setFont(font);
        btn6->setAutoRepeat(true);

        horizontalLayout->addWidget(btn6);

        btn7 = new QToolButton(WidgetKeyboard);
        btn7->setObjectName(QStringLiteral("btn7"));
        sizePolicy.setHeightForWidth(btn7->sizePolicy().hasHeightForWidth());
        btn7->setSizePolicy(sizePolicy);
        btn7->setFont(font);
        btn7->setAutoRepeat(true);

        horizontalLayout->addWidget(btn7);

        btn8 = new QToolButton(WidgetKeyboard);
        btn8->setObjectName(QStringLiteral("btn8"));
        sizePolicy.setHeightForWidth(btn8->sizePolicy().hasHeightForWidth());
        btn8->setSizePolicy(sizePolicy);
        btn8->setFont(font);
        btn8->setAutoRepeat(true);

        horizontalLayout->addWidget(btn8);

        btn9 = new QToolButton(WidgetKeyboard);
        btn9->setObjectName(QStringLiteral("btn9"));
        sizePolicy.setHeightForWidth(btn9->sizePolicy().hasHeightForWidth());
        btn9->setSizePolicy(sizePolicy);
        btn9->setFont(font);
        btn9->setAutoRepeat(true);

        horizontalLayout->addWidget(btn9);

        btn0 = new QToolButton(WidgetKeyboard);
        btn0->setObjectName(QStringLiteral("btn0"));
        sizePolicy.setHeightForWidth(btn0->sizePolicy().hasHeightForWidth());
        btn0->setSizePolicy(sizePolicy);
        btn0->setFont(font);
        btn0->setAutoRepeat(true);

        horizontalLayout->addWidget(btn0);

        btnHiphen = new QToolButton(WidgetKeyboard);
        btnHiphen->setObjectName(QStringLiteral("btnHiphen"));
        sizePolicy.setHeightForWidth(btnHiphen->sizePolicy().hasHeightForWidth());
        btnHiphen->setSizePolicy(sizePolicy);
        btnHiphen->setFont(font);
        btnHiphen->setAutoRepeat(true);

        horizontalLayout->addWidget(btnHiphen);

        btnAssign = new QToolButton(WidgetKeyboard);
        btnAssign->setObjectName(QStringLiteral("btnAssign"));
        sizePolicy.setHeightForWidth(btnAssign->sizePolicy().hasHeightForWidth());
        btnAssign->setSizePolicy(sizePolicy);
        btnAssign->setFont(font);
        btnAssign->setAutoRepeat(true);

        horizontalLayout->addWidget(btnAssign);

        btnBackSpace = new QToolButton(WidgetKeyboard);
        btnBackSpace->setObjectName(QStringLiteral("btnBackSpace"));
        sizePolicy.setHeightForWidth(btnBackSpace->sizePolicy().hasHeightForWidth());
        btnBackSpace->setSizePolicy(sizePolicy);
        btnBackSpace->setFont(font);
        btnBackSpace->setAutoRepeat(true);

        horizontalLayout->addWidget(btnBackSpace);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btnCaps = new QToolButton(WidgetKeyboard);
        btnCaps->setObjectName(QStringLiteral("btnCaps"));
        sizePolicy.setHeightForWidth(btnCaps->sizePolicy().hasHeightForWidth());
        btnCaps->setSizePolicy(sizePolicy);
        btnCaps->setFont(font);
        btnCaps->setCheckable(true);
        btnCaps->setAutoRepeat(true);

        horizontalLayout_3->addWidget(btnCaps);

        btnA = new QToolButton(WidgetKeyboard);
        btnA->setObjectName(QStringLiteral("btnA"));
        sizePolicy.setHeightForWidth(btnA->sizePolicy().hasHeightForWidth());
        btnA->setSizePolicy(sizePolicy);
        btnA->setFont(font);
        btnA->setAutoRepeat(true);

        horizontalLayout_3->addWidget(btnA);

        btnS = new QToolButton(WidgetKeyboard);
        btnS->setObjectName(QStringLiteral("btnS"));
        sizePolicy.setHeightForWidth(btnS->sizePolicy().hasHeightForWidth());
        btnS->setSizePolicy(sizePolicy);
        btnS->setFont(font);
        btnS->setAutoRepeat(true);

        horizontalLayout_3->addWidget(btnS);

        btnD = new QToolButton(WidgetKeyboard);
        btnD->setObjectName(QStringLiteral("btnD"));
        sizePolicy.setHeightForWidth(btnD->sizePolicy().hasHeightForWidth());
        btnD->setSizePolicy(sizePolicy);
        btnD->setFont(font);
        btnD->setAutoRepeat(true);

        horizontalLayout_3->addWidget(btnD);

        btnF = new QToolButton(WidgetKeyboard);
        btnF->setObjectName(QStringLiteral("btnF"));
        sizePolicy.setHeightForWidth(btnF->sizePolicy().hasHeightForWidth());
        btnF->setSizePolicy(sizePolicy);
        btnF->setFont(font);
        btnF->setAutoRepeat(true);

        horizontalLayout_3->addWidget(btnF);

        btnG = new QToolButton(WidgetKeyboard);
        btnG->setObjectName(QStringLiteral("btnG"));
        sizePolicy.setHeightForWidth(btnG->sizePolicy().hasHeightForWidth());
        btnG->setSizePolicy(sizePolicy);
        btnG->setFont(font);
        btnG->setAutoRepeat(true);

        horizontalLayout_3->addWidget(btnG);

        btnH = new QToolButton(WidgetKeyboard);
        btnH->setObjectName(QStringLiteral("btnH"));
        sizePolicy.setHeightForWidth(btnH->sizePolicy().hasHeightForWidth());
        btnH->setSizePolicy(sizePolicy);
        btnH->setFont(font);
        btnH->setAutoRepeat(true);

        horizontalLayout_3->addWidget(btnH);

        btnJ = new QToolButton(WidgetKeyboard);
        btnJ->setObjectName(QStringLiteral("btnJ"));
        sizePolicy.setHeightForWidth(btnJ->sizePolicy().hasHeightForWidth());
        btnJ->setSizePolicy(sizePolicy);
        btnJ->setFont(font);
        btnJ->setAutoRepeat(true);

        horizontalLayout_3->addWidget(btnJ);

        btnK = new QToolButton(WidgetKeyboard);
        btnK->setObjectName(QStringLiteral("btnK"));
        sizePolicy.setHeightForWidth(btnK->sizePolicy().hasHeightForWidth());
        btnK->setSizePolicy(sizePolicy);
        btnK->setFont(font);
        btnK->setAutoRepeat(true);

        horizontalLayout_3->addWidget(btnK);

        btnL = new QToolButton(WidgetKeyboard);
        btnL->setObjectName(QStringLiteral("btnL"));
        sizePolicy.setHeightForWidth(btnL->sizePolicy().hasHeightForWidth());
        btnL->setSizePolicy(sizePolicy);
        btnL->setFont(font);
        btnL->setAutoRepeat(true);

        horizontalLayout_3->addWidget(btnL);

        btnSemiColon = new QToolButton(WidgetKeyboard);
        btnSemiColon->setObjectName(QStringLiteral("btnSemiColon"));
        sizePolicy.setHeightForWidth(btnSemiColon->sizePolicy().hasHeightForWidth());
        btnSemiColon->setSizePolicy(sizePolicy);
        btnSemiColon->setFont(font);
        btnSemiColon->setAutoRepeat(true);

        horizontalLayout_3->addWidget(btnSemiColon);

        btnSp = new QToolButton(WidgetKeyboard);
        btnSp->setObjectName(QStringLiteral("btnSp"));
        sizePolicy.setHeightForWidth(btnSp->sizePolicy().hasHeightForWidth());
        btnSp->setSizePolicy(sizePolicy);
        btnSp->setFont(font);
        btnSp->setAutoRepeat(true);

        horizontalLayout_3->addWidget(btnSp);

        btnReturn = new QToolButton(WidgetKeyboard);
        btnReturn->setObjectName(QStringLiteral("btnReturn"));
        sizePolicy.setHeightForWidth(btnReturn->sizePolicy().hasHeightForWidth());
        btnReturn->setSizePolicy(sizePolicy);
        btnReturn->setFont(font);
        btnReturn->setAutoRepeat(true);

        horizontalLayout_3->addWidget(btnReturn);


        gridLayout_3->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btnShiftLeft = new QToolButton(WidgetKeyboard);
        btnShiftLeft->setObjectName(QStringLiteral("btnShiftLeft"));
        sizePolicy.setHeightForWidth(btnShiftLeft->sizePolicy().hasHeightForWidth());
        btnShiftLeft->setSizePolicy(sizePolicy);
        btnShiftLeft->setFont(font);
        btnShiftLeft->setCheckable(true);
        btnShiftLeft->setAutoRepeat(true);

        horizontalLayout_4->addWidget(btnShiftLeft);

        btnZ = new QToolButton(WidgetKeyboard);
        btnZ->setObjectName(QStringLiteral("btnZ"));
        sizePolicy.setHeightForWidth(btnZ->sizePolicy().hasHeightForWidth());
        btnZ->setSizePolicy(sizePolicy);
        btnZ->setFont(font);
        btnZ->setAutoRepeat(true);

        horizontalLayout_4->addWidget(btnZ);

        btnX = new QToolButton(WidgetKeyboard);
        btnX->setObjectName(QStringLiteral("btnX"));
        sizePolicy.setHeightForWidth(btnX->sizePolicy().hasHeightForWidth());
        btnX->setSizePolicy(sizePolicy);
        btnX->setFont(font);
        btnX->setAutoRepeat(true);

        horizontalLayout_4->addWidget(btnX);

        btnC = new QToolButton(WidgetKeyboard);
        btnC->setObjectName(QStringLiteral("btnC"));
        sizePolicy.setHeightForWidth(btnC->sizePolicy().hasHeightForWidth());
        btnC->setSizePolicy(sizePolicy);
        btnC->setFont(font);
        btnC->setAutoRepeat(true);

        horizontalLayout_4->addWidget(btnC);

        btnV = new QToolButton(WidgetKeyboard);
        btnV->setObjectName(QStringLiteral("btnV"));
        sizePolicy.setHeightForWidth(btnV->sizePolicy().hasHeightForWidth());
        btnV->setSizePolicy(sizePolicy);
        btnV->setFont(font);
        btnV->setAutoRepeat(true);

        horizontalLayout_4->addWidget(btnV);

        btnB = new QToolButton(WidgetKeyboard);
        btnB->setObjectName(QStringLiteral("btnB"));
        sizePolicy.setHeightForWidth(btnB->sizePolicy().hasHeightForWidth());
        btnB->setSizePolicy(sizePolicy);
        btnB->setFont(font);
        btnB->setAutoRepeat(true);

        horizontalLayout_4->addWidget(btnB);

        btnN = new QToolButton(WidgetKeyboard);
        btnN->setObjectName(QStringLiteral("btnN"));
        sizePolicy.setHeightForWidth(btnN->sizePolicy().hasHeightForWidth());
        btnN->setSizePolicy(sizePolicy);
        btnN->setFont(font);
        btnN->setAutoRepeat(true);

        horizontalLayout_4->addWidget(btnN);

        btnM = new QToolButton(WidgetKeyboard);
        btnM->setObjectName(QStringLiteral("btnM"));
        sizePolicy.setHeightForWidth(btnM->sizePolicy().hasHeightForWidth());
        btnM->setSizePolicy(sizePolicy);
        btnM->setFont(font);
        btnM->setAutoRepeat(true);

        horizontalLayout_4->addWidget(btnM);

        btnComma = new QToolButton(WidgetKeyboard);
        btnComma->setObjectName(QStringLiteral("btnComma"));
        sizePolicy.setHeightForWidth(btnComma->sizePolicy().hasHeightForWidth());
        btnComma->setSizePolicy(sizePolicy);
        btnComma->setFont(font);
        btnComma->setAutoRepeat(true);

        horizontalLayout_4->addWidget(btnComma);

        btnPeriod = new QToolButton(WidgetKeyboard);
        btnPeriod->setObjectName(QStringLiteral("btnPeriod"));
        sizePolicy.setHeightForWidth(btnPeriod->sizePolicy().hasHeightForWidth());
        btnPeriod->setSizePolicy(sizePolicy);
        btnPeriod->setFont(font);
        btnPeriod->setAutoRepeat(true);

        horizontalLayout_4->addWidget(btnPeriod);

        btnBcwdSlash = new QToolButton(WidgetKeyboard);
        btnBcwdSlash->setObjectName(QStringLiteral("btnBcwdSlash"));
        sizePolicy.setHeightForWidth(btnBcwdSlash->sizePolicy().hasHeightForWidth());
        btnBcwdSlash->setSizePolicy(sizePolicy);
        btnBcwdSlash->setFont(font);
        btnBcwdSlash->setAutoRepeat(true);

        horizontalLayout_4->addWidget(btnBcwdSlash);

        btnShiftRight = new QToolButton(WidgetKeyboard);
        btnShiftRight->setObjectName(QStringLiteral("btnShiftRight"));
        sizePolicy.setHeightForWidth(btnShiftRight->sizePolicy().hasHeightForWidth());
        btnShiftRight->setSizePolicy(sizePolicy);
        btnShiftRight->setFont(font);
        btnShiftRight->setCheckable(true);
        btnShiftRight->setAutoRepeat(true);

        horizontalLayout_4->addWidget(btnShiftRight);


        gridLayout_3->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        btnCtrlLeft = new QToolButton(WidgetKeyboard);
        btnCtrlLeft->setObjectName(QStringLiteral("btnCtrlLeft"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnCtrlLeft->sizePolicy().hasHeightForWidth());
        btnCtrlLeft->setSizePolicy(sizePolicy1);
        btnCtrlLeft->setFont(font);
        btnCtrlLeft->setCheckable(true);
        btnCtrlLeft->setAutoRepeat(true);

        horizontalLayout_5->addWidget(btnCtrlLeft);

        btnAltLeft = new QToolButton(WidgetKeyboard);
        btnAltLeft->setObjectName(QStringLiteral("btnAltLeft"));
        sizePolicy1.setHeightForWidth(btnAltLeft->sizePolicy().hasHeightForWidth());
        btnAltLeft->setSizePolicy(sizePolicy1);
        btnAltLeft->setFont(font);
        btnAltLeft->setCheckable(true);
        btnAltLeft->setAutoRepeat(true);

        horizontalLayout_5->addWidget(btnAltLeft);

        btnSpace = new QToolButton(WidgetKeyboard);
        btnSpace->setObjectName(QStringLiteral("btnSpace"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnSpace->sizePolicy().hasHeightForWidth());
        btnSpace->setSizePolicy(sizePolicy2);
        btnSpace->setFont(font);
        btnSpace->setAutoRepeat(true);

        horizontalLayout_5->addWidget(btnSpace);

        sliderOpacity = new QSlider(WidgetKeyboard);
        sliderOpacity->setObjectName(QStringLiteral("sliderOpacity"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sliderOpacity->sizePolicy().hasHeightForWidth());
        sliderOpacity->setSizePolicy(sizePolicy3);
        sliderOpacity->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(sliderOpacity);


        gridLayout_3->addLayout(horizontalLayout_5, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btnTab = new QToolButton(WidgetKeyboard);
        btnTab->setObjectName(QStringLiteral("btnTab"));
        sizePolicy.setHeightForWidth(btnTab->sizePolicy().hasHeightForWidth());
        btnTab->setSizePolicy(sizePolicy);
        btnTab->setFont(font);
        btnTab->setAutoRepeat(true);

        horizontalLayout_2->addWidget(btnTab);

        btnQ = new QToolButton(WidgetKeyboard);
        btnQ->setObjectName(QStringLiteral("btnQ"));
        sizePolicy.setHeightForWidth(btnQ->sizePolicy().hasHeightForWidth());
        btnQ->setSizePolicy(sizePolicy);
        btnQ->setFont(font);
        btnQ->setAutoRepeat(true);

        horizontalLayout_2->addWidget(btnQ);

        btnW = new QToolButton(WidgetKeyboard);
        btnW->setObjectName(QStringLiteral("btnW"));
        sizePolicy.setHeightForWidth(btnW->sizePolicy().hasHeightForWidth());
        btnW->setSizePolicy(sizePolicy);
        btnW->setFont(font);
        btnW->setAutoRepeat(true);

        horizontalLayout_2->addWidget(btnW);

        btnE = new QToolButton(WidgetKeyboard);
        btnE->setObjectName(QStringLiteral("btnE"));
        sizePolicy.setHeightForWidth(btnE->sizePolicy().hasHeightForWidth());
        btnE->setSizePolicy(sizePolicy);
        btnE->setFont(font);
        btnE->setAutoRepeat(true);

        horizontalLayout_2->addWidget(btnE);

        btnR = new QToolButton(WidgetKeyboard);
        btnR->setObjectName(QStringLiteral("btnR"));
        sizePolicy.setHeightForWidth(btnR->sizePolicy().hasHeightForWidth());
        btnR->setSizePolicy(sizePolicy);
        btnR->setFont(font);
        btnR->setAutoRepeat(true);

        horizontalLayout_2->addWidget(btnR);

        btnT = new QToolButton(WidgetKeyboard);
        btnT->setObjectName(QStringLiteral("btnT"));
        sizePolicy.setHeightForWidth(btnT->sizePolicy().hasHeightForWidth());
        btnT->setSizePolicy(sizePolicy);
        btnT->setFont(font);
        btnT->setAutoRepeat(true);

        horizontalLayout_2->addWidget(btnT);

        btnY = new QToolButton(WidgetKeyboard);
        btnY->setObjectName(QStringLiteral("btnY"));
        sizePolicy.setHeightForWidth(btnY->sizePolicy().hasHeightForWidth());
        btnY->setSizePolicy(sizePolicy);
        btnY->setFont(font);
        btnY->setAutoRepeat(true);

        horizontalLayout_2->addWidget(btnY);

        btnU = new QToolButton(WidgetKeyboard);
        btnU->setObjectName(QStringLiteral("btnU"));
        sizePolicy.setHeightForWidth(btnU->sizePolicy().hasHeightForWidth());
        btnU->setSizePolicy(sizePolicy);
        btnU->setFont(font);
        btnU->setAutoRepeat(true);

        horizontalLayout_2->addWidget(btnU);

        btnI = new QToolButton(WidgetKeyboard);
        btnI->setObjectName(QStringLiteral("btnI"));
        sizePolicy.setHeightForWidth(btnI->sizePolicy().hasHeightForWidth());
        btnI->setSizePolicy(sizePolicy);
        btnI->setFont(font);
        btnI->setAutoRepeat(true);

        horizontalLayout_2->addWidget(btnI);

        btnO = new QToolButton(WidgetKeyboard);
        btnO->setObjectName(QStringLiteral("btnO"));
        sizePolicy.setHeightForWidth(btnO->sizePolicy().hasHeightForWidth());
        btnO->setSizePolicy(sizePolicy);
        btnO->setFont(font);
        btnO->setAutoRepeat(true);

        horizontalLayout_2->addWidget(btnO);

        btnP = new QToolButton(WidgetKeyboard);
        btnP->setObjectName(QStringLiteral("btnP"));
        sizePolicy.setHeightForWidth(btnP->sizePolicy().hasHeightForWidth());
        btnP->setSizePolicy(sizePolicy);
        btnP->setFont(font);
        btnP->setAutoRepeat(true);

        horizontalLayout_2->addWidget(btnP);

        btnStartSquare = new QToolButton(WidgetKeyboard);
        btnStartSquare->setObjectName(QStringLiteral("btnStartSquare"));
        sizePolicy.setHeightForWidth(btnStartSquare->sizePolicy().hasHeightForWidth());
        btnStartSquare->setSizePolicy(sizePolicy);
        btnStartSquare->setFont(font);
        btnStartSquare->setAutoRepeat(true);

        horizontalLayout_2->addWidget(btnStartSquare);

        btnCloseSquare = new QToolButton(WidgetKeyboard);
        btnCloseSquare->setObjectName(QStringLiteral("btnCloseSquare"));
        sizePolicy.setHeightForWidth(btnCloseSquare->sizePolicy().hasHeightForWidth());
        btnCloseSquare->setSizePolicy(sizePolicy);
        btnCloseSquare->setFont(font);
        btnCloseSquare->setAutoRepeat(true);

        horizontalLayout_2->addWidget(btnCloseSquare);

        btnFwdSlash = new QToolButton(WidgetKeyboard);
        btnFwdSlash->setObjectName(QStringLiteral("btnFwdSlash"));
        sizePolicy.setHeightForWidth(btnFwdSlash->sizePolicy().hasHeightForWidth());
        btnFwdSlash->setSizePolicy(sizePolicy);
        btnFwdSlash->setFont(font);
        btnFwdSlash->setAutoRepeat(true);

        horizontalLayout_2->addWidget(btnFwdSlash);


        gridLayout_3->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 1, 0, 1, 1);

        frameNumPad = new QFrame(WidgetKeyboard);
        frameNumPad->setObjectName(QStringLiteral("frameNumPad"));
        frameNumPad->setFrameShape(QFrame::NoFrame);
        frameNumPad->setLineWidth(1);
        layoutNumPad = new QGridLayout(frameNumPad);
        layoutNumPad->setObjectName(QStringLiteral("layoutNumPad"));
        layoutNumPad->setHorizontalSpacing(3);
        layoutNumPad->setVerticalSpacing(0);
        btnDivide = new QToolButton(frameNumPad);
        btnDivide->setObjectName(QStringLiteral("btnDivide"));
        sizePolicy.setHeightForWidth(btnDivide->sizePolicy().hasHeightForWidth());
        btnDivide->setSizePolicy(sizePolicy);
        btnDivide->setFont(font);
        btnDivide->setAutoRepeat(true);

        layoutNumPad->addWidget(btnDivide, 0, 1, 1, 1);

        btnMultiply = new QToolButton(frameNumPad);
        btnMultiply->setObjectName(QStringLiteral("btnMultiply"));
        sizePolicy.setHeightForWidth(btnMultiply->sizePolicy().hasHeightForWidth());
        btnMultiply->setSizePolicy(sizePolicy);
        btnMultiply->setFont(font);
        btnMultiply->setAutoRepeat(true);

        layoutNumPad->addWidget(btnMultiply, 0, 2, 1, 1);

        btnSubtraction = new QToolButton(frameNumPad);
        btnSubtraction->setObjectName(QStringLiteral("btnSubtraction"));
        sizePolicy.setHeightForWidth(btnSubtraction->sizePolicy().hasHeightForWidth());
        btnSubtraction->setSizePolicy(sizePolicy);
        btnSubtraction->setFont(font);
        btnSubtraction->setAutoRepeat(true);

        layoutNumPad->addWidget(btnSubtraction, 0, 3, 1, 1);

        btnNum7 = new QToolButton(frameNumPad);
        btnNum7->setObjectName(QStringLiteral("btnNum7"));
        sizePolicy.setHeightForWidth(btnNum7->sizePolicy().hasHeightForWidth());
        btnNum7->setSizePolicy(sizePolicy);
        btnNum7->setFont(font);
        btnNum7->setAutoRepeat(true);

        layoutNumPad->addWidget(btnNum7, 1, 0, 1, 1);

        btnNum8 = new QToolButton(frameNumPad);
        btnNum8->setObjectName(QStringLiteral("btnNum8"));
        sizePolicy.setHeightForWidth(btnNum8->sizePolicy().hasHeightForWidth());
        btnNum8->setSizePolicy(sizePolicy);
        btnNum8->setFont(font);
        btnNum8->setAutoRepeat(true);

        layoutNumPad->addWidget(btnNum8, 1, 1, 1, 1);

        btnNum9 = new QToolButton(frameNumPad);
        btnNum9->setObjectName(QStringLiteral("btnNum9"));
        sizePolicy.setHeightForWidth(btnNum9->sizePolicy().hasHeightForWidth());
        btnNum9->setSizePolicy(sizePolicy);
        btnNum9->setFont(font);
        btnNum9->setAutoRepeat(true);

        layoutNumPad->addWidget(btnNum9, 1, 2, 1, 1);

        btnNum4 = new QToolButton(frameNumPad);
        btnNum4->setObjectName(QStringLiteral("btnNum4"));
        sizePolicy.setHeightForWidth(btnNum4->sizePolicy().hasHeightForWidth());
        btnNum4->setSizePolicy(sizePolicy);
        btnNum4->setFont(font);
        btnNum4->setAutoRepeat(true);

        layoutNumPad->addWidget(btnNum4, 2, 0, 1, 1);

        btnNum5 = new QToolButton(frameNumPad);
        btnNum5->setObjectName(QStringLiteral("btnNum5"));
        sizePolicy.setHeightForWidth(btnNum5->sizePolicy().hasHeightForWidth());
        btnNum5->setSizePolicy(sizePolicy);
        btnNum5->setFont(font);
        btnNum5->setAutoRepeat(true);

        layoutNumPad->addWidget(btnNum5, 2, 1, 1, 1);

        btnNum6 = new QToolButton(frameNumPad);
        btnNum6->setObjectName(QStringLiteral("btnNum6"));
        sizePolicy.setHeightForWidth(btnNum6->sizePolicy().hasHeightForWidth());
        btnNum6->setSizePolicy(sizePolicy);
        btnNum6->setFont(font);
        btnNum6->setAutoRepeat(true);

        layoutNumPad->addWidget(btnNum6, 2, 2, 1, 1);

        btnSum = new QToolButton(frameNumPad);
        btnSum->setObjectName(QStringLiteral("btnSum"));
        sizePolicy.setHeightForWidth(btnSum->sizePolicy().hasHeightForWidth());
        btnSum->setSizePolicy(sizePolicy);
        btnSum->setFont(font);
        btnSum->setAutoRepeat(true);

        layoutNumPad->addWidget(btnSum, 1, 3, 2, 1);

        btnNum1 = new QToolButton(frameNumPad);
        btnNum1->setObjectName(QStringLiteral("btnNum1"));
        sizePolicy.setHeightForWidth(btnNum1->sizePolicy().hasHeightForWidth());
        btnNum1->setSizePolicy(sizePolicy);
        btnNum1->setFont(font);
        btnNum1->setAutoRepeat(true);

        layoutNumPad->addWidget(btnNum1, 3, 0, 1, 1);

        btnNum2 = new QToolButton(frameNumPad);
        btnNum2->setObjectName(QStringLiteral("btnNum2"));
        sizePolicy.setHeightForWidth(btnNum2->sizePolicy().hasHeightForWidth());
        btnNum2->setSizePolicy(sizePolicy);
        btnNum2->setFont(font);
        btnNum2->setAutoRepeat(true);

        layoutNumPad->addWidget(btnNum2, 3, 1, 1, 1);

        btnNum3 = new QToolButton(frameNumPad);
        btnNum3->setObjectName(QStringLiteral("btnNum3"));
        sizePolicy.setHeightForWidth(btnNum3->sizePolicy().hasHeightForWidth());
        btnNum3->setSizePolicy(sizePolicy);
        btnNum3->setFont(font);
        btnNum3->setAutoRepeat(true);

        layoutNumPad->addWidget(btnNum3, 3, 2, 1, 1);

        btnNum0 = new QToolButton(frameNumPad);
        btnNum0->setObjectName(QStringLiteral("btnNum0"));
        sizePolicy.setHeightForWidth(btnNum0->sizePolicy().hasHeightForWidth());
        btnNum0->setSizePolicy(sizePolicy);
        btnNum0->setFont(font);
        btnNum0->setAutoRepeat(true);

        layoutNumPad->addWidget(btnNum0, 4, 0, 1, 2);

        btnNumDot = new QToolButton(frameNumPad);
        btnNumDot->setObjectName(QStringLiteral("btnNumDot"));
        sizePolicy.setHeightForWidth(btnNumDot->sizePolicy().hasHeightForWidth());
        btnNumDot->setSizePolicy(sizePolicy);
        btnNumDot->setFont(font);
        btnNumDot->setAutoRepeat(true);

        layoutNumPad->addWidget(btnNumDot, 4, 2, 1, 1);

        btnEnter = new QToolButton(frameNumPad);
        btnEnter->setObjectName(QStringLiteral("btnEnter"));
        sizePolicy.setHeightForWidth(btnEnter->sizePolicy().hasHeightForWidth());
        btnEnter->setSizePolicy(sizePolicy);
        btnEnter->setFont(font1);
        btnEnter->setAutoRepeat(true);

        layoutNumPad->addWidget(btnEnter, 3, 3, 2, 1);

        btnNumLock = new QToolButton(frameNumPad);
        btnNumLock->setObjectName(QStringLiteral("btnNumLock"));
        btnNumLock->setEnabled(false);
        sizePolicy.setHeightForWidth(btnNumLock->sizePolicy().hasHeightForWidth());
        btnNumLock->setSizePolicy(sizePolicy);
        btnNumLock->setFont(font1);
        btnNumLock->setAutoRepeat(true);

        layoutNumPad->addWidget(btnNumLock, 0, 0, 1, 1);


        gridLayout_5->addWidget(frameNumPad, 1, 2, 1, 1);

        gridLayout_5->setRowStretch(0, 2);
        gridLayout_5->setRowStretch(1, 9);
        gridLayout_5->setColumnStretch(0, 7);
        gridLayout_5->setColumnStretch(1, 2);
        gridLayout_5->setColumnStretch(2, 2);

        verticalLayout_2->addLayout(gridLayout_5);


        retranslateUi(WidgetKeyboard);

        QMetaObject::connectSlotsByName(WidgetKeyboard);
    } // setupUi

    void retranslateUi(QWidget *WidgetKeyboard)
    {
        WidgetKeyboard->setWindowTitle(QApplication::translate("WidgetKeyboard", "Virtual Keyboard", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnEsc->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000000", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        btnEsc->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        btnEsc->setText(QApplication::translate("WidgetKeyboard", "Esc", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnF1->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000030", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnF1->setText(QApplication::translate("WidgetKeyboard", "F1", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnF2->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000031", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnF2->setText(QApplication::translate("WidgetKeyboard", "F2", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnF3->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000032", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnF3->setText(QApplication::translate("WidgetKeyboard", "F3", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnF4->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000033", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnF4->setText(QApplication::translate("WidgetKeyboard", "F4", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnF5->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000034", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnF5->setText(QApplication::translate("WidgetKeyboard", "F5", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnF6->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000035", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnF6->setText(QApplication::translate("WidgetKeyboard", "F6", Q_NULLPTR));
        btnF7->setText(QApplication::translate("WidgetKeyboard", "F7", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnF8->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000037", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnF8->setText(QApplication::translate("WidgetKeyboard", "F8", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnF9->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000038", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnF9->setText(QApplication::translate("WidgetKeyboard", "F9", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnF10->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000039", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnF10->setText(QApplication::translate("WidgetKeyboard", "F10", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnF11->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x0100003a", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnF11->setText(QApplication::translate("WidgetKeyboard", "F11", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnF12->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x0100003b", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnF12->setText(QApplication::translate("WidgetKeyboard", "F12", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnPrint->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000009", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnPrint->setText(QApplication::translate("WidgetKeyboard", "Print\n"
"Screen", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnHome_2->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000026", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnHome_2->setText(QApplication::translate("WidgetKeyboard", "Scroll\n"
"Lock", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnPgU_2->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000008", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnPgU_2->setText(QApplication::translate("WidgetKeyboard", "Pause\n"
"Break", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnIns->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000006", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnIns->setText(QApplication::translate("WidgetKeyboard", "Insert", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnHome->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000010", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnHome->setText(QApplication::translate("WidgetKeyboard", "Home", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnPgU->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000016", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnPgU->setText(QApplication::translate("WidgetKeyboard", "PgUP", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnDel->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000007", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnDel->setText(QApplication::translate("WidgetKeyboard", "Delete", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnEnd->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000011", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnEnd->setText(QApplication::translate("WidgetKeyboard", "End", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnPgD->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000017", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnPgD->setText(QApplication::translate("WidgetKeyboard", "PgDn", Q_NULLPTR));
        checkBoxShowNumPad->setText(QApplication::translate("WidgetKeyboard", "Show Numeric Keypad", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnArrowU->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000013", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnArrowU->setText(QString());
#ifndef QT_NO_ACCESSIBILITY
        btnArrowL->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000012", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnArrowL->setText(QString());
#ifndef QT_NO_ACCESSIBILITY
        btnArrowD->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000015", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnArrowD->setText(QString());
#ifndef QT_NO_ACCESSIBILITY
        btnArrowR->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000014", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnArrowR->setText(QString());
#ifndef QT_NO_ACCESSIBILITY
        btnTilt->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x60", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnTilt->setText(QApplication::translate("WidgetKeyboard", "`", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btn1->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x31", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btn1->setText(QApplication::translate("WidgetKeyboard", "1", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btn2->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x32", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btn2->setText(QApplication::translate("WidgetKeyboard", "2", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btn3->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x33", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btn3->setText(QApplication::translate("WidgetKeyboard", "3", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btn4->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x34", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btn4->setText(QApplication::translate("WidgetKeyboard", "4", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btn5->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x35", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btn5->setText(QApplication::translate("WidgetKeyboard", "5", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btn6->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x36", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btn6->setText(QApplication::translate("WidgetKeyboard", "6", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btn7->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x37", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btn7->setText(QApplication::translate("WidgetKeyboard", "7", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btn8->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x38", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btn8->setText(QApplication::translate("WidgetKeyboard", "8", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btn9->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x39", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btn9->setText(QApplication::translate("WidgetKeyboard", "9", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btn0->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x30", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btn0->setText(QApplication::translate("WidgetKeyboard", "0", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnHiphen->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x2d", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnHiphen->setText(QApplication::translate("WidgetKeyboard", "-", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnAssign->setAccessibleName(QApplication::translate("WidgetKeyboard", "13", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnAssign->setText(QApplication::translate("WidgetKeyboard", "=", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnBackSpace->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000003", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnBackSpace->setText(QApplication::translate("WidgetKeyboard", "Backspace", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnCaps->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000024", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnCaps->setText(QApplication::translate("WidgetKeyboard", "    Caps   ", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnA->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x41", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnA->setText(QApplication::translate("WidgetKeyboard", "A", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnS->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x53", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnS->setText(QApplication::translate("WidgetKeyboard", "S", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnD->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x44", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnD->setText(QApplication::translate("WidgetKeyboard", "D", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnF->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x46", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnF->setText(QApplication::translate("WidgetKeyboard", "F", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnG->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x47", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnG->setText(QApplication::translate("WidgetKeyboard", "G", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnH->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x48", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnH->setText(QApplication::translate("WidgetKeyboard", "H", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnJ->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x4a", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnJ->setText(QApplication::translate("WidgetKeyboard", "J", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnK->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x4b", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnK->setText(QApplication::translate("WidgetKeyboard", "K", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnL->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x4c", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnL->setText(QApplication::translate("WidgetKeyboard", "L", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnSemiColon->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x3b", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnSemiColon->setText(QApplication::translate("WidgetKeyboard", ";", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnSp->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x27", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnSp->setText(QApplication::translate("WidgetKeyboard", "'", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnReturn->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000004", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnReturn->setText(QApplication::translate("WidgetKeyboard", "    Return   ", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnShiftLeft->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000020", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnShiftLeft->setText(QApplication::translate("WidgetKeyboard", "     Shift     ", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnZ->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x5a", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnZ->setText(QApplication::translate("WidgetKeyboard", "Z", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnX->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x58", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnX->setText(QApplication::translate("WidgetKeyboard", "X", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnC->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x43", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnC->setText(QApplication::translate("WidgetKeyboard", "C", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnV->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x56", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnV->setText(QApplication::translate("WidgetKeyboard", "V", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnB->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x42", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnB->setText(QApplication::translate("WidgetKeyboard", "B", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnN->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x4e", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnN->setText(QApplication::translate("WidgetKeyboard", "N", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnM->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x4d", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnM->setText(QApplication::translate("WidgetKeyboard", "M", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnComma->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x2c", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnComma->setText(QApplication::translate("WidgetKeyboard", ",", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnPeriod->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x2e", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnPeriod->setText(QApplication::translate("WidgetKeyboard", ".", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnBcwdSlash->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x2f", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnBcwdSlash->setText(QApplication::translate("WidgetKeyboard", "/", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnShiftRight->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000020", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnShiftRight->setText(QApplication::translate("WidgetKeyboard", "     Shift      ", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnCtrlLeft->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000021", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnCtrlLeft->setText(QApplication::translate("WidgetKeyboard", "    Ctrl     ", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnAltLeft->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000023", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnAltLeft->setText(QApplication::translate("WidgetKeyboard", "   Alt  ", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnSpace->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x20", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnSpace->setText(QString());
#ifndef QT_NO_TOOLTIP
        sliderOpacity->setToolTip(QApplication::translate("WidgetKeyboard", "Transparency", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_ACCESSIBILITY
        btnTab->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000001", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnTab->setText(QApplication::translate("WidgetKeyboard", "  Tab   ", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnQ->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x51", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnQ->setText(QApplication::translate("WidgetKeyboard", "Q", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnW->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x57", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnW->setText(QApplication::translate("WidgetKeyboard", "W", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnE->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x45", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnE->setText(QApplication::translate("WidgetKeyboard", "E", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnR->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x52", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnR->setText(QApplication::translate("WidgetKeyboard", "R", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnT->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x54", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnT->setText(QApplication::translate("WidgetKeyboard", "T", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnY->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x59", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnY->setText(QApplication::translate("WidgetKeyboard", "Y", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnU->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x55", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnU->setText(QApplication::translate("WidgetKeyboard", "U", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnI->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x49", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnI->setText(QApplication::translate("WidgetKeyboard", "I", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnO->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x4f", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnO->setText(QApplication::translate("WidgetKeyboard", "O", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnP->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x50", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnP->setText(QApplication::translate("WidgetKeyboard", "P", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnStartSquare->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x5b", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnStartSquare->setText(QApplication::translate("WidgetKeyboard", "[", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnCloseSquare->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x5d", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnCloseSquare->setText(QApplication::translate("WidgetKeyboard", "]", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnFwdSlash->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x5c", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnFwdSlash->setText(QApplication::translate("WidgetKeyboard", "\\", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnDivide->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x2f", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnDivide->setText(QApplication::translate("WidgetKeyboard", "  / ", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnMultiply->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x2a", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnMultiply->setText(QApplication::translate("WidgetKeyboard", " * ", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnSubtraction->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x2d", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnSubtraction->setText(QApplication::translate("WidgetKeyboard", "-", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnNum7->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x37", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnNum7->setText(QApplication::translate("WidgetKeyboard", "7", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnNum8->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x38", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnNum8->setText(QApplication::translate("WidgetKeyboard", "8", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnNum9->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x39", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnNum9->setText(QApplication::translate("WidgetKeyboard", "9", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnNum4->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x34", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnNum4->setText(QApplication::translate("WidgetKeyboard", "4", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnNum5->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x35", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnNum5->setText(QApplication::translate("WidgetKeyboard", "5", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnNum6->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x36", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnNum6->setText(QApplication::translate("WidgetKeyboard", "6", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnSum->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x2b", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnSum->setText(QApplication::translate("WidgetKeyboard", "+", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnNum1->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x31", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnNum1->setText(QApplication::translate("WidgetKeyboard", "1", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnNum2->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x32", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnNum2->setText(QApplication::translate("WidgetKeyboard", "2", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnNum3->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x33", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnNum3->setText(QApplication::translate("WidgetKeyboard", "3", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnNum0->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x30", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnNum0->setText(QApplication::translate("WidgetKeyboard", "0", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnNumDot->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x2e", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnNumDot->setText(QApplication::translate("WidgetKeyboard", ".", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnEnter->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000005", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnEnter->setText(QApplication::translate("WidgetKeyboard", "Enter", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btnNumLock->setAccessibleName(QApplication::translate("WidgetKeyboard", "0x01000025", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btnNumLock->setText(QApplication::translate("WidgetKeyboard", "Num\n"
"Lock", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetKeyboard: public Ui_WidgetKeyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETKEYBOARD_H
