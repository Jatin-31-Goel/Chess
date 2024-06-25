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

    // To check if Bishop can move to the coordinates (x,y)             
    bool is_possible_bishop(int x,int y,chessboard chess)
    {
        // Ensuring that target spot (x,y) does not have the same color piece
        if(chess.chess[x][y].c[0] == chess.chess[this->x][this->y].c[0])
            return false;
        
        int diff_in_x = abs(x - this->x); // Finding the difference between the x-coordinates of the current and target spot 
        int diff_in_y = abs(y - this->y); // Finding the difference between the y-coordinates of the current and target spot

        // Bishop can only move diagonally 

        if(diff_in_x != diff_in_y) // No. of steps in x-direction should be same in the y-direction
           return false;
        
        int max_x = max(x,this->x);
        int max_y = max(y,this->y);
        int min_x = min(x,this->x);
        int min_y = min(y,this->y);

        if((max_x == x && max_y == y)||(max_x == this->x && max_y == this->y)) // Target spot is either in 1st or 3rd Quadrant
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

        else if((max_x == x && min_y == y)||(max_x == this->x && min_y == this->y)) // Target spot is either in 2nd or 4th Quadrant
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

    // Changing the current coordinates to that of the target spot
    void change_coordinates(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
};

