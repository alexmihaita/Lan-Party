
#pragma once
#include"Node.hpp"
class Linked_list

{
private:
    Node *head;
public:
    Linked_list();
    ~Linked_list();
    void append_node(Team t);
    void delete_node(Node* );
    void Reverse();
    Node* get_head()
    {
        return head;
    }
    Node* get_curr();
    void afisare_lista_fisier(ostream &);
    void set_lista(Node* head1)
    {
        head=head1;
    }
    void citire_afisare(char* argv[]);
    void delete_afisare(char* argv[]);
    int highestpower(int);
    void lowelm();
    int sizeoflist();
    void afisare_lista_fisier2(ostream&);
    void stergere_echipe(char* argv[]);
    Team& operator[]( int i);
};
