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
    QLabel *label;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelCurrentBalance;
    QHBoxLayout *horizontalLayout_2;
    QFrame *line_3;
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

        label = new QLabel(ReaderDialog);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        line = new QFrame(ReaderDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelCurrentBalance = new QLabel(ReaderDialog);
        labelCurrentBalance->setObjectName(QStringLiteral("labelCurrentBalance"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelCurrentBalance->sizePolicy().hasHeightForWidth());
        labelCurrentBalance->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(labelCurrentBalance);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_2);

        line_3 = new QFrame(ReaderDialog);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        backButton = new QPushButton(ReaderDialog);
        backButton->setObjectName(QStringLiteral("backButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy2);

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
        label->setText(QApplication::translate("ReaderDialog", "LABEL PERINTAH DAN KETERANGAN", nullptr));
        labelCurrentBalance->setText(QApplication::translate("ReaderDialog", "- Informasi Saldo", nullptr));
        backButton->setText(QApplication::translate("ReaderDialog", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReaderDialog: public Ui_ReaderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READERDIALOG_H
