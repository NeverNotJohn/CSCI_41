#include <iostream>

using namespace std;

struct node {

    // data and pointer

    double data;
    node* next;

    // constructors
    node() 
    {
        data = 0;
        next = nullptr;
    }
    node (double d) 
    {
        data = d;
        next = nullptr;
    }
    node (double d, node* nxt) 
    {
        data = d;
        next = nxt;
    }

    ~node() {}

};

struct linkList{

    // creates linklist of three terms
    node* tail = new node(0.5);
    node* two = new node(0.4, tail);
    node* one = new node(0.3, two);

    node* head = one;
    
    bool search (double input);              // output true or false if item is in list
    bool search_rec(double input, node* head);

    void append(double input);
    void append_rec(node* head, double input);

};

bool linkList::search(double input) {

    node* current = head;

    while (current != nullptr)                  // keep looping till hits tail
    {
        if (current->data == input) { return true; }
        else {current = current-> next;}
    }
    return false;                            // executes only after finding null

}

bool linkList:: search_rec(double input, node* head) {
    if (head == nullptr)
    {
        return false;
    }
    
    else if (head -> data == input)
    {
        return true;
    }

    else 
    {
        return search_rec(input, head->next);
    }

}

void linkList::append(double input) {
    node* current = head;

    while (true)
    {
        if (current->next == nullptr) {break;}          // tail found
        else {current = current->next;}
    }

    node* last = new node(input);                       // new node
    current->next = last;                               // previous tail now points to new tail
}

void linkList::append_rec(node* head, double input) {
    if (head->next == nullptr)
    {
        node* last = new node(input);                       // new node
        head->next = last;    
    }
    
    else 
    {
        append_rec(head = head->next, input);
    }

}



int main() {

    // NORMAL SEARCH

    // with pointers
    linkList* listOne = new linkList();
    if (listOne->search(0.5)) {cout << "Num is in list! :D" << endl;}
    
    else {cout << "Num is NOT in list :(" << endl;}

    // without pointers
    linkList listTwo;
    if (listTwo.search(0.10)) {cout << "Num is in list! :D" << endl;}

    else {cout << "Num is NOT in list :(" << endl;}

    // RECURSIVE SEARCH

    // with pointers
    linkList* listThree = new linkList();
    if (listThree->search_rec(0.5, listThree->head)) {cout << "Num is in list! :D" << endl;}
    
    else {cout << "Num is NOT in list :(" << endl;}

    // without pointers

    linkList listFour;
    if (listFour.search_rec(0.10, listFour.head)) {cout << "Num is in list! :D" << endl;}
    
    else {cout << "Num is NOT in list :(" << endl;}

    // APPEND

    // with pointers
    linkList* listFive = new linkList();
    listFive->append(0.69);
    cout << listFive->search(0.69) << endl;         // 0 if append fails, 1 if append worked

    // without pointers
    linkList listSix;
    listSix.append(0.69);
    cout << listSix.search(0.69) << endl;

    
    // APPEND WITH RECURSION

    // with pointers
    linkList* listSeven = new linkList();
    listSeven->append_rec(listSeven->head, 0.69);
    cout << listSeven->search(0.69) << endl;         // 0 if append fails, 1 if append worked

    // without pointers
    linkList listEight;
    listEight.append_rec(listEight.head, 0.69);
    cout << listEight.search(0.69) << endl;


}

