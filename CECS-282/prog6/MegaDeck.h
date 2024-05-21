#ifndef MEGADECK_H
#define MEGADECK_H

#include "Deck.h"

class MegaDeck : public Deck {
public:
    MegaDeck(int n);
    Card deal();
};
#endif