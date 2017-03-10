#ifndef PIECE_H
#define PIECE_H

#include "Player.h"

class Piece {
public:
    Piece();
    ~Piece();
    
    // returns the owner of this piece, could be a non-owner ('.'))
    Player* getOwner();
    
    // update the owner of this particular piece to a real player
    void setOwner(Player* player);
    
    // returns true if the piece is used/owned
    bool isOwned();
    
    // returns true if this piece and the incoming piece have the same owner
    bool isSameOwner(Piece piece);
    
    
private:
    Player* owner;
    
};

#endif

