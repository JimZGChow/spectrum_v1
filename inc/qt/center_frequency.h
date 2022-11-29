//
// Created by jcc on 22-11-29.
//

#ifndef SPECTRUM_CENTER_FREQUENCY_H
#define SPECTRUM_CENTER_FREQUENCY_H
#include "qt/ui_control_option.h"

namespace Ui{
    class controlOptions;
}


class center_frequency : public QDialog
{
    Q_OBJECT

public:
    center_frequency(QWidget *parent = 0);
    ~center_frequency();

private:
    Ui::controlOptions *ui;
};


#endif //SPECTRUM_CENTER_FREQUENCY_H
