/********************************************************************************
** Form generated from reading UI file 'dialogcardreader.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
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
    QLabel *label;
    QFrame *line;
    QLabel *labelPicture;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer;
    QFrame *line_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *nextButton;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *DialogCardReader)
    {
        if (DialogCardReader->objectName().isEmpty())
            DialogCardReader->setObjectName(QStringLiteral("DialogCardReader"));
        DialogCardReader->resize(400, 300);
        verticalLayout = new QVBoxLayout(DialogCardReader);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(DialogCardReader);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        line = new QFrame(DialogCardReader);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        labelPicture = new QLabel(DialogCardReader);
        labelPicture->setObjectName(QStringLiteral("labelPicture"));
        labelPicture->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelPicture);

        line_2 = new QFrame(DialogCardReader);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        backButton = new QPushButton(DialogCardReader);
        backButton->setObjectName(QStringLiteral("backButton"));
        sizePolicy.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(13);
        backButton->setFont(font1);
        backButton->setLayoutDirection(Qt::LeftToRight);
        backButton->setAutoRepeatInterval(100);
        backButton->setAutoDefault(true);

        horizontalLayout->addWidget(backButton);

        horizontalSpacer = new QSpacerItem(40, 5, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        line_3 = new QFrame(DialogCardReader);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        nextButton = new QPushButton(DialogCardReader);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        sizePolicy.setHeightForWidth(nextButton->sizePolicy().hasHeightForWidth());
        nextButton->setSizePolicy(sizePolicy);
        nextButton->setFont(font1);

        horizontalLayout->addWidget(nextButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_3);


        retranslateUi(DialogCardReader);
        QObject::connect(backButton, SIGNAL(clicked()), DialogCardReader, SLOT(close()));

        QMetaObject::connectSlotsByName(DialogCardReader);
    } // setupUi

    void retranslateUi(QDialog *DialogCardReader)
    {
        DialogCardReader->setWindowTitle(QApplication::translate("DialogCardReader", "Dialog", nullptr));
        label->setText(QApplication::translate("DialogCardReader", "SILAHKAN TAP KARTU", nullptr));
        labelPicture->setText(QApplication::translate("DialogCardReader", "TextLabel", nullptr));
        backButton->setText(QApplication::translate("DialogCardReader", "BACK", nullptr));
        nextButton->setText(QApplication::translate("DialogCardReader", "NEXT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogCardReader: public Ui_DialogCardReader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCARDREADER_H
