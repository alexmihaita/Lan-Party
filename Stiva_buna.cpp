#include"Stiva_buna.hpp"
#include <iomanip>
using namespace std;

void Stiva_buna::add_stiva(Team d)
{

    // Create new node temp and allocate memory
    Node* temp;
    temp = new Node(d);

    // Check if stack (heap) is full.
    // Then inserting an element would
    // lead to stack overflow
    if (!temp)
    {
        cout << "\nHeap Overflow";
        exit(1);
    }

    // Initialize data into temp data field
    temp->data=d;

    // Put top pointer reference into temp link
    temp->next = top;

    // Make temp as top of Stack
    top = temp;
}

bool Stiva_buna::isEmpty()
{
     if(this->sizeofstiva()==0)
        return true;
    return false;
}

void Stiva_buna::pop_stiva()
{
    Node* temp;

    // Check for stack underflow
    if (top == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {

        // Top assign into temp
        temp = top;

        // Assign second node to top
        top = top->next;

        // Destroy connection between
        // first and second
        temp->next = NULL;

        // Release memory of top node
        free(temp);

    }
}

void Stiva_buna::display_stiva(ostream& fisier, float incr)
{
    Node* temp;
    // Check for stack underflow
    if (top == NULL)
    {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {

            // Print node data
            float scor = temp->data.scor_echipa() + incr;
            temp->data.set_scor_final(scor);
            fisier<<temp->data.get_nume_echipa().append(34-temp->data.get_nume_echipa().length(), ' ')<<"-  "  << std::fixed<< std::setprecision(2)<< scor <<endl;
            //fisier<<temp->data.get_nume_echipa()<<endl;

            // Assign temp link to temp
            temp = temp->next;
        }
    }
}


 int Stiva_buna::sizeofstiva()
 {
    Node * temp = top;
    int c =0;
    while(temp!=NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
 }

 Team Stiva_buna::peek()
{

    // Check for empty stack
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}


