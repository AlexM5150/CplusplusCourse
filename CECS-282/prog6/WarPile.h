#ifndef WARPILE_H
#define WARPILE_H

#include "CardPile.h"

class WarPile : public CardPile {
public:
    Card deal();
};
#endif