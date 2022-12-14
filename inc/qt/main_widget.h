//
// Created by jcc on 22-11-29.
//

#ifndef SPECTRUM_MAIN_WIDGET_H
#define SPECTRUM_MAIN_WIDGET_H

#include <QWidget>
#include "ui_main_widget.h"
#include "fix/dataBuffer.h"
#include "process/spectrumProcrss.h"

QT_BEGIN_NAMESPACE
namespace Ui { class main_widget; }
QT_END_NAMESPACE


enum fft_size_e{
    SIZE256,
    SIZE512,
    SIZE1024,
    SIZE2048
};

enum fft_window_e{
    WINDOWHAMMING,
    WINDOWHANNING,
    WINDOWBLACKMAN,
    NOWINDOW
};

class main_widget : public QWidget {
Q_OBJECT

public:
    explicit main_widget(QWidget *parent = nullptr);

    ~main_widget() override;

public slots:
    void span_change(int);
    void start_change(int);
    void end_change(int);
    void click();
    void time_out();
    void is_running(bool);
signals:
    void click_status(bool);
    void change_rf(double span,double frequency);

protected:

private:
    Ui::main_Widget *ui;
    spectrumProcess *_spectrum_process;
    QTimer *_time;
    bool _isrunning;


private:
    void spectrum_draw_init();
    void spectrum_1M_draw_init();
    void waterFall_draw_init();
    void comboBox_init();
};


#endif //SPECTRUM_MAIN_WIDGET_H
