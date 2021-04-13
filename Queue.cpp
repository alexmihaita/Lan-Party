#include "Queue.hpp"
void Queue::add_coada(Team x)
{
    //Create a new LL node
		Node* temp = new Node(x);

		// If queue is empty, then
		// new node is front and rear both
		if (this->spate == NULL) {
			this->fata = this->spate = temp;
			return;
		}

		// Add the new node at
		// the end of queue and change rear
		this->spate->next = temp;
		this->spate = temp;
}




    void Queue::display_coada( ofstream& fisier ) {
    Node* temp = fata;
    if ((fata == NULL) && (spate == NULL))
    {
        fisier<<"Coada este goala"<<endl;
        return;
    }
    while (temp != NULL)
    {
        fisier<<temp->data.get_nume_echipa().append(33-temp->data.get_nume_echipa().length(), ' ')<<"-";//.afisare_fisier(fisier);
        temp = temp->next;
        string str=temp->data.get_nume_echipa();
        // string str2=
        str.insert(str.begin(), 33-str.length(), ' ');
        fisier<<str<<endl;
        temp=temp->next;
    }
    }
    void Queue::delete_coada() {

    if (fata == NULL)
        return;

    // Store previous front and
    // move front one node ahead
    Node* temp = fata;
    fata = fata->next;

    // If front becomes NULL, then
    // change rear also as NULL
    if (fata == NULL)
        spate = NULL;

    delete (temp);
    }
