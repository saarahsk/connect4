#include "PlayerAI.h"

#include <iostream>
using namespace std;

PlayerAI::PlayerAI(char symbol) : Player(symbol) {
    srand(time(nullptr));
}

PlayerAI::~PlayerAI() {

}

int PlayerAI::askForColumn() {
    return rand() % 7;
}