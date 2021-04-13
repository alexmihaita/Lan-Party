#pragma once
#include"Player.hpp"
#include<fstream>
class Team
{
private:
    int numar_playeri;
    Player* coechipieri;
    string nume_echipa;
    float scorFinal;
public:
    Team();
    Team(int nr, Player* c, string nume_echipa);
    Team (const Team &);
    ~Team();
    Team & operator = (const Team &);

    int get_numar_playeri();
    Player* get_coechipieri();
    string get_nume_echipa();
    void set_numar_playeri(int nr);
    void set_nume_echipa(string nume);
    void set_scor_final(float scor);
    float scor_echipa();
    float get_scor_final();
    void afisare();
    friend istream& operator >> (istream &, Team &);
    friend ostream& operator << (ostream &, Team &);
    friend bool operator == (const Team&, const Team&);
    friend bool operator != ( const Team&, const Team&);
    //friend ifstream& operator >>(ifstream &, Team &);
    //friend ofstream& operator << (ofstream &, Team &);
    void afisare_fisier(ostream &fisier);
    void afisare_fisier2(ostream&);
    //void set_scor_echipa(int scor_echipa());

};
