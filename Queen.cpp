#include<iostream>
using namespace std;

// Class for implementing the Piece Queen which inherits some features, in public mode, from the parent class 'rook' and 'bishop'.
class queen :public rook, public bishop
{
    public:
    /*
        Constructor for the Queen :
        As the queen will follow the movements of a rook or a bishop only, so we call the constructors of their parent classes inorder to change 
        the x and y coordinates of them.
    */
    queen (char color, int x, int y) : rook(color, x, y), bishop(color, x, y){}

    
    /*
        This Checks if the target spot is accessible by the queen based on the below logic:
        Queen can only move :
            1) Either horizontally or vertically straight like Rook.
            2) Diagonally like Bishop
    */
    bool is_possible(int x,int y,chessboard chess)
    {
        // Scope Resolution(::) indicates the working of that particular property of the parent class 
        if(rook::is_possible(x,y, chess) || bishop::is_possible(x, y, chess)) // This checks for the rook or bishop type movements 
            return true;

        return false; // All the possible cases have already been encountered above.
    } 

    
    /*
        Whenever the Queen has moved we call this function to change the internal x and y co-ordinate of its parent classes so that next time 
        when the is_possible function is called, it will have the updated coordinates.
    */
    void change_coordinates(int x,int y)
    {   
        this->rook::x = x;     
        this->rook::y = y;
        this->bishop:: x = x;
        this->bishop::y = y;
    }
};
