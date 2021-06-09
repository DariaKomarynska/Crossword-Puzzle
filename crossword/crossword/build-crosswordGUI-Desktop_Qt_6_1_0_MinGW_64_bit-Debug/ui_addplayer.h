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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddPlayer
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *newPlayerName;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelBtn;
    QVBoxLayout *verticalLayout;
    QPushButton *addBtn;

    void setupUi(QDialog *AddPlayer)
    {
        if (AddPlayer->objectName().isEmpty())
            AddPlayer->setObjectName(QString::fromUtf8("AddPlayer"));
        AddPlayer->resize(715, 214);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(71);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddPlayer->sizePolicy().hasHeightForWidth());
        AddPlayer->setSizePolicy(sizePolicy);
        AddPlayer->setMinimumSize(QSize(214, 0));
        AddPlayer->setMaximumSize(QSize(715, 214));
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
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(AddPlayer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 100));
        QPalette palette1;
        QBrush brush4(QColor(5, 208, 201, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label->setPalette(palette1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Cooper Black")});
        font.setPointSize(28);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        newPlayerName = new QLineEdit(AddPlayer);
        newPlayerName->setObjectName(QString::fromUtf8("newPlayerName"));
        newPlayerName->setMinimumSize(QSize(0, 100));
        QPalette palette2;
        QBrush brush5(QColor(251, 110, 181, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush6(QColor(251, 110, 181, 128));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        QBrush brush7(QColor(0, 0, 0, 128));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        newPlayerName->setPalette(palette2);
        newPlayerName->setFont(font);

        horizontalLayout_2->addWidget(newPlayerName);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cancelBtn = new QPushButton(AddPlayer);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cancelBtn->sizePolicy().hasHeightForWidth());
        cancelBtn->setSizePolicy(sizePolicy1);
        QPalette palette3;
        QBrush brush8(QColor(83, 83, 83, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        cancelBtn->setPalette(palette3);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cooper Black")});
        font1.setPointSize(20);
        cancelBtn->setFont(font1);

        horizontalLayout->addWidget(cancelBtn);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addBtn = new QPushButton(AddPlayer);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        sizePolicy1.setHeightForWidth(addBtn->sizePolicy().hasHeightForWidth());
        addBtn->setSizePolicy(sizePolicy1);
        addBtn->setMinimumSize(QSize(320, 0));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        addBtn->setPalette(palette4);
        addBtn->setFont(font1);

        verticalLayout->addWidget(addBtn);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(AddPlayer);

        QMetaObject::connectSlotsByName(AddPlayer);
    } // setupUi

    void retranslateUi(QDialog *AddPlayer)
    {
        AddPlayer->setWindowTitle(QCoreApplication::translate("AddPlayer", "New Player", nullptr));
        label->setText(QCoreApplication::translate("AddPlayer", "Enter name: ", nullptr));
        cancelBtn->setText(QCoreApplication::translate("AddPlayer", "Cancel", nullptr));
        addBtn->setText(QCoreApplication::translate("AddPlayer", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPlayer: public Ui_AddPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPLAYER_H
