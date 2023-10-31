//Konghwan Shin
//KS54897
//Project 6
#include "player.h"

Player::Player(){
    // Default constructor
    myName = "";
}

void Player::addCard(Card c){
    // Adds a card to the player's hand
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    removeCardFromHand(c1);

    myBook.push_back(c2);
    removeCardFromHand(c2);
}

bool Player::checkHandForBook(Card& c1, Card& c2){
    for (size_t i = 0; i < myHand.size(); i++) {
        for (size_t j = i + 1; j < myHand.size(); j++) {
            if (myHand[i].getRank() == myHand[j].getRank() && !myHand[i].sameSuitAs(myHand[j])) {
                c1 = myHand[i];
                c2 = myHand[j];
                return true;
            }
        }
    }
    return false;
}

bool Player::rankInHand(Card c) const{
    for (const auto& card : myHand) {
        if (card.getRank() == c.getRank() && card != c) {
            return true;
        }
    }
    return false;
}


Card Player::chooseCardFromHand() const{
    int cardC = rand() % getHandSize();

    return myHand[cardC];
}

bool Player::cardInHand(Card c) const{
    for (const auto& card : myHand) {
        if (card == c) {
            return true;
        }
    }
    return false;}

Card Player::removeCardFromHand(Card c){
    for (auto iter = myHand.begin(); iter != myHand.end(); ++iter) {
        if (*iter == c) {
            Card removedCard = *iter;
            myHand.erase(iter);
            return removedCard;
        }
    }
    return Card();
}


string Player::showHand() const{
    string work;

    vector<Card>::const_iterator iter;
    for (iter = myHand.begin(); iter != myHand.end(); iter++) {
        work += iter->toString() + " ";
    }
    return (work);
}

string Player::showBooks() const{
    string work;
    for (const Card& card : myBook) {
        work += card.toString() + " ";
    }
    return work;
}

int Player::getHandSize() const{
    return myHand.size();
}

int Player::getBookSize() const {
    return myBook.size() / 2;
}

bool Player::checkHandForPair(Card& c1, Card& c2) {

    return checkHandForBook(c1, c2);
}

bool Player::sameRankInHand(Card c) const {
    int rCount = 0;
    for (const auto& card : myHand) {
        if (card.getRank() == c.getRank()) {
            rCount++;
            if (rCount > 1) {
                return true;
            }
        }
    }
    return false;

}
