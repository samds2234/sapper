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
#include <QGraphicsTextItem>

class Visualization : public QGraphicsScene
{
    Q_OBJECT
public:
    Visualization();
    void setData(int,int,int);
    void drawField(void);
public slots:
    void end(bool);

signals:
    void gameOver(bool);
    void begin(void);
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
