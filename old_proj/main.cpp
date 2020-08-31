//#include "widget.h"
//#include "insertionwidget.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Widget w;
    // w.show();
//    insertionWidget b;
//    b.show();
    MainWindow w;
    w.show();

    return a.exec();
}
