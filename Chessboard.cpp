#include<iostream>
using namespace std;

// This class will contain the functions to implement the chessboard.
class chessboard{
    public:

    // This will be implementing a single cell of the chessboard which is of the string data type.
    struct block{
        string c;
    };

    // This is the array which will have the game set up.
    struct block chess[9][9];
    
    // The constructor initializes everything to the original position. All the pieces are put in place and all the empty positions are initialized.
    chessboard(){

        // This loop initializes the empty spaces.
        for(int i = 1; i<9; i++){
            for(int j = 1; j<9; j++){
                this->chess[i][j].c = "**";
            }
        }

        // This will put in the original pieces of Pawn.
        for(int j = 1; j<9; j++){
            this->chess[7][j].c = "BP";
        }
        for(int j = 1; j<9; j++){
            this->chess[2][j].c = "WP";
        }
        
        // This initializes the original 8 black pieces.
        this->chess[8][1].c = this->chess[8][8].c = "BR";
        this->chess[8][2].c = this->chess[8][7].c = "BN";
        this->chess[8][3].c = this->chess[8][6].c = "BB";
        this->chess[8][4].c = "BQ";
        this->chess[8][5].c = "BK";
        
        // This initializes the original 8 white pieces.
        this->chess[1][1].c = this->chess[1][8].c = "WR";
        this->chess[1][2].c = this->chess[1][7].c = "WN";
        this->chess[1][3].c = this->chess[1][6].c = "WB";
        this->chess[1][4].c = "WQ";
        this->chess[1][5].c = "WK";
    }

    // This prints the chess board.
    void print(){
        cout<<"  ";
        for(int i = 1; i<=8; i++){
            cout<<" "<<i<<" ";
        }
        cout<<endl;
        for(int i = 8; i>=1; i--){
            cout<<i<<" ";
            for(int j = 1; j<=8; j++){
                cout<<this->chess[i][j].c<<" ";
            }
            cout<<endl;
        }
    }

    // This finalizes the change on the chess board after a move has been successfully made.
    void change(int x1, int x2, int y1, int y2){
        this->chess[x2][y2].c = this->chess[x1][y1].c;
        this->chess[x1][y1].c = "**";
    }
};

/*
    This primarily implements the class 'piece' containing the common properties which will be present with all other chess pieces.
    It will be inherited to all other pieces.
*/
class piece{
    public:
    int x;             // This keeps the track of the current x coordinate of a piece.
    int y;             // This keeps the track of the current y coordinate of a piece.
    char color;        // This stores 'W' or 'B' depending on the color of a piece.
    int movements;     // Keeps track of how many moves has been done by a piece.

    // Constructor with parameters for a piece
    piece(char color,int x,int y)
    {
        this->color = color;   // We pass the color of a piece.
        this->x = x;           // We initiate the original position of a piece in the beginning (x).
        this->y = y;           // We initiate the original position of a piece in the beginning (y).
        this->movements = 0;   // On initiation no move has been done by a piece
    }
};

