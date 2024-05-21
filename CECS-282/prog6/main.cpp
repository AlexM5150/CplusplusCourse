//  Name Alex Melford
//  Class (CECS 282-01)
//  Project Name (Prog 6 – Mega War)
//  Due Date (12/08/2021)
//  I certify that this program is my own original work. I did not copy any part of this program from
//  any other source. I further certify that I typed each and every line of code in this program.
#include "Card.h"
#include "CardPile.h"
#include "Deck.h"
#include "Player.h"
#include "MegaDeck.h"
#include "WarPile.h"
#include "LostFound.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void megaWar(vector<Player*>& Winners, LostFound& lf) {
    WarPile warPile;
    int lpSize = lf.getSize();

    for(int i = 0; i < lpSize; i++)
        warPile.add(lf.deal()); 

    map<int, Card> cardNum; 
    int highcard = 0;

    vector<Player*> warW;
    int hand;
    for(Player*& pWin : Winners){
        hand = pWin->getSize();
        if(hand < 4){
            for(int i = 0; i < hand; i++)
                warPile.add(pWin->pDeal());
        }
    }
    vector<Player*>::iterator it;
    it = Winners.begin();
    while(it != Winners.end()){
        if((*it)->getSize() == 0)
            Winners.erase(it);
        else
            it++;
    }
    for(Player*& pWin : Winners){
        for (int j = 0; j < 3; j++)
            warPile.add(pWin->pDeal());
    }

    for(Player*& pWin : Winners)
        cardNum[pWin->getPos()] = pWin->pDeal(); 
    
    map<int, Card>::iterator it2;
    for(it2 = cardNum.begin(); it2 != cardNum.end(); it2++){
        int value = it2->second.CardValue();
        if(value > highcard)
            highcard = value;  
    }
    for(it2 = cardNum.begin(); it2 != cardNum.end(); it2++){ 
        if(it2->second.CardValue() == highcard){
            for(Player*& pWin : Winners){
                if(pWin->getPos() == it2->first)
                    warW.push_back(pWin);
            }
        }
    }
    for(it2 = cardNum.begin(); it2 != cardNum.end(); it2++)
        warPile.add(it2->second);  
    
    int wpSize = warPile.getSize();
    int oneW = 0; 
    if(warW.size() == 1){ 
        warW[oneW]->battleW(); 
        for(int i = 0; i < wpSize; i++) 
            warW[oneW]->bottomCard(warPile.deal());
    } 
    else{
        for(int i = 0; i < wpSize; i++)
            lf.add(warPile.deal());
        megaWar(warW, lf);
    }
}

int CardsLeft(vector<Player*>& players) { 
    int temp = 0;
    for (Player*& i : players) 
        temp = temp + i->pLeft();
    return temp;
}


int main() {
    int dSize;
    int pSize;
    vector<Player*> players;
    LostFound lf;

    cout << "Number of Decks: ";
    cin >> dSize;
    cout << "Number of players: ";
    cin >> pSize;
    for(int i = 0; i < pSize; i++){
        Player* p = new Player(i);
        players.push_back(p);
    }
    MegaDeck myDeck(dSize);
    myDeck.shuffle();

    int split = myDeck.getSize() / pSize;
    int r = myDeck.getSize() % pSize; 
    for(int i = 0; i < pSize; i++){
        for(int j = 0; j < split; j++)
            players[i]->add(myDeck.deal());
    }
    while(r > 0){
        players[0]->add(myDeck.deal());
        r--;
    }

    int numBattles = 1; 
    while (CardsLeft(players) > 1){
        map<int, Card> cardNum; 
        vector<Player*> Winners; 
        int highcard = 0;

        for(Player*& i : players){ 
            if(i->pLeft() == 1){
                i->numBattles();
                cardNum[i->getPos()] = i->pDeal(); 
            }
        }
        map<int, Card>::iterator it; 
        for(it = cardNum.begin(); it != cardNum.end(); it++){
            int value = it->second.CardValue();
            if(value > highcard)
                highcard = value;
        }
        for(it = cardNum.begin(); it != cardNum.end(); it++){
            if(it->second.CardValue() == highcard)
                Winners.push_back(players[it->first]); 
        }
        int oneW = 0;
        if(Winners.size() == 1){
            Winners[oneW]->battleW(); 
            for(it = cardNum.begin(); it != cardNum.end(); it++)
                Winners[oneW]->bottomCard(it->second);
        }
        else{ 
            for(it = cardNum.begin(); it != cardNum.end(); it++)
                lf.add(it->second);
            megaWar(Winners, lf);
        }
        cout << "Battle " << numBattles++ << " outcome: " << endl;
        for(Player*& i : players)
            i->pDisplay();
    }
}