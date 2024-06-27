#include<iostream>
#include "Rook.cpp"
#include "Knight.cpp"
#include "Bishop.cpp"
#include "Queen.cpp"
using namespace std;

// Class for implementing the Piece Pawn which inherits some features, in public mode, from the parent class 'piece'.
class pawn : public piece
{
    public:

    int change; // This keeps track of the promotion of pawn.    
    int choice; // This will come into picture when there are suitable conditions for promoting pawn into other pieces of chess.  

    // Constructor for the pawn wherein common features already been initiated by the constructor of the parent class.
    pawn(char color, int x, int y) : piece(color,x,y){
        this->change = 0;
    }

    /*
        Pawn can be promoted to other chess pieces, if it reches to the other end.
    */
    int Promotion_of_Pawn(chessboard chess)
    {
        if((this->x == 8 || this->x == 1) && this->change == 0)
        {
            cout<<"You have the priviledge to promote your piece : \n 1. Queen \n 2. Bishop \n 3. Rook \n 4. Knight \nEnter the number corresponding to the piece : ";
            int choice;
            cin>>choice;
            this->choice = choice;
            this->change = 1;
        }
        return this->choice;
    }


    /*
        This Checks if the target spot is accessible by the pawn based on the below logic:
            - Pawn can only move one step vertically forward usually.
            - It can move two steps vertically forward only when it is at its initial position(unmoved).
            - It can move one step diagonally forward only when it attacks opponents piece. 
    */
    bool is_possible(int x,int y,chessboard chess)
    {   
        if(this->change){
            switch(this->choice){
                case 1 : {
                    queen temp(this->color, this->x, this->y);
                    return temp.is_possible(x, y, chess);
                }

                case 2 : {
                    bishop temp(this->color, this->x, this->y);
                    return temp.is_possible(x, y, chess);
                }

                case 3 : {
                    rook temp(this->color, this->x, this->y);
                    return temp.is_possible(x, y, chess);
                }

                case 4 : {
                    knight temp(this->color, this->x, this->y);
                    return temp.is_possible(x, y, chess);
                }
            }
        }
        
        // Ensuring that target spot (x,y) does not have the same color piece
        if(chess.chess[x][y].c[0] == chess.chess[this->x][this->y].c[0])
            return false;


        if(chess.chess[this->x][this->y].c[0]=='W') // Checking conditions for the movement of a white pawn piece
        {
            if((x - this->x == 1) && (y == this->y) && (chess.chess[x][y].c=="**")) // Ensuring vertically forward movement
                return (++this->movements)&&true;
            else if((x - this->x == 2) && (y == this->y) && (this->movements == 0) && (chess.chess[x][y].c=="**")) // Ensuring initial two step vertcally forward movement
                return (++(++this->movements))&& true ;
            else if((x - this->x == 1) && (y - this->y == 1 || y - this->y == -1) && (chess.chess[x][y].c[0]=='B')) // Ensuring diagonally forward attacking movement
                return (++this->movements)&&true;  
        }

        else if(chess.chess[this->x][this->y].c[0]=='B') // Checking conditions for the movement of a black pawn piece
        {
            if((this->x - x == 1) && (this->y == y) && (chess.chess[x][y].c=="**")) // Ensuring vertically forward movement
                return (++this->movements)&&true;
            else if((this->x - x == 2) && (this->y == y) && (this->movements == 0) && (chess.chess[x][y].c=="**")) // Ensuring initial two step vertcally forward movement
                return (++(++this->movements))&& true ;
            else if((this->x - x == 1) && (this->y - y == 1 || this->y - y == -1) && (chess.chess[x][y].c[0]=='W')) // Ensuring diagonally forward attacking movement
                return (++this->movements)&&true;  
        }
        
        else
            return false; // All the possible cases have already been encountered above
    }

    // Whenever the Pawn has moved we call this function to change the internal x and y co-ordinate of the pawn.
    void change_coordinates(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
};
