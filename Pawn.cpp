#include<iostream>
#include "Rook.cpp"
#include "Knight.cpp"
#include "Bishop.cpp"
#include "Queen.cpp"
using namespace std;

class pawn{
    public:
    int x;
    int y;
    char color;
    int movements;
    int change;
    int choice; 

    pawn(char color, int x, int y){
        this->color = color;
        this->x = x;
        this->y = y;
        this->movements = 0;
        this->change = 0;
    }

    int Promotion_of_Pawn(chessboard chess)
    {
        if(this->x == 8 && this->change == 0)
        {
            cout<<"You have the priviledge to promote your piece : \n 1. Queen \n 2. Bishop \n 3. Rook \n 4. Knight \nEnter the number corresponding to the piece :"<<endl;
            int choice;
            cin>>choice;
            this->choice = choice;
            this->change = 1;
        }
        return this->choice;
    }

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
                    return temp.is_possible_bishop(x, y, chess);
                }

                case 3 : {
                    rook temp(this->color, this->x, this->y);
                    return temp.is_possible_rook(x, y, chess);
                }

                case 4 : {
                    knight temp(this->color, this->x, this->y);
                    return temp.is_possible(x, y, chess);
                }
            }
        }
        if(this->x == x && this->y == y)
            return false;
        else if(chess.chess[this->x][this->y].c[0]=='W')
        {
            if((x - this->x == 1) && (y == this->y) && (chess.chess[x][y].c=="**"))
                return (++this->movements)&&true;
            else if((x - this->x == 2) && (y == this->y) && (this->movements == 0) && (chess.chess[x][y].c=="**"))
                return (++(++this->movements))&& true ;
            else if((x - this->x == 1) && (y - this->y == 1) && (chess.chess[x][y].c[0]=='B'))
                return (++this->movements)&&true;  
            else if(((x - this->x == 1) && (y - this->y == -1) && (chess.chess[x][y].c[0]=='B')))
                return (++this->movements)&&true;  
        }
        else if(chess.chess[this->x][this->y].c[0]=='B')
        {
            if((this->x - x == 1) && (this->y == y) && (chess.chess[x][y].c=="**"))
                return (++this->movements)&&true;
            else if((this->x - x == 2) && (this->y == y) && (this->movements == 0) && (chess.chess[x][y].c=="**"))
                return (++(++this->movements))&& true ;
            else if((this->x - x == 1) && (this->y - y == 1) && (chess.chess[x][y].c[0]=='W'))
                return (++this->movements)&&true;  
            else if(((this->x - x == 1) && (this->y - y == -1) && (chess.chess[x][y].c[0]=='W')))
                return (++this->movements)&&true;  
        }
        return false;
    }
    void change_coordinates(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
};
