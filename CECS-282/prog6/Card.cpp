#include "Card.h"

#include <iostream>

using namespace std;

Card::Card() {
    suit = HEART;
    rank = ACE;
}

Card::Card(RANKS r, SUITS s) {
    suit = s;
    rank = r;
}

bool Card::operator<(Card right){
    return rank <right.rank?true:false;
}

void Card::display() {
    string chosenSuit;
    string chosenRank;

    switch (rank) {
        case ACE:
            chosenRank = "ACE";
            break;
        case TWO:
            chosenRank = "2";
            break;
        case THREE:
            chosenRank = "3";
            break;
        case FOUR:
            chosenRank = "4";
            break;
        case FIVE:
            chosenRank = "5";
            break;
        case SIX:
            chosenRank = "6";
            break;
        case SEVEN:
            chosenRank = "7";
            break;
        case EIGHT:
            chosenRank = "8";
            break;
        case NINE:
            chosenRank = "9";
            break;
        case TEN:
            chosenRank = "TEN";
            break;
        case JACK:
            chosenRank = "JACK";
            break;
        case QUEEN:
            chosenRank = "QUEEN";
            break;
        case KING:
            chosenRank = "KING";
            break;
    }
    cout << chosenRank << " of ";

    switch (suit) {
        case HEART:
            chosenSuit = "HEART";
            break;
        case DIAMOND:
            chosenSuit = "DIAMOND";
            break;
        case SPADE:
            chosenSuit = "SPADE";
            break;
        case CLUB:
            chosenSuit = "CLUB";
            break;
    }

    cout << chosenSuit;
}

int Card::CardValue() {
    switch (rank) {
        case ACE:
            return 1;
        case TWO:
            return 2;
        case THREE:
            return 3;
        case FOUR:
            return 4;
        case FIVE:
            return 5;
        case SIX:
            return 6;
        case SEVEN:
            return 7;
        case EIGHT:
            return 8;
        case NINE:
            return 9;
        case TEN:
            return 10;
        case JACK:
            return 11;
        case QUEEN:
            return 12;
        case KING:
            return 13;
    }
}