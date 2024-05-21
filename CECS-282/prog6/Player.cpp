#include "Player.h"
#include <iomanip>

Player::Player(int num){
    playerPos = num;
    battle = 0;
    w = 0;
}

void Player::pDisplay(){ 
    cout << setw(3) << left << "Player "  << getPos() + 1 << setw(3) <<  ":"
    << "Fierceness = " << setprecision(3) << setw(5) << Fierceness() << " Cards = "
    << setw(5) << getSize() << " Battles = " << setw(5) << getBattles() << " Wins = " << getW() << endl;
}

Card Player::pDeal(){
    Card playerCard = remove();
    return playerCard;
}

double Player::Fierceness(){
    double sum = 0.0;
    double size = getSize();
    if(size == 0)
        return 0;
    for(int i = 0; i < size; i++)
        sum = sum + this->pile[i].CardValue();
    return (sum/size);
}

int Player::pLeft(){
    if(getSize() > 0)
        return 1;
    return 0;
}

void Player::bottomCard(Card card) { 
    pile.insert(pile.begin(), card);
}

int Player::getPos() const {
    return playerPos;
}
int Player::getBattles() const{
    return battle;
}
int Player::getW() const{
    return w;
}

void Player::numBattles(){
    battle++;
}

void Player::battleW(){
    w++;
}