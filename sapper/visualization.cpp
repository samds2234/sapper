#include "visualization.h"

Visualization::Visualization()
{
    width=10;
    height=10;
    numBomb=10;
    start=false;

    sizeOfSquare=20;

    field.resize(width);
    actUserField.resize(width);

    for(int i=0;i<width;++i){
        field[i].resize(height);
        actUserField[i].resize(height);
    }

    for(int i=0;i<width;++i){
        for(int j=0;j<height;++j){
            field[i][j]=0;
            actUserField[i][j]=0;
        }
    }

    game.setData(width,height,numBomb);

    QObject::connect(&game,SIGNAL(gameOver(bool)),this,SLOT(end(bool)));

    drawField();


}

void Visualization::setData(int w, int h, int num){

    width=w;
    height=h;
    numBomb=num;

    field.resize(width);
    actUserField.resize(height);

    for(int i=0;i<width;++i){

        field[i].resize(height);
        actUserField[i].resize(height);

    }

    for(int i=0;i<width;++i){
        for(int j=0;j<height;++j){
            field[i][j]=0;
            actUserField[i][j]=0;
        }
    }

    game.setData(width,height,numBomb);

    drawField();

    start=false;

}

void Visualization::drawField(void){

  for(int i=0;i<width;++i){
      for(int j=0;j<height;++j){
          if(actUserField[i][j]==0){
              QColor col;
              col.setRgb(169,169,169);
              QBrush br(col);
              QPen pen;
              pen.setColor(QColor(0,0,0));

              this->addRect(i*sizeOfSquare,j*sizeOfSquare,sizeOfSquare,sizeOfSquare,pen,br);

          }
          else if(actUserField[i][j]==2){
              QColor col;
              col.setRgb(218,164,96);
              QBrush br(col);
              QPen pen;
              pen.setColor(QColor(0,0,0));

              this->addRect(i*sizeOfSquare,j*sizeOfSquare,sizeOfSquare,sizeOfSquare,pen,br);

          }
          else{
              if(field[i][j]==-1){
                  QColor col;
                  col.setRgb(128,0,0);
                  QBrush br(col);
                  QPen pen;
                  pen.setColor(QColor(0,0,0));

                  this->addRect(i*sizeOfSquare,j*sizeOfSquare,sizeOfSquare,sizeOfSquare,pen,br);

              }
              else if(field[i][j]==0){
                  QColor col;
                  col.setRgb(255,255,255);
                  QBrush br(col);
                  QPen pen;
                  pen.setColor(QColor(0,0,0));

                  this->addRect(i*sizeOfSquare,j*sizeOfSquare,sizeOfSquare,sizeOfSquare,pen,br);

              }
              else{
                     QString str;
                     str.setNum(field[i][j],10);
                     QGraphicsTextItem *item1=new QGraphicsTextItem(str);
                     item1->setPos(i*sizeOfSquare,j*sizeOfSquare);
                     this->addItem(item1);
                     this->addLine(i*sizeOfSquare,j*sizeOfSquare,(i)*sizeOfSquare,(j+1)*sizeOfSquare);
                     this->addLine(i*sizeOfSquare,j*sizeOfSquare,(i+1)*sizeOfSquare,(j)*sizeOfSquare);
                  }
              }
          }
      }
  }



void Visualization::mousePressEvent(QGraphicsSceneMouseEvent *event){

    if(start==false){
        if(event->button()==Qt::LeftButton){
            start=true;
            int i=(event->scenePos().x())/sizeOfSquare;
            int j=event->scenePos().y()/sizeOfSquare;
            game.generate(i,j);

            field=game.getField();
            actUserField=game.getActUserField();

            drawField();
    }
    }
    else{
        if(event->button()==Qt::LeftButton){
            int i=event->scenePos().x()/sizeOfSquare;
            int j=event->scenePos().y()/sizeOfSquare;
            game.move(i,j,false);

            field=game.getField();
            actUserField=game.getActUserField();
            drawField();
        }
        else{
            int i=event->scenePos().x()/sizeOfSquare;
            int j=event->scenePos().y()/sizeOfSquare;
            game.move(i,j,true);

            field=game.getField();
            actUserField=game.getActUserField();
            drawField();
        }
    }

}


void Visualization::end(bool a){
    if(a){
        emit gameOver(true);
    }
    else{
        emit gameOver(false);
    }
}

