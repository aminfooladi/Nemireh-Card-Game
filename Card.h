#ifndef CARD_H
#define CARD_H

#include "main.h" 

using namespace std;

class Card
{
private:
    string name;
    string type;
    string description;
public:
    Card();
    Card(string name, string type, string description);

    Card(const Card& other);
    Card& operator= (const Card& other);
    bool operator==(const string other);

    string getName() const;
    string getType() const;
    string getDescription() const;

    void setName(string name);
    void setType(string type);
    void setDescription(string description);

    void showCardInformation() const;

    ~Card();
};

#endif