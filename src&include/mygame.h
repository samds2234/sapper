#ifndef MYGAME_H
#define MYGAME_H

#include <QVector>
#include <cstdlib>
using std::rand;
using std::srand;
#include <ctime>
using std::time;


class MyGame
{
public:
    MyGame();
    void generate(int,int);
    void setData(int,int,int);
    void expand(int,int);
    void move(int,int);
    QVector<QVector<int>> getField(void);
    QVector<QVector<int>> getActUserField(void);
    bool isWin(void);
signals:
    void gameOver(bool);
private:
    int width;
    int height;
    int numBomb;
    int kol;
    QVector<QVector<int>> field;
    QVector<QVector<int>> actUserField;
};

#endif // MYGAME_H
