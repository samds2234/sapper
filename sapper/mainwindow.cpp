#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->game->setScene(&viz);

    numBomb=17;
    width=10;
    height=10;
    cnt=0;

    ui->lcdBomb->display(numBomb);


    QObject::connect(ui->actionNewGame,SIGNAL(triggered(bool)),this,SLOT(newGame()));
    QObject::connect(&t,SIGNAL(timeout()),this,SLOT(timerHandler()));
    QObject::connect(&viz,SIGNAL(begin()),this,SLOT(origin()));
    QObject::connect(&viz,SIGNAL(gameOver(bool)),this,SLOT(go(bool)));
    QObject::connect(&tun,SIGNAL(getData(int,int,int)),this,SLOT(setData(int,int,int)));
    QObject::connect(ui->actionSettings,SIGNAL(triggered(bool)),this,SLOT(disp()));
    QObject::connect(ui->actionStat,SIGNAL(triggered(bool)),this,SLOT(dispStat()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newGame(void){

    viz.setData(width,height,numBomb);
    cnt=0;
    ui->lcdTime->display(cnt);
}

void MainWindow::stat(void){

}

void MainWindow::settings(void){

}

void MainWindow::origin(void){

    t.start(1000);

}

void MainWindow::timerHandler(void){

    cnt++;
    ui->lcdTime->display(cnt);

}

void MainWindow::go(bool a){

    t.stop();
    cnt=0;

    if(a){
       win.show();

    }
    else lose.show();
}

void MainWindow::setData(int w, int h, int num){

    width=w;
    height=h;
    numBomb=num;

}

void MainWindow::disp(void){

    tun.show();

}

void MainWindow::dispStat(void){

    statG.show();

}
