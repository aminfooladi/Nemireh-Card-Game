#include "main.h" 
#include "Card.h"

Card::Card()
{
    this->name = "";
    this->type = "";
    this->description = "";
}

Card::Card(string name, string type, string description)
{
    this->name = name;
    this->type = type;
    this->description = description;
}

Card::Card(const Card& other)
{
    this->name = other.name;
    this->type = other.type;
    this->description = other.description;
}
Card& Card::operator=(const Card& other)
{
    this->name = other.name;
    this->type = other.type;
    this->description = other.description;
    return *this;
}
bool Card::operator==(const string other)
{
    
    if (this->name == other) return true;
    else return false;
}

string Card::getName() const
{
    return this->name;
}
string Card::getType() const
{
    return this->type;
}
string Card::getDescription() const
{
    return this->description;
}

void Card::setName(string name)
{
    this->name = name;
}
void Card::setType(string type)
{
    this->type = type;
}
void Card::setDescription(string description)
{
    this->description = description;
}

void Card::showCardInformation() const
{
    cout << "******************************************\n";
    if (this->type == "Good Cards")
    {
        cout << "\033[38;5;120m";
    }
    else if (this->type == "Medium Cards")
    {
        cout << "\033[38;5;153m"; 
    }
    else if (this->type == "Bad Cards")
    {
        cout << "\033[38;5;210m";
    }
    
    cout << "* Name : " << this->name << "\n";
    cout << "* Type : " << this->type << "\n";
    cout << "* Desc : " << this->description << "\n";
    
    cout << "\033[0m";
    cout << "******************************************\n";
}

Card::~Card()
{
}

