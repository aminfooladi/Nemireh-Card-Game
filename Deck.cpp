#include "main.h"
#include "Deck.h"


Deck::Deck()
{

}

Deck::Deck(string name, vector<Card> cards_in_game, vector<Card> cards_in_garbage)
{
    this->name = name;
    this->cards_in_game = cards_in_game;
    this->cards_in_garbage = cards_in_garbage;
}

Deck::Deck(const Deck& other)
{
    this->name = other.name;
    this->cards_in_game = other.cards_in_game;
    this->cards_in_garbage = other.cards_in_garbage;
}

Deck& Deck::operator=(const Deck& other)
{
    this->name = other.name;
    this->cards_in_game = other.cards_in_game;
    this->cards_in_garbage = other.cards_in_garbage;
    return *this;
}

int Deck::getNumberOfCardsInGame() const
{
    return this->cards_in_game.size();
}
int Deck::getNumberOfCardsInGarbage() const
{
    return this->cards_in_garbage.size();
}
Card Deck::showCardInGame(int index)
{
    if (cards_in_game.size() == 0)
    {
        cout << "+----------------------------------------+\n";
        cout << "| Deck is empty! No card to show.        |\n";
        cout << "+----------------------------------------+\n";
        Card temp; 
        return temp;
    }
    return this->cards_in_game[index];
}
Card Deck::showCardInGarbage(int index) 
{
    return this->cards_in_garbage[index];
}

void Deck::addCardInGame(Card temp)
{
    this->cards_in_game.push_back(temp);
}
void Deck::addCardInGarbage(Card temp)
{
    this->cards_in_garbage.push_back(temp);
}
void Deck::deleteCardInGame(int index)
{
    this->cards_in_game.erase(cards_in_game.begin() + index);
}
void Deck::deleteCardInGarbage(int index)
{
    this->cards_in_garbage.erase(cards_in_garbage.begin() + index);
}
void Deck::clearCardInGame()
{
    this->cards_in_game.clear();
}
void Deck::clearCardInGarbage()
{
    this->cards_in_garbage.clear();
}


Deck::~Deck()
{

}