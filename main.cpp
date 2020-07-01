#include "widget.h"
#include "insertionwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Widget w;
    // w.show();
    insertionWidget b;
    b.show();

    return a.exec();
}
