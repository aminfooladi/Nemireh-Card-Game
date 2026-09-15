#include "Game.h"
#include "main.h" 

Game::Game()
{
    this->status = "loginPage";
}

string Game::getStatus() const
{
    return this->status;
}
int Game::getNumberOfPlayer() const
{
    return this->number_of_player;
}
Player Game::getMinPlayer()
{
    return this->mainPlayer;
}

void Game::setStatus(string status)
{
    this->status = status;
}
void Game::setNumberOfPlayer(int number_of_player)
{
    this->number_of_player = number_of_player;
}

void Game::loginPage( Player& player  )
{
    string name;
    system("cls");
    cout << "========================================\n";
    cout << "             WELCOME TO                 \n";
    cout << "            NEMIREH GAME                \n";
    cout << "========================================\n";
    if (this->mainPlayer.getName() != "" && player.getName()=="")
    {
        cout << "+--------------------------------------+\n";
        cout << "| Computer player ?                    |\n";
        cout << "| 1. No                                |\n";
        cout << "| 2. Yes, easy computer player         |\n";
        cout << "| 3. Yes, hard computer player         |\n";
        cout << "+--------------------------------------+\n";

        string dastoor2;
        cin >> dastoor2;
        if (dastoor2 == "2")
        {
            cout << "OK !!! \n";
            string computerName = ("ComputerEasy" + this->mainPlayer.getName());
            player.setName(computerName);
            player.setIsComputer(true);
            player.setpassword("#Computer1");
            this->players_account.push_back(player);
            this->players_list.push_back(player);
            this->status = "inMainMenu";
            Sleep(3000);
            return;
        }
        if (dastoor2 == "3")
        {
            cout << "OK !!! \n";
            string computerName = ("ComputerHard" + this->mainPlayer.getName());
            player.setName(computerName);
            player.setIsComputer(true);
            player.setpassword("#Computer1");
            this->players_account.push_back(player);
            this->players_list.push_back(player);
            this->status = "inMainMenu";
            Sleep(3000);
            return;
        }
    }
    if (player.getName() == "")
    {
        cout << "* Please enter your name: ";
        cin >> name;
        player.setName(name);
    }
    else
    {
        name = player.getName();
        if (player.getName()[0]== 'C' && player.getName()[7] == 'r')
        {
            int index = serch<Player>(player.getName(), this->players_account);
            this->players_list.push_back(this->players_account[index]);
            this->status = "inMainMenu";
            return;
        }
        cout << "Player " << player.getName() << " please login : \n";

    }
    cout << "+--------------------------------------+\n";
    cout << "| Do you have an account?              |\n";
    cout << "| 1. No, create new account            |\n";
    cout << "| 2. Yes, I have an account            |\n";
    cout << "+--------------------------------------+\n";
    cout << "Choice: ";
    string dastoor;
    cin >> dastoor;
    if (dastoor == "1")
    {
        int name_index;
        do
        {
            name_index = serch<Player>(name, this->players_account);
            if (name_index != -1)
            {
                cout << "-Wrong !! user name has reserved !! \n";
                cout << "* Please enter your name: (enter Exit to try again !!) ";

                cin >> name;
                if (name == "Exit")
                {
                    player.setName("");
                    loginPage(player);
                    return;
                }
            }
        } while (name_index != -1);
        player.setName(name);

        cout << "Please enter your password: ";
        string password;
        cin >> password;
        while (!passwordSecurity(password))
        {
            cout << "- Password is weak! Please enter a stronger password: (enter Exit to try again !!) ";
            cin >> password;
            if (password == "Exit")
            {
                player.setName("");
                loginPage(player);
                return;
            }
        }
        player.setpassword(password);
        player.setIsComputer(false);
        this->players_account.push_back(player);
        this->players_list.push_back(player);

    }
    else
    {
        int index = serch<Player>(name, this->players_account);
        if (index == -1)
        {
            cout << "- Wrong !! The user name is not true . \n";
            Sleep(1000);
            player.setName("");
            this->loginPage(player);
            return;
        }
        cout << "Please enter your password: ";
        string password;
        cin >> password;
        while (this->players_account[index].getpassword() != password)
        {
            cout << "- Wrong password! Try again: (enter Exit to try again !!) ";
            cin >> password;
            if (password == "Exit")
            {
                loginPage(player);
                return;
            }
        }
        this->players_list.push_back(this->players_account[index]);
    }
    this->status = "inMainMenu";
}
void Game::mainMenu()
{
    this->mainPlayer = this->players_list[0];
    string dastoor = mainMenuShows();
    if (dastoor == "1")
    {
        this->mainPlayer = this->players_list[0];
        int temp_number = this->players_list[0].getNameOfPlayerInteam().size();
        this->number_of_player = temp_number+1;
        for (int i = 1; i <=temp_number ; i++)
        {
            Player temp;
            temp.setName(this->players_list[0].getNameOfPlayerInteam()[i - 1]);
            cout << "Player " << temp.getName() << " please login : \n";
            this->loginPage(temp);
        }
        int index_deck = serch<Deck>(this->players_list[0].getName(), this->deck_of_games);
        this->deck = this->deck_of_games[index_deck];
    }
    if (dastoor == "2")
    {
        this->mainPlayer = this->players_list[0];
        this->number_of_player = mainMenuNumberOfPlayer();
        this->players_list[0].setIsPlayerTurn(true);
        for (int i = 1 ; i < this->number_of_player ; i++)
        {
            Player temp;
            cout << "Player " << i + 1 << " please login : \n";
            this->loginPage(temp);
        }
        createFirstDeck();
        givePlayersFirstCards();
        for (int i = 0; i < this->players_list.size();i++)
        {
            this->players_list[i].setIsAlive(true);
        }
        int index_deck = serch<Deck>(this->players_list[0].getName(), this->deck_of_games);
        if (index_deck != -1)
        {
            this->deck_of_games.erase(this->deck_of_games.begin() + index_deck);
        }
        this->deck.setName(this->players_list[0].getName());
    }
    if (dastoor != "1" && dastoor != "2")
    {
        this->status = "endGame";
        return;
    }



    int players_number = this->players_list.size();
    for (int j = 0; j < players_number ; j++)
    {
        for (int k = 0; k < this->players_list[j].getNameOfPlayerInteam().size() ; k++)
        {
            int index = serch<Player>(this->players_list[j].getNameOfPlayerInteam()[k], this->players_account);
            if (index != -1)
            {
                this->players_account[index].clearCardInHand();
                this->players_account[index].clearTeamNames();
                this->players_account[index].setIsAlive(false);
                this->players_account[index].setIsPlayerTurn(false);
            }

        }
        this->players_list[j].clearTeamNames();
        int index = serch<Player>(this->players_list[j].getName(), this->players_account);

        if (index != -1)
        {
            this->players_account[index] = this->players_list[j];
        }
        for (int k = 0; k < players_number; k++)
        {
            if (k != j)
            {
                this->players_list[j].receiveTeamName(this->players_list[k].getName());
            }
        }
    }

    this->status = "playGame";
}
void Game::stopMenu()
{
    system("cls");
    this->showInformationOfPlayers();
    string dastoor;
    cout << "+--------------------------------------+\n";
    cout << "|             STOP MENU                |\n";
    cout << "+--------------------------------------+\n";
    cout << "| 1. Continue Game                     |\n";
    cout << "| 2. Save , Mine Menu                  |\n";
    cout << "| 3. Mine Menu                         |\n";
    cout << "| 4. Save , Quit Game                  |\n";
    cout << "| 5. Quit Game                         |\n";
    cout << "+--------------------------------------+\n";
    cout << " Enter your choice: ";
    cin >> dastoor;
    if (dastoor == "1")
    {
        this->status = "playGame";
        return;
    }
    else if (dastoor == "2")
    {
        this->savePlayersAccount();
        this->status = "inMainMenu";
        return;
    }
    else if (dastoor == "3")
    {
        this->status = "inMainMenu";
        return;
    }
    else if (dastoor == "4")
    {
        this->savePlayersAccount();
        this->status = "endGame";
        return;
    }
    else
    {
        this->status = "endGame";
        return;
    }
}
void Game::playGame()
{
    this->setNumberOfPlayer(this->players_list[0].getNameOfPlayerInteam().size()+1);
    bool the_last_card_was_NaroyNakar = false;
    while (true)
    {
        bool endgame = false;
        for (int i = 0; i < this->number_of_player; i++)
        {
            if (!this->players_list[i].getIsPlayerTurn())
            {
                continue;
            }
            if (this->someoneIsWinner() != -1)
            {
                this->players_list[this->someoneIsWinner()].setScore(this->players_list[this->someoneIsWinner()].getScore()+1);
                showResultOfGame(this->someoneIsWinner());
                this->players_list[this->someoneIsWinner()].setIsAlive(false);
                this->status = "endGame";
                endgame = true;
                break;
            }
            if (this->players_list[i].getIsAlive() == false)
            {
                int number;
                if ((i + 2) <= this->number_of_player)
                    number = i + 2;
                else
                    number = 1;
                if (this->players_list[number-1].getIsAlive())
                {

                    cout << "\n+============================================+\n";
                    cout << "|        Next Player: " << this->players_list[number - 1].getName() << endl;
                    cout << "+============================================+\n";
                    cout << " Press Enter to continue...";
                    string temp;
                    cin.ignore();
                    getline(cin, temp);

                }
                this->players_list[i].setIsPlayerTurn(false);
                this->players_list[i + 1].setIsPlayerTurn(true);
                continue;
            }
            int dastoor;
            if (this->players_list[i].getIsComputer())
            {
                if (this->players_list[i].getName()[8] == 'E')
                {
                    dastoor = this->players_list[i].computerEasyPlayGame("dastoor", i);
                }
                else
                {
                    dastoor = this->players_list[i].computerHardPlayGame(this->deck.showCardInGame(), "dastoor",i);
                }
            }
            else
            {
                system("cls");
                this->showGame(this->players_list[i], i + 1);
                dastoor = this->players_list[i].playerPlayGame();
            }
     
            while (dastoor == 1 || dastoor == 2 || dastoor == 3 || dastoor == 4)
            {
                if (dastoor == 1)
                {
                    int index_card;
                    if (!this->players_list[i].getIsComputer())
                    {
                        cin >> index_card;
                        index_card--;
                    }
                    else
                    {
                        if (this->players_list[i].getName()[8] == 'E')
                        {
                            index_card = this->players_list[i].computerEasyPlayGame("1",i);
                        }
                        else
                        {
                            index_card = this->players_list[i].computerHardPlayGame(this->deck.showCardInGame(), "1",i);
                        }
                    }
                    
                    vector<Card>card_temp;
                    card_temp.push_back(this->players_list[i].returnCard(index_card));

                    Card played_card = this->players_list[i].playCard(index_card);
                    this->deck.addCardInGarbage(played_card);



                    if (this->checkNaKheir(card_temp))
                    {
                        if (!this->players_list[i].getIsComputer())
                        {
                            system("cls");
                            this->showGame(this->players_list[i], i + 1);
                            dastoor = this->players_list[i].playerPlayGame();
                        }
                        continue;
                    }

                    this->doCardOptions(this->players_list[i], played_card, dastoor, the_last_card_was_NaroyNakar);

                }

                if (dastoor == 2)
                {

                    vector<int> index_card(2);
                    for (int k = 0; k < 2; k++)
                    {
                        if (!this->players_list[i].getIsComputer())
                        {
                            cin >> index_card[k];
                            index_card[k]--;
                        }
                        else
                        {
                            if (this->players_list[i].getName()[8] == 'H')
                            {
                                index_card = this->players_list[i].computerHardPlayGame(this->deck.showCardInGame(), "2");
                            }
                        }
                        
                    }
                    if (this->players_list[i].returnCard(index_card[0]).getName() == this->players_list[i].returnCard(index_card[1]).getName())
                    {

                        vector<Card>card_temp;
                        card_temp.push_back(this->players_list[i].returnCard(index_card[0]));
                        card_temp.push_back(this->players_list[i].returnCard(index_card[1]));


                        if (this->checkNaKheir(card_temp))
                        {
                            if (!this->players_list[i].getIsComputer())
                            {
                                system("cls");
                                this->showGame(this->players_list[i], i + 1);
                                dastoor = this->players_list[i].playerPlayGame();
                            }
                            continue;
                        }
                        string first = this->players_list[i].returnCard(index_card[0]).getName();
                        string last = this->players_list[i].returnCard(index_card[1]).getName();
                        Card temp("BajSibyl", "Medium Cards", "Take one random card from an opponent");
                        this->doCardOptions(this->players_list[i], temp, dastoor, the_last_card_was_NaroyNakar);

                        int index_first_card = serch<Card>(first, this->players_list[i].getCardInHand());
                        Card first_card = this->players_list[i].playCard(index_first_card);
                        this->deck.addCardInGarbage(first_card);
                        int index_last_card = serch<Card>(last, this->players_list[i].getCardInHand());
                        Card last_card = this->players_list[i].playCard(index_last_card);
                        this->deck.addCardInGarbage(last_card);
                    }
                    else
                    {
                        cout << "- Wrong !! Cards are not same . \n";
                    }
                }

                if (dastoor == 3)
                {
                    
                    int index_card[3] = { 0,0,0 };
                    for (int k = 0; k < 3; k++)
                    {
                        cin >> index_card[k];
                        index_card[k]--;
                    }
                    if (this->players_list[i].returnCard(index_card[0]).getName() == this->players_list[i].returnCard(index_card[1]).getName())
                    {
                        if (this->players_list[i].returnCard(index_card[1]).getName() == this->players_list[i].returnCard(index_card[2]).getName())
                        {
                            if (this->players_list[i].returnCard(index_card[2]).getName() == this->players_list[i].returnCard(index_card[0]).getName())
                            {
                                vector<Card>card_temp;
                                string names[3];
                                for (int k = 0; k < 3; k++)
                                {
                                    names[k] = this->players_list[i].returnCard(index_card[k]).getName();
                                    card_temp.push_back(this->players_list[i].returnCard(index_card[k]));
                                }
                                
                                
                                if (this->checkNaKheir(card_temp))
                                {
                                    int index_cards[3] = { 0,0,0 };
                                    for (int k = 0; k < 3; k++)
                                    {
                                        index_cards[k] = serch<Card>(names[k], this->players_list[i].getCardInHand());
                                        Card temp = this->players_list[i].playCard(index_cards[k]);
                                        this->deck.addCardInGarbage(temp);
                                    }
                                    if (!this->players_list[i].getIsComputer())
                                    {
                                        system("cls");
                                        this->showGame(this->players_list[i], i + 1);
                                        dastoor = this->players_list[i].playerPlayGame();
                                    }
                                    continue;
                                }

                                cout << "+=========== STEAL A CARD =============+\n";
                                cout << "| Choose a player to steal from:       |\n";
                                cout << "+======================================+\n";
                                cout << " Player name: ";
                                int number_player;
                                string player_name;
                                cin >> player_name;
                                number_player = serch<Player>(player_name, this->players_list);

                                cout << "+=========== STEAL A CARD =============+\n";
                                cout << "| Choose a Card to steal from:         |\n";
                                cout << "+======================================+\n";
                                cout << " Card name: ";
                                int number_card;
                                string card_name;
                                cin >> card_name;
                                number_card = serch<Card>(card_name, this->players_list[number_player].getCardInHand());
                                if (number_card == -1)
                                {
                                    cout << "- Wrong !! Player dont have this card .\n";
                                    Sleep(2000);
                                }
                                else
                                {
                                    this->players_list[i].receiveCard(this->players_list[number_player].playCard(number_card));
                                }
                                int index_cards[3] = { 0,0,0 };
                                for (int k = 0; k < 3; k++)
                                {
                                    index_cards[k] = serch<Card>(names[k], this->players_list[i].getCardInHand());
                                    Card temp = this->players_list[i].playCard(index_cards[k]);
                                    this->deck.addCardInGarbage(temp);
                                }

                            }
                        }
                    }
                    else
                    {
                        cout << "- Wrong !! Cards are not same . \n";
                    }
                }

                if (dastoor == 4)
                {

                    int index_card[5];
                    cout << "Enter 5 card numbers: ";
                    for (int k = 0; k < 5; k++)
                    {
                        cin >> index_card[k];
                        index_card[k]--;
                    }
                    bool all_different = true;
                    string names[5];
                    vector<Card>card_temp;
                    for (int k = 0; k < 5; k++)
                    {
                        card_temp.push_back(this->players_list[i].returnCard(index_card[k]));
                        names[k] = this->players_list[i].returnCard(index_card[k]).getName();
                        for (int j = k+1; j < 5; j++)
                        {
                            if (names[k] == names[j])
                            {
                                all_different = false;
                                break;
                            }
                        }
                    }
                    if (all_different)
                    {
                        if (this->checkNaKheir(card_temp))
                        {
                            if (!this->players_list[i].getIsComputer())
                            {
                                system("cls");
                                this->showGame(this->players_list[i], i + 1);
                                dastoor = this->players_list[i].playerPlayGame();
                            }
                            for (int k = 0; k < 5; k++)
                            {
                                index_card[k] = serch<Card>(names[k], this->players_list[i].getCardInHand());
                                Card temp = this->players_list[i].playCard(index_card[k]);
                                this->deck.addCardInGarbage(temp);
                            }
                            continue;
                        }
                        if (this->deck.getNumberOfCardsInGarbage() == 0)
                        {
                            cout << "No cards in garbage!\n";
                        }
                        else
                        {
                            cout << "\n+========== GARBAGE CARDS ==========+\n";
                            for (int k = 0; k < this->deck.getNumberOfCardsInGarbage(); k++)
                            {
                                cout << k + 1 << ". /n";
                                this->deck.showCardInGarbage(k).showCardInformation();
                            }
                            cout << "+====================================+\n";
                            cout << "Choose : ";
                            int number_card;
                            cin >> number_card;
                            number_card--;
                            this->players_list[i].receiveCard(this->deck.showCardInGarbage(number_card));
                            this->deck.deleteCardInGarbage(number_card);
                        }
                        for (int k = 0; k < 5; k++)
                        {
                            index_card[k] = serch<Card>(names[k], this->players_list[i].getCardInHand());
                            Card temp = this->players_list[i].playCard(index_card[k]);
                            this->deck.addCardInGarbage(temp);
                        }
                    }
                    else
                    {
                        cout << "Cards are not all different!\n";
                    }
                }

                if (dastoor == 1 || dastoor == 2 || dastoor == 3 || dastoor == 4)
                {
                    if (this->players_list[i].getIsComputer())
                    {
                        if (this->players_list[i].getName()[8] == 'E')
                        {
                            dastoor = this->players_list[i].computerEasyPlayGame("dastoor", i);
                        }
                        else
                        {
                            dastoor = this->players_list[i].computerHardPlayGame(this->deck.showCardInGame(), "dastoor", i);
                        }
                    }
                    else
                    {
                        system("cls");
                        this->showGame(this->players_list[i], i + 1);
                        dastoor = this->players_list[i].playerPlayGame();
                    }

                }
            }
            if (dastoor == 7) //JimFang
            {

                if (!the_last_card_was_NaroyNakar)
                {
                    int number=0;
                    if ((i + 2) <= this->number_of_player)
                        number = i + 2;
                    else
                        number = 1;


                    if (this->players_list[number - 1].getIsAlive())
                    {

                        cout << "\n+============================================+\n";
                        cout << "|        Next Player: " << this->players_list[number - 1].getName() << endl;
                        cout << "+============================================+\n";
                        cout << " Press Enter to continue...";
                        string temp;
                        cin.ignore();
                        getline(cin, temp);

                    }

                    

                    if (i + 1 < this->number_of_player)
                        this->players_list[i + 1].setIsPlayerTurn(true);
                    else
                        this->players_list[0].setIsPlayerTurn(true);
                    if (i > 0) this->players_list[i].setIsPlayerTurn(false);
                }
                if (the_last_card_was_NaroyNakar)
                {
                    the_last_card_was_NaroyNakar = false;
                }

                continue;
            }
            if (dastoor == 8)
            {
                dastoor = 7;

                int number=0;
                if ((i + 2) <= this->number_of_player)
                    number = i + 2;
                else
                    number = 1;
                if (this->players_list[number - 1].getIsAlive())
                {

                    cout << "\n+============================================+\n";
                    cout << "|        Next Player: " << this->players_list[number - 1].getName() << endl;
                    cout << "+============================================+\n";
                    cout << " Press Enter to continue...";
                    string temp;
                    cin.ignore();
                    getline(cin, temp);

                }

                

                if (i + 1 < this->number_of_player)
                    this->players_list[i + 1].setIsPlayerTurn(true);
                else
                    this->players_list[0].setIsPlayerTurn(true);
                if (i > 0) this->players_list[i].setIsPlayerTurn(false);
                continue;
            }

            if (dastoor == 5)
            {
                if (this->deck.showCardInGame(0).getName() == "AjalMoadlagh")
                {
                    int index_card2 = serch<Card>("ShafayeAjel", this->players_list[i].getCardInHand());
                    if (index_card2 == -1)
                    {
                        this->players_list[i].setIsAlive(false);
                        cout << "\033[38;5;210m"; // قرمز کم‌رنگ
                        cout << "+=============== FATAL ================+\n";
                        cout << "| You drew AJAL MOADLAGH!              |\n";
                        cout << "| You have NO ShafayeAjel!             |\n";
                        cout << "| YOU ARE ELIMINATED                   |\n";
                        cout << "+======================================+\n";
                        cout << "\033[0m";
                        int count = this->players_list[i].getNumberOfCardInHand();
                        for (int k = 0; k <count ; k++)
                        {
                            Card temp =  this->players_list[i].playCard(0);
                            this->deck.addCardInGarbage(temp);
                        }
                    }
                    else
                    {
                        this->bor();
                        Card temp = this->players_list[i].playCard(index_card2);
                        this->deck.addCardInGarbage(temp);
                        cout << "\033[38;5;120m"; // سبز کم‌رنگ
                        cout << "+=============== SAVED ================+\n";
                        cout << "| You drew AJAL MOADLAGH!              |\n";
                        cout << "| You used ShafayeAjel!                |\n";
                        cout << "| YOU SURVIVED!                        |\n";
                        cout << "| Deck has been shuffled.              |\n";
                        cout << "+======================================+\n";
                        cout << "\033[0m";
                    }
                    cout << " Press Enter to continue...";
                    string temp;
                    cin.ignore();
                    getline(cin, temp);
                }
                else
                {
                    this->players_list[i].receiveCard(this->deck.showCardInGame(0));
                    this->deck.deleteCardInGame(0);
                    if (the_last_card_was_NaroyNakar)
                    {
                        i = i - 1;
                        the_last_card_was_NaroyNakar = false;
                    }
                }
                system("cls");

                int number=0;
                if ((i + 2) <= this->number_of_player)
                    number = i + 2;
                else
                    number = 1;
                if (this->players_list[number - 1].getIsAlive())
                {

                    cout << "\n+============================================+\n";
                    cout << "|        Next Player: " << this->players_list[number - 1].getName() << endl;
                    cout << "+============================================+\n";
                    cout << " Press Enter to continue...";
                    string temp;
                    cin.ignore();
                    getline(cin, temp);

                }
            }
            
            if (dastoor == 6)
            {
                this->status = "stopMenu";
                return;
            }
            
            
            
            if ( i+1 < this->number_of_player)
                this->players_list[i+1].setIsPlayerTurn(true);
            else 
                this->players_list[0].setIsPlayerTurn(true);
            if (i>0) this->players_list[i].setIsPlayerTurn(false);


        }
        if (endgame)
        {
            break;
        }
    }
}
void Game::endGame()
{
    return;
}
void Game::createFirstDeck()
{
    int j;
    for (j = 0; j < 5; j++)
    {
        Card temp("NaKheir", "Medium Cards", "Cancel the effect of any other card");
        this->deck.addCardInGame(temp);
    }
    for (j = 0; j < 4; j++)
    {
        Card temp("NaroyNakar", "Medium Cards", "Force an opponent to play two turns in a row");
        this->deck.addCardInGame(temp);
    }
    for (j = 0; j < 4; j++)
    {
        Card temp("JimFang", "Good Cards", "Skip your turn without drawing a card");
        this->deck.addCardInGame(temp);
    }
    for (j = 0; j < 4; j++)
    {
        Card temp("BajSibyl", "Medium Cards", "Take one random card from an opponent");
        this->deck.addCardInGame(temp);
    }
    for (j = 0; j < 4; j++)
    {
        Card temp("GharOghati", "Medium Cards", "Shuffle all cards in the main deck");
        this->deck.addCardInGame(temp);
    }
    for (j = 0; j < 4; j++)
    {
        Card temp("Talebin", "Good Cards", "Look at the top 3 cards of the deck");
        this->deck.addCardInGame(temp);
    }
    for (j = 0; j < 5; j++)
    {
        Card temp("KhanzarPanzar1", "Medium Cards", "If you have two of this card, take one card from an opponent");
        this->deck.addCardInGame(temp);
    }
    for (j = 0; j < 5; j++)
    {
        Card temp("KhanzarPanzar2", "Medium Cards", "If you have two of this card, take one card from an opponent");
        this->deck.addCardInGame(temp);
    }
    for (j = 0; j < 5; j++)
    {
        Card temp("KhanzarPanzar3", "Medium Cards", "If you have two of this card, take one card from an opponent");
        this->deck.addCardInGame(temp);
    }
    for (j = 0; j < 4; j++)
    {
        Card temp("KhanzarPanzar4", "Medium Cards", "If you have two of this card, take one card from an opponent");
        this->deck.addCardInGame(temp);
    }
    this->bor();
}
void Game::givePlayersFirstCards()
{
    int i, j;
    for (i = 0; i < this->number_of_player; i++)
    {
        this->players_list[i].clearCardInHand();
        for (j = 0; j < 4; j++)
        {
            this->players_list[i].receiveCard(this->deck.showCardInGame(0));
            this->deck.deleteCardInGame(0);
        }
        Card temp("ShafayeAjel", "Good Cards", "If you take the AjalMoadlagh card, this card will save you.");
        this->players_list[i].receiveCard(temp);
    }
    for (j = 0; j < 6-this->number_of_player; j++)
    {
        Card temp("ShafayeAjel", "Good Cards", "If you take the AjalMoadlagh card, this card will save you.");
        this->deck.addCardInGame(temp);
    }
    for (j = 0; j < this->number_of_player-1 ; j++)
    {
        Card temp("AjalMoadlagh", "Bad Cards", "If you take this card and you don't have ShafayeAjel, you lose the game.");
        this->deck.addCardInGame(temp);
    }
    this->bor();
}
void Game::bor()
{
    int size = this->deck.getNumberOfCardsInGame();
    if (size <= 0) return;
    vector<Card> temp(size);

    for (int i = 0; i < size; i++)
    {
        int random = randomNumber(size - i);
        temp[i] = this->deck.showCardInGame(random);
        this->deck.deleteCardInGame(random);
    }
    for (int i = 0; i < size; i++)
    {
        this->deck.addCardInGame(temp[i]);
    }
}
void Game::showGame(Player player, int number_of_player)
{
    this->showInformationOfPlayers();
    cout << "\n+============ LAST CARD ===============+\n";

    int garbageCount = this->deck.getNumberOfCardsInGarbage();
    if (garbageCount > 0)
    {
        int index = garbageCount - 1; 

        cout << "\033[38;5;228m";
        cout << "| ";
        cout << this->deck.showCardInGarbage(index).getName();
        cout << " - ";
        cout << this->deck.showCardInGarbage(index).getType();
        cout << " - ";
        cout << this->deck.showCardInGarbage(index).getDescription();
        cout << "\n";
        cout << "\033[0m";
    }
    else
    {
        cout << "| No card in garbage.                 |\n";
    }
    cout << "+======================================+\n";
    cout << "+=========== YOUR CARDS ===============+\n";
    cout << "| Player : " << number_of_player << "                           |\n";
    player.showCard();
    cout << "+======================================+\n";
}
void Game::doCardOptions(Player& player, Card played_card, int& dastoor, bool& the_last_card_was_NaroyNakar )
{
    if (played_card.getName() == "GharOghati")
    {
        this->bor();
        string dastoor;
        if (!player.getIsComputer())
        {

            cout << "+============ SHUFFLE DECK ============+\n";
            cout << "| All cards have been shuffled.        |\n";
            cout << "| Do you want to shuffle again?        |\n";
            cout << "+======================================+\n";
            cout << " (yes/no): ";
            cin >> dastoor;
        }
        else
        {
            if (player.getName()[8] == 'E')
            {
                dastoor = "no";
            }
            else
            {
                while (this->deck.showCardInGame(0).getName() == "AjalMoadlagh")
                {
                    this->bor();
                }
                
            }
            dastoor = "no";
        }

        while (dastoor != "no" && dastoor != "No")
        {
            this->bor();
            cout << "+============ SHUFFLE DECK ============+\n";
            cout << "| All cards have been shuffled.        |\n";
            cout << "| Do you want to shuffle again?        |\n";
            cout << "+======================================+\n";
            cout << " (yes/no): ";
            cin >> dastoor;
        }
        return;
    }
    if (played_card.getName() == "JimFang")
    {
        dastoor = 7;
        return;
    }
    if (played_card.getName() == "BajSibyl")
    {
        cout << "+=========== STEAL A CARD =============+\n";
        cout << "| Choose a player to steal from:       |\n";
        cout << "+======================================+\n";
        cout << " Player name: "; 
        int number_player;
        string player_name;
        if (!player.getIsComputer()) cin >> player_name;
        else
        {
            int random = rand() % (this->players_list.size() - 1);
            player_name = player.getNameOfPlayerInteam()[random];
        }
        
        number_player = serch<Player>(player_name, this->players_list);

        int handSize = this->players_list[number_player].getNumberOfCardInHand();
        if (handSize > 0) 
        {
            int index = randomNumber(handSize);
            player.receiveCard(this->players_list[number_player].playCard(index));
        }
        return;
    }
    if (played_card.getName() == "Talebin")
    {
        if (player.getIsComputer()) return;
        cout << "+======================================+\n";
        cout << "| Top 3 cards of the deck:             |\n";
        cout << "+--------------------------------------+\n";
        for (int i = 0; i < 3; i++)
        {
            cout << "| Card " << i + 1 << " : \n";
            if ( this->deck.getNumberOfCardsInGame() > 0) this->deck.showCardInGame(i).showCardInformation();
        }
        cout << "+======================================+\n";
        cout << " Press Enter to continue...";
        string enter;
        cin.ignore();
        getline(cin, enter);
        return;
    }
    if (played_card.getName() == "NaroyNakar")
    {
        dastoor = 8;
        the_last_card_was_NaroyNakar = true;
        return;
    }

}
bool Game::checkNaKheir(vector<Card> temp)
{
    string someone_played_NaKheir;
    int count_of_NaKheirs = 0;
    do
    {
        system("cls");
        this->showInformationOfPlayers();

        for (int i = 0; i < temp.size();i++)
        {
            temp[i].showCardInformation();
        }

        cout << "+=========== INTERRUPT OPPORTUNITY ==========+\n";
        cout << "| Anyone wants to play NaKheir card?         |\n";
        cout << "| (If yes, enter player name, else enter NO) |\n";
        cout << "+============================================+\n";
        cout << "=> ";
        cin >> someone_played_NaKheir;
        if (someone_played_NaKheir != "NO" && someone_played_NaKheir != "no" && someone_played_NaKheir != "No")
        {
            int index_player = serch<Player>(someone_played_NaKheir, this->players_list);
            if (index_player != -1)
            {
                int index_card2 = serch<Card>("NaKheir", this->players_list[index_player].getCardInHand());
                if (index_card2 != -1)
                {
                    Card played_card2 = this->players_list[index_player].playCard(index_card2);
                    this->deck.addCardInGarbage(played_card2);
                    count_of_NaKheirs++;
                }
                else
                {
                    cout << "Player " << index_player << " has\'nt NaKheir card !!! \n";
                }
            }
            else
            {
                cout << "Player did not find !!!\n";
            }
            Sleep(2000);
        }
    } while (someone_played_NaKheir != "NO" && someone_played_NaKheir != "no" && someone_played_NaKheir != "No");

    if (count_of_NaKheirs % 2 == 1) return true;
    else
    {
        return false;
    }
}
int Game::someoneIsWinner()
{
    int counter = 0;
    int size = this->players_list.size();
    for (int i = 0;i < size; i++)
    {
        if (this->players_list[i].getIsAlive() == false) counter++;
    }
    if (counter == (size - 1))
    {
        for (int i = 0;i < size; i++)
        {
            if (this->players_list[i].getIsAlive() == true)
            {
                for (int j = 0; j < size; j++)
                {
                    this->players_list[j].clearTeamNames();
                    this->players_list[j].clearCardInHand();
                    int index = serch<Player>(this->players_list[j].getName(),this->players_account);

                    if (index != -1)
                    {
                        this->players_account[index] = this->players_list[j];
                    }
                }
                int index_deck = serch<Deck>(this->mainPlayer.getName(), this->deck_of_games);
                if (index_deck!=-1) this->deck_of_games.erase(this->deck_of_games.begin() + index_deck);
                return i;
            }
        }
    }
    return -1;
}
void Game::showResultOfGame(int index_winner)
{
    cout << "Number of cards remaining : " << this->deck.getNumberOfCardsInGame() << endl;
    cout << "Remaining Cards : \n";
    for (int k = 0; k < this->deck.getNumberOfCardsInGame(); k++)
    {
        cout << "Card " << k + 1 << " : \n";
        this->deck.showCardInGame(k).showCardInformation();
    }
    this->deck.clearCardInGame();
    this->deck.clearCardInGarbage();
    cout << "\033[38;5;120m";
    cout << "Winner is : " << this->players_list[index_winner].getName() << endl;
    for (int i = 0; i < this->players_list.size() ; i++)
    {
        if (i != index_winner)
        {
            cout << "\033[38;5;210m";
            cout << this->players_list[i].getName() << " is lost .\n";
            cout << "\033[0m";
        }
    }
    cout << "\033[0m";
    return;
}
void Game::loadPlayersAccount()
{
    ifstream players_account("players_account.txt");
    string name, password;
    bool is_alive , is_player_turn , is_computer;
    int score;
    int number_of_card_in_hand, number_of_players_in_teem;
    int size;
    players_account >> size;
    players_account.ignore();
    for (int k = 0; k < size; k++)
    {
        players_account >> name >> password >> is_alive >> score >> is_computer;

        if (is_alive)
        {
            players_account >> is_player_turn;
            players_account >> number_of_card_in_hand;
            players_account.ignore();
            vector<Card> card_in_hand;
            string card_name, card_type, card_description;
            for (int i = 0; i < number_of_card_in_hand; i++)
            {

                getline(players_account, card_name);
                getline(players_account, card_type);
                getline(players_account, card_description);

                Card card_temp(card_name, card_type, card_description);
                card_in_hand.push_back(card_temp);
            }
            players_account >> number_of_players_in_teem;
            vector<string> teem;
            string player_name;
            for (int i = 0; i < number_of_players_in_teem; i++)
            {
                players_account >> player_name;
                teem.push_back(player_name);
            }
            Player temp(name, password,is_alive, score, is_player_turn, card_in_hand, teem, is_computer);
            this->players_account.push_back(temp);
        }
        else
        {
            Player temp(name, password,is_alive,score,is_computer);
            this->players_account.push_back(temp);
        }
    }

    int number_of_deck;
    players_account >> number_of_deck;
    players_account.ignore();

    for (int j = 0; j < number_of_deck; j++)
    {
        string deck_name;
        getline(players_account, deck_name);

        Deck tempDeck; 
        tempDeck.setName(deck_name);
        int size;
        players_account >> size;
        players_account.ignore();
        for (int k = 0; k < size; k++)
        {
            string card_name, card_type, card_description;
            getline(players_account, card_name);
            getline(players_account, card_type);
            getline(players_account, card_description);
            Card temp(card_name, card_type, card_description);
            tempDeck.addCardInGame(temp);
        }
        players_account >> size;
        players_account.ignore();
        for (int k = 0; k < size; k++)
        {
            string card_name, card_type, card_description;
            getline(players_account, card_name);
            getline(players_account, card_type);
            getline(players_account, card_description);
            Card temp(card_name, card_type, card_description);
            tempDeck.addCardInGarbage(temp);
        }

        this->deck_of_games.push_back(tempDeck);
    }

    players_account.close();
}
void Game::savePlayersAccount()
{
    int size = this->players_list.size();
    for (int i = 0; i < size; i++)
    {
        int index = serch<Player>(this->players_list[i].getName(), this->players_account);
        if (index != -1)
            players_account[index] = players_list[i]; 
        else
            players_account.push_back(players_list[i]);
    }

    size = this->players_account.size();

    ofstream players_account("players_account.txt");
    
    players_account << size << endl;

    for (int i = 0; i < size; i++)
    {
        players_account << this->players_account[i].getName()
            << " " << this->players_account[i].getpassword()
            << " " << this->players_account[i].getIsAlive()
            << " " << this->players_account[i].getScore() 
            << " " << this->players_account[i].getIsComputer() << endl;
        if (this->players_account[i].getIsAlive())
        {
            players_account << this->players_account[i].getIsPlayerTurn() << endl;
            players_account << this->players_account[i].getNumberOfCardInHand() << endl;
            for (int j = 0; j < this->players_account[i].getNumberOfCardInHand(); j++)
            {
                players_account << this->players_account[i].returnCard(j).getName() << endl
                    << this->players_account[i].returnCard(j).getType() << endl
                    << this->players_account[i].returnCard(j).getDescription() << endl;
            }
            players_account << this->players_account[i].getNameOfPlayerInteam().size() << endl;
            int number = this->players_account[i].getNameOfPlayerInteam().size();
            for (int j = 0; j < number; j++)
            {
                players_account << this->players_account[i].getNameOfPlayerInteam()[j] << " ";
            }
            players_account << endl;
        }
    }

    

    int index_deck = serch<Deck>(this->players_list[0].getName(), this->deck_of_games);
    if (index_deck != -1)
    {
        this->deck_of_games[index_deck] = this->deck;
    }
    else
    {
        this->deck_of_games.push_back(this->deck);
    }
    int number_of_decks = this->deck_of_games.size();
    players_account << number_of_decks << endl ;

    for (int j = 0; j < number_of_decks; j++)
    {
        players_account << this->deck_of_games[j].getName() << endl;
        size = this->deck_of_games[j].getNumberOfCardsInGame();
        players_account << size << endl;
        for (int i = 0; i < size; i++)
        {
            players_account << this->deck_of_games[j].showCardInGame(i).getName() << endl;
            players_account << this->deck_of_games[j].showCardInGame(i).getType() << endl;
            players_account << this->deck_of_games[j].showCardInGame(i).getDescription() << endl;
        }
        size = this->deck_of_games[j].getNumberOfCardsInGarbage();
        players_account << size << endl;
        for (int i = 0; i < size; i++)
        {
            players_account << this->deck_of_games[j].showCardInGarbage(i).getName() << endl;
            players_account << this->deck_of_games[j].showCardInGarbage(i).getType() << endl;
            players_account << this->deck_of_games[j].showCardInGarbage(i).getDescription() << endl;
        }
    }
    players_account.close();
}
void Game::showInformationOfPlayers()
{
    cout << "Players Information : \n";
    cout << "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";
    for (int i = 0; i < this->players_list.size(); i++)
    {
        cout << "Player (" << i + 1 << ") : " << this->players_list[i].getName() << "\t";
    }
    cout << endl;
    cout << "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";
}

