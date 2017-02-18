#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include <QObject>
#include <QGraphicsScene>
#include <QVector>
#include "mygame.h"
#include <QBrush>
#include <QRect>
#include <QColor>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>

class Visualization : public QGraphicsScene
{
    Q_OBJECT
public:
    Visualization();
    void setData(int,int,int);
    void drawField(void);
public slots:
    void boom(void);
signals:
    void gameOver(bool);
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *);
private:
    int width;
    int height;
    int numBomb;
    QVector<QVector<int>> field;
    QVector<QVector<int>> actUserField;
    int sizeOfSquare;
    MyGame game;
    bool start;
};

#endif // VISUALIZATION_H
