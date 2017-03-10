#include "Game.h"
#include "PlayerAI.h"

#include <iostream>
using namespace std;

Game::Game()
{
    x = nullptr;
    o = nullptr;
}

Game::~Game() {
    
}

void Game::runGame() {
    int players = 0;
    while (true) {
        cout << "How many players (1 or 2): ";
        cin >> players;
        
        if (players != 1 && players != 2) {
            cout << "Invalid input. Try again." << endl;
            continue;
        }
        
        break;
    }
    
    bool suggestions = false;
    while (true) {
        string input;
        cout << "Enable suggestions (yes or no)? ";
        cin >> input;
        
        if (input == "yes") {
            suggestions = true;
            break;
        }
        else if (input == "no") {
            suggestions = false;
            break;
        }
        else {
            cout << "Invalid input. Try again." << endl;
        }
    }
    
    x = new Player('x'); // always human
    
    // do we need to make an AI?
    if (players == 1) {
        o = new PlayerAI('o');
    }
    else {
        o = new Player('o');
    }
    
    Player* current = x;
    
    while (true) {
        // display board on every turn
        board.displayBoard();
        
        if (suggestions) {
            board.makeSuggestion(current);
        }
        
        int column = current->askForColumn();
        
        // add the piece to a column and make sure that the column wasn't full
        bool added = board.addToColumn(current, column - 1);
        if (!added) {
            cout << "Column " << column
                    << " is full. Please make another selection." << endl;
            continue;
        }
        
        // check if the player won by adding the last piece to the board
        if (board.checkWin()) {
            board.displayBoard();
            cout << "Player " << current->getSymbol()
                    << " wins! Congratulations!" << endl;
            break;
        }
        
        // switch the currently active player
        if (current->getSymbol() == x->getSymbol()) {
            current = o;
        }
        else {
            current = x;
        }
    }
}