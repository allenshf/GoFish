#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"

using namespace std;

Card::Card(){

    mySuit = spades;
    myRank = 1;
}

Card::Card(int rank, Card::Suit s) {
    mySuit = s;
    myRank = rank;
}

string Card::toString() const{
    return"";
}
bool Card::sameSuitAs(const Card& c) const{
    return false;
}
int Card::getRank() const{
    return myRank;
}
string Card::suitString(Suit s) const{
    return"";
}

string Card::rankString(int r) const{
    return"";
}


bool Card::operator == (const Card& rhs) const{
    return false;
}
bool Card::operator != (const Card& rhs) const{
    return false;
}
ostream& Card::operator << (ostream& out, const Card& c){
    out<<c.myRank;
    return out;
}
