#include <iostream>
#include "Chessboard.cpp"
#include "Pawn.cpp"
#include "King.cpp"
using namespace std;

int main(){
    // cout<<"HELLO \n Enter the name of first player : ";
    // string name1;
    // cin>>name1;
    // cout<<"HELLO \n Enter the name of second player : ";
    // string name2 ;
    // cin>>name2;
    chessboard chess;
    chess.print();
    int turn = 0;
    rook WR1('W', 1, 1), WR2('W', 1, 8), BR1('B', 8, 1), BR2('B', 8, 8);
    knight WN1('W', 1, 2), WN2('W', 1, 7), BN1('B', 8, 2), BN2('B', 8, 7);
    bishop WB1('W', 1, 3), WB2('W', 1, 6), BB1('B', 8, 3), BB2('B', 8, 6);
    pawn WP1('W', 2, 1), WP2('W', 2, 2), WP3('W', 2, 3), WP4('W', 2, 4), WP5('W', 2, 5),WP6('W', 2, 6),WP7('W', 2, 7),WP8('W', 2, 8),BP1('W', 7, 1), BP2('W', 7, 2), BP3('W', 7, 3), BP4('W', 7, 4), BP5('W', 7, 5),BP6('W', 7, 6),BP7('W', 7, 7),BP8('W', 7, 8);
    queen WQ('W', 1,4), BQ('B', 8, 4);
    king WK('W', 1, 5), BK('B', 8, 5);
    while(1)
    {  
        int x1, y1, x2, y2;
        cout<<"Enter current position : ";
        cin>>x1>>y1;
        cout<<endl;
        cout<<"Enter final position : ";
        cin>>x2>>y2;
        chessboard chess_2;
        if(turn == 0){
            if(chess.chess[x1][y1].c[0] == 'B'){
                cout<<"You cannot move opponents piece"<<endl;
                continue;
            }
            for(int i = 1; i<9; i++){
                for(int j = 1; j<9; j++){
                    chess_2.chess[i][j] = chess.chess[i][j];
                }
            }
            switch(chess.chess[x1][y1].c[1]){
                case 'R' : {
                    if(WR1.x == x1 && WR1.y == y1){
                        if(WR1.is_possible_rook(x2, y2, chess)){
                            WR1.movements++;
                            WR1.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!WK.is_legal( WK.x, WK.y, chess))
                                WR1.movements--;
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    else if(WR2.x == x1 && WR2.y == y1){
                        if(WR2.is_possible_rook(x2, y2, chess)){
                            WR2.movements++;
                            WR2.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!WK.is_legal( WK.x, WK.y, chess))
                                WR2.movements--;
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    break;
                }
                case 'Q' : {
                    if(WQ.is_possible(x2, y2, chess)){
                        WQ.change_coordinates(x2, y2);
                        chess.change(x1, x2, y1 , y2);
                    }
                   else{
                        cout<<"Invalid move"<<endl;
                        continue;
                    }                   
                    break;
                }
                case 'N' : 
                {
                    if(WN1.x == x1 && WN1.y == y1){
                        if(WN1.is_possible(x2, y2, chess)){
                            WN1.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    else if(WN2.x == x1 && WN2.y == y1){
                        if(WN2.is_possible(x2, y2, chess)){
                            WN2.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    break;
                }
                case 'B' : 
                {
                    if(WB1.x == x1 && WB1.y == y1){
                        if(WB1.is_possible_bishop(x2, y2, chess)){
                            WB1.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    else if(WB2.x == x1 && WB2.y == y1){
                        if(WB2.is_possible_bishop(x2, y2, chess)){
                            WB2.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    break;
                }
                case 'P' : 
                {
                    int temp;
                    if(WP1.x == x1 && WP1.y == y1){
                        if(WP1.is_possible(x2, y2, chess)){
                            WP1.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!WK.is_legal( WK.x, WK.y, chess))
                                WP1.movements--;
                            temp = WP1.change_piece(chess);
                            if(temp){
                                if(temp == 1){
                                    chess.chess[WP1.x][WP1.y].c = "WPQ";
                                }

                                else if(temp == 2){
                                    chess.chess[WP1.x][WP1.y].c = "WPB";
                                }

                                else if(temp == 3){
                                    chess.chess[WP1.x][WP1.y].c = "WPR";
                                }

                                else{
                                    chess.chess[WP1.x][WP1.y].c = "WPN";
                                }
                            }
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    if(WP2.x == x1 && WP2.y == y1){
                        if(WP2.is_possible(x2, y2, chess)){
                            WP2.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!WK.is_legal( WK.x, WK.y, chess))
                                WP2.movements--;
                            temp = WP2.change_piece(chess);
                            if(temp){
                                if(temp == 1){
                                    chess.chess[WP2.x][WP2.y].c = "WPQ";
                                }

                                else if(temp == 2){
                                    chess.chess[WP2.x][WP2.y].c = "WPB";
                                }

                                else if(temp == 3){
                                    chess.chess[WP2.x][WP2.y].c = "WPR";
                                }

                                else{
                                    chess.chess[WP2.x][WP2.y].c = "WPN";
                                }
                            }
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    if(WP3.x == x1 && WP3.y == y1){
                        if(WP3.is_possible(x2, y2, chess)){
                            WP3.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!WK.is_legal( WK.x, WK.y, chess))
                                WP3.movements--;
                            temp = WP3.change_piece(chess);
                            if(temp){
                                if(temp == 1){
                                    chess.chess[WP3.x][WP3.y].c = "WPQ";
                                }

                                else if(temp == 2){
                                    chess.chess[WP3.x][WP3.y].c = "WPB";
                                }

                                else if(temp == 3){
                                    chess.chess[WP3.x][WP3.y].c = "WPR";
                                }

                                else{
                                    chess.chess[WP3.x][WP3.y].c = "WPN";
                                }
                            }
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    if(WP4.x == x1 && WP4.y == y1){
                        if(WP4.is_possible(x2, y2, chess)){
                            WP4.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!WK.is_legal( WK.x, WK.y, chess))
                                WP4.movements--;
                            temp = WP4.change_piece(chess);
                            if(temp){
                                if(temp == 1){
                                    chess.chess[WP4.x][WP4.y].c = "WPQ";
                                }

                                else if(temp == 2){
                                    chess.chess[WP4.x][WP4.y].c = "WPB";
                                }

                                else if(temp == 3){
                                    chess.chess[WP4.x][WP4.y].c = "WPR";
                                }

                                else{
                                    chess.chess[WP4.x][WP4.y].c = "WPN";
                                }
                            }
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    if(WP5.x == x1 && WP5.y == y1){
                        if(WP5.is_possible(x2, y2, chess)){
                            WP5.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!WK.is_legal( WK.x, WK.y, chess))
                                WP5.movements--;
                            temp = WP5.change_piece(chess);
                            if(temp){
                                if(temp == 1){
                                    chess.chess[WP5.x][WP5.y].c = "WPQ";
                                }

                                else if(temp == 2){
                                    chess.chess[WP5.x][WP5.y].c = "WPB";
                                }

                                else if(temp == 3){
                                    chess.chess[WP5.x][WP5.y].c = "WPR";
                                }

                                else{
                                    chess.chess[WP5.x][WP5.y].c = "WPN";
                                }
                            }
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    if(WP6.x == x1 && WP6.y == y1){
                        if(WP6.is_possible(x2, y2, chess)){
                            WP6.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!WK.is_legal( WK.x, WK.y, chess))
                                WP6.movements--;
                            temp = WP6.change_piece(chess);
                            if(temp){
                                if(temp == 1){
                                    chess.chess[WP6.x][WP6.y].c = "WPQ";
                                }

                                else if(temp == 2){
                                    chess.chess[WP6.x][WP6.y].c = "WPB";
                                }

                                else if(temp == 3){
                                    chess.chess[WP6.x][WP6.y].c = "WPR";
                                }

                                else{
                                    chess.chess[WP6.x][WP6.y].c = "WPN";
                                }
                            }
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    if(WP7.x == x1 && WP7.y == y1){
                        if(WP7.is_possible(x2, y2, chess)){
                            WP7.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!WK.is_legal( WK.x, WK.y, chess))
                                WP7.movements--;
                            temp = WP7.change_piece(chess);
                            if(temp){
                                if(temp == 1){
                                    chess.chess[WP7.x][WP7.y].c = "WPQ";
                                }

                                else if(temp == 2){
                                    chess.chess[WP7.x][WP7.y].c = "WPB";
                                }

                                else if(temp == 3){
                                    chess.chess[WP7.x][WP7.y].c = "WPR";
                                }

                                else{
                                    chess.chess[WP7.x][WP7.y].c = "WPN";
                                }
                            }
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    if(WP8.x == x1 && WP8.y == y1){
                        if(WP8.is_possible(x2, y2, chess)){
                            WP8.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!WK.is_legal( WK.x, WK.y, chess))
                                WP8.movements--;
                            temp = WP8.change_piece(chess);
                            if(temp){
                                if(temp == 1){
                                    chess.chess[WP8.x][WP8.y].c = "WPQ";
                                }

                                else if(temp == 2){
                                    chess.chess[WP8.x][WP8.y].c = "WPB";
                                }

                                else if(temp == 3){
                                    chess.chess[WP8.x][WP8.y].c = "WPR";
                                }

                                else{
                                    chess.chess[WP8.x][WP8.y].c = "WPN";
                                }
                            }
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    break;
                }
                case 'K' : 
                {
                    if(WK.x == x1 && WK.y == y1){
                        if(WK.is_possible(x2, y2, chess)){
                            WK.movements++;
                            WK.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!WK.is_legal( WK.x, WK.y, chess))
                                WK.movements--;
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    break;
                }
                default: cout<<"Invalid move"<<endl;
                        continue;
                        break;
            }

            if(!WK.is_legal( WK.x, WK.y, chess))
            {
                cout<<"ILLEGAL MOVE"<<endl;
                for(int i = 1; i<9; i++)
                    for(int j = 1; j<9; j++)
                        chess.chess[i][j] = chess_2.chess[i][j];
            
                chess.print();
                continue;
            }
            chess.print();
            turn = 0;
        }   
    }
}
