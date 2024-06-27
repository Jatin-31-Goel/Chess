#include<bits/stdc++.h>
using namespace std;

// Class for implementing the Piece Knight which inherits some features, in public mode, from the parent class 'piece'.
class knight : public piece
{
    public:

    // Constructor for the knight wherein common features have already been initiated by the constructor of the parent class.
    knight(char color, int x, int y) : piece(color,x,y) {}


    /*
        This Checks if the target spot is accessible by the knight based on the below logic:
        Knight can only move:
            1) Either one step horizontal and two steps vertical
            2) Or two steps horizontal and one step vertical
    */
    bool is_possible(int x,int y,chessboard chess)
    {
        // Ensuring that target spot (x,y) does not have the same color piece
        if(chess.chess[x][y].c[0] == chess.chess[this->x][this->y].c[0])
            return false;
        
        int diff_in_x = abs(x - this->x); // The absolute difference between x-coordinates of the current and target spot 
        int diff_in_y = abs(y - this->y); // The absolute difference between y-coordinates of the current and target spot
        
        if(diff_in_x ==1 && diff_in_y ==2) // Ensuring if it is one step horizontal and two steps vertical
            return true;

        else if(diff_in_x ==2 && diff_in_y ==1) // Ensuring if it is two steps horizontal and one step vertical
            return true;

        else 
            return false;  // All the possible cases have already been encountered above
    } 

    // Whenever the knight has moved we call this function to change the internal x and y co-ordinate of the knight. 
    void change_coordinates(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
};
