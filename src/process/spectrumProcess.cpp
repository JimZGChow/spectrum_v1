//
// Created by jcc on 22-12-1.
//
#include "process/spectrumProcrss.h"

#define DATABUFF_SIZE 30*1024
#define MAXWATER_FALL_SIZE 50

spectrumProcess::spectrumProcess(QCustomPlot *custcomPlot, QCustomPlot *small_plot_1M, QCustomPlot *water_fall) {
    this->_RF_sample_rate = 2.5e6;
    this->_RF_band_width  = 2.0e6;
    this->_RF_frequency   = 100.5e6;
    this->_RF_gain        = 50;

    _buffer_data    = new DataBuffer<float>(DATABUFF_SIZE);
    _spectrum_draw  = new SpectrumScope(custcomPlot, small_plot_1M, water_fall, _buffer_data, 1024,
                                        _RF_frequency, _RF_sample_rate, _RF_band_width);
    _spectrum_fft       = new common_fft(1024);
    _log                = new mp::log();
    _iq_data            = fftwf_alloc_complex(sizeof(DSPCOMPLEX) * 1024);
    _window_type        = 0;
    _window_coefficient = new float[1024];
    get_window_coefficient(_window_coefficient,1024,_window_type);

    this->_spectrumBuffer_fft = _spectrum_fft->getVector();
    this->_is_running = false;
    connect(this, SIGNAL(buffer_data_load()),
            this->_spectrum_draw, SLOT(buffer_data_loaded()));

}

spectrumProcess::~spectrumProcess() {
    this->_log->DEBUG("~spectrumProcess ...");
    delete _buffer_data;
    delete _spectrum_draw;
    delete _spectrum_fft;
    delete _log;
    delete[] _window_coefficient;
     fftwf_free(_iq_data);
}

void spectrumProcess::run() {
    try {

        _is_running = true;
        _buffer_data->flash_data_buffer();
        _device->sdr_check(0);
        _device->sdr_set_gain(_RF_gain,0);
        _device->sdr_set_bandwidth(_RF_band_width,0);
        _device->sdr_set_samplerate(_RF_sample_rate,0);
        _device->sdr_set_lo_frequency(_RF_frequency);
        _device->sdr_set_rx_samplecnt(1024); /* sample cnt */
        _device->sdr_start_rx(spectrumProcess::get_rx_data, this);

        while(_is_running){
            usleep(10);
        }

    }
    catch (...){
        this->_log->ERROR("Spectrum Process failed");
    }

}

void spectrumProcess::clicked_status(bool is_on) {
    this->_is_running = is_on;
    if(is_on){
        try {
            _device = mp::sdrDevice::make_sdrDevice("iio","ip:192.168.1.10");
            if(_device->sdr_open()){
                emit is_run(true);
                _spectrum_draw->start();
                this->start();

            }
            else{
                emit is_run(false);
            }
        }
       catch (...){
           this->_log->ERROR("Make sdr device Failed ...");
       }

    }
    else{
        try {
            emit is_run(false);
            _device->sdr_close();
            _buffer_data->flash_data_buffer();
            msleep(10);
            _spectrum_draw->run_scope_drawing(is_on);
        }
       catch (...){
           this->_log->ERROR("Close sdr device Failed ...");
       }
    }

}

/* set window */
bool is_change = 1;
void spectrumProcess::get_rx_data(mp::sdr_transfer *transfer) {
    auto *obj = (spectrumProcess *)transfer->user;
    obj->_iq_save.save_iq_data(transfer->data,transfer->length);
    try {
        for(int i = 0;i < transfer->length;i++){
            obj->_iq_data[i][0] = transfer->data[2*i] * obj->_window_coefficient[i];
            obj->_iq_data[i][1] = transfer->data[2*i+1] * obj->_window_coefficient[i];
        }
        auto load_size = obj->_buffer_data->put_data_into_buffer(obj->_iq_data,2 * transfer->length);
        if(load_size == transfer->length * 2){
            emit obj->buffer_data_load();
            if(is_change){
//                obj->_device->sdr_set_lo_frequency(90.1e6);
                is_change = 0;
            }
            else{
//                obj->_device->sdr_set_lo_frequency(100.1e6);
                is_change = 1;

            }
        }
    }
    catch (...){
        obj->_log->ERROR("get_rx_data Failed ...");
    }

}

void spectrumProcess::changed_rf(double span, double frequency) {
    if(_is_running){
        _device->sdr_set_lo_frequency(frequency);
        _device->sdr_set_bandwidth(span * 1e6,0);
        _device->sdr_set_samplerate(span * 1e6,0);
        _spectrum_draw->set_sdr_info(span * 1e6,frequency,span * 1e6);
    }
}

void spectrumProcess::gain_change(int value) {
    if(_is_running){
        _device->sdr_set_gain(value,0);
    }
}

void spectrumProcess::fft_size_changed(int value) {
    this->_spectrum_draw->set_fft_size(value);
}

void spectrumProcess::averageChanged(int value) {
    this->_spectrum_draw->set_fft_average(value);
}

void spectrumProcess::fft_window_changed(int value) {
    get_window_coefficient(_window_coefficient,1024,value);
}

/********************************************************
 * It's different opject
 * ******************************************************/
