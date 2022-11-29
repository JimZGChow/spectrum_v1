#include <QApplication>
#include "qt/main_widget.h"



int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto *main_window = new main_widget();
    main_window->show();
    return QApplication::exec();
}
