#include <iostream>
#include "Chessboard.cpp"
#include "Pawn.cpp"
#include "King.cpp"
using namespace std;

int main(){
    cout<<"Enter the name of first player : \n";
    string name1;
    cin>>name1;
    cout<<"Enter the name of second player : ";
    string name2 ;
    cin>>name2;
    cout<<"Lets the game begin"<<endl;
    cout<<endl<<name1 << " "<<"vs"<<" "<<name2<<endl<<endl;;
    chessboard chess;
    chess.print();
    int turn = 0;
    rook WR1('W', 1, 1), WR2('W', 1, 8), BR1('B', 8, 1), BR2('B', 8, 8);
    knight WN1('W', 1, 2), WN2('W', 1, 7), BN1('B', 8, 2), BN2('B', 8, 7);
    bishop WB1('W', 1, 3), WB2('W', 1, 6), BB1('B', 8, 3), BB2('B', 8, 6);
    pawn WP1('W', 2, 1), WP2('W', 2, 2), WP3('W', 2, 3), WP4('W', 2, 4), WP5('W', 2, 5),WP6('W', 2, 6),WP7('W', 2, 7),WP8('W', 2, 8),BP1('B', 7, 1), BP2('B', 7, 2), BP3('B', 7, 3), BP4('B', 7, 4), BP5('B', 7, 5),BP6('B', 7, 6),BP7('B', 7, 7),BP8('B', 7, 8);
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
                        if(WR1.is_possible(x2, y2, chess)){
                            WR1.movements++;
                            WR1.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!WK.is_legal( WK.x, WK.y, chess))
                            {
                                WR1.movements--;
                                WR1.change_coordinates(x1, y1);
                            }
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    else if(WR2.x == x1 && WR2.y == y1){
                        if(WR2.is_possible(x2, y2, chess)){
                            WR2.movements++;
                            WR2.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!WK.is_legal( WK.x, WK.y, chess))
                            {
                                WR2.movements--;
                                WR2.change_coordinates(x1, y1);
                            }
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
                        if(!WK.is_legal( WK.x, WK.y, chess))
                            WQ.change_coordinates(x1, y1);
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
                            if(!WK.is_legal( WK.x, WK.y, chess))
                                WN1.change_coordinates(x1, y1);
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
                            if(!WK.is_legal( WK.x, WK.y, chess))
                                WN2.change_coordinates(x1, y1);
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
                        if(WB1.is_possible(x2, y2, chess)){
                            WB1.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!WK.is_legal( WK.x, WK.y, chess))
                                WB1.change_coordinates(x1, y1);
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    else if(WB2.x == x1 && WB2.y == y1){
                        if(WB2.is_possible(x2, y2, chess)){
                            WB2.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!WK.is_legal( WK.x, WK.y, chess))
                                WB2.change_coordinates(x1, y1);
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
                            {
                                WP1.movements--;
                                WP1.change_coordinates(x1, y1);
                            }
                            temp = WP1.Promotion_of_Pawn(chess);
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
                            {
                                WP2.movements--;
                                WP2.change_coordinates(x1, y1);
                            }
                            temp = WP2.Promotion_of_Pawn(chess);
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
                            {
                                WP3.movements--;
                                WP3.change_coordinates(x1, y1);
                            }
                            temp = WP3.Promotion_of_Pawn(chess);
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
                            {
                                WP4.movements--;
                                WP4.change_coordinates(x1, y1);
                            }
                            temp = WP4.Promotion_of_Pawn(chess);
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
                            {
                                WP5.movements--;
                                WP5.change_coordinates(x1, y1);
                            }
                            temp = WP5.Promotion_of_Pawn(chess);
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
                            {
                                WP6.movements--;
                                WP6.change_coordinates(x1, y1);
                            }
                            temp = WP6.Promotion_of_Pawn(chess);
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
                            {
                                WP7.movements--;
                                WP7.change_coordinates(x1, y1);
                            }
                            temp = WP7.Promotion_of_Pawn(chess);
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
                            {
                                WP8.movements--;
                                WP8.change_coordinates(x1, y1);
                            }
                            temp = WP8.Promotion_of_Pawn(chess);
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
                        if(WK.is_possible(x2, y2, chess,WR2.movements)){
                            if(x1==1 && x2==1 && y1==5 && y2==7)
                            {
                                if(!WK.is_legal( WK.x, WK.y, chess) || !WK.is_legal( WK.x, 6, chess) || !WK.is_legal( WK.x, 7 , chess))
                                {   
                                    int t1 = 0;
                                    int t2 = 0;
                                    int t3 = 0;
                                    if(!WK.is_legal( WK.x, WK.y, chess))
                                        t1 = 1;
                                    if(!WK.is_legal( WK.x, WK.y + 1, chess))
                                        t2 = 1;
                                    if(!WK.is_legal( WK.x, WK.y + 2, chess))
                                        t3 = 1;
                                    cout<<t1<<" "<<t2<<" "<<t3<<endl;
                                    cout<<"Castling Not Possible"<<endl;
                                    chess.print();
                                    continue;
                                }
                                WK.movements++;
                                WK.change_coordinates(x2, y2);
                                WR2.movements++;
                                WR2.change_coordinates(1,6);
                                chess.change(x1, x2, y1 , y2);
                                chess.change(1,1,8,6);
                                if(!WK.is_legal( WK.x, WK.y, chess))
                                {
                                    WK.movements--;
                                    WR2.movements--;
                                    WK.change_coordinates(x1, y1);
                                    WR2.change_coordinates(1,8);
                                    
                                    for(int i = 1; i<9; i++)
                                        for(int j = 1; j<9; j++)
                                            chess.chess[i][j] = chess_2.chess[i][j];
                                    cout<<"ILLEGAL MOVE"<<endl;
            
                                    chess.print();
                                    continue;
                                }
                            }
                            else
                            {
                                WK.movements++;
                                WK.change_coordinates(x2, y2);
                                chess.change(x1, x2, y1 , y2);
                                if(!WK.is_legal( WK.x, WK.y, chess))
                                {
                                    WK.movements--;
                                    WK.change_coordinates(x1, y1);
                                    cout<<"ILLEGAL MOVE"<<endl;
                                        for(int i = 1; i<9; i++)
                                            for(int j = 1; j<9; j++)
                                                chess.chess[i][j] = chess_2.chess[i][j];
            
                                    chess.print();
                                    continue;
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
            turn = 1;
        }   
        else{
            if(chess.chess[x1][y1].c[0] == 'W'){
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
                    if(BR1.x == x1 && BR1.y == y1){
                        if(BR1.is_possible(x2, y2, chess)){
                            BR1.movements++;
                            BR1.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!BK.is_legal( BK.x, BK.y, chess))
                            {
                                BR1.movements--;
                                BR1.change_coordinates(x1, y1);
                            }
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    else if(BR2.x == x1 && BR2.y == y1){
                        if(BR2.is_possible(x2, y2, chess)){
                            BR2.movements++;
                            BR2.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!BK.is_legal( BK.x, BK.y, chess))
                            {
                                BR2.movements--;
                                BR2.change_coordinates(x1, y1);
                            }
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    break;
                }
                case 'Q' : {
                    if(BQ.is_possible(x2, y2, chess)){
                        BQ.change_coordinates(x2, y2);
                        chess.change(x1, x2, y1 , y2);
                        if(!BK.is_legal( BK.x, BK.y, chess))
                        BQ.change_coordinates(x1, y1);
                    }
                   else{
                        cout<<"Invalid move"<<endl;
                        continue;
                    }                   
                    break;
                }
                case 'N' : 
                {
                    if(BN1.x == x1 && BN1.y == y1){
                        if(BN1.is_possible(x2, y2, chess)){
                            BN1.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!BK.is_legal( BK.x, BK.y, chess))
                                BN1.change_coordinates(x1, y1);
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    else if(BN2.x == x1 && BN2.y == y1){
                        if(BN2.is_possible(x2, y2, chess)){
                            BN2.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!BK.is_legal( BK.x, BK.y, chess))
                                BN2.change_coordinates(x1, y1);
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
                    if(BB1.x == x1 && BB1.y == y1){
                        if(BB1.is_possible(x2, y2, chess)){
                            BB1.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!BK.is_legal( BK.x, BK.y, chess))
                                BB1.change_coordinates(x1, y1);
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    else if(BB2.x == x1 && BB2.y == y1){
                        if(BB2.is_possible(x2, y2, chess)){
                            BB2.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!BK.is_legal( BK.x, BK.y, chess))
                                BB2.change_coordinates(x1, y1);
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
                    if(BP1.x == x1 && BP1.y == y1){
                        if(BP1.is_possible(x2, y2, chess)){
                            BP1.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!BK.is_legal( BK.x, BK.y, chess))
                            {
                                BP1.movements--;
                                BP1.change_coordinates(x1, y1);
                            }
                            temp = BP1.Promotion_of_Pawn(chess);
                            if(temp){
                                if(temp == 1){
                                    chess.chess[BP1.x][BP1.y].c = "BPQ";
                                }

                                else if(temp == 2){
                                    chess.chess[BP1.x][BP1.y].c = "BPB";
                                }

                                else if(temp == 3){
                                    chess.chess[BP1.x][BP1.y].c = "BPR";
                                }

                                else{
                                    chess.chess[BP1.x][BP1.y].c = "BPN";
                                }
                            }
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    if(BP2.x == x1 && BP2.y == y1){
                        if(BP2.is_possible(x2, y2, chess)){
                            BP2.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!BK.is_legal( BK.x, BK.y, chess))
                            {
                                BP2.movements--;
                                BP2.change_coordinates(x1, y1);
                            }
                            temp = BP2.Promotion_of_Pawn(chess);
                            if(temp){
                                if(temp == 1){
                                    chess.chess[BP2.x][BP2.y].c = "BPQ";
                                }

                                else if(temp == 2){
                                    chess.chess[BP2.x][BP2.y].c = "BPB";
                                }

                                else if(temp == 3){
                                    chess.chess[BP2.x][BP2.y].c = "BPR";
                                }

                                else{
                                    chess.chess[BP2.x][BP2.y].c = "BPN";
                                }
                            }
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    if(BP3.x == x1 && BP3.y == y1){
                        if(BP3.is_possible(x2, y2, chess)){
                            BP3.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!BK.is_legal( BK.x, BK.y, chess))
                            {
                                BP3.movements--;
                                BP3.change_coordinates(x1, y1);
                            }
                            temp = BP3.Promotion_of_Pawn(chess);
                            if(temp){
                                if(temp == 1){
                                    chess.chess[BP3.x][BP3.y].c = "BPQ";
                                }

                                else if(temp == 2){
                                    chess.chess[BP3.x][BP3.y].c = "BPB";
                                }

                                else if(temp == 3){
                                    chess.chess[BP3.x][BP3.y].c = "BPR";
                                }

                                else{
                                    chess.chess[BP3.x][BP3.y].c = "BPN";
                                }
                            }
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    if(BP4.x == x1 && BP4.y == y1){
                        if(BP4.is_possible(x2, y2, chess)){
                            BP4.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!BK.is_legal( BK.x, BK.y, chess))
                            {
                                BP4.movements--;
                                BP4.change_coordinates(x1, y1);
                            }
                            temp = BP4.Promotion_of_Pawn(chess);
                            if(temp){
                                if(temp == 1){
                                    chess.chess[BP4.x][BP4.y].c = "BPQ";
                                }

                                else if(temp == 2){
                                    chess.chess[BP4.x][BP4.y].c = "BPB";
                                }

                                else if(temp == 3){
                                    chess.chess[BP4.x][BP4.y].c = "BPR";
                                }

                                else{
                                    chess.chess[BP4.x][BP4.y].c = "BPN";
                                }
                            }
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    if(BP5.x == x1 && BP5.y == y1){
                        if(BP5.is_possible(x2, y2, chess)){
                            BP5.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!BK.is_legal( BK.x, BK.y, chess))
                            {
                                BP5.movements--;
                                BP5.change_coordinates(x1, y1);
                            }
                            temp = BP5.Promotion_of_Pawn(chess);
                            if(temp){
                                if(temp == 1){
                                    chess.chess[BP5.x][BP5.y].c = "BPQ";
                                }

                                else if(temp == 2){
                                    chess.chess[BP5.x][BP5.y].c = "BPB";
                                }

                                else if(temp == 3){
                                    chess.chess[BP5.x][BP5.y].c = "BPR";
                                }

                                else{
                                    chess.chess[BP5.x][BP5.y].c = "BPN";
                                }
                            }
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    if(BP6.x == x1 && BP6.y == y1){
                        if(BP6.is_possible(x2, y2, chess)){
                            BP6.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!BK.is_legal( BK.x, BK.y, chess))
                            {
                                BP6.movements--;
                                BP6.change_coordinates(x1, y1);
                            }
                            temp = BP6.Promotion_of_Pawn(chess);
                            if(temp){
                                if(temp == 1){
                                    chess.chess[BP6.x][BP6.y].c = "BPQ";
                                }

                                else if(temp == 2){
                                    chess.chess[BP6.x][BP6.y].c = "BPB";
                                }

                                else if(temp == 3){
                                    chess.chess[BP6.x][BP6.y].c = "BPR";
                                }

                                else{
                                    chess.chess[BP6.x][BP6.y].c = "BPN";
                                }
                            }
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    if(BP7.x == x1 && BP7.y == y1){
                        if(BP7.is_possible(x2, y2, chess)){
                            BP7.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!BK.is_legal( BK.x, BK.y, chess))
                            {
                                BP7.movements--;
                                BP7.change_coordinates(x1, y1);
                            }
                            temp = BP7.Promotion_of_Pawn(chess);
                            if(temp){
                                if(temp == 1){
                                    chess.chess[BP7.x][BP7.y].c = "BPQ";
                                }

                                else if(temp == 2){
                                    chess.chess[BP7.x][BP7.y].c = "BPB";
                                }

                                else if(temp == 3){
                                    chess.chess[BP7.x][BP7.y].c = "BPR";
                                }

                                else{
                                    chess.chess[BP7.x][BP7.y].c = "BPN";
                                }
                            }
                        }
                        else{
                            cout<<"Invalid move"<<endl;
                            continue;
                        }
                    }
                    if(BP8.x == x1 && BP8.y == y1){
                        if(BP8.is_possible(x2, y2, chess)){
                            BP8.change_coordinates(x2, y2);
                            chess.change(x1, x2, y1 , y2);
                            if(!BK.is_legal( BK.x, BK.y, chess))
                            {
                                BP8.movements--;
                                BP8.change_coordinates(x1, y1);
                            }
                            temp = BP8.Promotion_of_Pawn(chess);
                            if(temp){
                                if(temp == 1){
                                    chess.chess[BP8.x][BP8.y].c = "BPQ";
                                }

                                else if(temp == 2){
                                    chess.chess[BP8.x][BP8.y].c = "BPB";
                                }

                                else if(temp == 3){
                                    chess.chess[BP8.x][BP8.y].c = "BPR";
                                }

                                else{
                                    chess.chess[BP8.x][BP8.y].c = "BPN";
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
                    if(BK.x == x1 && BK.y == y1){
                        if(BK.is_possible(x2, y2, chess,BR2.movements)){
                            if(x1==8 && x2==8 && y1==5 && y2==7)
                            {
                                if(!BK.is_legal( BK.x, BK.y, chess) || !BK.is_legal( BK.x, BK.y + 1, chess) || !BK.is_legal( BK.x, BK.y +2 , chess))
                                {   
                                    int t1 = 0;
                                    int t2 = 0;
                                    int t3 = 0;
                                    if(!BK.is_legal( BK.x, BK.y, chess))
                                        t1 = 1;
                                    if(!BK.is_legal( BK.x, BK.y + 1, chess))
                                        t2 = 1;
                                    if(!BK.is_legal( BK.x, BK.y + 2, chess))
                                        t3 = 1;
                                    cout<<t1<<" "<<t2<<" "<<t3<<endl;
                                    cout<<"Castling Not Possible"<<endl;
                                    chess.print();
                                    continue;
                                }
                                BK.movements++;
                                BK.change_coordinates(x2, y2);
                                BR2.movements++;
                                BR2.change_coordinates(8,6);
                                chess.change(x1, x2, y1 , y2);
                                chess.change(8,8,8,6);
                                if(!BK.is_legal( BK.x, BK.y, chess))
                                {
                                    BK.movements--;
                                    BR2.movements--;
                                    BK.change_coordinates(x1, y1);
                                    BR2.change_coordinates(8,8);
                                    
                                    for(int i = 1; i<9; i++)
                                        for(int j = 1; j<9; j++)
                                            chess.chess[i][j] = chess_2.chess[i][j];
                                    cout<<"ILLEGAL MOVE"<<endl;
            
                                    chess.print();
                                    continue;
                                }
                            }
                            else
                            {
                                BK.movements++;
                                BK.change_coordinates(x2, y2);
                                chess.change(x1, x2, y1 , y2);
                                if(!BK.is_legal( BK.x, BK.y, chess))
                                {
                                    BK.movements--;
                                    BK.change_coordinates(x1, y1);
                                    cout<<"ILLEGAL MOVE"<<endl;
                                        for(int i = 1; i<9; i++)
                                            for(int j = 1; j<9; j++)
                                                chess.chess[i][j] = chess_2.chess[i][j];
            
                                    chess.print();
                                    continue;
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
                default: cout<<"Invalid move"<<endl;
                        continue;
                        break;            
            }
            if(!BK.is_legal( BK.x, BK.y, chess))
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

