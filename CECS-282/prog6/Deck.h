#ifndef DECK_H
#define DECK_H

#include "CardPile.h"

class Deck : public CardPile{
public:
    Deck();
    Card deal();
};
#endif