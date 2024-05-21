#ifndef LOSTFOUND_H
#define LOSTFOUND_H

#include "CardPile.h"

class LostFound : public CardPile{
public:
    Card deal();
};
#endif