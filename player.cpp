#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

Player::Player(){

}


void Player::addCard(Card c){
    myHand.push_back(c);
}
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
    for(Card temp: myHand){
        if(temp.getRank() == c.getRank())
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
    for(Card temp : myHand){
        if(temp == c)
            return true;
    }
    return false;
}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
    Card removed;
    for(vector<Card>::iterator it = myHand.begin(); it != myHand.end();it++){
        if(*it == c){
            removed = *it;
            myHand.erase(it);
        }
    }
    return removed;
}

string Player::showHand() const{
    string out ="";
    for(Card c:myHand){
        out += c.toString() + " ";
    }
    return out;
}
string Player::showBooks() const{
    string out = "";
    for(int i = 0; i < myBook.size(); i+=2){
        out += myBook[i].toString() + " & " + myBook[i+1].toString() + " ";
    }
    return out;
}

int Player::getHandSize() const{
    return myHand.size();
}
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