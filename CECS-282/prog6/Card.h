#ifndef CARD_H
#define CARD_H

enum SUITS {HEART, DIAMOND, SPADE, CLUB};
enum RANKS {ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

class Card {
private:
    SUITS suit;
    RANKS rank;
public:
    Card();
    Card(RANKS r, SUITS s);
    bool operator<(Card right);
    void display();
    int CardValue();
};


#endif 