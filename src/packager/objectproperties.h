#ifndef OBJECTPROPERTIES_H
#define OBJECTPROPERTIES_H

#include <QDialog>

namespace Ui {
    class ObjectProperties;
}

class ObjectProperties : public QDialog {
    Q_OBJECT
public:
    ObjectProperties(QWidget *parent = 0);
    ~ObjectProperties();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ObjectProperties *m_ui;
};

#endif // OBJECTPROPERTIES_H
