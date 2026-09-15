#ifndef PLAYER_H
#define PLAYER_H

#include "main.h" 
#include "Card.h"

using namespace std;

class Player
{
private:
    string name;
    string password;
    bool is_alive;
    vector<Card> cards_in_hands;
    bool is_player_turn;
    int score;
    vector<string> name_of_player_in_teem;
    bool is_computer;
public:
    Player();
    Player(string name, string password);
    Player(string name, string password, vector<Card>cards_in_hands);
    Player(string name, string password, bool is_alive, int score, bool is_computer);
    Player(string name, string password, bool is_alive, int score, bool is_player_turn, vector<Card>cards_in_hands, vector<string>name_of_player_in_teem, bool is_computer);

    Player(const Player& other);

    Player& operator=(const Player& other);

    bool getIsComputer() { return this->is_computer; }
    string getName() const;
    string getpassword() const;
    bool getIsAlive() const;
    bool getIsPlayerTurn() const;
    int getScore() const;
    int getNumberOfCardInHand() const;
    vector<Card>& getCardInHand();
    vector<string>& getNameOfPlayerInteam();

    void setIsComputer(bool is_computer) { this->is_computer = is_computer; }
    void setName(string name);
    void setpassword(string password);
    void setIsAlive(bool is_alive);
    void setIsPlayerTurn(bool turns_played);
    void setScore(int score);

    void receiveCard(Card temp);
    Card playCard(int indexCard);
    void showCard();
    Card returnCard(int indexCard);
    void receiveTeamName(string name);
    void clearTeamNames();
    void clearCardInHand();
    int playerPlayGame();
    int computerEasyPlayGame(string status, int index);
    int computerHardPlayGame(Card next, string status, int index);
    vector<int> computerHardPlayGame(Card next, string status);

    ~Player();
};

#endif