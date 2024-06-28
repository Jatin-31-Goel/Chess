#include <bits/stdc++.h>
using namespace std;

// Class for implementing the Piece King which inherits some features, in public mode, from the parent class 'piece'.
class king : public piece
{
    public:
    
    // Constructor for the king wherein common features already been initiated by the constructor of the parent class.
    king(char color, int x, int y) : piece(color,x,y){}


    /*
        This Checks if the target spot is accessible by the king based on the below logic:
        King can only move one step in any direction.
    */
    /*
        As the piece class has been inherited in the king, inorder to satisfy the virtual function, we have implemented the same 
        in the child class. Its a function overloading case : Function with the same name in the same class with different parameters. 
    */
    bool is_possible(int x,int y, chessboard chess){}
    bool is_possible(int x, int y, chessboard chess, int k)
    {
        // Ensuring that target spot (x,y) does not have the same color piece
        if(chess.chess[x][y].c[0] == chess.chess[this->x][this->y].c[0])
            return false;

        int diff_in_x = abs(x - this->x); // The absolute difference between x-coordinates of the current and target spot
        int diff_in_y = abs(y - this->y); // The absolute difference between y-coordinates of the current and target spot


        /*
            This checks for castling which is possible only when :
            The king and rook are present at their initial positions and are unmoved as well. Moreover no piece should be present between both of them.
        */
        if ((this->x == 1 || this->x == 8) && this->y == 5 && this->movements == 0 && (x == 1 || x == 8) && y == 7 && k == 0)
        {
            if (chess.chess[x][y].c == "**" && chess.chess[x][y - 1].c == "**")
                return true;
        }

        // Ensuring that if it is either horizontal, vertical or diagonal one step movement
        else if ((diff_in_x <= 1 && diff_in_y <= 1))
            return true;

        else
            return false; // All the possible cases have already been encountered above.
    }

    // This checks for illegal moves pertaining to king.

    /*
        Illegal Move: We call a move illegal, when the king is in check and we undertake a move that doesn't bring the king out
        of the check position.

        To check this, at every step -> after changing the position of the piece we will check if the king is placed in check or not.

        To do this we move in all directions:
            * We check for a rook, queen, king of other color in horizontal or vertical directions which would make it a check
            * In diagonals we check for pawn, queen, bishop
            * The number of steps must match the valid movements as well.
    */

