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
    return rankString(myRank) + suitString(mySuit);
}
bool Card::sameSuitAs(const Card& c) const{
    if(mySuit == c.mySuit){
        return true;
    }
    return false;
}
int Card::getRank() const{
    return myRank;
}
string Card::suitString(Suit s) const{
    if(s == clubs)
        return "c";
    else if(s == diamonds)
        return "d";
    else if(s == hearts)
        return "h";
    else if(s == spades)
        return "s";
    return "";
}

string Card::rankString(int r) const{
    if(r == 1)
        return "A";
    if(r >= 2 && r <= 10){
        char val = r + 0x30;
        string temp = "" + val;
        return temp;
    }
    if(r == 11)
        return "J";
    if(r == 12)
        return "Q";
    if(r == 13)
        return "K";
    return "";
}


bool Card::operator == (const Card& rhs) const{
    if(mySuit != rhs.mySuit)
        return false;
    if(myRank != rhs.myRank)
        return false;
    return true;
}
bool Card::operator != (const Card& rhs) const{
    if(mySuit == rhs.mySuit){
        if(myRank == rhs.myRank)
            return false;
    }
    return true;
}
ostream& Card::operator << (ostream& out, const Card& c){
    out<< c.toString();
    return out;
}
