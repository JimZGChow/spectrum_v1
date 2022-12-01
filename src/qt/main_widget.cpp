//
// Created by jcc on 22-11-29.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_widget.h" resolved

#include "qt/main_widget.h"
#include "qdebug.h"
#include "fix/my_math.h"

main_widget::main_widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::main_Widget){
    ui->setupUi(this);
    ui->spinBox_end->setValue(102);
    /* set time */
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dockWidget->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetFloatable);
    /* draw plot setup */
    this->spectrum_draw_init();

    connect(ui->spinBox_span, SIGNAL(valueChanged(int)),
            this, SLOT(span_change(int)));
    connect(ui->spinBox_start, SIGNAL(valueChanged(int)),
            this, SLOT(start_change(int)));
    connect(ui->spinBox_end, SIGNAL(valueChanged(int)),
            this, SLOT(end_change(int)));

}

main_widget::~main_widget() {
    delete ui;
}

/**
 * Span spinbox value change Receiver configure and lcd number
 * */
void main_widget::span_change(int value) {
    ui->spinBox_end->setValue(ui->spinBox_start->value() + value);
    /* cal lcd */
    auto center_frequency = ((static_cast<double>(ui->spinBox_start->value()) + ui->spinBox_end->value()) / 2)*1e6;
    ui->lcdNumber_9->display(get_one_number_from_position(center_frequency,9));
    ui->lcdNumber_8->display(get_one_number_from_position(center_frequency,8));
    ui->lcdNumber_7->display(get_one_number_from_position(center_frequency,7));
    ui->lcdNumber_6->display(get_one_number_from_position(center_frequency,6));
    ui->lcdNumber_5->display(get_one_number_from_position(center_frequency,5));
}

void main_widget::start_change(int value) {
    if(value >= ui->spinBox_end->value() - 2){
        ui->spinBox_start->setValue(ui->spinBox_end->value() - 3);
    }
    else{
        span_change(ui->spinBox_end->value() - value);
    }
    ui->spinBox_span->setValue(ui->spinBox_end->value() - ui->spinBox_start->value());
}

void main_widget::end_change(int value) {
    if(value <= ui->spinBox_start->value() + 2){
        ui->spinBox_end->setValue(ui->spinBox_start->value() + 3);
    }
    else{
        span_change( value - ui->spinBox_start->value());
    }
    ui->spinBox_span->setValue(ui->spinBox_end->value() - ui->spinBox_start->value());
}

/**
 * Spectrum draw plot setup
 * */
void main_widget::spectrum_draw_init() {
    QPen pen = ui->spectrum_plot->xAxis->basePen();
    pen.setColor(Qt::white);
    /* back ground */
    ui->spectrum_plot->setBackground(QColor(85, 87, 83));
    /* x y label */
    ui->spectrum_plot->xAxis->setLabelColor(Qt::white);
    ui->spectrum_plot->yAxis->setLabelColor(Qt::white);
    ui->spectrum_plot->xAxis->setTickLabelColor(Qt::white);
    ui->spectrum_plot->yAxis->setTickLabelColor(Qt::white);

    /* set tick pen */
    ui->spectrum_plot->xAxis->setTickPen(pen);
    ui->spectrum_plot->xAxis->setBasePen(pen);
    ui->spectrum_plot->xAxis->setSubTickPen(pen);
    ui->spectrum_plot->yAxis->setTickPen(pen);
    ui->spectrum_plot->yAxis->setBasePen(pen);
    ui->spectrum_plot->yAxis->setSubTickPen(pen);

    /* set attr */
    ui->spectrum_plot->xAxis->setVisible(true);
    ui->spectrum_plot->xAxis->setTickLabels(true);
    ui->spectrum_plot->yAxis->setVisible(true);
    ui->spectrum_plot->yAxis->setTickLabels(true);
    ui->spectrum_plot->xAxis->setLabel("Freqency (MHz)");
    ui->spectrum_plot->yAxis->setLabel("dBm (1000mv)");
    ui->spectrum_plot->yAxis->setRange(-30,70,Qt::AlignCenter);
    ui->spectrum_plot->xAxis->setRange(70,130,Qt::AlignCenter);

    /* set graph */
    QPen draw_pen(Qt::white);
    draw_pen.setWidth(4);

    ui->spectrum_plot->addGraph();
    ui->spectrum_plot->graph()->setPen(QPen(Qt::green));
    ui->spectrum_plot->addGraph();
    ui->spectrum_plot->graph(1)->setPen(QPen(Qt::red));
    ui->spectrum_plot->addGraph();
    ui->spectrum_plot->graph(2)->setPen(draw_pen);
    ui->spectrum_plot->graph(2)->setLineStyle(QCPGraph::lsNone);
    ui->spectrum_plot->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDot,2));

    /* set curson */
    draw_pen.setColor(QColor(239, 41, 41));
    draw_pen.setWidth(4);
    ui->spectrum_plot->addGraph();
    ui->spectrum_plot->graph(3)->setPen(draw_pen);
    ui->spectrum_plot->graph(3)->setLineStyle(QCPGraph::lsNone);
    ui->spectrum_plot->graph(3)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDot,2));

    draw_pen.setColor(QColor(252, 175, 62));
    draw_pen.setWidth(4);
    ui->spectrum_plot->addGraph();
    ui->spectrum_plot->graph(4)->setPen(draw_pen);
    ui->spectrum_plot->graph(4)->setLineStyle(QCPGraph::lsNone);
    ui->spectrum_plot->graph(4)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDot,2));

    draw_pen.setColor(QColor(252, 233, 79));
    draw_pen.setWidth(5);
    ui->spectrum_plot->addGraph();
    ui->spectrum_plot->graph(5)->setPen(draw_pen);
    ui->spectrum_plot->graph(5)->setLineStyle(QCPGraph::lsNone);
    ui->spectrum_plot->graph(5)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDot,2));

    draw_pen.setColor(QColor(173, 127, 168));
    draw_pen.setWidth(5);
    ui->spectrum_plot->addGraph();
    ui->spectrum_plot->graph(6)->setPen(draw_pen);
    ui->spectrum_plot->graph(6)->setLineStyle(QCPGraph::lsNone);
    ui->spectrum_plot->graph(6)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDot,2));
    ui->spectrum_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}
