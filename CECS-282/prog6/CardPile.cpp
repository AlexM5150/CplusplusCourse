#include "CardPile.h"

void CardPile::add(Card c) {
    pile.push_back(c);
}

Card CardPile::remove() {
    Card temp = pile[pile.size() - 1];
    pile.pop_back();
    return temp;
}

void CardPile::display() {
    for (int i = 0; i < pile.size(); i++) {
        pile[i].display();
        cout << "\n";
    }
}

int CardPile::getSize() {
    return pile.size();
}

Card CardPile::deal() {
    Card topCard = pile.front();
    remove();
    return topCard;
}

void CardPile::shuffle() {
    srand(time(NULL));
    for (int i = 0; i < pile.size(); i++) {
        int n = rand() % pile.size();
        Card temp = pile[i];
        pile[i] = pile[n];
        pile[n] = temp;
    }
}