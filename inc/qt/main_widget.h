//
// Created by jcc on 22-11-29.
//

#ifndef SPECTRUM_MAIN_WIDGET_H
#define SPECTRUM_MAIN_WIDGET_H

#include <QWidget>
#include "ui_main_widget.h"



QT_BEGIN_NAMESPACE
namespace Ui { class main_widget; }
QT_END_NAMESPACE

class main_widget : public QWidget {
Q_OBJECT

public:
    explicit main_widget(QWidget *parent = nullptr);

    ~main_widget() override;

public slots:
    void span_change(int);
    void start_change(int);
    void end_change(int);

protected:

private:
    Ui::main_Widget *ui;

private:
    void spectrum_draw_init();
};


#endif //SPECTRUM_MAIN_WIDGET_H
