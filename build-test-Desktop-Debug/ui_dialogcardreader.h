/********************************************************************************
** Form generated from reading UI file 'dialogcardreader.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCARDREADER_H
#define UI_DIALOGCARDREADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogCardReader
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *image_label;
    QSpacerItem *verticalSpacer_2;
    QFrame *line;
    QLabel *labelPicture;
    QFrame *line_2;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer;
    QFrame *line_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *nextButton;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *DialogCardReader)
    {
        if (DialogCardReader->objectName().isEmpty())
            DialogCardReader->setObjectName(QStringLiteral("DialogCardReader"));
        DialogCardReader->resize(538, 300);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(108, 167, 191, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        DialogCardReader->setPalette(palette);
        verticalLayout = new QVBoxLayout(DialogCardReader);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        image_label = new QLabel(DialogCardReader);
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

        verticalLayout->addWidget(image_label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_2);

        line = new QFrame(DialogCardReader);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        labelPicture = new QLabel(DialogCardReader);
        labelPicture->setObjectName(QStringLiteral("labelPicture"));
        QFont font1;
        font1.setPointSize(25);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        labelPicture->setFont(font1);
        labelPicture->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelPicture);

        line_2 = new QFrame(DialogCardReader);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        backButton = new QPushButton(DialogCardReader);
        backButton->setObjectName(QStringLiteral("backButton"));
        sizePolicy.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(25);
        backButton->setFont(font2);
        backButton->setLayoutDirection(Qt::LeftToRight);
        backButton->setAutoRepeatInterval(100);
        backButton->setAutoDefault(true);

        horizontalLayout->addWidget(backButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        line_3 = new QFrame(DialogCardReader);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        nextButton = new QPushButton(DialogCardReader);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        sizePolicy.setHeightForWidth(nextButton->sizePolicy().hasHeightForWidth());
        nextButton->setSizePolicy(sizePolicy);
        nextButton->setFont(font2);

        horizontalLayout->addWidget(nextButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_3);


        retranslateUi(DialogCardReader);
        QObject::connect(backButton, SIGNAL(clicked()), DialogCardReader, SLOT(close()));

        QMetaObject::connectSlotsByName(DialogCardReader);
    } // setupUi

    void retranslateUi(QDialog *DialogCardReader)
    {
        DialogCardReader->setWindowTitle(QApplication::translate("DialogCardReader", "Dialog", Q_NULLPTR));
        image_label->setText(QApplication::translate("DialogCardReader", "SILAHKAN TAP KARTU", Q_NULLPTR));
        labelPicture->setText(QApplication::translate("DialogCardReader", "TextLabel", Q_NULLPTR));
        backButton->setText(QApplication::translate("DialogCardReader", "<   KEMBALI", Q_NULLPTR));
        nextButton->setText(QApplication::translate("DialogCardReader", "SELANJUTNYA", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogCardReader: public Ui_DialogCardReader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCARDREADER_H
