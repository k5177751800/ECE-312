//Konghwan Shin
//KS54897
//Project 6
#include "deck.h"
#include <random>
//Constructor for Deck
Deck::Deck() {
    myIndex = SIZE - 1;

    int cardIndex = 0;
    for (int rank = 1; rank <= 13; ++rank) {
        for (Card::Suit suit : {Card::spades, Card::hearts, Card::diamonds, Card::clubs}) {
            myCards[cardIndex++] = Card(rank, suit);
        }
    }
}

void Deck::shuffle() {

    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = SIZE - 1; i > 0; i--) {
        std::uniform_int_distribution<int> dist(0, i);
        int j = dist(gen);
        std::swap(myCards[i], myCards[j]);
    }

    myIndex = SIZE - 1;
}

Card Deck::dealCard() {
    if (myIndex >= 0) {
        return myCards[myIndex--];
    }
    else { //return funtion for fail
        return Card();
    }
}

int Deck::size() const {
    return myIndex + 1;
}