/********************************************************************************
** Form generated from reading UI file 'controlmesin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLMESIN_H
#define UI_CONTROLMESIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ControlMesin
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *image_label;
    QSpacerItem *verticalSpacer;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_11;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QSpacerItem *verticalSpacer_5;
    QComboBox *listNomerMesin;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line_3;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_4;
    QComboBox *listResi;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *pushButton_cuci;
    QSpacerItem *horizontalSpacer_6;
    QFrame *line_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_kering;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *verticalSpacer_7;
    QFrame *line;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QDialog *ControlMesin)
    {
        if (ControlMesin->objectName().isEmpty())
            ControlMesin->setObjectName(QStringLiteral("ControlMesin"));
        ControlMesin->resize(663, 499);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(108, 167, 191, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        ControlMesin->setPalette(palette);
        verticalLayout_2 = new QVBoxLayout(ControlMesin);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_2);

        image_label = new QLabel(ControlMesin);
        image_label->setObjectName(QStringLiteral("image_label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(image_label->sizePolicy().hasHeightForWidth());
        image_label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        image_label->setFont(font);
        image_label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(image_label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer);

        line_2 = new QFrame(ControlMesin);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_15);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_11);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(ControlMesin);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(25);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer_5);

        listNomerMesin = new QComboBox(ControlMesin);
        listNomerMesin->setObjectName(QStringLiteral("listNomerMesin"));
        sizePolicy.setHeightForWidth(listNomerMesin->sizePolicy().hasHeightForWidth());
        listNomerMesin->setSizePolicy(sizePolicy);
        QPalette palette1;
        QBrush brush3(QColor(191, 210, 214, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush3);
        QBrush brush4(QColor(240, 240, 240, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        listNomerMesin->setPalette(palette1);
        QFont font2;
        font2.setPointSize(25);
        listNomerMesin->setFont(font2);

        verticalLayout_3->addWidget(listNomerMesin);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        line_3 = new QFrame(ControlMesin);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new QLabel(ControlMesin);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_4->addItem(verticalSpacer_4);

        listResi = new QComboBox(ControlMesin);
        listResi->setObjectName(QStringLiteral("listResi"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        listResi->setPalette(palette2);
        listResi->setFont(font2);

        verticalLayout_4->addWidget(listResi);


        horizontalLayout->addLayout(verticalLayout_4);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_12);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_16);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_13);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_17);

        pushButton_cuci = new QPushButton(ControlMesin);
        pushButton_cuci->setObjectName(QStringLiteral("pushButton_cuci"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(30);
        sizePolicy1.setHeightForWidth(pushButton_cuci->sizePolicy().hasHeightForWidth());
        pushButton_cuci->setSizePolicy(sizePolicy1);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        QBrush brush5(QColor(239, 235, 231, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        QBrush brush6(QColor(186, 189, 182, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        QBrush brush7(QColor(136, 138, 133, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        pushButton_cuci->setPalette(palette3);
        QFont font3;
        font3.setPointSize(25);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_cuci->setFont(font3);

        horizontalLayout_2->addWidget(pushButton_cuci);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        line_4 = new QFrame(ControlMesin);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        pushButton_kering = new QPushButton(ControlMesin);
        pushButton_kering->setObjectName(QStringLiteral("pushButton_kering"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_kering->sizePolicy().hasHeightForWidth());
        pushButton_kering->setSizePolicy(sizePolicy2);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        pushButton_kering->setPalette(palette4);
        pushButton_kering->setFont(font3);

        horizontalLayout_2->addWidget(pushButton_kering);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_18);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_14);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_7);

        line = new QFrame(ControlMesin);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        pushButton_3 = new QPushButton(ControlMesin);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setFont(font3);

        horizontalLayout_3->addWidget(pushButton_3);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_6);


        retranslateUi(ControlMesin);
        QObject::connect(pushButton_3, SIGNAL(clicked()), ControlMesin, SLOT(close()));

        QMetaObject::connectSlotsByName(ControlMesin);
    } // setupUi

    void retranslateUi(QDialog *ControlMesin)
    {
        ControlMesin->setWindowTitle(QApplication::translate("ControlMesin", "Dialog", Q_NULLPTR));
        image_label->setText(QApplication::translate("ControlMesin", "CONTROL MESIN CUCI", Q_NULLPTR));
        label->setText(QApplication::translate("ControlMesin", "List Nomer Mesin", Q_NULLPTR));
        label_2->setText(QApplication::translate("ControlMesin", "List Resi", Q_NULLPTR));
        pushButton_cuci->setText(QApplication::translate("ControlMesin", "CUCI", Q_NULLPTR));
        pushButton_kering->setText(QApplication::translate("ControlMesin", "KERING", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("ControlMesin", "<   KEMBALI", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ControlMesin: public Ui_ControlMesin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLMESIN_H
