#include <bits/stdc++.h>

using namespace std;


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

    ~node(){
        if(next != nullptr)
            delete next;

        cout << endl <<"~node()!!!"<<endl;

    }


    node* getNext();
    int getData();
    void setNext(node* nodePtr);
};



int node::getData(){
    return this->data;
}

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
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList(){

        node* nodePtr = this->head;


        while(nodePtr->getNext() != nullptr){
            node* temp = nodePtr;

            nodePtr = nodePtr->getNext();

            delete temp;
        }

        if(nodePtr != nullptr)
            delete nodePtr;

        cout << endl << "~LinkedList()!!!!";

    }

    void pushFront(node& N);
    void pushBack (node& N);
    void popFront();
    void popBack ();
    void printList();
    bool emptyLL();
};



bool emptyLL(){
    if(this->head == nullptr){
        return true;
    }

    else return false;

}

void LinkedList::pushFront(node& N){
    N.setNext(head);
    this->head = &N;
}

void LinkedList::pushBack(node& N){
    if(this->head == nullptr){
        this->head = &N;
    }

    if(this->tail != nullptr){
        this->tail->setNext(&N);
    }


    this->tail = &N;

    cout << "pushBack!" << endl;
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

void LinkedList::printList(){
    node* nodePtr = this->head;

    while(true){
        cout << nodePtr->getData() << " ";

        if(nodePtr->getNext() != nullptr)
            nodePtr = nodePtr->getNext();

        else break;
    }

    cout << endl << "printList!!";
}



int main()
{
    node *n1 = new node(5);


    cout << n1->getData() << endl;


    LinkedList* LL = new LinkedList();

    LL->pushBack(*n1);

    LL->printList();

    delete LL;

    return 0;
}
