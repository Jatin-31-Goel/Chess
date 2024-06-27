#include<bits/stdc++.h>
using namespace std;

// Class for implementing the Piece Bishop which inherits some features, in public mode, from the parent class 'piece'.
class bishop: public piece 
{
    public:

    // Constructor for the bishop wherein common features have already been initiated by the constructor of the parent class.
    bishop(char color, int x, int y) :  piece(color,x,y){}


    /*
        This Checks if the target spot is accessible by the bishop based on the below logic:
        Bishop can only move diagonally.
    */             
    bool is_possible_bishop(int x,int y,chessboard chess)
    {
        // Ensuring that target spot (x,y) does not have the same color piece
        if(chess.chess[x][y].c[0] == chess.chess[this->x][this->y].c[0])
            return false;
        
        int diff_in_x = abs(x - this->x); // The absolute difference between the x-coordinates of the current and target spot 
        int diff_in_y = abs(y - this->y); // The absolute difference between the y-coordinates of the current and target spot

        if(diff_in_x != diff_in_y) // Ensuring if it is a diagonal movement i.e. no. of steps in x-direction should be same in the y-direction
           return false;
        
        int max_x = max(x,this->x);
        int max_y = max(y,this->y);
        int min_x = min(x,this->x);
        int min_y = min(y,this->y);

        if((max_x == x && max_y == y)||(max_x == this->x && max_y == this->y)) // Target spot is either in 1st or 3rd Quadrant w.r.t current position
        {
            int start_x = max_x - 1;
            int start_y = max_y - 1;
            int stop_x  = min_x;
            int stop_y  = min_y;

            // Ensuring that no piece is present between the current and the target spot
            while(start_x!=stop_x && start_y!=stop_y)
            {
                if(chess.chess[start_x][start_y].c!="**")
                    return false;
                start_x--;start_y--;
            }
        }

        else if((max_x == x && min_y == y)||(max_x == this->x && min_y == this->y)) // Target spot is either in 2nd or 4th Quadrant w.r.t current position
        {
            int start_x = max_x - 1;
            int start_y = min_y + 1;
            int stop_x  = min_x;
            int stop_y  = max_y;

            // Ensuring that no piece is present between the current and the target spot
            while(start_x!=stop_x && start_y!=stop_y)
            {
                if(chess.chess[start_x][start_y].c!="**")
                    return false;
                start_x--;start_y++;
            }
        }
        
        // All the Rejection cases have already been encountered 
        return true;
    }

    // Whenever the bishop has moved we call this function to change the internal x and y co-ordinate of the bishop.
    void change_coordinates(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
};

