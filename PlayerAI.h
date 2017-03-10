#ifndef PLAYERAI_H
#define PLAYERAI_H

#include "Player.h"

class PlayerAI : public Player {
public:
    PlayerAI(char symbol);
    ~PlayerAI();

    virtual int askForColumn();

private:

};

#endif

