#include "Piece.h"

#include <iostream>

Piece::Piece()
{
    owner = nullptr;
}

Piece::~Piece() {

}

Player* Piece::getOwner() {
    return owner;
}

void Piece::setOwner(Player* player) {
    owner = player;
}

bool Piece::isOwned() {
    if (owner == nullptr) {
        return false;
    }
    
    return true;
}

bool Piece::isSameOwner(Piece piece) {
    if (owner == nullptr || piece.getOwner() == nullptr) {
        return false;
    }
    
    if (owner->getSymbol() == piece.getOwner()->getSymbol()) {
        return true;
    }
    else {
        return false;
    }
}