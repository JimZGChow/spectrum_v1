//
// Created by jcc on 22-12-1.
//

#ifndef SPECTRUM_DRAW_H
#define SPECTRUM_DRAW_H

#include "qt/qcustomplot.h"
#include "fix/dataBuffer.h"
#include "fix/fftw_common.h"
#include "fix/source_creator.h"
#include "device/sdrDevice.h"


/* spectrum scope */
class SpectrumScope : public QThread{
public:
    explicit SpectrumScope(QCustomPlot *customPlot);
    ~SpectrumScope() override;

    void display(QVector<double> x_axis, QVector<double> y_axis);

private:
    QCustomPlot *_fft_scope;

};


class spectrumProcess : public QThread{
    Q_OBJECT
public:
    explicit spectrumProcess(QCustomPlot *custcomPlot);
    ~spectrumProcess() override;

    void run() override;

private:
    SpectrumScope *_spectrum_draw;
    DataBuffer<double> *_buffer_data;
    common_fft *_spectrum_fft;
    double _sample_rate;


    DSPCOMPLEX *_spectrumBuffer_fft;
    SINCOS *_cos10k;

    bool _is_running;

    /* device */
    std::shared_ptr<mp::sdrDevice> _device;
    static void get_rx_data(mp::sdr_transfer *transfer);
public slots:
    void clicked_status(bool);
};





#endif //SPECTRUM_DRAW_H
