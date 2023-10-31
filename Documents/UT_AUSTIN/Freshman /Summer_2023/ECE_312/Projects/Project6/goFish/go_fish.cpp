//Konghwan Shin
//KS54897
//Project 6
#include "card.h"
#include "player.h"
#include "deck.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    srand(time(NULL));
    ofstream expFile("gofish_results.txt");
    if (!expFile) {
        cout << "Error: Unable to open output file!" << endl;
        return 1;
    }


    Deck deck;
    //randomizes the deck
    deck.shuffle();

    //two players Joe and Jane
    Player player1("Joe");
    Player player2("Jane");

    // Deal initial 7 cards to each players
    for (int i = 0; i < 7; i++) {
        player1.addCard(deck.dealCard());
        player2.addCard(deck.dealCard());
    }

    Player* currentPlayer = &player1;
    Player* otherPlayer = &player2;
    if (rand()%2 == 1) {
        swap(currentPlayer,otherPlayer);
    }

    while (true) {
        // Print current hands and books for both players
        expFile << endl;
        expFile << "Joe's Hand: " << player1.showHand() << endl;
        expFile << endl;
        expFile << "Jane's Hand: " << player2.showHand() << endl;
        expFile << endl;

        // Check if the game is over (all books are formed)
        if (player1.getBookSize() + player2.getBookSize() == 26) {
            expFile << "\nJoe's Hand: " << player1.showHand() << endl;
            expFile << "Joe's Books: " << player1.showBooks() << endl;
            expFile << "Total Book Cards for Joe: " << player1.getBookSize() << endl;

            expFile << "Jane's Hand: " << player2.showHand() << endl;
            expFile << "Jane's Books: " << player2.showBooks() << endl;
            expFile << "Total Book Cards for Jane: " << player2.getBookSize() << endl;

            if (player1.getBookSize() > player2.getBookSize())
                expFile << "Joe wins!" << endl;
            else if (player2.getBookSize() > player1.getBookSize())
                expFile << "Jane wins!" << endl;
            else
                expFile << "It's a tie!" << endl;
            break;
        }
        if(currentPlayer->getHandSize()) {
            // Player takes a turn
            Card askedCard = currentPlayer->chooseCardFromHand();
            expFile << currentPlayer->getName() << " asks for " << askedCard.rankString(askedCard.getRank()) << endl;

            if (otherPlayer->rankInHand(askedCard)) {
                Card transferredCard;
                while (otherPlayer->rankInHand(askedCard)) {

                    transferredCard = otherPlayer->chooseCardFromHand();
                    while (askedCard.getRank() != transferredCard.getRank()) {
                        transferredCard = otherPlayer->chooseCardFromHand();
                    }

                    currentPlayer->addCard(transferredCard);
                    otherPlayer->removeCardFromHand(transferredCard);
                    expFile << otherPlayer->getName() << " gives " << currentPlayer->getName() << " "
                            << transferredCard.toString() << endl;
                }
                currentPlayer->bookCards(askedCard, transferredCard);

                expFile << currentPlayer->getName() << " books " << askedCard.toString() << " and "
                        << transferredCard.toString() << endl;
                Card c1, c2;
                while (currentPlayer->checkHandForPair(c1, c2)) {
                    currentPlayer->bookCards(c1, c2);
                    expFile << currentPlayer->getName() << " books " << c1.toString() << " and "
                            << c2.toString() << endl;
                }
                swap(currentPlayer, otherPlayer);
            }
            else {
                // Go fish
                Card drawnCard = deck.dealCard();
                currentPlayer->addCard(drawnCard);
                expFile << "Go fish! " << currentPlayer->getName() << " draws " << drawnCard.toString() << endl;
                Card c1, c2;
                while (currentPlayer->checkHandForPair(c1, c2)) {
                    currentPlayer->bookCards(c1, c2);
                }
                swap(currentPlayer, otherPlayer);
            }
        }
        else {
            Card drawnCard = deck.dealCard();
            currentPlayer->addCard(drawnCard);
            expFile << currentPlayer->getName() << " draws " << drawnCard.toString() << endl;
            Card c1, c2;
            while (currentPlayer->checkHandForPair(c1, c2)) {
                currentPlayer->bookCards(c1, c2);
            }
            swap(currentPlayer, otherPlayer);
        }
    }



    expFile.close();
    return 0;
}