#include "objectproperties.h"
#include "ui_objectproperties.h"

ObjectProperties::ObjectProperties(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::ObjectProperties)
{
    m_ui->setupUi(this);
}

ObjectProperties::~ObjectProperties()
{
    delete m_ui;
}

void ObjectProperties::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
