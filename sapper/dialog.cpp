#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QObject::connect(ui->ok,SIGNAL(clicked(bool)),this,SLOT(end()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::end(void){

    this->close();

}
