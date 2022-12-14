//
// Created by jcc on 22-11-29.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_widget.h" resolved

#include "qt/main_widget.h"
#include "qdebug.h"
#include "fix/my_math.h"

main_widget::main_widget(QWidget *parent) :
        QWidget(parent),
        _time(new QTimer),
        ui(new Ui::main_Widget){
    ui->setupUi(this);
    ui->spinBox_end->setValue(102);
    /* set time */
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dockWidget->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetFloatable);
    /* process plot setup */

    this->_time->setInterval(1000);
    this->_time->start();
    this->spectrum_draw_init();
    this->spectrum_1M_draw_init();
    this->waterFall_draw_init();
    this->comboBox_init();


    this -> _isrunning = false;
    this -> _spectrum_process = new spectrumProcess(ui->spectrum_plot, ui->plot_1M, ui->waterfall_widget);
    connect(ui->spinBox_span, SIGNAL(valueChanged(int)),
            this, SLOT(span_change(int)));
    connect(ui->spinBox_start, SIGNAL(valueChanged(int)),
            this, SLOT(start_change(int)));
    connect(ui->spinBox_end, SIGNAL(valueChanged(int)),
            this, SLOT(end_change(int)));
    connect(ui->spinBox_average, SIGNAL(valueChanged(int)),
            this->_spectrum_process,SLOT(averageChanged(int)));
    connect(ui->comboBox_fft_size, SIGNAL(currentIndexChanged(int)),
            this->_spectrum_process,SLOT(fft_size_changed(int)));
    connect(ui->comboBox_window,SIGNAL(currentIndexChanged(int)),
            this->_spectrum_process,SLOT(fft_window_changed(int)));
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
            this->_spectrum_process,SLOT(gain_change(int)));
    connect(ui->pushButton,SIGNAL(clicked()),
            this,SLOT(click()));
    connect(this,SIGNAL(click_status(bool)),
            this->_spectrum_process,SLOT(clicked_status(bool)));
    connect(this->_spectrum_process,SIGNAL(is_run(bool)),
            this,SLOT(is_running(bool)));
    connect(this, SIGNAL(change_rf(double, double)),
            this->_spectrum_process,SLOT(changed_rf(double, double)));
    connect(this->_time, SIGNAL(timeout()),
            this,SLOT(time_out()));
}

main_widget::~main_widget() {
    delete ui;
    delete _time;
}

void main_widget::click() {
    if(! this->_isrunning){
        this->_isrunning = true;
    }
    else{
        this->_isrunning = false;
    }
    emit(click_status(this->_isrunning));
}

