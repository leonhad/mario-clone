#ifndef MAPEDITORWINDOW_H
#define MAPEDITORWINDOW_H

#include <QtWidgets/QMainWindow>

namespace Ui {
    class MapEditorWindow;
}

class MapEditorWindow : public QMainWindow {
    Q_OBJECT
public:
    MapEditorWindow(QWidget *parent = 0);
    ~MapEditorWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MapEditorWindow *m_ui;
};

#endif // MAPEDITORWINDOW_H
