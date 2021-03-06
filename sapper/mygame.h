#ifndef MYGAME_H
#define MYGAME_H

#include <QObject>
#include <QVector>
#include <cstdlib>
using std::rand;
using std::srand;
#include <ctime>
using std::time;


class MyGame:public QObject
{
    Q_OBJECT
public:
    explicit MyGame(QObject *parent = 0);
    void generate(int,int);
    void setData(int,int,int);
    void expand(int,int);
    void move(int,int,bool);
    QVector<QVector<int>> getField(void);
    QVector<QVector<int>> getActUserField(void);
    bool isWin(void);
    void boom();
signals:
    void gameOver(bool);
    void changeBomb(int);
private:
    int width;
    int height;
    int numBomb;
    int kol;
    QVector<QVector<int>> field;
    QVector<QVector<int>> actUserField;
    int counting;

};

#endif // MYGAME_H
