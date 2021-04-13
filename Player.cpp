
#include<fstream>
#include<iostream>
#include<string>
#include"Player.hpp"
using namespace std;


Player::Player(string fn, string sn, int p)
{
    firstName=fn;
    secondName=sn;
    points=p;
}

void Player::afisare()
{
    cout<<firstName<<" "<<secondName<<" "<<points;
}

Player& Player::operator=(const Player &p)
{
    firstName=p.firstName;
    secondName=p.secondName;
    points=p.points;
    return *this;
}

istream & operator>>(istream &citeste, Player &t)
{

    citeste>>t.firstName;
    citeste>>t.secondName;
    citeste>>t.points;
    return citeste;
}

ostream & operator<<(ostream &afiseaza, const Player &p)
{

    afiseaza<<p.firstName<<endl;
    afiseaza<<p.secondName<<endl;
    afiseaza<<p.points<<endl;
    return afiseaza;
}

void Player::afisare_fisier(ofstream& fisier)
{
   fisier<<firstName<<" "<<secondName<<" "<<points<<endl;
}
int Player::getPoints()
{
    return points;
}
