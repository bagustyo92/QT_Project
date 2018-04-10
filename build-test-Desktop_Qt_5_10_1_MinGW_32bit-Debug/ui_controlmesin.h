/********************************************************************************
** Form generated from reading UI file 'controlmesin.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ControlMesin
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QComboBox *listNomerMesin;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QComboBox *listResi;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3;

    void setupUi(QDialog *ControlMesin)
    {
        if (ControlMesin->objectName().isEmpty())
            ControlMesin->setObjectName(QStringLiteral("ControlMesin"));
        ControlMesin->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(ControlMesin);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(ControlMesin);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

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
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(ControlMesin);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        listNomerMesin = new QComboBox(ControlMesin);
        listNomerMesin->setObjectName(QStringLiteral("listNomerMesin"));
        sizePolicy.setHeightForWidth(listNomerMesin->sizePolicy().hasHeightForWidth());
        listNomerMesin->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(listNomerMesin);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new QLabel(ControlMesin);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        listResi = new QComboBox(ControlMesin);
        listResi->setObjectName(QStringLiteral("listResi"));

        verticalLayout_4->addWidget(listResi);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton = new QPushButton(ControlMesin);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(30);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(ControlMesin);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        line = new QFrame(ControlMesin);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        pushButton_3 = new QPushButton(ControlMesin);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(ControlMesin);
        QObject::connect(pushButton_3, SIGNAL(clicked()), ControlMesin, SLOT(close()));

        QMetaObject::connectSlotsByName(ControlMesin);
    } // setupUi

    void retranslateUi(QDialog *ControlMesin)
    {
        ControlMesin->setWindowTitle(QApplication::translate("ControlMesin", "Dialog", nullptr));
        label_3->setText(QApplication::translate("ControlMesin", "CONTROL MESIN CUCI", nullptr));
        label->setText(QApplication::translate("ControlMesin", "List Nomer Mesin", nullptr));
        label_2->setText(QApplication::translate("ControlMesin", "List Resi", nullptr));
        pushButton->setText(QApplication::translate("ControlMesin", "CUCI", nullptr));
        pushButton_2->setText(QApplication::translate("ControlMesin", "KERING", nullptr));
        pushButton_3->setText(QApplication::translate("ControlMesin", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControlMesin: public Ui_ControlMesin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLMESIN_H
