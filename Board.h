#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"

class Board {
public:
    Board();
    ~Board();

    // prints the board after each turn
    void displayBoard();
    
    // check if the board has a winning player on it
    bool checkWin();
    
    // adds a piece to the available position in a given column
    bool addToColumn(Player* player, int column);
    
    // analyzes the game board and makes a suggestion on which column to select
    void makeSuggestion(Player* player);

private:
    // check for a downward win given a row and a column
    bool checkDown(int row, int column);
    
    // check for a right win given a row and a column
    bool checkRight(int row, int column);
    
    // check for a diagonal right win given a row and column
    bool checkDiagonal(int row, int column);
    
    void removeFromColumn(int column);
    
    Piece board[6][7];
};

#endif

