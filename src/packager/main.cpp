#include <QApplication>
#include "packagerwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PackagerWindow w;
    w.show();
    return a.exec();
}
