//  Alex Melford
//  Class (CECS 282-01)
//  Project Name (Prog 1 – Solitaire Prime)
//  Due Date (9/13/2021)
// 
//  I certify that this program is my own original work. I did not copy any part of this program from 
//  any other source. I further certify that I typed each and every line of code in this program.
#include <iostream>
#include "Card.h"
#include "Deck.h"

using namespace std;

int main()
{
    Deck d;
    int choice;
    int sum = 0;
    bool isPrime(int sum);
    bool flag = true;
    int piles = 0;
    while (flag != false){
        sum = 0;
        piles = 0;
        cout << "Welcome to Solitaire Prime!\n";
        cout << " 1 - New Deck\n";
        cout << " 2 - Display Deck\n";
        cout << " 3 - Shuffle Deck\n";
        cout << " 4 - Play Solitaire Prime\n";
        cout << " 5 - Exit\n";

        cin >> choice;

        if (choice == 1){
            d.refreshDeck();
            cout << "New deck created succesfully" << endl;
        }
        else if (choice == 2){
            d.showDeck();
            cout << endl;
        }
        else if(choice == 3){
            d.shuffle();
            cout << "Deck shuffled succesfully" << endl;
        }
        else if (choice == 4){
            for (int i = 0; i < 52; i++){
                Card a = d.deal();
                sum += a.getValue();
                a.showCard();
                cout << ", ";
                if (isPrime(sum)){
                    cout << "Prime: " << sum << endl;
                    piles++;
                    sum = 0;
                }
                    
            }

            if (sum == 0){
                cout << "Winner in " << piles << " piles" << endl;
                d.refreshDeck();
            }
            else {
                cout << "sum: "<< sum << " Loser" << endl;
                d.refreshDeck();
            }
        }
        else{
            flag = false;
        }
    }

    return 0;
}

bool isPrime(int sum)
    {
        if (sum <= 1)
            return false;
        for (int i = 2; i < sum; i++)
            if (sum % i == 0)
                return false;
        return true;
    }

