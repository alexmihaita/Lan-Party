
#pragma once
#include"Node.hpp"
using namespace std;

class Stiva_buna
{
private:
    Node* top;
public:
    Stiva_buna()
    {
        top=NULL;
    }
    ~Stiva_buna()
    {
        delete top;
    }
    void add_stiva(Team);
    bool isEmpty();
    void pop_stiva();
    void display_stiva(ostream&, float incr);
    int sizeofstiva();
    Team peek();

};
