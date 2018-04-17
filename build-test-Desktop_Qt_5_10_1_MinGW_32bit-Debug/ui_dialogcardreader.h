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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogCardReader
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *line;
    QLabel *labelPicture;
    QFrame *line_2;

    void setupUi(QDialog *DialogCardReader)
    {
        if (DialogCardReader->objectName().isEmpty())
            DialogCardReader->setObjectName(QStringLiteral("DialogCardReader"));
        DialogCardReader->resize(400, 300);
        verticalLayout = new QVBoxLayout(DialogCardReader);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(DialogCardReader);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(11);
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


        retranslateUi(DialogCardReader);

        QMetaObject::connectSlotsByName(DialogCardReader);
    } // setupUi

    void retranslateUi(QDialog *DialogCardReader)
    {
        DialogCardReader->setWindowTitle(QApplication::translate("DialogCardReader", "Dialog", nullptr));
        label->setText(QApplication::translate("DialogCardReader", "SILAHKAN TAP KARTU", nullptr));
        labelPicture->setText(QApplication::translate("DialogCardReader", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogCardReader: public Ui_DialogCardReader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCARDREADER_H
