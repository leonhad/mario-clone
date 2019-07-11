#ifndef PACKAGERWINDOW_H
#define PACKAGERWINDOW_H

#include <QMainWindow>

namespace Ui {
    class PackagerWindow;
}

class PackagerWindow : public QMainWindow {
    Q_OBJECT
public:
    PackagerWindow(QWidget *parent = 0);
    ~PackagerWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::PackagerWindow *m_ui;
};

#endif // PACKAGERWINDOW_H
