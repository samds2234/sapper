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

    viz.setData(width,height,numBomb);

    ui->lcdBomb->display(numBomb);


    QObject::connect(ui->actionNewGame,SIGNAL(triggered(bool)),this,SLOT(newGame()));
    QObject::connect(&t,SIGNAL(timeout()),this,SLOT(timerHandler()));
    QObject::connect(&viz,SIGNAL(begin()),this,SLOT(origin()));
    QObject::connect(&viz,SIGNAL(gameOver(bool)),this,SLOT(go(bool)));
    QObject::connect(&tun,SIGNAL(getData(int,int,int)),this,SLOT(setData(int,int,int)));
    QObject::connect(ui->actionSettings,SIGNAL(triggered(bool)),this,SLOT(disp()));
    QObject::connect(ui->actionStat,SIGNAL(triggered(bool)),this,SLOT(dispStat()));
    QObject::connect(&viz,SIGNAL(changeBomb(int)),this,SLOT(chBH(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newGame(void){

    viz.setData(width,height,numBomb);
    cnt=0;
    ui->lcdTime->display(cnt);
    ui->lcdBomb->display(numBomb);
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


    if(a){
       win.show();
       writeFile(true);

    }
    else{

        lose.show();
        writeFile(false);
    }

     cnt=0;
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

void MainWindow::writeFile(bool winGame){

    QFile file;
    file.setFileName("stat.dat");
    file.open(QIODevice::ReadWrite);
    QString temp;
    QString str;

    int num1;
    int num2;
    int num3;

    temp=file.readLine();
    num1=temp.toInt();
    temp=file.readLine();
    num2=temp.toInt();
    temp=file.readLine();
    num3=temp.toInt();

    if(cnt<num3&&winGame) num3=cnt;
    num1++;
    if(winGame)num2++;
    temp.setNum(num1);
    str+=temp+"\n";
    temp.setNum(num2);
    str+=temp+"\n";
    temp.setNum(num3);
    str+=temp;
    file.reset();
    file.close();
    file.open(QIODevice::WriteOnly|QIODevice::Truncate);
    QTextStream out(&file);
    out.flush();
    out<<str;
    file.close();
    statG.update1();

}

void MainWindow::chBH(int a){

    ui->lcdBomb->display(a);

}
