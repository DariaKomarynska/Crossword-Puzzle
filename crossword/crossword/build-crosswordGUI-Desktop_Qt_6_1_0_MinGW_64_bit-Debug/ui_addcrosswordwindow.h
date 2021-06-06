/********************************************************************************
** Form generated from reading UI file 'addcrosswordwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCROSSWORDWINDOW_H
#define UI_ADDCROSSWORDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addCrosswordWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QTextBrowser *newNameTxt;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *addBtn;
    QPushButton *cancelBtn;

    void setupUi(QWidget *addCrosswordWindow)
    {
        if (addCrosswordWindow->objectName().isEmpty())
            addCrosswordWindow->setObjectName(QString::fromUtf8("addCrosswordWindow"));
        addCrosswordWindow->resize(618, 244);
        addCrosswordWindow->setMaximumSize(QSize(618, 244));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(38, 116, 138, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        addCrosswordWindow->setPalette(palette);
        gridLayout = new QGridLayout(addCrosswordWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        newNameTxt = new QTextBrowser(addCrosswordWindow);
        newNameTxt->setObjectName(QString::fromUtf8("newNameTxt"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newNameTxt->sizePolicy().hasHeightForWidth());
        newNameTxt->setSizePolicy(sizePolicy);
        newNameTxt->setMaximumSize(QSize(16777215, 100));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        QBrush brush2(QColor(38, 116, 138, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        QBrush brush4(QColor(0, 0, 0, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        newNameTxt->setPalette(palette1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Cooper Black")});
        font.setPointSize(20);
        newNameTxt->setFont(font);

        verticalLayout_3->addWidget(newNameTxt);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addBtn = new QPushButton(addCrosswordWindow);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addBtn->sizePolicy().hasHeightForWidth());
        addBtn->setSizePolicy(sizePolicy1);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        addBtn->setPalette(palette2);
        addBtn->setFont(font);

        verticalLayout->addWidget(addBtn);

        cancelBtn = new QPushButton(addCrosswordWindow);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        sizePolicy1.setHeightForWidth(cancelBtn->sizePolicy().hasHeightForWidth());
        cancelBtn->setSizePolicy(sizePolicy1);
        QPalette palette3;
        QBrush brush5(QColor(83, 83, 83, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        cancelBtn->setPalette(palette3);
        cancelBtn->setFont(font);

        verticalLayout->addWidget(cancelBtn);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(addCrosswordWindow);

        QMetaObject::connectSlotsByName(addCrosswordWindow);
    } // setupUi

    void retranslateUi(QWidget *addCrosswordWindow)
    {
        addCrosswordWindow->setWindowTitle(QCoreApplication::translate("addCrosswordWindow", "Form", nullptr));
        addBtn->setText(QCoreApplication::translate("addCrosswordWindow", "Add", nullptr));
        cancelBtn->setText(QCoreApplication::translate("addCrosswordWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addCrosswordWindow: public Ui_addCrosswordWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCROSSWORDWINDOW_H
