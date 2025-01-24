#include "include/Cards.h"
#include <memory>
#include <string.h>
#include <algorithm>
#include <random>
#include <iterator>
#include <chrono>
#include <iostream>

Deck::Deck(int size = 1){
    for(int d = 0; d< size; d++){
        for(int s = 0;s < strlen(SUITS); s++){
            for(int f = 0; f< sizeof(VALUES)/sizeof(int);f++){
                std::shared_ptr<Card> c(new Card); 
                c->face=FACES[f];
                c->suit = SUITS[s];
                c->value = VALUES[f];
                cards.push_back(c);
            }
        }
    }
}

void Deck::shuffle(){
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(std::begin(cards), std::end(cards), std::default_random_engine(seed));
}

shared_ptr<Card> Deck::deal(){

    shared_ptr<Card> c = cards.back();
    cards.pop_back();
    return c;
}


shared_ptr<Card> getCard(Deck& deck){
    return deck.deal();
}

ostream& Card::printCard(ostream& out){
    out << this->face << this->suit << ' ';
    return out;
}

void Hand::printHand(ostream& out){
    for(int i=0; i<this->cards.size(); i++)
    cards.at(i)->printCard(out);
    return;
}

void Hand::draw(Deck& deck){
    cards.push_back(deck.deal());
}








int main(){
    Deck* deck = new Deck();
    deck->shuffle();
    Hand hand;
    hand.draw(*deck);
    hand.draw(*deck);
    hand.draw(*deck);
    hand.draw(*deck);
    hand.printHand(cout);

    

    return 0;
}