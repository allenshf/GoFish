#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <ctime>

#include "card.h"
#include "deck.h"

using namespace std;


Deck::Deck(){
    myIndex = 0;
    srand((unsigned)time(0));
    int i = 0;
    for(int j = 1; j <= 13; j++){
        Card temp(j,Card::spades);
        myCards[i] = temp;
        i++;
    }
    for(int j = 1; j <= 13; j++){
        Card temp(j,Card::hearts);
        myCards[i] = temp;
        i++;
    }
    for(int j = 1; j <= 13; j++){
        Card temp(j,Card::diamonds);
        myCards[i] = temp;
        i++;
    }
    for(int j = 1; j <= 13; j++){
        Card temp(j,Card::clubs);
        myCards[i] = temp;
        i++;
    }
}

void Deck::shuffle(){
    int numCards = SIZE;
    for(int i = 0; i < SIZE*2; i++){
        int firstCardIndex = (rand() % numCards);
        int secondCardIndex = (rand() % numCards);
        Card temp = myCards[secondCardIndex];
        myCards[secondCardIndex] = myCards[firstCardIndex];
        myCards[firstCardIndex] = temp;
    }
}
Card Deck::dealCard() {
    if (myIndex == SIZE){
        cout << "Deck full";
        Card temp;              //Return default if nothing *FIX ThIS*
        return temp;
    }
    Card top = myCards[myIndex];
    myIndex++;
    return top;
}

int  Deck::size() const{
    return SIZE - myIndex;
}
