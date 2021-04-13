
#include"Linked_list.hpp"
#include<cmath>
Linked_list::Linked_list()
{
    head=NULL;
}


Linked_list::~Linked_list()
{



    Node* curr= head;
    while(curr!=0) {
        Node* next=curr->next;
        delete curr;
        curr=next;
    }
    head=0;
}

void Linked_list::append_node ( Team data )
{
    Node* n = new Node ( data );

    if ( head != NULL ) {
        Node* curr = head;

        while ( curr->next != NULL ) {
            curr = curr->next;
        }

        curr->set_next ( n );
    } else {
        head = n;
    }
}



void Linked_list::afisare_lista_fisier ( ostream &fisier )
{

    Node* curr = head;

    while ( curr != NULL ) {
        curr->data.afisare_fisier ( fisier );
        curr = curr->next;
    }

}

void Linked_list::afisare_lista_fisier2 ( ostream &fisier )
{


    Node* curr = head;

    while ( curr != NULL ) {
        curr->data.afisare_fisier2 ( fisier );
        curr = curr->next;
    }

}

void Linked_list::Reverse()
{


    // Initialize current, previous and
    // next pointers
    Node* current = head;
    Node *prev = NULL, *next = NULL;

    while ( current != NULL ) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }

    head = prev;


}

void Linked_list::citire_afisare(char* argv[])
{

    ifstream citeste (argv[2]);
    ofstream afiseaza (argv[3]);
    Team *t;
    int n;
    citeste>>n;
    t=new Team[n];

    for(int i=0; i<n;i++) {
        citeste>>t[i];
        this->append_node(t[i]);
    }
    this->Reverse();
    this->afisare_lista_fisier(afiseaza);
    citeste.close();
    afiseaza.close();

}

int Linked_list::sizeoflist()
{
    int count=0;
    Node* it=head;
    while(it)
    {
        count++;
        it=it->next;
    }
    return count;
}

void Linked_list::delete_afisare(char* argv[])
{
    ifstream citeste (argv[2]);
    ofstream afiseaza (argv[3]);

    int n1=this->sizeoflist();
    int m=highestpower(n1);

    while(m!=n1) {

        this->lowelm();
        n1--;
    }

}

void Linked_list::stergere_echipe(char* argv[])
{

    ifstream citeste(argv[2]);
    ofstream afiseaza(argv[3], ios::app);
    this->delete_afisare(argv);
    this->afisare_lista_fisier2(afiseaza);
}

int Linked_list::highestpower(int n)
{
    int res = 0;
    for (int i=n; i>=1; i--)
    {
        // If i is a power of 2
        if ((i & (i-1)) == 0)
        {
            res = i;
            break;
        }
    }
    return res;
}


void Linked_list::lowelm()
{

    float minim = 999999.f;

    Node* curr=head;
    Node* temp=NULL;
    while(curr!=NULL) {
        if(minim>curr->data.scor_echipa()) {
            minim=curr->data.scor_echipa();
            temp=curr;

            //return;
        }
        curr=curr->next;
    }
    this->delete_node(temp);
    //cout<<temp->data.get_nume_echipa();
    //return minim;
}


void Linked_list::delete_node( Node *n)
{
     // When node to be deleted is head node
    if(head == n)
    {
        if(head->next == NULL)
        {
            cout << "There is only one node." <<
                    " The list can't be made empty ";
            return;
        }

        /* Copy the data of next node to head */
        head->data = head->next->data;

        // store address of next node
        n = head->next;

        // Remove the link of next node
        head->next = head->next->next;

        // free memory
        free(n);

        return;
    }


    // When not first node, follow
    // the normal deletion process

    // find the previous node
    Node *prev = head;
    while(prev->next != NULL && prev->next != n)
        prev = prev->next;

    // Check if node really exists in Linked List
    if(prev->next == NULL)
    {
        cout << "\nGiven node is not present in Linked List";
        return;
    }

    // Remove node from Linked List
    prev->next = prev->next->next;

    // Free memory
    free(n);

    return;
}

Team& Linked_list::operator[](int i)
{
    int c=0;
    Node* curr=head;
    while(curr!=NULL)
    {
        if(c==i)
        {
            return curr->data;
        }
        else
        {
            c++;
            curr=curr->next;
        }
    }
}