Game::~Game()
{

}

bool passwordSecurity(string password)
{
    bool result = false, captal = false, smal = false, carector = false;
    int size = password.length();
    for (int i = 0; i < size; i++)
    {
        if (password[i] == '@' || password[i] == '#' || password[i] == '%' || password[i] == '$') carector = true;
        else if (password[i] >= 'A' && password[i] <= 'Z') captal = true;
        else if (password[i] >= 'a' && password[i] <= 'z') smal = true;
    }
    if (captal && smal && carector && (size >= 8)) result = true;
    return result;
}
int randomNumber(int temp)
{
    return rand() % temp;
}
string mainMenuShows()
{
    system("cls");
    cout << "+--------------------------------------+\n";
    cout << "|             MAIN MENU                |\n";
    cout << "+--------------------------------------+\n";
    cout << "| 1. Load Last Game                    |\n";
    cout << "| 2. Start New Game                    |\n";
    cout << "| 3. Quit Game                         |\n";
    cout << "+--------------------------------------+\n";
    cout << " Enter your choice: ";
    string dastoor;
    cin >> dastoor;
    return dastoor;
}
int mainMenuNumberOfPlayer()
{
    system("cls");
    cout << "+--------------------------------------+\n";
    cout << "|          SELECT PLAYERS              |\n";
    cout << "+--------------------------------------+\n";
    cout << "| 1. 2 Players                         |\n";
    cout << "| 2. 3 Players                         |\n";
    cout << "| 3. 4 Players                         |\n";
    cout << "| 4. 5 Players                         |\n";
    cout << "+--------------------------------------+\n";
    cout << " Enter number of players: ";
    int dastoor;
    cin >> dastoor;
    return dastoor+1;
}

template <typename T>
int serch(string name, vector<T>& object)
{
    for (int i = 0; i < object.size(); i++)
    {
        if (object[i].getName() == name)
        {
            return i;
        }
    }
    return -1;
}