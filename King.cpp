#include <bits/stdc++.h>
using namespace std;

// Class for implementing the Piece King.
class king
{
public:
    int x;         // This keeps the track of the current x coordinate of King
    int y;         // This keeps the track of the current y coordinate of King
    char color;    // This stores 'W' or 'B' depending on the color of the king.
    int movements; // Keeps track of how many moves has been done by this piece.

    // Constructor for the piece of the king.
    king(char color, int x, int y)
    {
        this->color = color; // We pass the color of the piece.
        this->x = x;         // We initiate the original position of the king in the beginning (x).
        this->y = y;         // We initiate the original position of the king in the beginning (y).
        this->movements = 0; // Initially 0 moves have been done by King's piece
    }

    // This Checks if the place where we want the king to move is accessible
    /*
        Logic:
            ** A king can move in any direction but the only condition is that it can only move 1 step.
            ** Hence we use this logic to check the validity of a move.
    */

    bool is_possible(int x, int y, chessboard chess, int k)
    {
        int temp1 = abs(x - this->x); // The absolute difference between new x-coordinate and original x-coordinate
        int temp2 = abs(y - this->y); // The absolute difference between new y-coordinate and original y-coordinate

        /*
            This checks for castling. The current position of the king is unmoved and we are trying to
            move it in place of rook.
        */
        if ((this->x == 1 || this->x == 8) && this->y == 5 && this->movements == 0 && (x == 1 || x == 8) && y == 7 && k == 0)
        {
            if (chess.chess[x][y].c == "**" && chess.chess[x][y - 1].c == "**")
                return true;
        }

        // If this isn't the case we check if the difference in the coordinates is less than or equal to 1
        // And both of the differences aren't 0 (case of no motion.)

        else if ((temp1 <= 1 && temp2 <= 1) && !(temp1 == 0 && temp2 == 0))
        {
            // This ensures that the place where the king wants to go doesn't have a piece of same color.
            if ((chess.chess[x][y].c[0] != chess.chess[this->x][this->y].c[0]))
                return true;

            // If there is piece of same color then it returns a false.
            return false;
        }

        // In all the other cases we return a false.
        return false;
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
        // We move in left direction in this case.
        while (temp >= 1)
        {

            // If we find a piece of same color we break the loop as there is no danger from this direction.
            if (chess.chess[temp][y].c[0] == chess.chess[x][y].c[0])
                break;

            // If we find the piece of different color we check if the piece can be used to kill the king.
            else if (chess.chess[temp][y].c[0] != chess.chess[x][y].c[0] && !(chess.chess[temp][y].c == "**"))
            {

                // If it is a 'R' or 'Q' then since they can move any number of steps we return a false right away.
                if (chess.chess[temp][y].c[1] == 'R' || chess.chess[temp][y].c[1] == 'Q')
                    return false;
                // For 'K' we check if the king is only 1 step away.
                else if (chess.chess[temp][y].c[1] == 'K' && abs(temp - x) == 1)
                    return false;

                // If it is none then we break the loop and declare the mood to be valid.
                else
                    break;
            }
            temp--;
        }

        // We move in right direction in this case.
        temp = x + 1;
        while (temp <= 8)
        {

            if (chess.chess[temp][y].c[0] == chess.chess[x][y].c[0])
                break;
            else if (chess.chess[temp][y].c[0] != chess.chess[x][y].c[0] && !(chess.chess[temp][y].c == "**"))
            {
                if (chess.chess[temp][y].c[1] == 'R' || chess.chess[temp][y].c[1] == 'Q')
                    return false;
                else if (chess.chess[temp][y].c[1] == 'K' && abs(temp - x) == 1)
                    return false;
                else
                    break;
            }
            temp++;
        }

        //  We similarly check for the upward direction.
        temp = y - 1;
        while (temp >= 1)
        {

            if (chess.chess[x][temp].c[0] == chess.chess[x][y].c[0])
                break;
            else if (chess.chess[x][temp].c[0] != chess.chess[x][y].c[0] && !(chess.chess[temp][y].c == "**"))
            {
                if (chess.chess[x][temp].c[1] == 'R' || chess.chess[x][temp].c[1] == 'Q')
                    return false;
                else if (chess.chess[x][temp].c[1] == 'K' && abs(temp - y) == 1)
                    return false;
                else
                    break;
            }
            temp--;
        }

        // We check for downward direction.
        temp = y + 1;
        while (temp <= 8)
        {

            if (chess.chess[x][temp].c[0] == chess.chess[x][y].c[0])
                break;
            else if (chess.chess[x][temp].c[0] != chess.chess[x][y].c[0] && !(chess.chess[temp][y].c == "**"))
            {
                if (chess.chess[x][temp].c[1] == 'R' || chess.chess[x][temp].c[1] == 'Q')
                    return false;
                else if (chess.chess[x][temp].c[1] == 'K' && abs(temp - y) == 1)
                    return false;
                else
                    break;
            }
            temp++;
        }

        // We move in the direction of the third co-ordinate.
        int temp1 = x - 1;
        int temp2 = y - 1;
        while (temp1 >= 1 && temp2 >= 1)
        {
            // If we find a piece of same color we break the loop as there is no danger from this direction.
            if (chess.chess[temp1][temp2].c[0] == chess.chess[x][y].c[0])
                break;

            // If we find a piece of different color we check for other conditions.
            else if (chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0] && !(chess.chess[temp1][temp2].c == "**"))
            {
                // If we find a 'B' (Bishop) or a 'Q' then we return false right away.
                if (chess.chess[temp1][temp2].c[1] == 'B' || chess.chess[temp1][temp2].c[1] == 'Q')
                    return false;
                // For the king we check if the number of steps are valid or not (1)
                else if ((chess.chess[temp1][temp2].c[1] == 'K' || chess.chess[temp1][temp2].c[1] == 'P') && (x - temp1) == 1 && (y - temp2) == 1)
                    return false;
                else
                    break;
            }
            temp1--;
            temp2--;
        }

