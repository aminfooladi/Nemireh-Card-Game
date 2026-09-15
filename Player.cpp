#include "main.h" 
#include "Player.h"

Player::Player()
{
    this->name = "";
    this->password = "";
    this->is_alive = true;
    this->score = 0;
    this->is_player_turn = false;
    this->is_computer = false;
}
Player::Player(string name, string password)
{
    this->name = name;
    this->password = password;
    this->is_alive = true;
    this->score = 0;
    this->is_player_turn = false;
    this->is_computer = false;
}
Player::Player(string name, string password, bool is_alive, int score, bool is_computer)
{
    this->name = name;
    this->password = password;
    this->is_alive = is_alive;
    this->score = score;
    this->is_player_turn = false;
    this->is_computer = is_computer;
}
Player::Player(string name, string password, vector<Card>cards_in_hands)
{
    this->name = name;
    this->password = password;
    this->cards_in_hands = cards_in_hands;
    this->is_alive = true;
    this->score = 0;
    this->is_player_turn = false;
    this->is_computer = false;
}
Player::Player(string name, string password, bool is_alive, int score, bool is_player_turn, vector<Card>cards_in_hands, vector<string>name_of_player_in_teem, bool is_computer)
{
    this->name = name;
    this->password = password;
    this->cards_in_hands = cards_in_hands;
    this->is_alive = is_alive;
    this->name_of_player_in_teem = name_of_player_in_teem;
    this->score = score;
    this->is_player_turn = is_player_turn;
    this->is_computer = is_computer;
}

Player::Player(const Player& other)
{
    this->name = other.name;
    this->password = other.password;
    this->is_alive = other.is_alive;
    this->cards_in_hands = other.cards_in_hands;
    this->score = other.score;
    this->name_of_player_in_teem = other.name_of_player_in_teem;
    this->is_player_turn = other.is_player_turn;
    this->is_computer = other.is_computer;
}

Player& Player::operator= (const Player& other)
{
    this->name = other.name;
    this->password = other.password;
    this->is_alive = other.is_alive;
    this->cards_in_hands = other.cards_in_hands;
    this->score = other.score;
    this->name_of_player_in_teem = other.name_of_player_in_teem;
    this->is_player_turn = other.is_player_turn;
    this->is_computer = other.is_computer;
    return *this;
}


string Player::getName() const
{
    return this->name;
}
string Player::getpassword() const
{
    return this->password;
}
bool Player::getIsAlive() const
{
    return this->is_alive;
}
bool Player::getIsPlayerTurn() const
{
    return this->is_player_turn;
}
int Player::getScore() const
{
    return this->score;
}
int Player::getNumberOfCardInHand() const
{
    return this->cards_in_hands.size();
}
vector<Card>& Player::getCardInHand() 
{
    return this->cards_in_hands;
}
vector<string>& Player::getNameOfPlayerInteam()
{
    return this->name_of_player_in_teem;
}


void Player::setName(string name)
{
    this->name = name;
}
void Player::setpassword(string password)
{
    this->password = password;
}
void Player::setIsAlive(bool is_alive)
{
    this->is_alive = is_alive;
}
void Player::setIsPlayerTurn(bool turns_played)
{
    this->is_player_turn = turns_played;
}
void Player::setScore(int score)
{
    this->score = score;
}

void Player::receiveCard(Card temp)
{
    this->cards_in_hands.push_back(temp);
}
Card Player::playCard(int indexCard)
{
    Card temp = this->cards_in_hands[indexCard];
    this->cards_in_hands.erase(cards_in_hands.begin() + indexCard);
    return temp;
}
void Player::showCard() 
{
    if (cards_in_hands.size()==0)
    {
        cout << "|        NO CARDS IN HAND!            |\n";
        return;
    }
    for (int i = 0; i < this->cards_in_hands.size(); i++)
    {
        cout << "\n+============== Card " << i + 1 << " ==============+\n";
        Card temp = this->cards_in_hands[i];
        this->cards_in_hands[i].showCardInformation();
    }
}
Card Player::returnCard(int indexCard)
{
    return this->cards_in_hands[indexCard];
}

void Player::receiveTeamName(string name)
{
    this->name_of_player_in_teem.push_back(name);
}

void Player::clearTeamNames()
{
    this->name_of_player_in_teem.clear();
}
void Player::clearCardInHand()
{
    this->cards_in_hands.clear();
}
int Player::playerPlayGame()
{
    int dastoor;
    cout << "+--------------------------------------+\n";
    cout << "| 1. Play a Card                       |\n";
    cout << "| 2. Play tow same Cads                |\n";
    cout << "| 3. Play tree same Cads               |\n";
    cout << "| 4. Play five diffrente Cads          |\n";
    cout << "| 5. Draw a Card                       |\n";
    cout << "| 6. Stop Game                         |\n";
    cout << "+--------------------------------------+\n";
    cout << " What is your decision? ";
    cin >> dastoor;
    return dastoor;
}
int Player::computerEasyPlayGame(string status , int index)
{
    if (this->cards_in_hands.size() == 0) return 5;
    int number_of_cards = this->cards_in_hands.size();
    if (status == "dastoor")
    {
        int random_number = rand() % 2;
        if (random_number == 0)
        {
            return 1;
        }
        else return 5;
    }
    else if (status == "1")
    {
        int random_number = rand() % number_of_cards;
        return random_number;
    }
}



