//
// Created by jcc on 22-11-29.
//

#include "qt/center_frequency.h"

center_frequency::center_frequency(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::controlOptions)
{
    ui->setupUi(this);
}

center_frequency::~center_frequency() {
    delete ui;
}
