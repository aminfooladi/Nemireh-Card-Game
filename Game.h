#ifndef GAME_H
#define GAME_H

#include "main.h" 
#include "Player.h"
#include "Deck.h"

using namespace std;

class Game
{
private:
    Player mainPlayer;
    vector<Player> players_list;
    Deck deck ;
    string status; 
    int number_of_player;
    vector<Player> players_account;
    vector<Deck> deck_of_games;
public:
    Game();

    string getStatus() const;
    int getNumberOfPlayer() const;
    Player getMinPlayer();
    void setStatus(string status);
    void setNumberOfPlayer(int number_of_player);

    void loginPage(Player& player);
    void mainMenu();
    void stopMenu();
    void playGame();
    void endGame();
    void createFirstDeck();
    void givePlayersFirstCards();
    void bor();
    void showGame(Player player, int number_of_player);
    void addPlayer(Player temp);
    int someoneIsWinner();
    void showResultOfGame(int index_winner);
    void doCardOptions(Player& player, Card played_card, int& dastoor, bool& the_last_card_was_NaroyNakar);
    bool checkNaKheir(vector<Card> temp);
    void loadPlayersAccount();
    void savePlayersAccount();
    void showInformationOfPlayers();

    ~Game();
};

bool passwordSecurity(string password);
int randomNumber(int temp);
string mainMenuShows();
int mainMenuNumberOfPlayer();

template <typename T>
int serch(string name, vector<T>& object);


#endif