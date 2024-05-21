#include "Deck.h"

Deck::Deck(){
    for(SUITS s = DIAMOND; s <= CLUB; s = SUITS(s + 1)){
        for(RANKS r = ACE; r <= KING; r = RANKS(r + 1)){
            Card c(r,s);
            add(c);
        }
    }
}

Card Deck::deal(){
    return remove();
}