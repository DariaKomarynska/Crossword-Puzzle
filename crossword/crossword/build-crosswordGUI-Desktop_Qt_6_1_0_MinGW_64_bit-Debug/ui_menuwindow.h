/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menuWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *newPlayerBtn;
    QPushButton *continueBtn;
    QPushButton *scoreBoardBtn;
    QPushButton *exitBtn;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *menuWindow)
    {
        if (menuWindow->objectName().isEmpty())
            menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        menuWindow->resize(781, 564);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(144, 172, 185, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        menuWindow->setPalette(palette);
        gridLayout = new QGridLayout(menuWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(menuWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(16777215, 200));
        QPalette palette1;
        QBrush brush2(QColor(38, 116, 138, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label->setPalette(palette1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Cooper Black")});
        font.setPointSize(38);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        newPlayerBtn = new QPushButton(menuWindow);
        newPlayerBtn->setObjectName(QString::fromUtf8("newPlayerBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(newPlayerBtn->sizePolicy().hasHeightForWidth());
        newPlayerBtn->setSizePolicy(sizePolicy1);
        newPlayerBtn->setMaximumSize(QSize(800, 100));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        newPlayerBtn->setPalette(palette2);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cooper Black")});
        font1.setPointSize(25);
        newPlayerBtn->setFont(font1);

        verticalLayout->addWidget(newPlayerBtn);

        continueBtn = new QPushButton(menuWindow);
        continueBtn->setObjectName(QString::fromUtf8("continueBtn"));
        sizePolicy1.setHeightForWidth(continueBtn->sizePolicy().hasHeightForWidth());
        continueBtn->setSizePolicy(sizePolicy1);
        continueBtn->setMaximumSize(QSize(800, 100));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush4(QColor(38, 140, 115, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        continueBtn->setPalette(palette3);
        continueBtn->setFont(font1);

        verticalLayout->addWidget(continueBtn);

        scoreBoardBtn = new QPushButton(menuWindow);
        scoreBoardBtn->setObjectName(QString::fromUtf8("scoreBoardBtn"));
        sizePolicy1.setHeightForWidth(scoreBoardBtn->sizePolicy().hasHeightForWidth());
        scoreBoardBtn->setSizePolicy(sizePolicy1);
        scoreBoardBtn->setMaximumSize(QSize(800, 100));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        scoreBoardBtn->setPalette(palette4);
        scoreBoardBtn->setFont(font1);

        verticalLayout->addWidget(scoreBoardBtn);

        exitBtn = new QPushButton(menuWindow);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));
        sizePolicy1.setHeightForWidth(exitBtn->sizePolicy().hasHeightForWidth());
        exitBtn->setSizePolicy(sizePolicy1);
        exitBtn->setMaximumSize(QSize(800, 100));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush5(QColor(83, 83, 83, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        exitBtn->setPalette(palette5);
        exitBtn->setFont(font1);

        verticalLayout->addWidget(exitBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(menuWindow);
        QObject::connect(exitBtn, &QPushButton::clicked, menuWindow, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(menuWindow);
    } // setupUi

    void retranslateUi(QWidget *menuWindow)
    {
        menuWindow->setWindowTitle(QCoreApplication::translate("menuWindow", "crossword", nullptr));
        label->setText(QCoreApplication::translate("menuWindow", "Hello Crossoword", nullptr));
        newPlayerBtn->setText(QCoreApplication::translate("menuWindow", "New Player", nullptr));
        continueBtn->setText(QCoreApplication::translate("menuWindow", "Continue", nullptr));
        scoreBoardBtn->setText(QCoreApplication::translate("menuWindow", "Scoreboard", nullptr));
        exitBtn->setText(QCoreApplication::translate("menuWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menuWindow: public Ui_menuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
