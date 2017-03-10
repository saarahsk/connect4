#include "Player.h"

#include <iostream>
using namespace std;

Player::Player(char s)
{
    symbol = s;
}

Player::~Player() {

}

char Player::getSymbol() {
    return symbol;
}

int Player::askForColumn() {
    while (true) {
        cout << "Player " << symbol << ", enter a column number from 1 to 7: ";
        
        // get the column the user wants to add a piece to
        int column = 0;
        cin >> column;
        if (column < 1 || column > 7) {
            cout << "Invalid input. Please select a number between 1 to 7." << endl;
            continue;
        }
        
        return column;
    }
}