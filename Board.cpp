#include "Board.h"

#include <iostream>
using namespace std;

Board::Board() {

}

Board::~Board() {

}

void Board::displayBoard() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            Piece piece = board[i][j];
            Player* player = piece.getOwner();
            
            if (player == nullptr) {
                cout << ".";
            }
            else {
                cout << player->getSymbol();
            }
            
            cout << " ";
        }
        
        cout << endl;
    }
    
    cout << "1 2 3 4 5 6 7" << endl;
}

bool Board::checkWin() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (!board[i][j].isOwned()) {
                continue;
            }
            
            if (checkDown(i, j)) {
                return true;
            }
            
            if (checkRight(i, j)) {
                return true;
            }
            
            if (checkDiagonal(i, j)) {
                return true;
            }
        }
    }
    
    return false;
}

bool Board::checkDown(int row, int column) {
    for (int i = 1; i < 4; i++) {
        if (row + i > 5) {
            return false;
        }
        
        if (!board[row][column].isSameOwner(board[row + i][column])) {
            return false;
        }
    }
    
    return true;
}

bool Board::checkRight(int row, int column) {
    for (int i = 1; i < 4; i++) {
        if (column + i > 6) {
            return false;
        }
        
        if (!board[row][column].isSameOwner(board[row][column + i])) {
            return false;
        }
    }
    
    return true;
}

bool Board::checkDiagonal(int row, int column) {
    for (int i = 1; i < 4; i++) {
        if (row + i > 5 || column + i > 6) {
            return false;
        }
        
        if (!board[row][column].isSameOwner(board[row + i][column + i])) {
            return false;
        }
    }
    
    return true;
}

bool Board::addToColumn(Player* p, int column) {
    for (int i = 5; i >= 0; i--) {
        Piece& piece = board[i][column];
        
        if (piece.isOwned()) {
            continue;
        }
        else {
          piece.setOwner(p);
          return true;
        }
    }

    return false;
}

void Board::makeSuggestion(Player* player) {
    for (int i = 0; i < 7; i++) {
        bool added = addToColumn(player, i);
        
        if (checkWin()) {
            cout << "HINT: Add a piece to column " << i + 1 << " to win!" << endl;
        }
        
        if (added) {
            removeFromColumn(i);
        }
    }
}

void Board::removeFromColumn(int column) {
    for (int i = 0; i < 6; i++) {
        Piece& piece = board[i][column];
        
        if (piece.isOwned()) {
            piece.setOwner(nullptr);
            break;
        }
    }
}

