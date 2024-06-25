#include<bits/stdc++.h>
using namespace std;

class knight{
    public:
    int x;
    int y;
    char color;
    int movements;

    // Constructor with Parameters
    knight(char color, int x, int y){
        this->color = color;
        this->x = x;
        this->y = y;
        this->movements = 0;
    }

    // To check if Knight can move to the coordinates (x,y)
    bool is_possible(int x,int y,chessboard chess)
    {
        // Ensuring that target spot (x,y) does not have the same color piece
        if(chess.chess[x][y].c[0] == chess.chess[this->x][this->y].c[0])
            return false;
        
        int diff_in_x = abs(x - this->x); // Finding the difference between the x-coordinates of the current and target spot 
        int diff_in_y = abs(y - this->y); // Finding the difference between the y-coordinates of the current and target spot
        
        // Knight can only move : 
        
        if(diff_in_x ==1 && diff_in_y ==2) // Either one step horizontal and two steps vertical
            return true;

        else if(diff_in_x ==2 && diff_in_y ==1) // Or two steps horizontal and one step vertical
            return true;

        else
            return false;
    } 

    // Changing the current coordinates to that of the target spot 
    void change_coordinates(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
};
