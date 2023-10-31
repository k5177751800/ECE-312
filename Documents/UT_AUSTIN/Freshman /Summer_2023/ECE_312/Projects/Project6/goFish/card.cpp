//Konghwan Shin
//KS54897
//Project 6
#include "card.h"

Card::Card() {
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s) {
    myRank = rank;
    mySuit = s;
}

string Card::toString() const {
    return rankString(myRank) + suitString(mySuit);
}

bool Card::sameSuitAs(const Card& c) const {
    return mySuit == c.mySuit;
}

int Card::getRank() const{
    return myRank;
}

string Card::suitString(Suit s) const{
    string suit;
    if (s == spades){
        suit = 's';
    } else if (s == hearts){
        suit = 'h';
    } else if(s == diamonds){
        suit = 'd';
    } else if (s == clubs){
        suit = 'c';
    }

    return suit;
}

string Card::rankString(int r) const{
    const std::string rankStrings[] = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    // Check if the rank is within the valid range
    if (r >= 1 && r <= 13) {
        return rankStrings[r];
    } else {
        return "Invalid Rank";
    }
}

bool Card::operator==(const Card& rhs) const {
    return myRank == rhs.myRank && mySuit == rhs.mySuit;
}

bool Card::operator!=(const Card& rhs) const {
    return !(*this == rhs);
}

ostream& operator<<(ostream& out, const Card& c)
{
    out << c.toString();
    return out;
}