int Player::computerHardPlayGame(Card next, string status, int index)
{
    if (this->cards_in_hands.size() == 0) return 5;
    int number_of_cards = this->cards_in_hands.size();

    int GharOghati = 0, JimFang = 0, BajSibyl = 0, NaroyNakar = 0, NaKheir = 0;
    int KhanzarPanzar1 = 0, KhanzarPanzar2 = 0, KhanzarPanzar3 = 0, KhanzarPanzar4 = 0;

    for (int i = 0; i < number_of_cards; i++)
    {
        if (this->cards_in_hands[i].getName() == "GharOghati") GharOghati++;
        if (this->cards_in_hands[i].getName() == "JimFang") JimFang++;
        if (this->cards_in_hands[i].getName() == "BajSibyl") BajSibyl++;
        if (this->cards_in_hands[i].getName() == "NaroyNakar") NaroyNakar++;
        if (this->cards_in_hands[i].getName() == "NaKheir") NaKheir++;
        if (this->cards_in_hands[i].getName() == "KhanzarPanzar1") KhanzarPanzar1++;
        if (this->cards_in_hands[i].getName() == "KhanzarPanzar2") KhanzarPanzar2++;
        if (this->cards_in_hands[i].getName() == "KhanzarPanzar3") KhanzarPanzar3++;
        if (this->cards_in_hands[i].getName() == "KhanzarPanzar4") KhanzarPanzar4++;
    }

    if (status == "dastoor")
    {
        if (GharOghati || JimFang || BajSibyl || NaroyNakar)
        {
            return 1;
        }
        else if ( (KhanzarPanzar1 % 2 == 0 && KhanzarPanzar1 > 0) || (KhanzarPanzar2 % 2 == 0 && KhanzarPanzar2 > 0) ||
            (KhanzarPanzar3 % 2 == 0 && KhanzarPanzar3 > 0) || (KhanzarPanzar4 % 2 == 0 && KhanzarPanzar4 > 0) ||
            (NaKheir % 2 == 0 && NaKheir > 0))
        {
            return 2;
        }
        return 5;
    }
    else if (status == "1")
    {
        for (int i = 0; i < number_of_cards; i++)
        {
            string name = this->cards_in_hands[i].getName();
            if (name == "GharOghati" || name == "JimFang" || name == "BajSibyl" || name == "NaroyNakar")
            {
                return i;
            }
        }
        return 0;
    }
    return 5;
}

vector<int> Player::computerHardPlayGame(Card next, string status)
{
    vector<int> ans(2, -1);
    if (this->cards_in_hands.size() < 2) return ans;
    int number_of_cards = this->cards_in_hands.size();

    int KhanzarPanzar1 = 0, KhanzarPanzar2 = 0, KhanzarPanzar3 = 0, KhanzarPanzar4 = 0, NaKheir = 0;

    for (int i = 0; i < number_of_cards; i++)
    {
        if (this->cards_in_hands[i].getName() == "KhanzarPanzar1") KhanzarPanzar1++;
        if (this->cards_in_hands[i].getName() == "KhanzarPanzar2") KhanzarPanzar2++;
        if (this->cards_in_hands[i].getName() == "KhanzarPanzar3") KhanzarPanzar3++;
        if (this->cards_in_hands[i].getName() == "KhanzarPanzar4") KhanzarPanzar4++;
        if (this->cards_in_hands[i].getName() == "NaKheir") NaKheir++;
    }

    if (status == "2")
    {
       
        if (KhanzarPanzar1 % 2 == 0)
        {
            for (int i = 0; i < number_of_cards; i++)
            {
                if (this->cards_in_hands[i].getName() == "KhanzarPanzar1")
                {
                    ans[0] = i;
                    for (int j = i + 1; j < number_of_cards; j++)
                    {
                        if (this->cards_in_hands[j].getName() == "KhanzarPanzar1")
                        {
                            ans[1] = j;
                            return ans;
                        }
                    }
                }
            }
        }

        if (KhanzarPanzar2 % 2 == 0)
        {
            for (int i = 0; i < number_of_cards; i++)
            {
                if (this->cards_in_hands[i].getName() == "KhanzarPanzar2")
                {
                    ans[0] = i;
                    for (int j = i + 1; j < number_of_cards; j++)
                    {
                        if (this->cards_in_hands[j].getName() == "KhanzarPanzar2")
                        {
                            ans[1] = j;
                            return ans;
                        }
                    }
                }
            }
        }
        if (KhanzarPanzar3 % 2 == 0)
        {
            for (int i = 0; i < number_of_cards; i++)
            {
                if (this->cards_in_hands[i].getName() == "KhanzarPanzar3")
                {
                    ans[0] = i;
                    for (int j = i + 1; j < number_of_cards; j++)
                    {
                        if (this->cards_in_hands[j].getName() == "KhanzarPanzar3")
                        {
                            ans[1] = j;
                            return ans;
                        }
                    }
                }
            }
        }
        if (KhanzarPanzar4 % 2 == 0)
        {
            for (int i = 0; i < number_of_cards; i++)
            {
                if (this->cards_in_hands[i].getName() == "KhanzarPanzar4")
                {
                    ans[0] = i;
                    for (int j = i + 1; j < number_of_cards; j++)
                    {
                        if (this->cards_in_hands[j].getName() == "KhanzarPanzar4")
                        {
                            ans[1] = j;
                            return ans;
                        }
                    }
                }
            }
        }
        if (NaKheir % 2 == 0)
        {
            for (int i = 0; i < number_of_cards; i++)
            {
                if (this->cards_in_hands[i].getName() == "NaKheir")
                {
                    ans[0] = i;
                    for (int j = i + 1; j < number_of_cards; j++)
                    {
                        if (this->cards_in_hands[j].getName() == "NaKheir")
                        {
                            ans[1] = j;
                            return ans;
                        }
                    }
                }
            }
        }
    }
    return ans;
}



Player::~Player()
{

}
