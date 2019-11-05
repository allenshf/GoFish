#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <ctime>
#include "card.h"
#include "deck.h"

using namespace std;


Deck::Deck(){
    myIndex = 0;
    srand((unsigned)time(0));
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
        printf("Deck full");
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
