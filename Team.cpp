
#include"Team.hpp"

using namespace std;

Team::Team()
{
    numar_playeri=0;
    coechipieri=NULL;
    nume_echipa="";
    scorFinal= 0.0;
}

Team::Team(const Team &copie)
{
    numar_playeri=copie.numar_playeri;
    coechipieri=new Player[numar_playeri];
    for(int i=0;i<numar_playeri;i++) {

        coechipieri[i]=copie.coechipieri[i];

    }
    nume_echipa=copie.nume_echipa;
    scorFinal=copie.scorFinal;
}

Team::Team(int nr, Player* c, string nume)
{
    numar_playeri=nr;
    coechipieri=new Player[numar_playeri];
    for ( int i = 0; i < numar_playeri; i++) {
        coechipieri[i]=c[i];
    }
    nume_echipa=nume;
}


Team& Team::operator=(const Team &t)
{
    numar_playeri=t.numar_playeri;
    coechipieri=new Player[numar_playeri];
    for(int i=0;i<numar_playeri; i++) {
        coechipieri[i]=t.coechipieri[i];
    }
    nume_echipa=t.nume_echipa;
    scorFinal=t.scorFinal;
    return *this;
}

Team::~Team()
{
    delete [] coechipieri;
}

int Team::get_numar_playeri()
{
    return numar_playeri;
}

string Team::get_nume_echipa()
{
    return nume_echipa;
}

Player* Team::get_coechipieri()
{
    return coechipieri;
}

void Team::set_numar_playeri(int nr)
{
    numar_playeri=nr;
}

void Team::set_nume_echipa(string nume)
{
    nume_echipa=nume;
}

istream & operator>>(istream &citeste, Team &t){

    citeste >> t.numar_playeri;
    getline(citeste, t.nume_echipa);
    t.coechipieri = new Player[t.numar_playeri];
    for(int i = 0; i < t.numar_playeri; i++){

       citeste >> t.coechipieri[i];

    }

    return citeste;
}

ostream & operator<<(ostream &afiseaza, Team &t){

    //afiseaza<<t.numar_playeri;
    afiseaza<<t.nume_echipa << " ";
    //for(int i = 0; i < t.numar_playeri; i++){

      // afiseaza<< t.coechipieri[i];
    //}
    afiseaza << t.scorFinal << endl;
    return afiseaza;
}

void Team::afisare()
{
    cout<<numar_playeri<<" ";

    for(int i = 0; i < numar_playeri; i++){

       coechipieri[i].afisare();
       cout<<endl;
    }
    cout<<nume_echipa<<endl;
}

void Team::afisare_fisier(ostream& fisier)
{
    string aux=this->nume_echipa.erase(0,1);
   // fisier<<this->numar_playeri<<" ";
    //for(int i=0 ; i<this->numar_playeri; i++) {
       // this->coechipieri[i].afisare_fisier(fisier);
   // }
    char space=' ';
   if(aux[aux.length()-1]==space)
     aux.erase(aux.end()-1, aux.end());

    this->set_nume_echipa(aux);
    fisier<<aux<<endl;
    //fisier<<scor_echipa()<<endl;
}

void Team::afisare_fisier2(ostream& fisier)
{
    string aux=this->nume_echipa;//.erase(0,1);
   // fisier<<this->numar_playeri<<" ";
    //for(int i=0 ; i<this->numar_playeri; i++) {
       // this->coechipieri[i].afisare_fisier(fisier);
   // }
    fisier<<aux<<endl;
    //fisier<<scor_echipa()<<endl;
}


float Team::scor_echipa()
{
    float s=0.0;
    for(int i=0;i < this->numar_playeri; i++) {
        s+=this->coechipieri[i].getPoints();
    }
    return s/this->numar_playeri;
}


void Team::set_scor_final(float scor) {
    this->scorFinal = scor;
}

float Team::get_scor_final() {
    return this->scorFinal;
}
