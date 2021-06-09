/********************************************************************************
** Form generated from reading UI file 'selectplayer.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTPLAYER_H
#define UI_SELECTPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selectPlayer
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *selectPlayerLbl;
    QListWidget *playerList;
    QHBoxLayout *horizontalLayout;
    QPushButton *backBtn;
    QPushButton *deletePlayerBtn;
    QPushButton *playBtn;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *selectPlayer)
    {
        if (selectPlayer->objectName().isEmpty())
            selectPlayer->setObjectName(QString::fromUtf8("selectPlayer"));
        selectPlayer->resize(918, 601);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(selectPlayer->sizePolicy().hasHeightForWidth());
        selectPlayer->setSizePolicy(sizePolicy);
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
        selectPlayer->setPalette(palette);
        gridLayout = new QGridLayout(selectPlayer);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer);

        selectPlayerLbl = new QLabel(selectPlayer);
        selectPlayerLbl->setObjectName(QString::fromUtf8("selectPlayerLbl"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(selectPlayerLbl->sizePolicy().hasHeightForWidth());
        selectPlayerLbl->setSizePolicy(sizePolicy1);
        selectPlayerLbl->setMaximumSize(QSize(16777215, 100));
        QPalette palette1;
        QBrush brush2(QColor(38, 116, 138, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        QBrush brush3(QColor(38, 116, 138, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        QBrush brush4(QColor(120, 120, 120, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        QBrush brush5(QColor(0, 0, 0, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        selectPlayerLbl->setPalette(palette1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Cooper Black")});
        font.setPointSize(36);
        selectPlayerLbl->setFont(font);

        verticalLayout->addWidget(selectPlayerLbl);

        playerList = new QListWidget(selectPlayer);
        playerList->setObjectName(QString::fromUtf8("playerList"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(playerList->sizePolicy().hasHeightForWidth());
        playerList->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(24);
        playerList->setFont(font1);

        verticalLayout->addWidget(playerList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        backBtn = new QPushButton(selectPlayer);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(backBtn->sizePolicy().hasHeightForWidth());
        backBtn->setSizePolicy(sizePolicy3);
        backBtn->setMinimumSize(QSize(0, 75));
        backBtn->setMaximumSize(QSize(16777215, 200));
        QPalette palette2;
        QBrush brush6(QColor(83, 83, 83, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        backBtn->setPalette(palette2);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Cooper Black")});
        font2.setPointSize(20);
        backBtn->setFont(font2);

        horizontalLayout->addWidget(backBtn);

        deletePlayerBtn = new QPushButton(selectPlayer);
        deletePlayerBtn->setObjectName(QString::fromUtf8("deletePlayerBtn"));
        sizePolicy3.setHeightForWidth(deletePlayerBtn->sizePolicy().hasHeightForWidth());
        deletePlayerBtn->setSizePolicy(sizePolicy3);
        deletePlayerBtn->setMinimumSize(QSize(0, 0));
        deletePlayerBtn->setMaximumSize(QSize(16777215, 200));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        deletePlayerBtn->setPalette(palette3);
        deletePlayerBtn->setFont(font2);

        horizontalLayout->addWidget(deletePlayerBtn);


        verticalLayout->addLayout(horizontalLayout);

        playBtn = new QPushButton(selectPlayer);
        playBtn->setObjectName(QString::fromUtf8("playBtn"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(playBtn->sizePolicy().hasHeightForWidth());
        playBtn->setSizePolicy(sizePolicy4);
        playBtn->setMinimumSize(QSize(0, 75));
        playBtn->setMaximumSize(QSize(16777215, 200));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        playBtn->setPalette(palette4);
        playBtn->setFont(font2);

        verticalLayout->addWidget(playBtn);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_2, 1, 1, 1, 1);


        retranslateUi(selectPlayer);

        QMetaObject::connectSlotsByName(selectPlayer);
    } // setupUi

    void retranslateUi(QWidget *selectPlayer)
    {
        selectPlayer->setWindowTitle(QCoreApplication::translate("selectPlayer", "crossword", nullptr));
        selectPlayerLbl->setText(QCoreApplication::translate("selectPlayer", "Select Player:", nullptr));
        backBtn->setText(QCoreApplication::translate("selectPlayer", "Back", nullptr));
        deletePlayerBtn->setText(QCoreApplication::translate("selectPlayer", "Delete", nullptr));
        playBtn->setText(QCoreApplication::translate("selectPlayer", "Play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class selectPlayer: public Ui_selectPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTPLAYER_H
