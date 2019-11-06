// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);



int main( )
{
    ofstream myFile("gofish_results.txt");

    int numCards = 7;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << "\n" << endl;

    bool gameDone = false;
    while(!gameDone){
        bool goFish = false;
        while(!goFish) {
            if(p1.getHandSize() == 0) {     //Check if hand is empty, if is,draw card and end turn
                goFish = true;
                if(d.size() > 0) {
                    Card temp = d.dealCard();
                    p1.addCard(temp);
                    myFile << p1.getName() << " draws " << temp.toString() << "\n" << endl;
                                                        myFile << d.size() << " cards left." << "\n" << endl;
                }
            }
            else {
                Card c1;
                Card c2;
                bool isBook = p1.checkHandForBook(c1, c2);      //Check if there's pair to book first
                if (isBook) {
                    p1.bookCards(c1, c2);
                    p1.removeCardFromHand(c1);
                    p1.removeCardFromHand(c2);
                    myFile << p1.getName() << " books the " << c1.rankString(c1.getRank()) << ".." << "\n" << endl;
                } else {                      //No pair already in hand
                    c1 = p1.chooseCardFromHand();                    //Choose card from hand to ask for
                    myFile << p1.getName() << " asks - Do you have a " << c1.rankString(c1.getRank()) << "?" << endl;
                    if (p2.rankInHand(c1)) {                                //If card matches rank, take card and book
                        Card tempS(c1.getRank(), Card::spades);
                        if (p2.cardInHand(tempS))
                            c2 = tempS;
                        Card tempH(c1.getRank(), Card::hearts);
                        if (p2.cardInHand(tempH))
                            c2 = tempH;
                        Card tempD(c1.getRank(), Card::diamonds);
                        if (p2.cardInHand(tempD))
                            c2 = tempD;
                        Card tempC(c1.getRank(), Card::clubs);
                        if (p2.cardInHand(tempC))
                            c2 = tempC;
                        myFile << p2.getName() << " says - Yes. I have a " << c1.rankString(c1.getRank()) << "."
                               << endl;
                        p1.bookCards(c1, c2);
                        myFile << p1.getName() << " books the " << c1.rankString(c1.getRank()) << ".." << "\n" << endl;
                        p1.removeCardFromHand(c1);
                        p2.removeCardFromHand(c2);
                        myFile << p1.getName() << " has : " << p1.showHand() << endl;
                        myFile << p2.getName() << " has : " << p2.showHand() << "\n" << endl;
                    } else {                                            //No matches "Go Fish" and end turn
                        myFile << p2.getName() << " says - Go Fish" << endl;
                        goFish = true;
                        if (d.size() > 0) {
                            Card temp = d.dealCard();
                            p1.addCard(temp);
                            myFile << p1.getName() << " draws " << temp.toString() << "\n" << endl;
                            myFile << d.size() << " cards left." << "\n" << endl;
                        }
                    }
                }
            }
        }
        if(p1.getBookSize() + p2.getBookSize() == 26)
            gameDone = true;
        if(!gameDone){
            goFish = false;
            while(!goFish) {
                if(p2.getHandSize() == 0) {     //Check if hand is empty, if is,draw card and end turn
                    goFish = true;
                    if(d.size() > 0) {
                        Card temp = d.dealCard();
                        p2.addCard(temp);
                        myFile << p2.getName() << " draws " << temp.toString() << "\n" << endl;
                                                             myFile << d.size() << " cards left." << "\n" << endl;
                    }
                }
                else {
                     Card c1;
                     Card c2;
                     bool isBook = p2.checkHandForBook(c1, c2);      //Check if there's pair to book first
                     if (isBook) {
                             p2.bookCards(c1, c2);
                             p2.removeCardFromHand(c1);
                             p2.removeCardFromHand(c2);
                             myFile << p2.getName() << " books the " << c1.rankString(c1.getRank()) << ".." << "\n" << endl;
                     }
                     else {                      //No pair already in hand
                            c1 = p2.chooseCardFromHand();                    //Choose card from hand to ask for
                            myFile << p2.getName() << " asks - Do you have a " << c1.rankString(c1.getRank()) << "?" << endl;
                            if (p1.rankInHand(c1)) {                                //If card matches rank, take card and book
                                Card tempS(c1.getRank(), Card::spades);
                                if (p1.cardInHand(tempS))
                                   c2 = tempS;
                                Card tempH(c1.getRank(), Card::hearts);
                                if (p1.cardInHand(tempH))
                                   c2 = tempH;
                                Card tempD(c1.getRank(), Card::diamonds);
                                 if (p1.cardInHand(tempD))
                                   c2 = tempD;
                                Card tempC(c1.getRank(), Card::clubs);
                                if (p1.cardInHand(tempC))
                                   c2 = tempC;
                                myFile << p1.getName() << " says - Yes. I have a " << c1.rankString(c1.getRank()) << "." << endl;
                                p2.bookCards(c1, c2);
                                myFile << p2.getName() << " books the " << c1.rankString(c1.getRank()) << ".." << "\n" << endl;
                                p2.removeCardFromHand(c1);
                                p1.removeCardFromHand(c2);
                                                                myFile << p1.getName() <<" has : " << p1.showHand() << endl;
                                                                myFile << p2.getName() <<" has : " << p2.showHand() << "\n" << endl;
                            }
                            else {                                            //No matches "Go Fish" and end turn
                                myFile << p1.getName() << " says - Go Fish" << endl;
                                goFish = true;
                                if (d.size() > 0) {
                                    Card temp = d.dealCard();
                                    p2.addCard(temp);
                                    myFile << p2.getName() << " draws " << temp.toString() << "\n" << endl;
                                    myFile << d.size() << " cards left." << "\n" << endl;
                                }
                            }
                    }
                }
            }
        }
        if(p1.getBookSize() + p2.getBookSize() == 26)
            gameDone = true;
//        gameDone = true;
    }
    if(p1.getBookSize() > p2.getBookSize()){
        myFile << p1.getName() << " Wins!" << endl;
    }
    if(p1.getBookSize() < p2.getBookSize()){
        myFile << p2.getName() << " Wins!" << endl;
    }
    if(p1.getBookSize() == p2.getBookSize()){
        myFile << "Its a draw!" << endl;
    }

    myFile.close();
    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}


   


