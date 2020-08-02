#include "qdraw.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qdraw w;
    w.showMaximized();
    return a.exec();
}
