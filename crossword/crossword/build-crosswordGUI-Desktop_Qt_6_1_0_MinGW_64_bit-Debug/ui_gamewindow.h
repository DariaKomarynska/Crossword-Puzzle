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
    QLCDNumber *scoreLCD;
    QLabel *dashTxtLbl;
    QLCDNumber *maxScoreLCD;
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
        gameWindow->resize(1052, 568);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(255, 241, 207, 255));
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
        QBrush brush2(QColor(5, 208, 201, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush3(QColor(144, 172, 185, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        QBrush brush4(QColor(120, 120, 120, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        crosswordNameLbl->setPalette(palette1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Cooper Black")});
        font.setPointSize(28);
        crosswordNameLbl->setFont(font);
        crosswordNameLbl->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(crosswordNameLbl);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        playerTxtLbl = new QLabel(gameWindow);
        playerTxtLbl->setObjectName(QString::fromUtf8("playerTxtLbl"));
        QPalette palette2;
        QBrush brush5(QColor(3, 128, 125, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        playerTxtLbl->setPalette(palette2);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cooper Black")});
        font1.setPointSize(26);
        playerTxtLbl->setFont(font1);
        playerTxtLbl->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(playerTxtLbl);

        playerNameLbl = new QLabel(gameWindow);
        playerNameLbl->setObjectName(QString::fromUtf8("playerNameLbl"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush6(QColor(255, 184, 151, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        QBrush brush7(QColor(255, 85, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush);
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
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        scoreTxtLbl->setPalette(palette4);
        scoreTxtLbl->setFont(font1);
        scoreTxtLbl->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(scoreTxtLbl);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        scoreLCD = new QLCDNumber(gameWindow);
        scoreLCD->setObjectName(QString::fromUtf8("scoreLCD"));
        scoreLCD->setMinimumSize(QSize(120, 0));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette5.setBrush(QPalette::Active, QPalette::LinkVisited, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush2);
        scoreLCD->setPalette(palette5);
        QFont font2;
        font2.setPointSize(12);
        scoreLCD->setFont(font2);

        horizontalLayout->addWidget(scoreLCD);

        dashTxtLbl = new QLabel(gameWindow);
        dashTxtLbl->setObjectName(QString::fromUtf8("dashTxtLbl"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        dashTxtLbl->setPalette(palette6);
        dashTxtLbl->setFont(font1);
        dashTxtLbl->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(dashTxtLbl);

        maxScoreLCD = new QLCDNumber(gameWindow);
        maxScoreLCD->setObjectName(QString::fromUtf8("maxScoreLCD"));
        maxScoreLCD->setMinimumSize(QSize(120, 0));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush5);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        maxScoreLCD->setPalette(palette7);

        horizontalLayout->addWidget(maxScoreLCD);


        horizontalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gameTable = new QTableWidget(gameWindow);
        gameTable->setObjectName(QString::fromUtf8("gameTable"));
        QPalette palette8;
        QBrush brush8(QColor(0, 0, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette8.setBrush(QPalette::Active, QPalette::Light, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush9(QColor(85, 85, 255, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Dark, brush9);
        QBrush brush10(QColor(255, 78, 246, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Mid, brush10);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette8.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush11(QColor(0, 0, 0, 128));
        brush11.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette8.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Dark, brush9);
        palette8.setBrush(QPalette::Inactive, QPalette::Mid, brush10);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette8.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette8.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Dark, brush9);
        palette8.setBrush(QPalette::Disabled, QPalette::Mid, brush10);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush9);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette8.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        gameTable->setPalette(palette8);
        gameTable->setLayoutDirection(Qt::LeftToRight);
        gameTable->setFrameShape(QFrame::NoFrame);
        gameTable->setFrameShadow(QFrame::Plain);
        gameTable->setLineWidth(0);
        gameTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        gameTable->setSelectionMode(QAbstractItemView::SingleSelection);
        gameTable->setTextElideMode(Qt::ElideMiddle);
        gameTable->setShowGrid(true);
        gameTable->setGridStyle(Qt::SolidLine);
        gameTable->setRowCount(0);
        gameTable->horizontalHeader()->setVisible(false);
        gameTable->horizontalHeader()->setHighlightSections(false);
        gameTable->verticalHeader()->setVisible(false);
        gameTable->verticalHeader()->setHighlightSections(false);

        verticalLayout_3->addWidget(gameTable, 0, Qt::AlignHCenter|Qt::AlignVCenter);


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
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI Symbol")});
        font3.setPointSize(18);
        questionList->setFont(font3);

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
        checkBtn->setMinimumSize(QSize(300, 75));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        QBrush brush12(QColor(35, 106, 126, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush12);
        QBrush brush13(QColor(5, 194, 188, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush13);
        QBrush brush14(QColor(38, 116, 138, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush14);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush13);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush14);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        checkBtn->setPalette(palette9);
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Cooper Black")});
        font4.setPointSize(22);
        checkBtn->setFont(font4);

        verticalLayout->addWidget(checkBtn);

        finishBtn = new QPushButton(gameWindow);
        finishBtn->setObjectName(QString::fromUtf8("finishBtn"));
        sizePolicy1.setHeightForWidth(finishBtn->sizePolicy().hasHeightForWidth());
        finishBtn->setSizePolicy(sizePolicy1);
        finishBtn->setMinimumSize(QSize(0, 75));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush12);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush13);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush14);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush13);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush14);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        finishBtn->setPalette(palette10);
        finishBtn->setFont(font4);

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
