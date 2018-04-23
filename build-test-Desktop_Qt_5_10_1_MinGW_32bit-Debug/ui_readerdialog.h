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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ReaderDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *labelTitle;
    QSpacerItem *verticalSpacer;
    QFrame *line_2;
    QLabel *label;
    QLabel *labelCurrentBalance;
    QFrame *line;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *ReaderDialog)
    {
        if (ReaderDialog->objectName().isEmpty())
            ReaderDialog->setObjectName(QStringLiteral("ReaderDialog"));
        ReaderDialog->resize(400, 300);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(12, 59, 151, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        ReaderDialog->setPalette(palette);
        verticalLayout = new QVBoxLayout(ReaderDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_2);

        labelTitle = new QLabel(ReaderDialog);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelTitle->sizePolicy().hasHeightForWidth());
        labelTitle->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelTitle);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        line_2 = new QFrame(ReaderDialog);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        label = new QLabel(ReaderDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        labelCurrentBalance = new QLabel(ReaderDialog);
        labelCurrentBalance->setObjectName(QStringLiteral("labelCurrentBalance"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelCurrentBalance->sizePolicy().hasHeightForWidth());
        labelCurrentBalance->setSizePolicy(sizePolicy1);
        labelCurrentBalance->setFont(font1);
        labelCurrentBalance->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelCurrentBalance);

        line = new QFrame(ReaderDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        backButton = new QPushButton(ReaderDialog);
        backButton->setObjectName(QStringLiteral("backButton"));
        sizePolicy.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(15);
        backButton->setFont(font2);

        horizontalLayout->addWidget(backButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ReaderDialog);
        QObject::connect(backButton, SIGNAL(clicked()), ReaderDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(ReaderDialog);
    } // setupUi

    void retranslateUi(QDialog *ReaderDialog)
    {
        ReaderDialog->setWindowTitle(QApplication::translate("ReaderDialog", "Dialog", nullptr));
        labelTitle->setText(QApplication::translate("ReaderDialog", "TAMPILAN PAKET PILIHAN", nullptr));
        label->setText(QApplication::translate("ReaderDialog", "Transaksi Anda BERHASIL!", nullptr));
        labelCurrentBalance->setText(QApplication::translate("ReaderDialog", "- Informasi Saldo", nullptr));
        backButton->setText(QApplication::translate("ReaderDialog", "<    KEMBALI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReaderDialog: public Ui_ReaderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READERDIALOG_H
