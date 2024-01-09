#include<iostream>
using namespace std;

class rook: public piece{
    public: 
    rook(char color, int x, int y) : piece(){
        this->color = color;
        this->x = x;
        this->y = y;
        this->movements = 0;
    }

     bool is_possible_rook(int x,int y,chessboard chess)
    {
        //cout<<"ROOK"<<endl;
        if(this->y == y && this->x == x)
            return false;
        else if (this->y == y){
            if((x - this->x)>0)
            {
                int temp = x - 1;
                while((temp - this->x)>0)
                {
                    if(chess.chess[temp][y].c!="**")
                        return false;
                    temp--;
                }
            }
            else if((this->x - x)>0)
            {
                int temp = x + 1 ;
                while((this->x - temp )>0)
                {
                    if(chess.chess[temp][y].c!="**")
                        return false;
                    temp++;
                }
            }
            if(chess.chess[x][y].c[0]==chess.chess[this->x][this->y].c[0])
                return false;
            this->movements++;
            return true;
        }
        else if (this->x == x)
        {
            if((y - this->y)>0)
            {
                int temp = y - 1;
                while((temp - this->y)>0)
                {
                    if(chess.chess[x][temp].c!="**")
                        return false;
                    temp--;
                }
            }
            else if((this->y - y)>0)
            {
                int temp = y +1 ;
                while((this->y - temp)>0)
                {
                    if(chess.chess[x][temp].c!="**")
                        return false;
                    temp++;
                }
            }
            if(chess.chess[x][y].c[0]==chess.chess[this->x][this->y].c[0])
                return false;
            this->movements++;
            return true;
        }
        else
            return false;
    } 
    void change_coordinates(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
};
