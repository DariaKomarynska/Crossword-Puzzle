/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *crosswordNameLbl;
    QHBoxLayout *horizontalLayout_3;
    QLabel *playerTxtLbl;
    QLabel *playerNameLbl;
    QHBoxLayout *horizontalLayout_2;
    QLabel *scoreTxtLbl;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *lcdNumber;
    QLabel *dashTxtLbl;
    QLCDNumber *lcdNumber_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *gameTable;
    QVBoxLayout *verticalLayout_2;
    QListWidget *questionList;
    QVBoxLayout *verticalLayout;
    QPushButton *checkBtn;
    QPushButton *finishBtn;

    void setupUi(QWidget *gameWindow)
    {
        if (gameWindow->objectName().isEmpty())
            gameWindow->setObjectName(QString::fromUtf8("gameWindow"));
        gameWindow->resize(1085, 677);
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
        gameWindow->setPalette(palette);
        gridLayout = new QGridLayout(gameWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        crosswordNameLbl = new QLabel(gameWindow);
        crosswordNameLbl->setObjectName(QString::fromUtf8("crosswordNameLbl"));
        QPalette palette1;
        QBrush brush2(QColor(251, 110, 181, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        crosswordNameLbl->setPalette(palette1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Cooper Black")});
        font.setPointSize(26);
        crosswordNameLbl->setFont(font);
        crosswordNameLbl->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(crosswordNameLbl);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        playerTxtLbl = new QLabel(gameWindow);
        playerTxtLbl->setObjectName(QString::fromUtf8("playerTxtLbl"));
        QPalette palette2;
        QBrush brush4(QColor(3, 128, 125, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        playerTxtLbl->setPalette(palette2);
        playerTxtLbl->setFont(font);
        playerTxtLbl->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(playerTxtLbl);

        playerNameLbl = new QLabel(gameWindow);
        playerNameLbl->setObjectName(QString::fromUtf8("playerNameLbl"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        playerNameLbl->setPalette(palette3);
        playerNameLbl->setFont(font);
        playerNameLbl->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(playerNameLbl);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        scoreTxtLbl = new QLabel(gameWindow);
        scoreTxtLbl->setObjectName(QString::fromUtf8("scoreTxtLbl"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        scoreTxtLbl->setPalette(palette4);
        scoreTxtLbl->setFont(font);
        scoreTxtLbl->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(scoreTxtLbl);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lcdNumber = new QLCDNumber(gameWindow);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        lcdNumber->setPalette(palette5);

        horizontalLayout->addWidget(lcdNumber);

        dashTxtLbl = new QLabel(gameWindow);
        dashTxtLbl->setObjectName(QString::fromUtf8("dashTxtLbl"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        dashTxtLbl->setPalette(palette6);
        dashTxtLbl->setFont(font);
        dashTxtLbl->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(dashTxtLbl);

        lcdNumber_2 = new QLCDNumber(gameWindow);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        lcdNumber_2->setPalette(palette7);

        horizontalLayout->addWidget(lcdNumber_2);


        horizontalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gameTable = new QTableWidget(gameWindow);
        gameTable->setObjectName(QString::fromUtf8("gameTable"));

        verticalLayout_3->addWidget(gameTable);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        questionList = new QListWidget(gameWindow);
        questionList->setObjectName(QString::fromUtf8("questionList"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(questionList->sizePolicy().hasHeightForWidth());
        questionList->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Symbol")});
        font1.setPointSize(18);
        questionList->setFont(font1);

        verticalLayout_2->addWidget(questionList);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBtn = new QPushButton(gameWindow);
        checkBtn->setObjectName(QString::fromUtf8("checkBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBtn->sizePolicy().hasHeightForWidth());
        checkBtn->setSizePolicy(sizePolicy1);
        checkBtn->setMinimumSize(QSize(400, 0));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        QBrush brush5(QColor(35, 106, 126, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush5);
        QBrush brush6(QColor(5, 194, 188, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QBrush brush7(QColor(38, 116, 138, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        checkBtn->setPalette(palette8);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Cooper Black")});
        font2.setPointSize(22);
        checkBtn->setFont(font2);

        verticalLayout->addWidget(checkBtn);

        finishBtn = new QPushButton(gameWindow);
        finishBtn->setObjectName(QString::fromUtf8("finishBtn"));
        sizePolicy1.setHeightForWidth(finishBtn->sizePolicy().hasHeightForWidth());
        finishBtn->setSizePolicy(sizePolicy1);
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        finishBtn->setPalette(palette9);
        finishBtn->setFont(font2);

        verticalLayout->addWidget(finishBtn);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_5->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);


        retranslateUi(gameWindow);

        QMetaObject::connectSlotsByName(gameWindow);
    } // setupUi

    void retranslateUi(QWidget *gameWindow)
    {
        gameWindow->setWindowTitle(QCoreApplication::translate("gameWindow", "crossword", nullptr));
        crosswordNameLbl->setText(QString());
        playerTxtLbl->setText(QCoreApplication::translate("gameWindow", "Player: ", nullptr));
        playerNameLbl->setText(QString());
        scoreTxtLbl->setText(QCoreApplication::translate("gameWindow", "Score: ", nullptr));
        dashTxtLbl->setText(QCoreApplication::translate("gameWindow", "/", nullptr));
        checkBtn->setText(QCoreApplication::translate("gameWindow", "Check", nullptr));
        finishBtn->setText(QCoreApplication::translate("gameWindow", "Finish", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameWindow: public Ui_gameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
