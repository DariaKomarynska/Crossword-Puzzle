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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addCrosswordWindow
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *newCrosswordName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *newCrosswordFile;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *generateFromListChckB;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelBtn;
    QPushButton *addBtn;

    void setupUi(QWidget *addCrosswordWindow)
    {
        if (addCrosswordWindow->objectName().isEmpty())
            addCrosswordWindow->setObjectName(QString::fromUtf8("addCrosswordWindow"));
        addCrosswordWindow->setEnabled(true);
        addCrosswordWindow->resize(771, 270);
        addCrosswordWindow->setMinimumSize(QSize(771, 270));
        addCrosswordWindow->setMaximumSize(QSize(771, 270));
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
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(addCrosswordWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QPalette palette1;
        QBrush brush2(QColor(5, 208, 201, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label->setPalette(palette1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Cooper Black")});
        font.setPointSize(24);
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        newCrosswordName = new QLineEdit(addCrosswordWindow);
        newCrosswordName->setObjectName(QString::fromUtf8("newCrosswordName"));
        QPalette palette2;
        QBrush brush4(QColor(251, 110, 181, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush5(QColor(251, 110, 181, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        QBrush brush6(QColor(0, 0, 0, 128));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        newCrosswordName->setPalette(palette2);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cooper Black")});
        font1.setPointSize(28);
        newCrosswordName->setFont(font1);

        horizontalLayout_3->addWidget(newCrosswordName);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(addCrosswordWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label_2->setPalette(palette3);
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        newCrosswordFile = new QLineEdit(addCrosswordWindow);
        newCrosswordFile->setObjectName(QString::fromUtf8("newCrosswordFile"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        newCrosswordFile->setPalette(palette4);
        newCrosswordFile->setFont(font1);

        horizontalLayout_2->addWidget(newCrosswordFile);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        generateFromListChckB = new QCheckBox(addCrosswordWindow);
        generateFromListChckB->setObjectName(QString::fromUtf8("generateFromListChckB"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(generateFromListChckB->sizePolicy().hasHeightForWidth());
        generateFromListChckB->setSizePolicy(sizePolicy);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush7(QColor(255, 85, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush7);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush2);
        QBrush brush8(QColor(0, 0, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        QBrush brush9(QColor(5, 208, 201, 128));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        generateFromListChckB->setPalette(palette5);
        generateFromListChckB->setFont(font);
        generateFromListChckB->setLayoutDirection(Qt::RightToLeft);
        generateFromListChckB->setTristate(false);

        horizontalLayout->addWidget(generateFromListChckB);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        cancelBtn = new QPushButton(addCrosswordWindow);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cancelBtn->sizePolicy().hasHeightForWidth());
        cancelBtn->setSizePolicy(sizePolicy1);
        cancelBtn->setMaximumSize(QSize(16777215, 60));
        QPalette palette6;
        QBrush brush10(QColor(83, 83, 83, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush10);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        cancelBtn->setPalette(palette6);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Cooper Black")});
        font2.setPointSize(20);
        cancelBtn->setFont(font2);

        verticalLayout->addWidget(cancelBtn);


        horizontalLayout_4->addLayout(verticalLayout);

        addBtn = new QPushButton(addCrosswordWindow);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(addBtn->sizePolicy().hasHeightForWidth());
        addBtn->setSizePolicy(sizePolicy2);
        addBtn->setMaximumSize(QSize(16777215, 100));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        addBtn->setPalette(palette7);
        addBtn->setFont(font2);

        horizontalLayout_4->addWidget(addBtn);


        gridLayout->addLayout(horizontalLayout_4, 2, 0, 1, 1);


        retranslateUi(addCrosswordWindow);

        QMetaObject::connectSlotsByName(addCrosswordWindow);
    } // setupUi

    void retranslateUi(QWidget *addCrosswordWindow)
    {
        addCrosswordWindow->setWindowTitle(QCoreApplication::translate("addCrosswordWindow", "Add Crossword", nullptr));
        label->setText(QCoreApplication::translate("addCrosswordWindow", "Enter Name: ", nullptr));
        label_2->setText(QCoreApplication::translate("addCrosswordWindow", "Enter File Name: ", nullptr));
        generateFromListChckB->setText(QCoreApplication::translate("addCrosswordWindow", "From list of words", nullptr));
        cancelBtn->setText(QCoreApplication::translate("addCrosswordWindow", "Cancel", nullptr));
        addBtn->setText(QCoreApplication::translate("addCrosswordWindow", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addCrosswordWindow: public Ui_addCrosswordWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCROSSWORDWINDOW_H
