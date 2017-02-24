#include "statistic.h"
#include "ui_statistic.h"

Statistic::Statistic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistic)
{
    ui->setupUi(this);
    str="";

    QFile file;
    file.setFileName("stat.dat");
    file.open(QIODevice::ReadOnly);
    QString temp;
    temp=file.readLine();
    str+="Кол-во игр:"+temp+"\n";
    temp=file.readLine();
    str+="Кол-во побед:"+temp+"\n";
    temp=file.readLine();
    str+="Лучшее время:"+temp+"\n";

    ui->console->setText(str);

    file.close();

    QObject::connect(ui->ok,SIGNAL(clicked(bool)),this,SLOT(end()));

}

Statistic::~Statistic()
{
    delete ui;
}

void Statistic::end(void){

    this->close();

}