        // Checking in first quadrant
        temp1 = x + 1;
        temp2 = y + 1;
        while (temp1 <= 8 && temp2 <= 8)
        {
            if (chess.chess[temp1][temp2].c[0] == chess.chess[x][y].c[0])
                break;
            else if (chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0] && !(chess.chess[temp1][temp2].c == "**"))
            {
                if (chess.chess[temp1][temp2].c[1] == 'B' || chess.chess[temp1][temp2].c[1] == 'Q')
                    return false;
                else if ((chess.chess[temp1][temp2].c[1] == 'K' || chess.chess[temp1][temp2].c[1] == 'P') && (temp1 - x) == 1 && (temp2 - y) == 1)
                    return false;
                else
                    break;
            }
            temp1++;
            temp2++;
        }

        // Checking in second quadrant
        temp1 = x - 1;
        temp2 = y + 1;
        while (temp1 >= 1 && temp2 <= 8)
        {
            if (chess.chess[temp1][temp2].c[0] == chess.chess[x][y].c[0])
                break;
            else if (chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0] && !(chess.chess[temp1][temp2].c == "**"))
            {
                if (chess.chess[temp1][temp2].c[1] == 'B' || chess.chess[temp1][temp2].c[1] == 'Q')
                    return false;
                else if ((chess.chess[temp1][temp2].c[1] == 'K' || chess.chess[temp1][temp2].c[1] == 'P') && (x - temp1) == 1 && (temp2 - y) == 1)
                    return false;
                else
                    break;
            }
            temp1--;
            temp2++;
        }

        // Checking in fourth quadrant
        temp1 = x + 1;
        temp2 = y - 1;
        while (temp1 <= 8 && temp2 >= 1)
        {

            if (chess.chess[temp1][temp2].c[0] == chess.chess[x][y].c[0])
                break;
            else if (chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0] && !(chess.chess[temp1][temp2].c == "**"))
            {
                if (chess.chess[temp1][temp2].c[1] == 'B' || chess.chess[temp1][temp2].c[1] == 'Q')
                    return false;
                else if ((chess.chess[temp1][temp2].c[1] == 'K' || chess.chess[temp1][temp2].c[1] == 'P') && (temp1 - x) == 1 && (y - temp2) == 1)
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
        if (temp1 <= 8 && temp2 <= 8)
            if ((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[1] == 'N')
                return false;
        temp1 = x - 1;
        temp2 = y - 2;
        if (temp1 >= 1 && temp2 >= 1)
            if ((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[1] == 'N')
                return false;
        temp1 = x + 1;
        temp2 = y - 2;
        if (temp1 <= 8 && temp2 >= 1)
            if ((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[1] == 'N')
                return false;
        temp1 = x - 1;
        temp2 = y + 2;
        if (temp1 >= 1 && temp2 <= 8)
            if ((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[1] == 'N')
                return false;
        temp1 = x + 2;
        temp2 = y + 1;
        if (temp1 <= 8 && temp2 <= 8)
            if ((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[1] == 'N')
                return false;
        temp1 = x - 2;
        temp2 = y - 1;
        if (temp1 >= 1 && temp2 >= 1)
            if ((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[1] == 'N')
                return false;
        temp1 = x + 2;
        temp2 = y - 1;
        if (temp1 <= 8 && temp2 >= 1)
            if ((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[1] == 'N')
                return false;
        temp1 = x - 2;
        temp2 = y + 1;
        if (temp1 >= 1 && temp2 <= 8)
            if ((chess.chess[temp1][temp2].c[0] != chess.chess[x][y].c[0]) && chess.chess[temp1][temp2].c[1] == 'N')
                return false;
        return true;
    }


    // Whenever the king has moved we call this function to finalize the movement and change the internal x and y co-ordinate of the king.
    void change_coordinates(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
