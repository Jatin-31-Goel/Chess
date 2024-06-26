#include<iostream>
using namespace std;

/*
    * The moves of a queen are a combinations of that of a rook and a bishop.
    * So the queen peice can be implemented checking both for movements of a rook and a bishop.
    * If any of both is true then we return true for the possibility of the piece.
*/

class queen :public rook, public bishop{
    public:
    int x_q;                    // The x - coordinate of the queen
    int y_q;                    // The y - coordinate of the queen
    char color_q;               // The color of the piece of the queen
    int movements_q;            // The number of moves that this piece has moved

    /*
        * Constructor of the queen
        * The constructors for the rook and bishop are also called as they are inherited
        * The original conditions for the piece are.
    */ 
    queen (char color, int x, int y) : rook(color, x, y), bishop(color, x, y){
        this->color_q = color;
        this->x_q = x;
        this->y_q = y;
        this->movements_q = 0;
    }

    // The function to check the moves for the queen. We check if either a bishop or a rook can take the path and the return true.
    bool is_possible(int x,int y,chessboard chess)
    {
        if(is_possible_rook(x,y, chess) || is_possible_bishop(x, y, chess)){
            return true;
        }
        return false;
    } 

    // The function to change the coordinates of the piece.
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