SpectrumScope::SpectrumScope(QCustomPlot *customPlot, QCustomPlot *small_plot, QCustomPlot *water_fall_plot,
                             DataBuffer<float> *scope_buffer, int samples, double frequency, double fs,
                             double bandwidth) {
    this->_fft_scope    = customPlot;
    this->_fft_1Mscope  = small_plot;
    this->_water_scope  = water_fall_plot;
    this->_scope_buffer = scope_buffer;
    this->_show_size    = samples;
    this->_is_drawing   = true;
    this->_fs           = fs;
    this->_freq         = frequency;
    this->_bandwidth    = bandwidth;
    this->_average_point = 5;

    _spectrum_fft = new common_fft(samples);
    _doFFT_buffer = new DataBuffer<float>(DATABUFF_SIZE);
    _log          = new mp::log();
    _draw         = fftwf_alloc_complex(sizeof(DSPCOMPLEX) * _show_size);
    _pubu_scope   = new QCPColorMap(water_fall_plot->yAxis,water_fall_plot->xAxis);

    _spectrum_data_buffer_fft = _spectrum_fft ->getVector();
    _pubu_scope->data()->setSize(MAXWATER_FALL_SIZE , _show_size);
}

SpectrumScope::~SpectrumScope() {
    delete _spectrum_fft;
    delete _doFFT_buffer;
    delete _log;
    delete _pubu_scope;
    fftwf_free(_draw);
}

void SpectrumScope::display(const QVector<double> &x_axis, const QVector<double> &y_axis, bool is_small) {
    try {
        if(not is_small){
            this->_fft_scope->graph(0)->setData(x_axis, y_axis);
            this->_fft_scope->xAxis->rescale();
            this->_fft_scope->replot(QCustomPlot::rpQueuedReplot);
        }
        else{
            this->_fft_1Mscope->graph(0)->setData(x_axis, y_axis);
            this->_fft_1Mscope->xAxis->rescale();
            this->_fft_1Mscope->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    catch (...){
        this->_log->ERROR("Display error ...");
    }
}

void SpectrumScope::buffer_data_loaded() {
    try {
        if(_scope_buffer->get_data_buffer_read_available() > 0){
            uint32_t get_data = _scope_buffer->get_data_from_buffer(_spectrum_data_buffer_fft,2 * _show_size);
            if(get_data != _show_size * 2){
                qDebug() << "buffer_loaded "<<get_data;
                return;
            }
            else if(_doFFT_buffer->get_data_buffer_write_available() > 0){
                _spectrum_fft->do_FFT();
                _spectrum_fft->do_Shift();
                _doFFT_buffer->put_data_into_buffer(_spectrum_data_buffer_fft,2 * _show_size);
            }
        }
    }
    catch (...){
        this->_log->ERROR("Buffer_data_loaded failed ...");
    }
}

void SpectrumScope::run() {
    try {
        _doFFT_buffer->flash_data_buffer();
        _is_drawing = true;
        while(_is_drawing){
            if(_doFFT_buffer->get_data_buffer_read_available() > 0){
                uint32_t read_size = _doFFT_buffer->get_data_from_buffer(_draw,2 * _show_size);
                if(read_size == 2 * _show_size){
                    this->draw_main_scope();
                    this->draw_1M_scope();
                    this->draw_water_fall_scope();
                }
            }
            msleep(80);
        }
    }
    catch (...){
        this->_log->ERROR("Spectrum scope failed ...");
    }
}

void SpectrumScope::run_scope_drawing(bool options) {
    this->_is_drawing = options;
    if(not options){
        this->_doFFT_buffer->flash_data_buffer();
    }
}

void SpectrumScope::set_sdr_info(double fs, double frequency, double bandwidth) {
    this->_fs = fs;
    this->_freq = frequency;
    this->_bandwidth = bandwidth;
}

void SpectrumScope::set_fft_size(int fft_size) {
    _show_size = fft_size;
}

void SpectrumScope::set_fft_average(int value) {
    _average_point = value;
}

void SpectrumScope::draw_main_scope() {
    QVector<double> x_fft(_show_size);
    for(int i = 0; i < _show_size;i++){
        x_fft[i] = ((_freq - _fs / 2) + (_fs / 1024 * i)) / 1e6;
    }
    QVector<double> y_fft(_show_size);
    for(int i = 0; i < _show_size;i++){
        double M = sqrt(_draw[i][0]*_draw[i][0] + _draw[i][1]*_draw[i][1]);
        double A = 2 * M / 1024;
        y_fft[i] = 20 * log10(A / 1e3);
    }
    fft_data_average(y_fft,_average_point,_show_size);
    this->display(x_fft, y_fft, false);
    if(_water_list.size() > MAXWATER_FALL_SIZE-1){
        _water_list.removeLast();
    }
    _water_list.prepend(y_fft);
}

void SpectrumScope::draw_1M_scope() {
/* just process 1M */
    double step = _fs / 1024;
    int draw_number = (int)(1e6 / step);
    draw_number = (draw_number % 2 == 1) ?  draw_number + 1 : draw_number;
    QVector<double> x1_fft(draw_number);
    for(int i = 0,j = ((_show_size / 2) - (draw_number/2)); i < draw_number;i++,j++){
        x1_fft[i] = ((_freq - _fs / 2) + (_fs / 1024 * j)) / 1e6;
    }
    QVector<double> y1_fft(draw_number);
    for(int i = 0,j = ((_show_size / 2) - (draw_number/2)); i < draw_number;i++,j++){
        double M = sqrt(_draw[j][0]*_draw[j][0] + _draw[j][1]*_draw[j][1]);
        double A = 2 * M / 1024;
        y1_fft[i] = 20 * log10(A / 1e3);
    }

    this->display(x1_fft,y1_fft,true);
}

void SpectrumScope::draw_water_fall_scope() {
    for(int i=0;i<_water_list.size();i++){
        for(int j=0;j<_show_size;j++){
            _pubu_scope->data()->setCell(i,j, qRound(_water_list.at(i).at(j)));
        }
    }
    _pubu_scope->setGradient(QCPColorGradient::gpSpectrum);
    _pubu_scope->rescaleDataRange(true);
    this->_water_scope->rescaleAxes();
    this->_water_scope->replot(QCustomPlot::rpQueuedReplot);
}



