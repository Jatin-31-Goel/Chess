#include<bits/stdc++.h>
using namespace std;

class rook: public piece{

    public: 
    rook(char color, int x, int y) : piece(){
        this->color = color;
        this->x = x;
        this->y = y;
        this->movements = 0;
    }

    // To check if Rook can move to the coordinates (x,y)
    bool is_possible_rook(int x,int y,chessboard chess)
    {
        // Ensuring that target spot (x,y) does not have the same color piece
        if(chess.chess[x][y].c[0] == chess.chess[this->x][this->y].c[0])
            return false;

        int diff_in_x = abs(x - this->x); // Finding the difference between the x-coordinates of the current and target spot 
        int diff_in_y = abs(y - this->y); // Finding the difference between the y-coordinates of the current and target spot

        // Rook can only move :

        if(diff_in_y == 0) // Either Horizontally
        {
            int start_x = max(x,this->x) - 1;
            int stop_x  = min(x,this->x);

            // Ensuring that no piece is present between the current and the target spot 
            while(start_x != stop_x)
            {
                if(chess.chess[start_x][y].c!="**")
                    return false;
                start_x--;
            }

            this->movements++; // Indicates that the Rook has been displaced atleast once from its initial position 
            return true;
        }

        else if(diff_in_x == 0) // Or Vertically
        {
            int start_y = max(y,this->y) - 1;
            int stop_y  = min(y,this->y);

            // Ensuring that no piece is present between the current and the target spot
            while(start_y != stop_y)
            {
                if(chess.chess[x][start_y].c!="**")
                    return false;
                start_y--;
            }
            
            this->movements++; // Indicates that the Rook has been displaced atleast once from its initial position
            return true;
        }

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
