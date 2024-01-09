#include<iostream>
using namespace std;

class queen :public rook, public bishop{
    public:
    int x_q;
    int y_q;
    char color_q;
    int movements_q;
    queen (char color, int x, int y) : rook(color, x, y), bishop(color, x, y){
        this->color_q = color;
        this->x_q = x;
        this->y_q = y;
        this->movements_q = 0;
    }

    bool is_possible(int x,int y,chessboard chess)
    {
        //cout<<"QUEEN";
        // rook r1(color, this->x, this->y);
        // bishop b1(color, this->x, this->y);
        if(is_possible_rook(x,y, chess) || is_possible_bishop(x, y, chess)){
            return cout<<"1"&&true;
        }
        return false;
    } 
    void change_coordinates(int x,int y)
    {   
        this->rook::x = x;
        this->rook::y = y;
        this->bishop:: x = x;
        this->bishop::y = y;
        this->x_q = x;
        this->y_q = y;
    }
};