void main_widget::is_running(bool is_run) {
    this->_isrunning = is_run;
    if(is_run){
        ui->pushButton -> setStyleSheet(QString::fromUtf8("background-color: rgb(0, 164, 0);"));
    }
    else{
        ui->pushButton -> setStyleSheet(QString::fromUtf8("background-color: rgb(164, 0, 0)"));
    }
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
    emit change_rf(value,center_frequency);
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

void main_widget::comboBox_init() {
    ui->comboBox_fft_size->addItem("256");
    ui->comboBox_fft_size->addItem("512");
    ui->comboBox_fft_size->addItem("1024");
    ui->comboBox_fft_size->addItem("2048");
    ui->comboBox_fft_size->setCurrentIndex(SIZE1024);
    ui->comboBox_window->addItem("hamming");
    ui->comboBox_window->addItem("hanning");
    ui->comboBox_window->addItem("black-man");
    ui->comboBox_window->addItem("no-window");
    ui->comboBox_window->setCurrentIndex(WINDOWHAMMING);

}

/**
 * Spectrum process plot setup
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

void main_widget::spectrum_1M_draw_init() {
    QPen pen = ui->plot_1M->xAxis->basePen();
    pen.setColor(Qt::white);
    /* back ground */
    ui->plot_1M->setBackground(QColor(85, 87, 83));
    /* x y label */
    ui->plot_1M->xAxis->setLabelColor(Qt::white);
    ui->plot_1M->yAxis->setLabelColor(Qt::white);
    ui->plot_1M->xAxis->setTickLabelColor(Qt::white);
    ui->plot_1M->yAxis->setTickLabelColor(Qt::white);

    /* set tick pen */
    ui->plot_1M->xAxis->setTickPen(pen);
    ui->plot_1M->xAxis->setBasePen(pen);
    ui->plot_1M->xAxis->setSubTickPen(pen);
    ui->plot_1M->yAxis->setTickPen(pen);
    ui->plot_1M->yAxis->setBasePen(pen);
    ui->plot_1M->yAxis->setSubTickPen(pen);

    /* set attr */
    ui->plot_1M->xAxis->setVisible(true);
    ui->plot_1M->xAxis->setTickLabels(true);
    ui->plot_1M->yAxis->setVisible(true);
    ui->plot_1M->yAxis->setTickLabels(true);
    ui->plot_1M->xAxis->setLabel("Freqency (MHz)");
    ui->plot_1M->yAxis->setLabel("dBm (1000mv)");
    ui->plot_1M->yAxis->setRange(-30,70,Qt::AlignCenter);
    ui->plot_1M->xAxis->setRange(70,130,Qt::AlignCenter);

    /* set graph */
    QPen draw_pen(Qt::white);
    draw_pen.setWidth(4);

    ui->plot_1M->addGraph();
    ui->plot_1M->graph()->setPen(QPen(Qt::yellow));
    ui->plot_1M->addGraph();
    ui->plot_1M->graph(1)->setPen(QPen(Qt::red));
    ui->plot_1M->addGraph();
    ui->plot_1M->graph(2)->setPen(draw_pen);
    ui->plot_1M->graph(2)->setLineStyle(QCPGraph::lsNone);
    ui->plot_1M->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDot,2));

    /* set curson */
    draw_pen.setColor(QColor(239, 41, 41));
    draw_pen.setWidth(4);
    ui->plot_1M->addGraph();
    ui->plot_1M->graph(3)->setPen(draw_pen);
    ui->plot_1M->graph(3)->setLineStyle(QCPGraph::lsNone);
    ui->plot_1M->graph(3)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDot,2));

    draw_pen.setColor(QColor(252, 175, 62));
    draw_pen.setWidth(4);
    ui->plot_1M->addGraph();
    ui->plot_1M->graph(4)->setPen(draw_pen);
    ui->plot_1M->graph(4)->setLineStyle(QCPGraph::lsNone);
    ui->plot_1M->graph(4)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDot,2));

    draw_pen.setColor(QColor(252, 233, 79));
    draw_pen.setWidth(5);
    ui->plot_1M->addGraph();
    ui->plot_1M->graph(5)->setPen(draw_pen);
    ui->plot_1M->graph(5)->setLineStyle(QCPGraph::lsNone);
    ui->plot_1M->graph(5)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDot,2));

    draw_pen.setColor(QColor(173, 127, 168));
    draw_pen.setWidth(5);
    ui->plot_1M->addGraph();
    ui->plot_1M->graph(6)->setPen(draw_pen);
    ui->plot_1M->graph(6)->setLineStyle(QCPGraph::lsNone);
    ui->plot_1M->graph(6)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDot,2));
    ui->plot_1M->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

void main_widget::waterFall_draw_init() {
    QPen pen = ui->waterfall_widget->xAxis->basePen();
    pen.setColor(Qt::white);
    ui->waterfall_widget->yAxis->setRangeReversed(true);
    /* back ground */
    ui->waterfall_widget->setBackground(QColor(85, 87, 83));
    ui->waterfall_widget->xAxis->grid()->setVisible(false);
    ui->waterfall_widget->yAxis->grid()->setVisible(false);
    ui->waterfall_widget->xAxis->setTicks(false);
    ui->waterfall_widget->yAxis->setTicks(false);
    ui->waterfall_widget->xAxis->setSubTicks(false);
    ui->waterfall_widget->yAxis->setSubTicks(false);

    /* x y label */
    ui->waterfall_widget->xAxis->setLabelColor(Qt::white);
    ui->waterfall_widget->yAxis->setLabelColor(Qt::white);
    ui->waterfall_widget->xAxis->setTickLabelColor(Qt::white);
    ui->waterfall_widget->yAxis->setTickLabelColor(Qt::white);

    ui->waterfall_widget->xAxis->setRange(70,130,Qt::AlignCenter);

    ui->waterfall_widget->xAxis->setLabel("Freqency (MHz)");
    ui->waterfall_widget->yAxis->setLabel("Time (s)");

    ui->waterfall_widget->addGraph();
    ui->waterfall_widget->graph(0)->setPen(QPen(Qt::blue));


}

/* set time clock calculate time */
void main_widget::time_out() {
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}










