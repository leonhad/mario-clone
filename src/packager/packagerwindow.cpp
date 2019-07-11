#include "packagerwindow.h"
#include "ui_packagerwindow.h"

PackagerWindow::PackagerWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::PackagerWindow)
{
    m_ui->setupUi(this);
}

PackagerWindow::~PackagerWindow()
{
    delete m_ui;
}

void PackagerWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
