#ifndef DECK_H
#define DECK_H

#include "main.h"
#include "Card.h"

using namespace std;

class Deck
{
private:
    string name;
    vector<Card> cards_in_game;
    vector<Card> cards_in_garbage;
public:
    Deck();
    Deck(string name, vector<Card> cards_in_game, vector<Card> cards_in_garbage);

    Deck(const Deck& other);
    Deck& operator=(const Deck& other);
    
    string getName() { return this->name; }
    int getNumberOfCardsInGame() const;
    int getNumberOfCardsInGarbage() const;
    Card showCardInGame(int index = 0);
    Card showCardInGarbage(int index = 0);

    void setName(string name) { this->name = name; }
    void addCardInGame(Card temp);
    void addCardInGarbage(Card temp);
    void deleteCardInGame(int index = 0);
    void deleteCardInGarbage(int index = 0);
    void clearCardInGame();
    void clearCardInGarbage();

    ~Deck();
};

#endif