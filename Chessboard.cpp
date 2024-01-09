#include<iostream>
using namespace std;

class chessboard{
    public:
    struct block{
        string c;
    };
    struct block chess[9][9];
    chessboard(){
        for(int i = 1; i<9; i++){
            for(int j = 1; j<9; j++){
                this->chess[i][j].c = "**";
            }
        }
        for(int j = 1; j<9; j++){
            this->chess[7][j].c = "BP";
        }
        for(int j = 1; j<9; j++){
            this->chess[2][j].c = "WP";
        }
        this->chess[8][1].c = "BR";
        this->chess[8][2].c = "BN";
        this->chess[8][3].c = "BB";
        this->chess[8][4].c = "BQ";
        this->chess[8][5].c = "BK";
        this->chess[8][6].c = "BB";
        this->chess[8][7].c = "BN";
        this->chess[8][8].c = "BR";

        this->chess[1][1].c = "WR";
        this->chess[1][2].c = "WN";
        this->chess[1][3].c = "WB";
        this->chess[1][4].c = "WQ";
        this->chess[1][5].c = "WK";
        this->chess[1][6].c = "WB";
        this->chess[1][7].c = "WN";
        this->chess[1][8].c = "WR";

    }

    void print(){
        for(int i = 8; i>=1; i--){
            for(int j = 1; j<=8; j++){
                cout<<this->chess[i][j].c<<" ";
            }
            cout<<endl;
        }
    }

    void change(int x1, int x2, int y1, int y2){
        this->chess[x2][y2].c = this->chess[x1][y1].c;
        this->chess[x1][y1].c = "**";
    }
};

class piece{
    public:
    int x;
    int y;
    char color;
    int movements;
};
