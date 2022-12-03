//
// Created by jcc on 22-12-1.
//

#ifndef SPECTRUM_DRAW_H
#define SPECTRUM_DRAW_H

#include "qt/qcustomplot.h"
#include "fix/dataBuffer.h"
#include "fix/fftw_common.h"
#include "fix/source_creator.h"
#include "fix/log.h"
#include "fix/my_math.h"
#include "device/sdrDevice.h"


/* spectrum scope */
class SpectrumScope : public QThread{
    Q_OBJECT
public:
    explicit SpectrumScope(QCustomPlot *customPlot, QCustomPlot *small_plot, QCustomPlot *water_fall_plot,
                           DataBuffer<float> *scope_buffer, int samples, double frequency, double fs,
                           double bandwidth);
    ~SpectrumScope() override;

    void run () override;
    void set_sdr_info(double fs,double frequency,double bandwidth);
    void display(const QVector<double> &x_axis, const QVector<double> &y_axis, bool is_small);
    void run_scope_drawing(bool options);

private:
    QCustomPlot *_fft_scope;
    QCustomPlot *_fft_1Mscope;
    QCustomPlot *_water_scope;

    QCPColorMap *_pubu_scope;
    common_fft *_spectrum_fft;
    DataBuffer<float> *_scope_buffer;
    int _show_size;
    DSPCOMPLEX  *_spectrum_data_buffer_fft;
    DSPCOMPLEX  *_draw;

    DataBuffer<float> *_doFFT_buffer;
    bool _is_drawing;
    mp::log *_log;
    double _fs,_freq,_bandwidth;

    QList<QVector<double>> _water_list;
public slots:
    void buffer_data_loaded();
};


class spectrumProcess : public QThread{
    Q_OBJECT
public:
    explicit spectrumProcess(QCustomPlot *custcomPlot, QCustomPlot *small_plot_1M, QCustomPlot *water_fall);
    ~spectrumProcess() override;

    void run() override;

private:
    SpectrumScope *_spectrum_draw;
    DataBuffer<float> *_buffer_data;
    common_fft *_spectrum_fft;


    DSPCOMPLEX *_spectrumBuffer_fft;
    DSPCOMPLEX  *_iq_data;

    mp::log *_log;
    bool _is_running;

    /* device */
    std::shared_ptr<mp::sdrDevice> _device;
    static void get_rx_data(mp::sdr_transfer *transfer);

    double _RF_sample_rate;
    double _RF_band_width;
    double _RF_frequency;
    double _RF_gain;

public slots:
    void clicked_status(bool);
    void changed_rf(double span,double frequency);
    void gain_change(int);

signals:
    void buffer_data_load();
    void is_run(bool);
};





#endif //SPECTRUM_DRAW_H
