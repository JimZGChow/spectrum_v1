//
// Created by jcc on 22-12-1.
//

#ifndef SPECTRUM_DRAW_H
#define SPECTRUM_DRAW_H

#include "qt/qcustomplot.h"
#include "fix/dataBuffer.h"
#include "fix/fftw_common.h"
#include "fix/source_creator.h"



/* spectrum scope */
class SpectrumScope : public QThread{
public:
    SpectrumScope(QCustomPlot *customPlot);
    ~SpectrumScope();

    void display(QVector<double> x_axe,QVector<double> y_axe);

private:
    QCustomPlot *_fft_scope;

};


class spectrumProcess : public QThread{
    Q_OBJECT
public:
    spectrumProcess(QCustomPlot *custcomPlot, DataBuffer<double> *buffer_data,
                    double input_sample_rate, double average_count);
    ~spectrumProcess() override;

    void run() override;

private:
    SpectrumScope *_spectrum_draw;
    DataBuffer<double> *_buffer_data;
    common_fft *_spectrum_fft;
    double _sample_rate;
    int _sample_count;
    double _average_cout;

    DSPCOMPLEX *_spectrumBuffer_fft;
    SINCOS *_cos10k;

    bool _is_running;

public slots:
    void clicked_status(bool);
};





#endif //SPECTRUM_DRAW_H
