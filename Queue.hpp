
#pragma once
#include"Node.hpp"

using namespace std;
class Queue
{
private:
    Node* fata, *spate;

public:
    Queue()
    {
        fata=NULL;
        spate=NULL;
    }


    Node* getFront() {
        return this->fata;
    }
    void add_coada(Team);
    void display_coada( ofstream& );
    void delete_coada();
    void display_coada2(ostream& );
    Team pop_coada();
    void display_runda(ostream&);
    bool isEmpty() {
    if(this->sizeofcoada()==0)
            return true;
        return false;
    }
    Team team_fata();
    Queue & operator = (const Queue &);
    int sizeofcoada()
{
    Node * temp = fata;
    int c =0;
    while(temp!=NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

};

