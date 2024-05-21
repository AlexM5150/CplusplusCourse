#include "MegaDeck.h"

MegaDeck::MegaDeck(int n){
    while(n > 0){
        Deck temp;
        while(temp.getSize() > 0){
            this->add(temp.deal());
        }
        n--;
    }
}

Card MegaDeck::deal(){
    Card temp = remove();
    return temp;
}

