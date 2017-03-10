#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player(char symbol);
    ~Player();
    
    // return the symbol representing a particular player
    char getSymbol();
    
    virtual int askForColumn();
    
private:
    char symbol;
};

#endif

