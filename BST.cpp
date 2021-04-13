#include"BST.hpp"
using namespace std;
node* BST :: makeEmpty(node* t) {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

node* BST :: myinsert(Team x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x.get_scor_final() > t->data.get_scor_final())
            t->left = myinsert(x, t->left);
        else if(x.get_scor_final() < t->data.get_scor_final())
            t->right = myinsert(x, t->right);
        else if(x.get_scor_final() == t->data.get_scor_final()) {
                if(x.get_nume_echipa()>t->data.get_nume_echipa())
                    t->left = myinsert(x, t->left);
                    else
                     t->right = myinsert(x, t->right);
        }

        return t;
    }

node* BST::findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

node* BST::findMax(node* t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }


void BST::inorder(node* t, ofstream& afiseaza) {
        if(t == NULL)
            return;
        inorder(t->left,afiseaza);
        afiseaza<<t->data.get_nume_echipa().append(34-t->data.get_nume_echipa().length(), ' ')<<"-  "  << std::fixed<< std::setprecision(2)<< t->data.get_scor_final() <<endl;
        inorder(t->right, afiseaza);
    }


void BST:: myinsert(Team x) {
        root = myinsert(x, root);
        ofstream fisier("y.txt");
        fisier<<"Nume echip: "<<x.get_nume_echipa()<<" Scor "<<x.get_scor_final()<<endl;
    }


void BST::display(ofstream& afiseaza) {
        afiseaza<<endl;
        afiseaza<<"TOP 8 TEAMS:"<<endl;
        inorder(root, afiseaza);
       // cout << endl;
    }


