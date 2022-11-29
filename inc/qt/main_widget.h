//
// Created by jcc on 22-11-29.
//

#ifndef SPECTRUM_MAIN_WIDGET_H
#define SPECTRUM_MAIN_WIDGET_H

#include <QWidget>
#include "ui_main_widget.h"
#include "qt/center_frequency.h"


QT_BEGIN_NAMESPACE
namespace Ui { class main_widget; }
QT_END_NAMESPACE

class main_widget : public QWidget {
Q_OBJECT

public:
    explicit main_widget(QWidget *parent = nullptr);

    ~main_widget() override;

private:
    Ui::main_Widget *ui;
    center_frequency *cf_ui;
};


#endif //SPECTRUM_MAIN_WIDGET_H
