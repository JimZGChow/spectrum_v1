/********************************************************************************
** Form generated from reading UI file 'control_option.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL_OPTION_H
#define UI_CONTROL_OPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>

QT_BEGIN_NAMESPACE

class Ui_controlOptions
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *lcdNumber_9;
    QLCDNumber *lcdNumber_8;
    QLCDNumber *lcdNumber_7;
    QLCDNumber *lcdNumber_6;
    QLCDNumber *lcdNumber_5;
    QLCDNumber *lcdNumber_4;
    QLCDNumber *lcdNumber_3;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber_1;
    QLCDNumber *lcdNumber_0;

    void setupUi(QDialog *controlOptions)
    {
        if (controlOptions->objectName().isEmpty())
            controlOptions->setObjectName(QString::fromUtf8("controlOptions"));
        controlOptions->resize(415, 79);
        gridLayout = new QGridLayout(controlOptions);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lcdNumber_9 = new QLCDNumber(controlOptions);
        lcdNumber_9->setObjectName(QString::fromUtf8("lcdNumber_9"));
        lcdNumber_9->setStyleSheet(QString::fromUtf8("background-color: rgb(206, 92, 0);"));
        lcdNumber_9->setLineWidth(3);
        lcdNumber_9->setMidLineWidth(1);
        lcdNumber_9->setDigitCount(1);

        horizontalLayout->addWidget(lcdNumber_9);

        lcdNumber_8 = new QLCDNumber(controlOptions);
        lcdNumber_8->setObjectName(QString::fromUtf8("lcdNumber_8"));
        lcdNumber_8->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 74, 135);"));
        lcdNumber_8->setLineWidth(3);
        lcdNumber_8->setMidLineWidth(1);
        lcdNumber_8->setDigitCount(1);

        horizontalLayout->addWidget(lcdNumber_8);

        lcdNumber_7 = new QLCDNumber(controlOptions);
        lcdNumber_7->setObjectName(QString::fromUtf8("lcdNumber_7"));
        lcdNumber_7->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 74, 135);"));
        lcdNumber_7->setLineWidth(3);
        lcdNumber_7->setMidLineWidth(1);
        lcdNumber_7->setDigitCount(1);

        horizontalLayout->addWidget(lcdNumber_7);

        lcdNumber_6 = new QLCDNumber(controlOptions);
        lcdNumber_6->setObjectName(QString::fromUtf8("lcdNumber_6"));
        lcdNumber_6->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 74, 135);"));
        lcdNumber_6->setLineWidth(3);
        lcdNumber_6->setMidLineWidth(1);
        lcdNumber_6->setDigitCount(1);

        horizontalLayout->addWidget(lcdNumber_6);

        lcdNumber_5 = new QLCDNumber(controlOptions);
        lcdNumber_5->setObjectName(QString::fromUtf8("lcdNumber_5"));
        lcdNumber_5->setStyleSheet(QString::fromUtf8("background-color: rgb(117, 80, 123);"));
        lcdNumber_5->setLineWidth(3);
        lcdNumber_5->setMidLineWidth(1);
        lcdNumber_5->setDigitCount(1);

        horizontalLayout->addWidget(lcdNumber_5);

        lcdNumber_4 = new QLCDNumber(controlOptions);
        lcdNumber_4->setObjectName(QString::fromUtf8("lcdNumber_4"));
        lcdNumber_4->setStyleSheet(QString::fromUtf8("background-color: rgb(117, 80, 123);"));
        lcdNumber_4->setLineWidth(3);
        lcdNumber_4->setMidLineWidth(1);
        lcdNumber_4->setDigitCount(1);

        horizontalLayout->addWidget(lcdNumber_4);

        lcdNumber_3 = new QLCDNumber(controlOptions);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        lcdNumber_3->setStyleSheet(QString::fromUtf8("background-color: rgb(117, 80, 123);"));
        lcdNumber_3->setLineWidth(3);
        lcdNumber_3->setMidLineWidth(1);
        lcdNumber_3->setDigitCount(1);

        horizontalLayout->addWidget(lcdNumber_3);

        lcdNumber_2 = new QLCDNumber(controlOptions);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);\n"
""));
        lcdNumber_2->setLineWidth(3);
        lcdNumber_2->setMidLineWidth(1);
        lcdNumber_2->setDigitCount(1);

        horizontalLayout->addWidget(lcdNumber_2);

        lcdNumber_1 = new QLCDNumber(controlOptions);
        lcdNumber_1->setObjectName(QString::fromUtf8("lcdNumber_1"));
        lcdNumber_1->setMaximumSize(QSize(16777215, 16777215));
        lcdNumber_1->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);\n"
""));
        lcdNumber_1->setLineWidth(3);
        lcdNumber_1->setMidLineWidth(1);
        lcdNumber_1->setDigitCount(1);

        horizontalLayout->addWidget(lcdNumber_1);

        lcdNumber_0 = new QLCDNumber(controlOptions);
        lcdNumber_0->setObjectName(QString::fromUtf8("lcdNumber_0"));
        lcdNumber_0->setMaximumSize(QSize(16777215, 16777215));
        lcdNumber_0->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);\n"
""));
        lcdNumber_0->setLineWidth(3);
        lcdNumber_0->setMidLineWidth(1);
        lcdNumber_0->setDigitCount(1);

        horizontalLayout->addWidget(lcdNumber_0);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(controlOptions);

        QMetaObject::connectSlotsByName(controlOptions);
    } // setupUi

    void retranslateUi(QDialog *controlOptions)
    {
        controlOptions->setWindowTitle(QApplication::translate("controlOptions", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class controlOptions: public Ui_controlOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_OPTION_H
