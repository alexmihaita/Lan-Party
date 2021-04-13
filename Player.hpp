
#pragma once
#include<iostream>
#include<string>
using namespace std;

class Player
{
private:
    string firstName;
    string secondName;
    int points;
public:
    Player(){};
    Player(string fn, string sn, int p);
    string getfName();
    string getsName();
    int getPoints();
    void afisare();
    friend istream & operator >> (istream&, Player&);
    friend ostream & operator << (ostream&, const Player&);
    Player & operator= ( const Player & );
    void afisare_fisier(ofstream &);
};