    bool is_legal(int x, int y, chessboard chess)
    {
        // Temp variable helps us check in horizontal and vertical directions.

        int temp = x - 1;
        // We move in vertically downward direction in this case.
        while (temp >= 1)
        {
            // If we find a piece of same color we break the loop as there is no danger from this direction.
            if (chess.chess[temp][y].c[0] == chess.chess[x][y].c[0])
                break;

            // If we do not find an empty space means there will be presence of opponents piece, we check if the piece can be used to kill the king.
            else if (chess.chess[temp][y].c != "**")
            {
                int len = (chess.chess[temp][y].c).length();

                // If it is a 'R' or 'Q' then since they can move any number of steps vertically we return a false right away.
                if (chess.chess[temp][y].c[len-1] == 'R' || chess.chess[temp][y].c[len-1] == 'Q')
                    return false;
                // For 'K' we check if the king is only 1 step away.
                else if (chess.chess[temp][y].c[len-1] == 'K' && (x - temp == 1))
                    return false;

                // If it is none of the above pieces then we break the loop and declare the move to be valid.
                else
                    break;
            }
            temp--;
        }

        // We move in vertically upward direction in this case.
        temp = x + 1;
        while (temp <= 8)
        {

            if (chess.chess[temp][y].c[0] == chess.chess[x][y].c[0])
                break;
            else if (chess.chess[temp][y].c != "**")
            {
                int len = (chess.chess[temp][y].c).length();
                if (chess.chess[temp][y].c[len-1] == 'R' || chess.chess[temp][y].c[len-1] == 'Q')
                    return false;
                else if (chess.chess[temp][y].c[len-1] == 'K' && (temp - x == 1))
                    return false;
                else
                    break;
            }
            temp++;
        }

        //  We similarly check for the horizontally left direction.
        temp = y - 1;
        while (temp >= 1)
        {

            if (chess.chess[x][temp].c[0] == chess.chess[x][y].c[0])
                break;
            else if (chess.chess[x][temp].c != "**")
            {
                int len = (chess.chess[x][temp].c).length();
                if (chess.chess[x][temp].c[len-1] == 'R' || chess.chess[x][temp].c[len-1] == 'Q')
                    return false;
                else if (chess.chess[x][temp].c[len-1] == 'K' && (y - temp == 1))
                    return false;
                else
                    break;
            }
            temp--;
        }

        // We check for horizontally right direction.
        temp = y + 1;
        while (temp <= 8)
        {
            if (chess.chess[x][temp].c[0] == chess.chess[x][y].c[0])
                break;
            else if (chess.chess[x][temp].c != "**")
            {
                int len = (chess.chess[x][temp].c).length();
                if (chess.chess[x][temp].c[len-1] == 'R' || chess.chess[x][temp].c[len-1] == 'Q')
                    return false;
                else if (chess.chess[x][temp].c[len-1] == 'K' && (temp - y == 1))
                    return false;
                else
                    break;
            }
            temp++;
        }

        // We move in the direction of the third quadrant.
        int temp1 = x - 1;
        int temp2 = y - 1;
        while (temp1 >= 1 && temp2 >= 1)
        {
            // If we find a piece of same color we break the loop as there is no danger from this direction.
            if (chess.chess[temp1][temp2].c[0] == chess.chess[x][y].c[0])
                break;

            // If we do not find an empty space means there will be presence of opponents piece, we check if the piece can be used to kill the king.
            else if (chess.chess[temp1][temp2].c != "**")
            {
                int len = (chess.chess[temp1][temp2].c).length();
                // If it is a 'B' or 'Q' then since they can move any number of steps diagonally we return a false right away.
                if (chess.chess[temp1][temp2].c[len-1] == 'B' || chess.chess[temp1][temp2].c[len-1] == 'Q')
                    return false;
                // For the king and the pawn we check if the number of steps are valid or not (1)
                else if ((chess.chess[temp1][temp2].c[len-1] == 'K' || (chess.chess[temp1][temp2].c[len-1] == 'P' && chess.chess[temp1][temp2].c[0] == 'W')) && (x - temp1 == 1) && (y - temp2 == 1))
                    return false;
                else
                    break;
            }
            temp1--;
            temp2--;
        }

        // We move in the direction of the first quadrant.
        temp1 = x + 1;
        temp2 = y + 1;
        while (temp1 <= 8 && temp2 <= 8)
        {
            if (chess.chess[temp1][temp2].c[0] == chess.chess[x][y].c[0])
                break;
            else if (chess.chess[temp1][temp2].c != "**")
            {
                int len = (chess.chess[temp1][temp2].c).length();
                if (chess.chess[temp1][temp2].c[len-1] == 'B' || chess.chess[temp1][temp2].c[len-1] == 'Q')
                    return false;
                else if ((chess.chess[temp1][temp2].c[len-1] == 'K' || (chess.chess[temp1][temp2].c[len-1] == 'P' && chess.chess[temp1][temp2].c[0] == 'B')) && (temp1 - x == 1) && (temp2 - y == 1))
                    return false;
                else
                    break;
            }
            temp1++;
            temp2++;
        }

        // Checking in fourth quadrant
        temp1 = x - 1;
        temp2 = y + 1;
        while (temp1 >= 1 && temp2 <= 8)
        {
            if (chess.chess[temp1][temp2].c[0] == chess.chess[x][y].c[0])
                break;
            else if (chess.chess[temp1][temp2].c != "**")
            {
                int len = (chess.chess[temp1][temp2].c).length();
                if (chess.chess[temp1][temp2].c[len-1] == 'B' || chess.chess[temp1][temp2].c[len-1] == 'Q')
                    return false;
                else if ((chess.chess[temp1][temp2].c[len-1] == 'K' || (chess.chess[temp1][temp2].c[len-1] == 'P' && chess.chess[temp1][temp2].c[0] == 'W')) && (x - temp1 == 1) && (temp2 - y == 1))
                    return false;
                else
                    break;
            }
            temp1--;
            temp2++;
        }

        // Checking in second quadrant
        temp1 = x + 1;
        temp2 = y - 1;
        while (temp1 <= 8 && temp2 >= 1)
        {
            if (chess.chess[temp1][temp2].c[0] == chess.chess[x][y].c[0])
                break;
            else if (chess.chess[temp1][temp2].c != "**")
            {
                int len = (chess.chess[temp1][temp2].c).length();
                if (chess.chess[temp1][temp2].c[len-1] == 'B' || chess.chess[temp1][temp2].c[len-1] == 'Q')
                    return false;
                else if ((chess.chess[temp1][temp2].c[len-1] == 'K' || (chess.chess[temp1][temp2].c[len-1] == 'P' && chess.chess[temp1][temp2].c[0] == 'B')) && (temp1 - x == 1) && (y - temp2 == 1))
                    return false;
                else
                    break;
            }
            temp1++;
            temp2--;
        }

        // This is for the knight piece. 

        /*
            We computer all the positions from where the knight can kill the King piece and then check if there is a knight present in that position in actuality.
        */
        temp1 = x + 1;
        temp2 = y + 2;
        int len = (chess.chess[temp1][temp2].c).length();
        if (temp1 <= 8 && temp2 <= 8)
            if ((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[len-1] == 'N')
                return false;
        temp1 = x - 1;
        temp2 = y - 2;
        len = (chess.chess[temp1][temp2].c).length();
        if (temp1 >= 1 && temp2 >= 1)
            if ((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[len-1] == 'N')
                return false;
        temp1 = x + 1;
        temp2 = y - 2;
        len = (chess.chess[temp1][temp2].c).length();
        if (temp1 <= 8 && temp2 >= 1)
            if ((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[len-1] == 'N')
                return false;
        temp1 = x - 1;
        temp2 = y + 2;
        len = (chess.chess[temp1][temp2].c).length();
        if (temp1 >= 1 && temp2 <= 8)
            if ((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[len-1] == 'N')
                return false;
        temp1 = x + 2;
        temp2 = y + 1;
        len = (chess.chess[temp1][temp2].c).length();
        if (temp1 <= 8 && temp2 <= 8)
            if ((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[len-1] == 'N')
                return false;
        temp1 = x - 2;
        temp2 = y - 1;
        len = (chess.chess[temp1][temp2].c).length();
        if (temp1 >= 1 && temp2 >= 1)
            if ((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[len-1] == 'N')
                return false;
        temp1 = x + 2;
        temp2 = y - 1;
        len = (chess.chess[temp1][temp2].c).length();
        if (temp1 <= 8 && temp2 >= 1)
            if ((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[len-1] == 'N')
                return false;
        temp1 = x - 2;
        temp2 = y + 1;
        len = (chess.chess[temp1][temp2].c).length();
        if (temp1 >= 1 && temp2 <= 8)
            if ((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[len-1] == 'N')
                return false;

        // All the Rejection cases have already been encountered above 
        return true;
    }


    // Whenever the king has moved we call this function to change the internal x and y co-ordinate of the king.
    void change_coordinates(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
