/********************************************************************************
** Form generated from reading UI file 'readerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READERDIALOG_H
#define UI_READERDIALOG_H

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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ReaderDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QFrame *line_2;
    QLabel *labelCurrentBalance;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QPushButton *backButton;

    void setupUi(QDialog *ReaderDialog)
    {
        if (ReaderDialog->objectName().isEmpty())
            ReaderDialog->setObjectName(QStringLiteral("ReaderDialog"));
        ReaderDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(ReaderDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelTitle = new QLabel(ReaderDialog);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelTitle->sizePolicy().hasHeightForWidth());
        labelTitle->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelTitle);

        line_2 = new QFrame(ReaderDialog);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        labelCurrentBalance = new QLabel(ReaderDialog);
        labelCurrentBalance->setObjectName(QStringLiteral("labelCurrentBalance"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelCurrentBalance->sizePolicy().hasHeightForWidth());
        labelCurrentBalance->setSizePolicy(sizePolicy1);
        labelCurrentBalance->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelCurrentBalance);

        line = new QFrame(ReaderDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        backButton = new QPushButton(ReaderDialog);
        backButton->setObjectName(QStringLiteral("backButton"));
        sizePolicy1.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(backButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ReaderDialog);
        QObject::connect(backButton, SIGNAL(clicked()), ReaderDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(ReaderDialog);
    } // setupUi

    void retranslateUi(QDialog *ReaderDialog)
    {
        ReaderDialog->setWindowTitle(QApplication::translate("ReaderDialog", "Dialog", nullptr));
        labelTitle->setText(QApplication::translate("ReaderDialog", "TAMPILAN PAKET PILIHAN", nullptr));
        labelCurrentBalance->setText(QApplication::translate("ReaderDialog", "- Informasi Saldo", nullptr));
        backButton->setText(QApplication::translate("ReaderDialog", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReaderDialog: public Ui_ReaderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READERDIALOG_H
