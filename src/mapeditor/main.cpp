#include <QApplication>
#include "mapeditorwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MapEditorWindow w;
    w.show();
    return a.exec();
}
