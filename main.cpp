#include <iostream>
#include<fstream>
#include"Linked_list.hpp"
#include"Stiva_buna.hpp"
#include "Queue.hpp"
#include"BST.hpp"
using namespace std;

void cerinta3(Queue &c, Queue &c2, Stiva_buna &s, Stiva_buna &s2,ofstream& afiseaza, BST& b)
{
    int k=0;
    afiseaza << endl;
    ofstream f("v.txt");
    while(c.sizeofcoada() != 1) {
    afiseaza << "--- ROUND NO:" <<  k+1 << endl;
    //afiseaza<<"SIZE OF COADA: " << c.sizeofcoada() << endl;
    c.display_coada(afiseaza);
    //Team t;
    //t=c.pop_coada();

    afiseaza<<endl<<"WINNERS OF ROUND NO:" <<  k+1 << endl;
    Team team1;
   // team1=c.pop_coada();
    Team team2;
    //team2=c.pop_coada();



    while(!c.isEmpty())
    {
        //cout<<"while";
        //team1=c.pop_coada();
        //team2=c.pop_coada();
        team1 = c.getFront()->data;
        c.delete_coada();
        team2 = c.getFront()->data;
        c.delete_coada();
        c2.delete_coada();
        c2.delete_coada();
        if(team1.scor_echipa()>team2.scor_echipa()) {


            s.add_stiva(team1);
            s2.add_stiva(team1);


        }

        else if(team2.scor_echipa()>team1.scor_echipa()) {


            s.add_stiva(team2);
            s2.add_stiva(team2);
            //f << team2;
            }
        else {
                    s.add_stiva(team2);
                    s2.add_stiva(team2);

            }

    }

   float j = (float) k + 1.0f;
   s.display_stiva(afiseaza, j);

   if(s.sizeofstiva()==8) {
    while(!s2.isEmpty()) {
    f<<"Marime stiva "<<s2.sizeofstiva();
    Team t=s2.peek();
    t.set_scor_final(t.scor_echipa()+j);
    f<<"Echipa "<<t.get_nume_echipa()<<endl;
    f<<"Scor "<<t.get_scor_final();
     b.myinsert(t);
     s2.pop_stiva();
   }

   }



      while(!s.isEmpty()) {

        Team t1 = s.peek();
        c.add_coada(t1);
        s.pop_stiva();

      }

       while(!s2.isEmpty()) {

        Team t1 = s2.peek();
        c2.add_coada(t1);
        s2.pop_stiva();

      }

    if(c.sizeofcoada() != 1)
        afiseaza<<endl;


    k++;
}


}

int main(int argc, char *argv[])
{


    ifstream cerinte(argv[1]);
    ofstream afiseaza(argv[3], ios::app);
    ofstream fisier("a.txt");
    ifstream citeste("d.in");
    //afiseaza.seekg(0, ios::end);
    Linked_list lista;
     BST b;

    for(int i=0; i<5; i++)
    {
        int task;
        cerinte>>task;
        switch (i)
        {
        case 0:
        {
            if(task==1)
                lista.citire_afisare(argv);
            break;
        }
        case 1:
        {
            if(task==1)
                lista.stergere_echipe(argv);
            break;
        }
        case 2:
        {
            if(task==1)
            {
                Stiva_buna s,s2;
                Queue c,c2;

                for(int i=0; i<lista.sizeoflist(); i++)
                {
                    lista[i].set_scor_final(lista[i].scor_echipa());
                    c.add_coada(lista[i]);
                    c2.add_coada(lista[i]);

                }

                    cerinta3(c,c2,s,s2,afiseaza, b);


                //string aux = t.get_nume_echipa();
                //cout  << c.sizeofcoada();
               // c.display_coada(afiseaza);

            }
            break;
        }
        case 3:
        {
            if(task==1)
            {
                b.display(afiseaza);
            }
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            cout<<"Eroare!"<<endl;
            break;
        }
        }
    }


    cerinte.close();
    return 0;

}

