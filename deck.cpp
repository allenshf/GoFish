#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <ctime>;
#include "card.h"
#include "deck.h"

using namespace std;


Deck::Deck(){
    myIndex = 0;
    srand((unsigned)time(0));
}

void Deck::shuffle(){

}
Card Deck::dealCard(){

    return myCards[myIndex];
}

int  Deck::size() const{
    return 0;
}

Deck::~Deck(){

}