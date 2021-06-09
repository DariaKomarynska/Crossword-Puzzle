/********************************************************************************
** Form generated from reading UI file 'selectcrossword.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTCROSSWORD_H
#define UI_SELECTCROSSWORD_H

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

class Ui_selectCrossword
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *playerTxtLbl;
    QLabel *playerLbl;
    QLabel *selectCrosswortTxtLbl;
    QListWidget *crosswordList;
    QHBoxLayout *horizontalLayout;
    QPushButton *deleteBtn;
    QPushButton *addCrosswordBtn;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *logoutBtn;
    QPushButton *playBtn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *selectCrossword)
    {
        if (selectCrossword->objectName().isEmpty())
            selectCrossword->setObjectName(QString::fromUtf8("selectCrossword"));
        selectCrossword->resize(917, 564);
        QPalette palette;
        QBrush brush(QColor(83, 83, 83, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(182, 199, 220, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        selectCrossword->setPalette(palette);
        gridLayout = new QGridLayout(selectCrossword);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        playerTxtLbl = new QLabel(selectCrossword);
        playerTxtLbl->setObjectName(QString::fromUtf8("playerTxtLbl"));
        QPalette palette1;
        QBrush brush4(QColor(38, 116, 138, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        playerTxtLbl->setPalette(palette1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Cooper Black")});
        font.setPointSize(22);
        playerTxtLbl->setFont(font);

        horizontalLayout_3->addWidget(playerTxtLbl);

        playerLbl = new QLabel(selectCrossword);
        playerLbl->setObjectName(QString::fromUtf8("playerLbl"));
        QPalette palette2;
        QBrush brush5(QColor(251, 110, 181, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        playerLbl->setPalette(palette2);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cooper Black")});
        font1.setPointSize(24);
        playerLbl->setFont(font1);

        horizontalLayout_3->addWidget(playerLbl);


        verticalLayout->addLayout(horizontalLayout_3);

        selectCrosswortTxtLbl = new QLabel(selectCrossword);
        selectCrosswortTxtLbl->setObjectName(QString::fromUtf8("selectCrosswortTxtLbl"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush4);
        QBrush brush6(QColor(38, 116, 138, 128));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        QBrush brush7(QColor(0, 0, 0, 128));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        selectCrosswortTxtLbl->setPalette(palette3);
        selectCrosswortTxtLbl->setFont(font);

        verticalLayout->addWidget(selectCrosswortTxtLbl);

        crosswordList = new QListWidget(selectCrossword);
        crosswordList->setObjectName(QString::fromUtf8("crosswordList"));
        QPalette palette4;
        QBrush brush8(QColor(35, 107, 127, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        crosswordList->setPalette(palette4);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(24);
        crosswordList->setFont(font2);
        crosswordList->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(crosswordList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        deleteBtn = new QPushButton(selectCrossword);
        deleteBtn->setObjectName(QString::fromUtf8("deleteBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deleteBtn->sizePolicy().hasHeightForWidth());
        deleteBtn->setSizePolicy(sizePolicy);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        deleteBtn->setPalette(palette5);
        deleteBtn->setFont(font);

        horizontalLayout->addWidget(deleteBtn);

        addCrosswordBtn = new QPushButton(selectCrossword);
        addCrosswordBtn->setObjectName(QString::fromUtf8("addCrosswordBtn"));
        addCrosswordBtn->setMinimumSize(QSize(0, 75));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        addCrosswordBtn->setPalette(palette6);
        addCrosswordBtn->setFont(font);

        horizontalLayout->addWidget(addCrosswordBtn);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        logoutBtn = new QPushButton(selectCrossword);
        logoutBtn->setObjectName(QString::fromUtf8("logoutBtn"));
        logoutBtn->setMinimumSize(QSize(0, 75));
        logoutBtn->setFont(font);

        horizontalLayout_2->addWidget(logoutBtn);

        playBtn = new QPushButton(selectCrossword);
        playBtn->setObjectName(QString::fromUtf8("playBtn"));
        playBtn->setMinimumSize(QSize(0, 75));
        QPalette palette7;
        QBrush brush9(QColor(26, 78, 93, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush9);
        QBrush brush10(QColor(46, 171, 140, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush10);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        playBtn->setPalette(palette7);
        playBtn->setFont(font);

        horizontalLayout_2->addWidget(playBtn);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        retranslateUi(selectCrossword);

        QMetaObject::connectSlotsByName(selectCrossword);
    } // setupUi

    void retranslateUi(QWidget *selectCrossword)
    {
        selectCrossword->setWindowTitle(QCoreApplication::translate("selectCrossword", "crossword", nullptr));
        playerTxtLbl->setText(QCoreApplication::translate("selectCrossword", "Player:", nullptr));
        playerLbl->setText(QString());
        selectCrosswortTxtLbl->setText(QCoreApplication::translate("selectCrossword", "Select Crossword:", nullptr));
        deleteBtn->setText(QCoreApplication::translate("selectCrossword", "Delete", nullptr));
        addCrosswordBtn->setText(QCoreApplication::translate("selectCrossword", "Add", nullptr));
        logoutBtn->setText(QCoreApplication::translate("selectCrossword", "Logout", nullptr));
        playBtn->setText(QCoreApplication::translate("selectCrossword", "Play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class selectCrossword: public Ui_selectCrossword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTCROSSWORD_H
