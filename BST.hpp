#pragma once
#include<iostream>
#include<iomanip>
#include"Team.hpp"
#include"node.hpp"
using namespace std;

class BST {

public:

    node* root;


    node* makeEmpty(node* t);

    node* myinsert(Team x, node* t);


    node* findMin(node* t);

    node* findMax(node* t);


    void inorder(node* t, ofstream& afiseaza);

    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        root = makeEmpty(root);
    }
    void myinsert(Team x);
    void display(ofstream& afiseaza);
};

