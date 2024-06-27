#include<bits/stdc++.h>
using namespace std;

// Class for implementing the Piece Rook which inherits some features, in public mode, from the parent class 'piece'.
class rook: public piece
{
    public:

    // Constructor for the rook wherein common features have already been initiated by the constructor of the parent class.
    rook(char color, int x, int y) : piece(color,x,y){}


    /*
        This Checks if the target spot is accessible by the rook based on the below logic:
        Rook can only move either horizontally or vertically straight.
    */
    bool is_possible_rook(int x,int y,chessboard chess)
    {
        // Ensuring that target spot (x,y) does not have the same color piece
        if(chess.chess[x][y].c[0] == chess.chess[this->x][this->y].c[0])
            return false;

        int diff_in_x = abs(x - this->x); // The absolute difference between the x-coordinates of the current and target spot 
        int diff_in_y = abs(y - this->y); // The absolute difference between the y-coordinates of the current and target spot

        if(diff_in_y == 0) // Ensuring if it is a horizontal movement
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

        else if(diff_in_x == 0) // Ensuring if it is a vertical movement
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

    // Whenever the rook has moved we call this function to change the internal x and y co-ordinate of the rook.
    void change_coordinates(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
};
