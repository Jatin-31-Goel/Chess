#include<bits/stdc++.h>
using namespace std;

class knight{
    public:
    int x;
    int y;
    char color;
    int movements;

    knight(char color, int x, int y){
        this->color = color;
        this->x = x;
        this->y = y;
        this->movements = 0;
    }

    bool is_possible(int x,int y,chessboard chess)
    {
        if(chess.chess[x][y].c[0] == chess.chess[this->x][this->y].c[0])
            return false;
        int temp1 = abs(x - this->x);
        int temp2 = abs(y - this->y);
        if(temp1 ==1 && temp2 ==2)
            return true;
        else if(temp1 ==2 && temp2 ==1)
            return true;
        return false;
    } 
    void change_coordinates(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
};
