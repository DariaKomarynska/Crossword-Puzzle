/********************************************************************************
** Form generated from reading UI file 'addplayer.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPLAYER_H
#define UI_ADDPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddPlayer
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *newPlayerName;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *addBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *AddPlayer)
    {
        if (AddPlayer->objectName().isEmpty())
            AddPlayer->setObjectName(QString::fromUtf8("AddPlayer"));
        AddPlayer->resize(618, 244);
        AddPlayer->setMaximumSize(QSize(618, 244));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(38, 116, 138, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        AddPlayer->setPalette(palette);
        gridLayout = new QGridLayout(AddPlayer);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        newPlayerName = new QTextEdit(AddPlayer);
        newPlayerName->setObjectName(QString::fromUtf8("newPlayerName"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Light")});
        font.setPointSize(24);
        newPlayerName->setFont(font);

        verticalLayout_2->addWidget(newPlayerName);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addBtn = new QPushButton(AddPlayer);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addBtn->sizePolicy().hasHeightForWidth());
        addBtn->setSizePolicy(sizePolicy);
        addBtn->setMinimumSize(QSize(320, 0));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        addBtn->setPalette(palette1);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cooper Black")});
        font1.setPointSize(20);
        addBtn->setFont(font1);

        verticalLayout->addWidget(addBtn);

        cancelBtn = new QPushButton(AddPlayer);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        sizePolicy.setHeightForWidth(cancelBtn->sizePolicy().hasHeightForWidth());
        cancelBtn->setSizePolicy(sizePolicy);
        QPalette palette2;
        QBrush brush4(QColor(83, 83, 83, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        cancelBtn->setPalette(palette2);
        cancelBtn->setFont(font1);

        verticalLayout->addWidget(cancelBtn);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(AddPlayer);

        QMetaObject::connectSlotsByName(AddPlayer);
    } // setupUi

    void retranslateUi(QDialog *AddPlayer)
    {
        AddPlayer->setWindowTitle(QCoreApplication::translate("AddPlayer", "New Player", nullptr));
        addBtn->setText(QCoreApplication::translate("AddPlayer", "Add", nullptr));
        cancelBtn->setText(QCoreApplication::translate("AddPlayer", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPlayer: public Ui_AddPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPLAYER_H
