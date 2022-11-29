/********************************************************************************
** Form generated from reading UI file 'main_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WIDGET_H
#define UI_MAIN_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_Widget
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter_3;
    QSplitter *splitter;
    QWidget *spectrum_widget;
    QWidget *waterfall_widget;
    QWidget *pow_widget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter_4;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QDateTimeEdit *dateTimeEdit;
    QSplitter *splitter_2;
    QWidget *control_widget;
    QWidget *user_widget;

    void setupUi(QWidget *main_Widget)
    {
        if (main_Widget->objectName().isEmpty())
            main_Widget->setObjectName(QString::fromUtf8("main_Widget"));
        main_Widget->resize(1200, 800);
        main_Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        gridLayout = new QGridLayout(main_Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter_3 = new QSplitter(main_Widget);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Vertical);
        spectrum_widget = new QWidget(splitter);
        spectrum_widget->setObjectName(QString::fromUtf8("spectrum_widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(8);
        sizePolicy1.setHeightForWidth(spectrum_widget->sizePolicy().hasHeightForWidth());
        spectrum_widget->setSizePolicy(sizePolicy1);
        spectrum_widget->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));
        splitter->addWidget(spectrum_widget);
        waterfall_widget = new QWidget(splitter);
        waterfall_widget->setObjectName(QString::fromUtf8("waterfall_widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(4);
        sizePolicy2.setHeightForWidth(waterfall_widget->sizePolicy().hasHeightForWidth());
        waterfall_widget->setSizePolicy(sizePolicy2);
        waterfall_widget->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));
        splitter->addWidget(waterfall_widget);
        pow_widget = new QWidget(splitter);
        pow_widget->setObjectName(QString::fromUtf8("pow_widget"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(pow_widget->sizePolicy().hasHeightForWidth());
        pow_widget->setSizePolicy(sizePolicy3);
        pow_widget->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));
        horizontalLayout = new QHBoxLayout(pow_widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        splitter_4 = new QSplitter(pow_widget);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(splitter_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(164, 0, 0);"));
        splitter_4->addWidget(pushButton);
        lineEdit = new QLineEdit(splitter_4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);\n"
"color: rgb(238, 238, 236);"));
        lineEdit->setAlignment(Qt::AlignCenter);
        splitter_4->addWidget(lineEdit);
        dateTimeEdit = new QDateTimeEdit(splitter_4);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setAlignment(Qt::AlignCenter);
        dateTimeEdit->setReadOnly(true);
        dateTimeEdit->setTime(QTime(0, 0, 0));
        dateTimeEdit->setMinimumTime(QTime(12, 0, 0));
        splitter_4->addWidget(dateTimeEdit);

        horizontalLayout->addWidget(splitter_4);

        splitter->addWidget(pow_widget);
        splitter_3->addWidget(splitter);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(splitter_2->sizePolicy().hasHeightForWidth());
        splitter_2->setSizePolicy(sizePolicy4);
        splitter_2->setMinimumSize(QSize(400, 0));
        splitter_2->setOrientation(Qt::Vertical);
        control_widget = new QWidget(splitter_2);
        control_widget->setObjectName(QString::fromUtf8("control_widget"));
        control_widget->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));
        splitter_2->addWidget(control_widget);
        user_widget = new QWidget(splitter_2);
        user_widget->setObjectName(QString::fromUtf8("user_widget"));
        user_widget->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));
        splitter_2->addWidget(user_widget);
        splitter_3->addWidget(splitter_2);

        gridLayout->addWidget(splitter_3, 0, 0, 1, 1);


        retranslateUi(main_Widget);

        QMetaObject::connectSlotsByName(main_Widget);
    } // setupUi

    void retranslateUi(QWidget *main_Widget)
    {
        main_Widget->setWindowTitle(QApplication::translate("main_Widget", "spectrum analize", nullptr));
        pushButton->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("main_Widget", "ip:192.168.1.10", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_Widget: public Ui_main_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WIDGET_H
