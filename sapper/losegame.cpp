#include "losegame.h"
#include "ui_losegame.h"

LoseGame::LoseGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoseGame)
{
    ui->setupUi(this);

    QObject::connect(ui->ok,SIGNAL(clicked(bool)),this,SLOT(end()));
}

LoseGame::~LoseGame()
{
    delete ui;
}

void LoseGame::end(void){

    this->close();

}
