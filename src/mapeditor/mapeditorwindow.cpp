#include "mapeditorwindow.h"
#include "ui_mapeditorwindow.h"

MapEditorWindow::MapEditorWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MapEditorWindow)
{
    m_ui->setupUi(this);
}

MapEditorWindow::~MapEditorWindow()
{
    delete m_ui;
}

void MapEditorWindow::changeEvent(QEvent *e)
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
