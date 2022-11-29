//
// Created by jcc on 22-11-29.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_widget.h" resolved

#include "qt/main_widget.h"


main_widget::main_widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::main_Widget){
    cf_ui  = new center_frequency();
    ui->setupUi(this);
    /* control ui widget */
    ui->splitter->setStretchFactor(0,8);
    ui->splitter->setStretchFactor(1,4);
    ui->splitter->setStretchFactor(2,1);

    ui->splitter_2->setStretchFactor(0,5);
    ui->splitter_2->setStretchFactor(1,1);

    ui->splitter_3->setStretchFactor(0,3);
    ui->splitter_3->setStretchFactor(1,1);

    /* set time */
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

}

main_widget::~main_widget() {
    delete ui;
    delete cf_ui;
}
