
#pragma once
#include"Team.hpp"
class Node
{
public:
    Team data;
    Node* next;

    Node(Team d)
    {
        data=d;
        next=NULL;
    }

    Team get_data()
    {
        return data;
    }
    Node* get_next()
    {
        return next;
    }
    void set_data(Team data)
    {
        this->data=data;
    }
    void set_next(Node* next)
    {
        this->next=next;
    }
};
