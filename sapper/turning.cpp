#include "turning.h"
#include "ui_turning.h"

Turning::Turning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Turning)
{
    ui->setupUi(this);
    ui->comboBoxDif->addItem("Easy");
    ui->comboBoxDif->addItem("Difficult");
    QString str="Easy";

    QObject::connect(ui->comboBoxDif,SIGNAL(currentIndexChanged(QString)),this,SLOT(remember(QString)));
    QObject::connect(ui->ok,SIGNAL(clicked(bool)),this,SLOT(setTur()));
    QObject::connect(ui->ret,SIGNAL(clicked(bool)),this,SLOT(end()));
}

Turning::~Turning()
{
    delete ui;
}

void Turning::remember(QString s){
    str=s;
}

void Turning::end(void){
    this->close();
}

void Turning::setTur(void){

   if(str=="Easy") emit getData(10,10,17);
   else if(str=="Difficult") emit getData(15,15,40);

   this->close();
}


