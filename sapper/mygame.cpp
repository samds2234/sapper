#include "mygame.h"

MyGame::MyGame(QObject *parent):QObject(parent)
{
    srand(time(0));
    width=10;
    height=10;
    numBomb=10;
    counting=numBomb;
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
    counting=numBomb;
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

    for(int k=0;k<16;++k){
        if(field[mass[k][0]][mass[k][1]]==0) expand(mass[k][0],mass[k][1]);
    }



}

void MyGame::expand(int i,int j){

    int mass[8][2]={0};
    int nuls=-1;

    if(i>0&&j>0){
        if(field[i-1][j-1]==0&&actUserField[i-1][j-1]!=1){
            mass[nuls+1][0]=i-1;
            mass[nuls+1][1]=j-1;
            ++nuls;
        }
        actUserField[i-1][j-1]=1;
    }
    if(i>0){
        if(field[i-1][j]==0&&actUserField[i-1][j]!=1){
            mass[nuls+1][0]=i-1;
            mass[nuls+1][1]=j;
            ++nuls;
        }
        actUserField[i-1][j]=1;
    }
    if(i>0&&j<(height-1)){
        if(field[i-1][j+1]==0&&actUserField[i-1][j+1]!=1){
            mass[nuls+1][0]=i-1;
            mass[nuls+1][1]=j+1;
            ++nuls;
        }
        actUserField[i-1][j+1]=1;
    }
    if(j>0){
        if(field[i][j-1]==0&&actUserField[i][j-1]!=1){
            mass[nuls+1][0]=i;
            mass[nuls+1][1]=j-1;
            ++nuls;
        }
        actUserField[i][j-1]=1;
    }
    if(j<(height-1)){
        if(field[i][j+1]==0&&actUserField[i][j+1]!=1){
            mass[nuls+1][0]=i;
            mass[nuls+1][1]=j+1;
            ++nuls;
        }
        actUserField[i][j+1]=1;
    }
    if(i<(width-1)&&j>0){
        if(field[i+1][j-1]==0&&actUserField[i+1][j-1]!=1){
            mass[nuls+1][0]=i+1;
            mass[nuls+1][1]=j-1;
            ++nuls;
        }
        actUserField[i+1][j-1]=1;
    }
    if(i<(width-1)){
        if(field[i+1][j]==0&&actUserField[i+1][j]!=1){
            mass[nuls+1][0]=i+1;
            mass[nuls+1][1]=j;
            ++nuls;
        }
        actUserField[i+1][j]=1;
    }
    if(i<(width-1)&&j<(height-1)){
        if(field[i+1][j+1]==0&&actUserField[i+1][j+1]!=1){
            mass[nuls+1][0]=i+1;
            mass[nuls+1][1]=j+1;
            ++nuls;
        }
        actUserField[i+1][j+1]=1;
    }

    for(int k=0;k<=nuls;++k){
        expand(mass[k][0],mass[k][1]);
    }

}

void MyGame::move(int i,int j,bool click){
    if(!click){
    if(actUserField[i][j]==0)actUserField[i][j]=1;
    if(field[i][j]==-1&&actUserField[i][j]!=2){
        emit gameOver(false);
        boom();
    }
    else if(field[i][j]==0&&actUserField[i][j]!=2){
        expand(i,j);
        if(isWin()){

            emit gameOver(true);
            boom();
        }
    }
    else{
        if(isWin()&&actUserField[i][j]!=2){

            emit gameOver(true);
            boom();
        }
    }
    }
    else{
        if(actUserField[i][j]!=1&&actUserField[i][j]!=2){

            actUserField[i][j]=2;
            counting--;
            emit changeBomb(counting);
        }
        else if(actUserField[i][j]==2){

            actUserField[i][j]=0;
            counting++;
            emit changeBomb(counting);
        }
    }

}

QVector<QVector<int>> MyGame::getField(void){
    return field;
}

QVector<QVector<int>> MyGame::getActUserField(void){
    return actUserField;
}

bool MyGame::isWin(void){
    int cnt=0;
    for(int i=0;i<width;++i){
        for(int j=0;j<height;++j){
            if(actUserField[i][j]==1)++cnt;
        }
    }
    if(cnt==(width*height-numBomb)) return true;
    else return false;


}

void MyGame::boom(void){
    for(int i=0;i<width;++i){
        for(int j=0;j<height;++j){
            actUserField[i][j]=1;
        }
    }
}
