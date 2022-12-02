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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_main_Widget
{
public:
    QGridLayout *gridLayout_2;
    QSplitter *splitter_3;
    QSplitter *splitter;
    QCustomPlot *spectrum_plot;
    QWidget *waterfall_widget;
    QWidget *pow_widget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter_4;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QDateTimeEdit *dateTimeEdit;
    QSplitter *splitter_2;
    QTabWidget *tabWidget;
    QWidget *span_configure_widget;
    QGridLayout *gridLayout;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
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
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_span;
    QSpinBox *spinBox_span;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpinBox *spinBox_start;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpinBox *spinBox_end;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QComboBox *comboBox_gain_mode;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QSlider *horizontalSlider;
    QWidget *draw_configure_widget;
    QWidget *add;
    QTabWidget *tabWidget_2;
    QWidget *small_show_widget;
    QGridLayout *gridLayout_3;
    QCustomPlot *plot_1M;

    void setupUi(QWidget *main_Widget)
    {
        if (main_Widget->objectName().isEmpty())
            main_Widget->setObjectName(QString::fromUtf8("main_Widget"));
        main_Widget->resize(1183, 737);
        main_Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 215, 207);"));
        gridLayout_2 = new QGridLayout(main_Widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        splitter_3 = new QSplitter(main_Widget);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Vertical);
        spectrum_plot = new QCustomPlot(splitter);
        spectrum_plot->setObjectName(QString::fromUtf8("spectrum_plot"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(12);
        sizePolicy1.setHeightForWidth(spectrum_plot->sizePolicy().hasHeightForWidth());
        spectrum_plot->setSizePolicy(sizePolicy1);
        spectrum_plot->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));
        splitter->addWidget(spectrum_plot);
        waterfall_widget = new QWidget(splitter);
        waterfall_widget->setObjectName(QString::fromUtf8("waterfall_widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(3);
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
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(splitter_4->sizePolicy().hasHeightForWidth());
        splitter_4->setSizePolicy(sizePolicy4);
        splitter_4->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(splitter_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(164, 0, 0);"));
        splitter_4->addWidget(pushButton);
        lineEdit = new QLineEdit(splitter_4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy5);
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
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(1);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(splitter_2->sizePolicy().hasHeightForWidth());
        splitter_2->setSizePolicy(sizePolicy6);
        splitter_2->setOrientation(Qt::Vertical);
        tabWidget = new QTabWidget(splitter_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(3);
        sizePolicy7.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy7);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        span_configure_widget = new QWidget();
        span_configure_widget->setObjectName(QString::fromUtf8("span_configure_widget"));
        gridLayout = new QGridLayout(span_configure_widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        dockWidget = new QDockWidget(span_configure_widget);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setFloating(false);
        dockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
        dockWidget->setAllowedAreas(Qt::NoDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 0, -1);
        lcdNumber_9 = new QLCDNumber(dockWidgetContents);
        lcdNumber_9->setObjectName(QString::fromUtf8("lcdNumber_9"));
        lcdNumber_9->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17);"));
        lcdNumber_9->setDigitCount(1);

        horizontalLayout_2->addWidget(lcdNumber_9);

        lcdNumber_8 = new QLCDNumber(dockWidgetContents);
        lcdNumber_8->setObjectName(QString::fromUtf8("lcdNumber_8"));
        lcdNumber_8->setDigitCount(1);
        lcdNumber_8->setProperty("value", QVariant(1.000000000000000));

        horizontalLayout_2->addWidget(lcdNumber_8);

        lcdNumber_7 = new QLCDNumber(dockWidgetContents);
        lcdNumber_7->setObjectName(QString::fromUtf8("lcdNumber_7"));
        lcdNumber_7->setStyleSheet(QString::fromUtf8(""));
        lcdNumber_7->setDigitCount(1);
        lcdNumber_7->setProperty("value", QVariant(0.000000000000000));

        horizontalLayout_2->addWidget(lcdNumber_7);

        lcdNumber_6 = new QLCDNumber(dockWidgetContents);
        lcdNumber_6->setObjectName(QString::fromUtf8("lcdNumber_6"));
        lcdNumber_6->setDigitCount(1);

        horizontalLayout_2->addWidget(lcdNumber_6);

        lcdNumber_5 = new QLCDNumber(dockWidgetContents);
        lcdNumber_5->setObjectName(QString::fromUtf8("lcdNumber_5"));
        lcdNumber_5->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        lcdNumber_5->setDigitCount(1);
        lcdNumber_5->setProperty("value", QVariant(5.000000000000000));

        horizontalLayout_2->addWidget(lcdNumber_5);

        lcdNumber_4 = new QLCDNumber(dockWidgetContents);
        lcdNumber_4->setObjectName(QString::fromUtf8("lcdNumber_4"));
        lcdNumber_4->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        lcdNumber_4->setDigitCount(1);

        horizontalLayout_2->addWidget(lcdNumber_4);

        lcdNumber_3 = new QLCDNumber(dockWidgetContents);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        lcdNumber_3->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        lcdNumber_3->setDigitCount(1);

        horizontalLayout_2->addWidget(lcdNumber_3);

        lcdNumber_2 = new QLCDNumber(dockWidgetContents);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setDigitCount(1);

        horizontalLayout_2->addWidget(lcdNumber_2);

        lcdNumber_1 = new QLCDNumber(dockWidgetContents);
        lcdNumber_1->setObjectName(QString::fromUtf8("lcdNumber_1"));
        lcdNumber_1->setDigitCount(1);

        horizontalLayout_2->addWidget(lcdNumber_1);

        lcdNumber_0 = new QLCDNumber(dockWidgetContents);
        lcdNumber_0->setObjectName(QString::fromUtf8("lcdNumber_0"));
        lcdNumber_0->setMaximumSize(QSize(16777215, 100));
        lcdNumber_0->setStyleSheet(QString::fromUtf8(""));
        lcdNumber_0->setDigitCount(1);

        horizontalLayout_2->addWidget(lcdNumber_0);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_span = new QLabel(dockWidgetContents);
        label_span->setObjectName(QString::fromUtf8("label_span"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(1);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(label_span->sizePolicy().hasHeightForWidth());
        label_span->setSizePolicy(sizePolicy8);
        label_span->setStyleSheet(QString::fromUtf8("font: 13pt \"Ubuntu\";\n"
""));
        label_span->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_span);

        spinBox_span = new QSpinBox(dockWidgetContents);
        spinBox_span->setObjectName(QString::fromUtf8("spinBox_span"));
        QSizePolicy sizePolicy9(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(2);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(spinBox_span->sizePolicy().hasHeightForWidth());
        spinBox_span->setSizePolicy(sizePolicy9);
        spinBox_span->setStyleSheet(QString::fromUtf8("font: 16pt \"Ubuntu\";"));
        spinBox_span->setAlignment(Qt::AlignCenter);
        spinBox_span->setMinimum(3);
        spinBox_span->setMaximum(3000);
        spinBox_span->setValue(3);

        horizontalLayout_5->addWidget(spinBox_span);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(dockWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy8.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy8);
        label->setStyleSheet(QString::fromUtf8("font: 13pt \"Ubuntu\";\n"
""));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label);

        spinBox_start = new QSpinBox(dockWidgetContents);
        spinBox_start->setObjectName(QString::fromUtf8("spinBox_start"));
        sizePolicy9.setHeightForWidth(spinBox_start->sizePolicy().hasHeightForWidth());
        spinBox_start->setSizePolicy(sizePolicy9);
        spinBox_start->setStyleSheet(QString::fromUtf8("font: 16pt \"Ubuntu\";"));
        spinBox_start->setAlignment(Qt::AlignCenter);
        spinBox_start->setMinimum(70);
        spinBox_start->setMaximum(6000);
        spinBox_start->setValue(99);

        horizontalLayout_3->addWidget(spinBox_start);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy8.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy8);
        label_2->setStyleSheet(QString::fromUtf8("font: 13pt \"Ubuntu\";\n"
""));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_2);

        spinBox_end = new QSpinBox(dockWidgetContents);
        spinBox_end->setObjectName(QString::fromUtf8("spinBox_end"));
        sizePolicy9.setHeightForWidth(spinBox_end->sizePolicy().hasHeightForWidth());
        spinBox_end->setSizePolicy(sizePolicy9);
        spinBox_end->setStyleSheet(QString::fromUtf8("font: 16pt \"Ubuntu\";"));
        spinBox_end->setAlignment(Qt::AlignCenter);
        spinBox_end->setMinimum(70);
        spinBox_end->setMaximum(6000);
        spinBox_end->setValue(102);

        horizontalLayout_4->addWidget(spinBox_end);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_3 = new QLabel(dockWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy8.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy8);

        horizontalLayout_7->addWidget(label_3);

        comboBox_gain_mode = new QComboBox(dockWidgetContents);
        comboBox_gain_mode->setObjectName(QString::fromUtf8("comboBox_gain_mode"));
        QSizePolicy sizePolicy10(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy10.setHorizontalStretch(2);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(comboBox_gain_mode->sizePolicy().hasHeightForWidth());
        comboBox_gain_mode->setSizePolicy(sizePolicy10);

        horizontalLayout_7->addWidget(comboBox_gain_mode);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(dockWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        horizontalSlider = new QSlider(dockWidgetContents);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(horizontalSlider);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_3->addLayout(verticalLayout_2);

        dockWidget->setWidget(dockWidgetContents);

        gridLayout->addWidget(dockWidget, 0, 0, 1, 1);

        tabWidget->addTab(span_configure_widget, QString());
        draw_configure_widget = new QWidget();
        draw_configure_widget->setObjectName(QString::fromUtf8("draw_configure_widget"));
        tabWidget->addTab(draw_configure_widget, QString());
        add = new QWidget();
        add->setObjectName(QString::fromUtf8("add"));
        tabWidget->addTab(add, QString());
        splitter_2->addWidget(tabWidget);
        tabWidget_2 = new QTabWidget(splitter_2);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        QSizePolicy sizePolicy11(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(1);
        sizePolicy11.setHeightForWidth(tabWidget_2->sizePolicy().hasHeightForWidth());
        tabWidget_2->setSizePolicy(sizePolicy11);
        tabWidget_2->setMinimumSize(QSize(0, 300));
        small_show_widget = new QWidget();
        small_show_widget->setObjectName(QString::fromUtf8("small_show_widget"));
        gridLayout_3 = new QGridLayout(small_show_widget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        plot_1M = new QCustomPlot(small_show_widget);
        plot_1M->setObjectName(QString::fromUtf8("plot_1M"));
        plot_1M->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));

        gridLayout_3->addWidget(plot_1M, 0, 0, 1, 1);

        tabWidget_2->addTab(small_show_widget, QString());
        splitter_2->addWidget(tabWidget_2);
        splitter_3->addWidget(splitter_2);

        gridLayout_2->addWidget(splitter_3, 0, 0, 1, 1);


        retranslateUi(main_Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(main_Widget);
    } // setupUi

    void retranslateUi(QWidget *main_Widget)
    {
        main_Widget->setWindowTitle(QApplication::translate("main_Widget", "spectrum analize", nullptr));
        pushButton->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("main_Widget", "ip:192.168.1.10", nullptr));
        dockWidget->setWindowTitle(QApplication::translate("main_Widget", "Receiver configure", nullptr));
        label_span->setText(QApplication::translate("main_Widget", "Span(M)", nullptr));
        label->setText(QApplication::translate("main_Widget", "Start(M)", nullptr));
        label_2->setText(QApplication::translate("main_Widget", "End(M)", nullptr));
        label_3->setText(QApplication::translate("main_Widget", "Gain mode", nullptr));
        label_4->setText(QApplication::translate("main_Widget", "Gain ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(span_configure_widget), QApplication::translate("main_Widget", "Span Configure", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(draw_configure_widget), QApplication::translate("main_Widget", "Draw Configure", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(add), QApplication::translate("main_Widget", "add", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(small_show_widget), QApplication::translate("main_Widget", "1M Show", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_Widget: public Ui_main_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WIDGET_H
