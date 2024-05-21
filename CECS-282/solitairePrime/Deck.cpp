#include <iostream>
#include "Card.h"
#include "Deck.h"
#include <time.h>

using namespace std;

    Deck::Deck(){
        refreshDeck();
    }    

    void Deck::refreshDeck(){
        topCard = 0;
        char ranks[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
        char suits[4] = {'S', 'H', 'D', 'C'};
        int x = 0;
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 13; j++){
                deck[x].setCard(ranks[j], suits[i]);
                //deck[x] = Card(ranks[j], suits[i]);
                x++; 
            }
                
        }
    }

    Card Deck::deal(){
        return deck[topCard++];
    }

    void Deck::shuffle(){
        int deckSize = sizeof(deck) / sizeof(deck[0]);
        srand(time(NULL));
        for (int i = 0; i < 10000; i++){
            int a = rand() % deckSize;
            int b = rand() % deckSize;

            Card temp = deck[a];
            deck[a] = deck[b];
            deck[b] = temp;
        }
    }

    int Deck::cardsLeft(){
        return 52 - (topCard);
    }

    void Deck::showDeck(){
        int x = 0;
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 13; j++){
                deck[x].showCard();
                cout << " ";
                x++; 
            }
            cout << endl; 
        }

    }
    
