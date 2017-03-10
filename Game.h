#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

class Game {
public:
    Game();
    ~Game();
    
    void runGame();
    
private:
    Player* x;
    Player* o;
    
    Board board;
};

#endif

