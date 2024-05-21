#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"

class Player : public CardPile{
private:
    int playerPos;
    int battle;
    int w;

public:
    Player(int n);
    Card pDeal();
    void numBattles();
    void battleW();
    void bottomCard(Card c);
    void pDisplay();
    int getBattles() const;
    int getW() const;
    int pLeft();
    int getPos() const;
    double Fierceness();
};
#endif