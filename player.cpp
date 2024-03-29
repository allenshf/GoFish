//Player.cpp file
// Names: Allen Shufer and Ryan Root
// EID: as87226 and rmr3494
// Section: 16045

#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

//default constructor
Player::Player(){

}

//adds a card to hand
void Player::addCard(Card c){
    myHand.push_back(c);
}

//books pair of cards
void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForBook(Card &c1, Card &c2){
    for(int i = 0; i < myHand.size();i++){
        for(int j = i+1; j < myHand.size();j++){
            if(myHand[i].getRank() == myHand[j].getRank()){
                c1 = myHand[i];
                c2 = myHand[j];
                return true;
            }
        }
    }
    return false;
}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const{
    for(int i = 0; i < myHand.size(); i++){
        if(myHand[i].getRank() == c.getRank())
            return true;
    }
    return false;
}

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const{
    int index = rand() % myHand.size();
    return myHand[index];
}

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{
    for(int i = 0; i < myHand.size(); i++){
        if(myHand[i] == c)
            return true;
    }
    return false;
}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
    Card removed;
    for(int i = 0; i < myHand.size();i++){
        Card temp = myHand[i];
        if(temp == c){
            removed = temp;
            myHand.erase(myHand.begin() + i);
        }
    }
    return removed;
}

//Shows the hand
string Player::showHand() const{
    string out ="";
    for(int i = 0; i < myHand.size(); i++){
        out += myHand[i].toString() + " ";
    }
    return out;
}

//Shows booked pairs
string Player::showBooks() const{
    string out = "";
    for(int i = 0; i < myBook.size(); i+=2){
        out += myBook[i].toString() + " & " + myBook[i+1].toString() + " ";
    }
    return out;
}

//returns hand size
int Player::getHandSize() const{
    return myHand.size();
}

//returns booked pairs
int Player::getBookSize() const{
    return myBook.size() / 2;
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

//bool Player::checkHandForPair(Card &c1, Card &c2){
//    return false;
//}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c

//bool Player::sameRankInHand(Card c) const{
//    return false;
//}
