#include<bits/stdc++.h>
using namespace std;

class bishop: public piece {

    public:
    bishop(char color, int x, int y) :  piece(){
        this->color = color;
        this->x = x;
        this->y = y;
        this->movements = 0;
    }

     bool is_possible_bishop(int x,int y,chessboard chess){
        if(abs(this->x-x)!=abs(this->y-y))
           return false;
        int k = this->x-x;
        int p = this->y-y;
        if(k>0 && p>0){
            int temp1=this->x - 1;
            int temp2=this->y - 1;
            while(temp1!=x && temp2!=y){
                if(chess.chess[temp1][temp2].c!="**")
                return false;
                temp1--;temp2--;
            }
            if(chess.chess[x][y].c[0]==chess.chess[this->x][this->y].c[0])
               return false;
            return true;
        }
        if(k>0 && p<0){
            int temp1=this->x - 1;
            int temp2=this->y + 1;
            while(temp1!=x && temp2!=y){
                if(chess.chess[temp1][temp2].c!="**")
                return false;
                temp1--;temp2++;
            }
            if(chess.chess[x][y].c[0]==chess.chess[this->x][this->y].c[0])
               return false;
            return true;
        }
        if(k<0 && p<0){
            int temp1=this->x + 1;
            int temp2=this->y + 1;
            while(temp1!=x && temp2!=y){
                if(chess.chess[temp1][temp2].c!="**")
                    return false;
                temp1++;temp2++;
            }
            if(chess.chess[x][y].c[0]==chess.chess[this->x][this->y].c[0])
               return false;
            return true;
        }
        if(k<0 && p>0){
            int temp1=this->x + 1;
            int temp2=this->y - 1;
            while(temp1!=x && temp2!=y){
                if(chess.chess[temp1][temp2].c!="**")
                return false;
                temp1++;temp2--;
            }
            if(chess.chess[x][y].c[0]==chess.chess[this->x][this->y].c[0])
               return false;
            return true;
        }
    }
    void change_coordinates(int x,int y)
    {
        this->x = x;
        this->y = y;
    }

};

