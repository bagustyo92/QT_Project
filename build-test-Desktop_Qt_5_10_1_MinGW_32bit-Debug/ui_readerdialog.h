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
    QLabel *label_5;
    QFrame *line_2;
    QLabel *label;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
    QPushButton *backButton;

    void setupUi(QDialog *ReaderDialog)
    {
        if (ReaderDialog->objectName().isEmpty())
            ReaderDialog->setObjectName(QStringLiteral("ReaderDialog"));
        ReaderDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(ReaderDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_5 = new QLabel(ReaderDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font;
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_5);

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
        label_3 = new QLabel(ReaderDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(ReaderDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(label_4);

        label_2 = new QLabel(ReaderDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

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
        label_5->setText(QApplication::translate("ReaderDialog", "TAMPILAN PAKET PILIHAN", nullptr));
        label->setText(QApplication::translate("ReaderDialog", "LABEL PERINTAH DAN KETERANGAN", nullptr));
        label_3->setText(QApplication::translate("ReaderDialog", "- Informasi Saldo", nullptr));
        label_4->setText(QApplication::translate("ReaderDialog", "- Informasi Tarif", nullptr));
        label_2->setText(QApplication::translate("ReaderDialog", "- Tap Card", nullptr));
        backButton->setText(QApplication::translate("ReaderDialog", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReaderDialog: public Ui_ReaderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READERDIALOG_H
