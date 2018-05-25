/********************************************************************************
** Form generated from reading UI file 'pendaftaranwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PENDAFTARANWINDOW_H
#define UI_PENDAFTARANWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PendaftaranWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *pictureLabel;
    QSpacerItem *verticalSpacer_3;
    QFrame *line;
    QSpacerItem *verticalSpacer_7;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_Name;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_3;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *lineEdit_Alamat;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *lineEdit_kelurahan;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *lineEdit_kecamatan;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *lineEdit_email;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_16;
    QLineEdit *lineEdit_nohape;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_4;
    QFrame *line_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer_17;
    QFrame *line_3;
    QSpacerItem *horizontalSpacer_18;
    QPushButton *nextButton;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_11;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PendaftaranWindow)
    {
        if (PendaftaranWindow->objectName().isEmpty())
            PendaftaranWindow->setObjectName(QStringLiteral("PendaftaranWindow"));
        PendaftaranWindow->resize(734, 1082);
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
        PendaftaranWindow->setPalette(palette);
        centralwidget = new QWidget(PendaftaranWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_2);

        pictureLabel = new QLabel(centralwidget);
        pictureLabel->setObjectName(QStringLiteral("pictureLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pictureLabel->sizePolicy().hasHeightForWidth());
        pictureLabel->setSizePolicy(sizePolicy);
        pictureLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(pictureLabel);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_3);

        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_7);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(23);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_12);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        verticalLayout_4->addWidget(label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setFont(font1);

        verticalLayout_4->addWidget(label_3);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setFont(font1);

        verticalLayout_4->addWidget(label_5);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setFont(font1);

        verticalLayout_4->addWidget(label_6);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setFont(font1);

        verticalLayout_4->addWidget(label_7);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setFont(font1);

        verticalLayout_4->addWidget(label_8);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setFont(font1);

        verticalLayout_4->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setFont(font1);

        horizontalLayout_3->addWidget(label_9);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        lineEdit_Name = new QLineEdit(centralwidget);
        lineEdit_Name->setObjectName(QStringLiteral("lineEdit_Name"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_Name->sizePolicy().hasHeightForWidth());
        lineEdit_Name->setSizePolicy(sizePolicy2);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        lineEdit_Name->setPalette(palette1);
        lineEdit_Name->setFont(font1);

        horizontalLayout_3->addWidget(lineEdit_Name);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setFont(font1);

        horizontalLayout_4->addWidget(label_10);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        dateEdit->setPalette(palette2);
        dateEdit->setFont(font1);

        horizontalLayout_4->addWidget(dateEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setFont(font1);

        horizontalLayout_6->addWidget(label_11);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        lineEdit_Alamat = new QLineEdit(centralwidget);
        lineEdit_Alamat->setObjectName(QStringLiteral("lineEdit_Alamat"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        lineEdit_Alamat->setPalette(palette3);
        lineEdit_Alamat->setFont(font1);

        horizontalLayout_6->addWidget(lineEdit_Alamat);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font1);

        horizontalLayout_7->addWidget(label_13);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        lineEdit_kelurahan = new QLineEdit(centralwidget);
        lineEdit_kelurahan->setObjectName(QStringLiteral("lineEdit_kelurahan"));
        QPalette palette4;
        QBrush brush3(QColor(108, 166, 190, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        lineEdit_kelurahan->setPalette(palette4);
        lineEdit_kelurahan->setFont(font1);

        horizontalLayout_7->addWidget(lineEdit_kelurahan);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font1);

        horizontalLayout_8->addWidget(label_14);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        lineEdit_kecamatan = new QLineEdit(centralwidget);
        lineEdit_kecamatan->setObjectName(QStringLiteral("lineEdit_kecamatan"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        lineEdit_kecamatan->setPalette(palette5);
        lineEdit_kecamatan->setFont(font1);

        horizontalLayout_8->addWidget(lineEdit_kecamatan);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font1);

        horizontalLayout_9->addWidget(label_12);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);

        lineEdit_email = new QLineEdit(centralwidget);
        lineEdit_email->setObjectName(QStringLiteral("lineEdit_email"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        lineEdit_email->setPalette(palette6);
        lineEdit_email->setFont(font1);

        horizontalLayout_9->addWidget(lineEdit_email);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font1);

        horizontalLayout_5->addWidget(label_15);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_16);

        lineEdit_nohape = new QLineEdit(centralwidget);
        lineEdit_nohape->setObjectName(QStringLiteral("lineEdit_nohape"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        lineEdit_nohape->setPalette(palette7);
        lineEdit_nohape->setFont(font1);

        horizontalLayout_5->addWidget(lineEdit_nohape);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_13);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_4);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_14);

        backButton = new QPushButton(centralwidget);
        backButton->setObjectName(QStringLiteral("backButton"));
        sizePolicy.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(25);
        backButton->setFont(font2);

        horizontalLayout_10->addWidget(backButton);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_17);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_10->addWidget(line_3);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_18);

        nextButton = new QPushButton(centralwidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        sizePolicy.setHeightForWidth(nextButton->sizePolicy().hasHeightForWidth());
        nextButton->setSizePolicy(sizePolicy);
        nextButton->setFont(font2);

        horizontalLayout_10->addWidget(nextButton);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_15);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_11);


        verticalLayout_2->addLayout(horizontalLayout_10);

        PendaftaranWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PendaftaranWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 734, 26));
        PendaftaranWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PendaftaranWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        PendaftaranWindow->setStatusBar(statusbar);

        retranslateUi(PendaftaranWindow);
        QObject::connect(backButton, SIGNAL(clicked()), PendaftaranWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(PendaftaranWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PendaftaranWindow)
    {
        PendaftaranWindow->setWindowTitle(QApplication::translate("PendaftaranWindow", "MainWindow", Q_NULLPTR));
        pictureLabel->setText(QApplication::translate("PendaftaranWindow", "TextLabel", Q_NULLPTR));
        label->setText(QApplication::translate("PendaftaranWindow", "FORMULIR PENDAFTARAN :", Q_NULLPTR));
        label_2->setText(QApplication::translate("PendaftaranWindow", "Nama", Q_NULLPTR));
        label_3->setText(QApplication::translate("PendaftaranWindow", "Tgl Lahir", Q_NULLPTR));
        label_5->setText(QApplication::translate("PendaftaranWindow", "Alamat", Q_NULLPTR));
        label_6->setText(QApplication::translate("PendaftaranWindow", "Kelurahan", Q_NULLPTR));
        label_7->setText(QApplication::translate("PendaftaranWindow", "Kecamatan", Q_NULLPTR));
        label_8->setText(QApplication::translate("PendaftaranWindow", "E-mail", Q_NULLPTR));
        label_4->setText(QApplication::translate("PendaftaranWindow", "No.HP", Q_NULLPTR));
        label_9->setText(QApplication::translate("PendaftaranWindow", ":", Q_NULLPTR));
        label_10->setText(QApplication::translate("PendaftaranWindow", ":", Q_NULLPTR));
        label_11->setText(QApplication::translate("PendaftaranWindow", ":", Q_NULLPTR));
        label_13->setText(QApplication::translate("PendaftaranWindow", ":", Q_NULLPTR));
        label_14->setText(QApplication::translate("PendaftaranWindow", ":", Q_NULLPTR));
        label_12->setText(QApplication::translate("PendaftaranWindow", ":", Q_NULLPTR));
        label_15->setText(QApplication::translate("PendaftaranWindow", ":", Q_NULLPTR));
        backButton->setText(QApplication::translate("PendaftaranWindow", "<  KEMBALI", Q_NULLPTR));
        nextButton->setText(QApplication::translate("PendaftaranWindow", "SELANJUTNYA  >", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PendaftaranWindow: public Ui_PendaftaranWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PENDAFTARANWINDOW_H
