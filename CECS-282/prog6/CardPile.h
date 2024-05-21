#ifndef CARDPILE_H
#define CARDPILE_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Card.h"
#include "time.h"

using namespace std;

class CardPile {
protected:
    vector<Card> pile;
public:
    void add(Card c);

    Card remove();

    void display();

    int getSize();

    Card deal();

    void shuffle();
};


#endif