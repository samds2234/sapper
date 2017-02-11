#include "mygame.h"

MyGame::MyGame(QObject *parent):QObject(parent)
{
    srand(time(0));
    width=10;
    height=10;
    numBomb=10;
    kol=0;
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

}

void MyGame::setData(int a,int b,int c){

    width=a;
    height=b;
    numBomb=c;
    kol=0;
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


}

void MyGame::generate(int i, int j){

    actUserField[i][j]=1;
    int mass[16][2]={0};
    int x=0;
    if((i-3)>=0&&(j-3)>=0){
        for(int k=(i-3);k<=i;++k){
            for(int l=(j-3);l<=j;++l){
                actUserField[k][l]=1;
                mass[x][0]=k;
                mass[x][1]=l;
                ++x;

            }
        }
    }
    else if((i+3)<width&&(j-3)>=0){
        for(int k=(i+3);k>=i;--k){
            for(int l=(j-3);l<=j;++l){
                actUserField[k][l]=1;
                mass[x][0]=k;
                mass[x][1]=l;
                ++x;
            }
        }
    }
    else if((i-3)>=0&&(j+3)<height){
        for(int k=(i-3);k<=i;++k){
            for(int l=(j+3);l>=j;--l){
                actUserField[k][l]=1;
                mass[x][0]=k;
                mass[x][1]=l;
                ++x;
            }
        }
    }
    else{
        for(int k=(i+3);k>=i;--k){
            for(int l=(j+3);l>=j;--l){
                actUserField[k][l]=1;
                mass[x][0]=k;
                mass[x][1]=l;
                ++x;
            }
        }
    }

    int number=numBomb;
    while(number>0){
        int k=rand()%width;
        int l=rand()%height;

        if(actUserField[k][l]==1||field[k][l]==-1) continue;
        else{

            field[k][l]=-1;
            --number;
           }
    }

    for(int k=0;k<width;++k){
        for(int l=0;l<height;++l){
            if(field[k][l]==0){
                int y=0;
                if(k>0&&l>0){
                    if(field[k-1][l-1]==-1)++y;
                }
                if(k>0){
                    if(field[k-1][l]==-1)++y;
                }
                if(k>0&&l<(height-1)){
                    if(field[k-1][l+1]==-1)++y;
                }
                if(l>0){
                    if(field[k][l-1]==-1)++y;
                }
                if(l<(height-1)){
                    if(field[k][l+1]==-1)++y;
                }
                if(k<(width-1)&&l>0){
                    if(field[k+1][l-1]==-1)++y;
                }
                if(k<(width-1)){
                    if(field[k+1][l]==-1)++y;
                }
                if(k<(width-1)&&l<(height-1)){
                    if(field[k+1][l+1]==-1)++y;
                }

                field[k][l]=y;
                y=0;

            }
        }

    }



}

void MyGame::expand(int i,int j){

}

void MyGame::move(int i,int j,bool click){

}

QVector<QVector<int>> MyGame::getField(void){
    return field;
}

QVector<QVector<int>> MyGame::getActUserField(void){
    return actUserField;
}

bool MyGame::isWin(void){
    return false;
}
