#include<bits/stdc++.h>
using namespace std;

class king{
    public:
    int x;
    int y;
    char color;
    int movements;

    king(char color, int x, int y){
        this->color = color;
        this->x = x;
        this->y = y;
        this->movements = 0;
    }
    bool is_possible(int x,int y,chessboard chess)
    {
        int temp1 = abs(x - this->x);
        int temp2 = abs(y - this->y);
        
        if((this->x==1 || this->x==8) && this->y==5 && this->movements==0 && (x==1 || x==8) && y==7)
        {
            if(chess.chess[x][y-2].c=="**" && chess.chess[x][y-1].c=="**")
                return true;
        }
        else if((temp1<=1 && temp2<=1) && !(temp1 ==0 && temp2 ==0))
        {
            if((chess.chess[x][y].c[0]!=chess.chess[this->x][this->y].c[0]))
                return true;
            return false;
        }

        return false;
    }
    bool is_legal(int x,int y,chessboard chess)
    {
        int temp = x - 1;
        while(temp>=1)
        {
           // cout<<"1";
            if(chess.chess[temp][y].c[0]==chess.chess[x][y].c[0])
                break;
            else if(chess.chess[temp][y].c[0]!=chess.chess[x][y].c[0])
            {
                if(chess.chess[temp][y].c[1]=='R' || chess.chess[temp][y].c[1]=='Q')
                    return false;
                else if(chess.chess[temp][y].c[1]=='K' && abs(temp - x) == 1)
                    return false;
            }
            temp--;
        }
        temp = x + 1;
        while(temp<=8)
        {
            if(chess.chess[temp][y].c[0]==chess.chess[x][y].c[0])
                break;
            else if(chess.chess[temp][y].c[0]!=chess.chess[x][y].c[0])
            {
                if(chess.chess[temp][y].c[1]=='R' || chess.chess[temp][y].c[1]=='Q')
                    return false;
                else if(chess.chess[temp][y].c[1]=='K' && abs(temp - x) == 1)
                    return false;
            }
            temp++;
        }
        temp = y - 1;
        while(temp>=1)
        {
           // cout<<"2";
            if(chess.chess[x][temp].c[0]==chess.chess[x][y].c[0])
                break;
            else if(chess.chess[x][temp].c[0]!=chess.chess[x][y].c[0])
            {
                if(chess.chess[x][temp].c[1]=='R' || chess.chess[x][temp].c[1]=='Q')
                    return false;
                else if(chess.chess[x][temp].c[1]=='K' && abs(temp - x) == 1)
                    return false;
            }
            temp--;
        }
        temp = y + 1;
        while(temp<=8)
        {
           // cout<<"3";
           if(chess.chess[x][temp].c[0]==chess.chess[x][y].c[0])
                break;
            else if(chess.chess[x][temp].c[0]!=chess.chess[x][y].c[0])
            {
                if(chess.chess[x][temp].c[1]=='R' || chess.chess[x][temp].c[1]=='Q')
                    return false;
                else if(chess.chess[x][temp].c[1]=='K' && abs(temp - x) == 1)
                    return false;
            }
            temp++;
        }
        int temp1 = x - 1;
        int temp2 = y - 1;
        while(temp1>=1 && temp2>=1)
        {
          //  cout<<"4";
             if(chess.chess[temp1][temp2].c[0] == chess.chess[x][y].c[0])
                break;
            else if(chess.chess[temp1][temp2].c[0]!=chess.chess[x][y].c[0])
            {
                if(chess.chess[temp1][temp2].c[1]=='B' || chess.chess[temp1][temp2].c[1]=='Q')
                    return false;
                else if((chess.chess[temp1][temp2].c[1]=='K' || chess.chess[temp1][temp2].c[1]=='P') && (x - temp1) == 1 && (y - temp2) == 1)
                    return false;
            }
            temp1--;
            temp2--;
        }
        temp1 = x + 1;
        temp2 = y + 1;
        while(temp1<=8 && temp2<=8)
        {
           // cout<<"5";
           if(chess.chess[temp1][temp2].c[0] == chess.chess[x][y].c[0])
                break;
            else if(chess.chess[temp1][temp2].c[0]!=chess.chess[x][y].c[0])
            {
                if(chess.chess[temp1][temp2].c[1]=='B' || chess.chess[temp1][temp2].c[1]=='Q')
                    return false;
                else if((chess.chess[temp1][temp2].c[1]=='K' || chess.chess[temp1][temp2].c[1]=='P') && (temp1 - x) == 1 && (temp2 - y) == 1)
                    return false;
            }
            temp1++;
            temp2++;
        }
        temp1 = x - 1;
        temp2 = y + 1;
        while(temp1>=1 && temp2<=8)
        {
          //  cout<<"6";
            if(chess.chess[temp1][temp2].c[0] == chess.chess[x][y].c[0])
                break;
            else if(chess.chess[temp1][temp2].c[0]!=chess.chess[x][y].c[0])
            {
                if(chess.chess[temp1][temp2].c[1]=='B' || chess.chess[temp1][temp2].c[1]=='Q')
                    return false;
                else if((chess.chess[temp1][temp2].c[1]=='K' || chess.chess[temp1][temp2].c[1]=='P') && (x - temp1) == 1 && (temp2 - y) == 1)
                    return false;
            }
            temp1--;
            temp2++;
        }
        temp1 = x + 1;
        temp2 = y - 1;
        while(temp1<=8 && temp2>=1)
        {
          //  cout<<"7";
            if(chess.chess[temp1][temp2].c[0] == chess.chess[x][y].c[0])
                break;
            else if(chess.chess[temp1][temp2].c[0]!=chess.chess[x][y].c[0])
            {
                if(chess.chess[temp1][temp2].c[1]=='B' || chess.chess[temp1][temp2].c[1]=='Q')
                    return false;
                else if((chess.chess[temp1][temp2].c[1]=='K' || chess.chess[temp1][temp2].c[1]=='P') && (temp1 - x) == 1 && (y - temp2) == 1)
                    return false;
            }
            temp1++;
            temp2--;
        }
        temp1 = x+1;
        temp2 = y+2;
        if(temp1<=8 && temp2<=8)
            if((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[1] == 'N')
                return false;
        temp1 = x-1;
        temp2 = y-2;
        if(temp1>=1 && temp2>=1)
            if((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[1] == 'N')
                return false;
        temp1 = x+1;
        temp2 = y-2;
        if(temp1<=8 && temp2>=1)
            if((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[1] == 'N')
                return false;
        temp1 = x-1;
        temp2 = y+2;
        if(temp1>=1 && temp2<=8)
            if((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[1] == 'N')
                return false;
        temp1 = x+2;
        temp2 = y+1;
        if(temp1<=8 && temp2<=8)
            if((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[1] == 'N')
                return false;
        temp1 = x-2;
        temp2 = y-1;
        if(temp1>=1 && temp2>=1)
            if((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[1] == 'N')
                return false;
        temp1 = x+2;
        temp2 = y-1;
        if(temp1<=8 && temp2>=1)
            if((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[1] == 'N')
                return false;
        temp1 = x-2;
        temp2 = y+1;
        if(temp1>=1 && temp2<=8)
            if((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[1] == 'N')
                return false;
        return true;
    }
    void change_coordinates(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
};
