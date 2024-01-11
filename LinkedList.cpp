#include <bits/stdc++.h>


class node{
private:
    int data;
    node* next;
public:
    node(){
        this->data = 0;
        this->next = nullptr;
    }


    node(int n){
        this->data = n;
        this->next = nullptr;

    }

    int getData();
    node* getNext();
    void setNext(node* nodePtr);
};

node* node::getNext(){
    return this->next;
}


void node::setNext(node* nodePtr){
    this->next = nodePtr;
}



class LinkedList{
private:
    node* head;
    node* tail;

public:
    void pushFront(node& N);
    void pushBack (node& N);
    void popFront();
    void popBack();
};



void LinkedList::pushFront(node& N){
    N.setNext(head);
    this->head = &N;
}

void LinkedList::pushBack(node& N){
    this->tail->setNext(&N);
    this->tail = &N;
}


void LinkedList::popFront(){
    node* popHead = this->head;
    this->head = head->getNext();

    delete popHead;
}

void LinkedList::popBack(){
    node* nodePtr = this->head;

    while(nodePtr->getNext()->getNext() != nullptr){
        nodePtr = nodePtr->getNext();
    }

    this->tail = nodePtr->getNext();
    delete tail->getNext();
    tail->setNext(nullptr);
}
