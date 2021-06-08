/********************************************************************************
** Form generated from reading UI file 'scoreboardwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREBOARDWINDOW_H
#define UI_SCOREBOARDWINDOW_H

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

class Ui_scoreBoardWindow
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *indexLbl;
    QLabel *playerLbl;
    QLabel *scoreLbl;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *indexList;
    QListWidget *playerList;
    QListWidget *scoreList;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QPushButton *backBtn;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *scoreBoardWindow)
    {
        if (scoreBoardWindow->objectName().isEmpty())
            scoreBoardWindow->setObjectName(QString::fromUtf8("scoreBoardWindow"));
        scoreBoardWindow->resize(809, 512);
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
        scoreBoardWindow->setPalette(palette);
        gridLayout = new QGridLayout(scoreBoardWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        indexLbl = new QLabel(scoreBoardWindow);
        indexLbl->setObjectName(QString::fromUtf8("indexLbl"));
        QPalette palette1;
        QBrush brush2(QColor(38, 116, 138, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        indexLbl->setPalette(palette1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Cooper Black")});
        font.setPointSize(22);
        indexLbl->setFont(font);
        indexLbl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(indexLbl);

        playerLbl = new QLabel(scoreBoardWindow);
        playerLbl->setObjectName(QString::fromUtf8("playerLbl"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        playerLbl->setPalette(palette2);
        playerLbl->setFont(font);
        playerLbl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(playerLbl);

        scoreLbl = new QLabel(scoreBoardWindow);
        scoreLbl->setObjectName(QString::fromUtf8("scoreLbl"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        scoreLbl->setPalette(palette3);
        scoreLbl->setFont(font);
        scoreLbl->setLayoutDirection(Qt::LeftToRight);
        scoreLbl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(scoreLbl);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        indexList = new QListWidget(scoreBoardWindow);
        indexList->setObjectName(QString::fromUtf8("indexList"));
        QPalette palette4;
        QBrush brush4(QColor(3, 128, 125, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        indexList->setPalette(palette4);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cooper Black")});
        font1.setPointSize(24);
        indexList->setFont(font1);
        indexList->setFrameShape(QFrame::NoFrame);
        indexList->setSelectionMode(QAbstractItemView::NoSelection);
        indexList->setTextElideMode(Qt::ElideNone);
        indexList->setItemAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(indexList);

        playerList = new QListWidget(scoreBoardWindow);
        playerList->setObjectName(QString::fromUtf8("playerList"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        playerList->setPalette(palette5);
        playerList->setFont(font1);
        playerList->setFrameShape(QFrame::NoFrame);
        playerList->setSelectionMode(QAbstractItemView::NoSelection);
        playerList->setTextElideMode(Qt::ElideNone);
        playerList->setItemAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(playerList);

        scoreList = new QListWidget(scoreBoardWindow);
        scoreList->setObjectName(QString::fromUtf8("scoreList"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush5(QColor(251, 110, 181, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush6(QColor(251, 110, 181, 128));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        QBrush brush7(QColor(0, 0, 0, 128));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        scoreList->setPalette(palette6);
        scoreList->setFont(font1);
        scoreList->setFrameShape(QFrame::NoFrame);
        scoreList->setSelectionMode(QAbstractItemView::NoSelection);
        scoreList->setTextElideMode(Qt::ElideNone);
        scoreList->setItemAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(scoreList);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(scoreBoardWindow);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        backBtn = new QPushButton(scoreBoardWindow);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(backBtn->sizePolicy().hasHeightForWidth());
        backBtn->setSizePolicy(sizePolicy);
        backBtn->setMinimumSize(QSize(0, 100));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        backBtn->setPalette(palette7);
        backBtn->setFont(font);

        horizontalLayout_3->addWidget(backBtn);

        label_2 = new QLabel(scoreBoardWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 1);


        retranslateUi(scoreBoardWindow);

        QMetaObject::connectSlotsByName(scoreBoardWindow);
    } // setupUi

    void retranslateUi(QWidget *scoreBoardWindow)
    {
        scoreBoardWindow->setWindowTitle(QCoreApplication::translate("scoreBoardWindow", "crossword", nullptr));
        indexLbl->setText(QCoreApplication::translate("scoreBoardWindow", "Index", nullptr));
        playerLbl->setText(QCoreApplication::translate("scoreBoardWindow", "Player", nullptr));
        scoreLbl->setText(QCoreApplication::translate("scoreBoardWindow", "Score", nullptr));
        label->setText(QString());
        backBtn->setText(QCoreApplication::translate("scoreBoardWindow", "Back", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class scoreBoardWindow: public Ui_scoreBoardWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREBOARDWINDOW_H
