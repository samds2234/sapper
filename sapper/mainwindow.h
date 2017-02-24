#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "visualization.h"
#include <QString>
#include <QFile>
#include <QTimer>
#include "dialog.h"
#include "losegame.h"
#include <QPalette>
#include "turning.h"
#include "statistic.h"
#include <QTextStream>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void writeFile(bool);
public slots:
    void stat(void);
    void settings(void);
    void newGame(void);
    void timerHandler(void);
    void origin(void);
    void go(bool);
    void setData(int,int,int);
    void disp(void);
    void dispStat(void);
    void chBH(int);

private:
    Ui::MainWindow *ui;
    Visualization viz;
    int width;
    int height;
    int numBomb;
    int cnt;
    QTimer t;
    QFile file;
    Dialog win;
    LoseGame lose;
    Turning tun;
    Statistic statG;
};

#endif // MAINWINDOW_H
