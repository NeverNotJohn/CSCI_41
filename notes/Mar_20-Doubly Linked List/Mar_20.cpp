#include <iostream>

using namespace std;

/*

    DOUBLY LINKED LIST

    Main functions in class

        Insert:
            head
            tail
            middle
                (after particular element)

        Delete:
            Head
            tail
            middle

        Search:
            Return element w/ particular value

        Display:
            Duh

    Requirements in class

        Reference to sentinal head-node
        Reference to sentinal tail-node
        Size counter, excluding 2 sentinels

    Special cases of Doubly Linked Lists

        Empty List
            Size = 0
            head.next = tail
            tail.prev = head

*/

/*
        PSUEDO CODE

    addFirst()
        new(T)                         // create object
        T.data <= y                    // set data
        T.next <= head                 // set next pointer to head
        head.prev <= T                 // yada yada
        head.next <= T
        size++

*/

struct node_bare {

    int data;

    node_bare *next;
    node_bare *prev;             // add previous pointer
};

struct node {

    // data and pointer

    double data;
    node* next;
    node* prev;

    // constructors
    node(node* nxt, node* prv)              // creation of empty linked list
    {
        data = NULL;
        next = nxt;
        prev = prv;
    }

    node (double d, node* nxt, node* prv) 
    {
        data = d;
        next = nxt;
        prev = prv;
    }

    ~node() {}

};

class doublely_linked_list {

    // initialization of head and tail node
    doublely_linked_list() // initializes head and tail nodes
        {    
            node* head = new node(nullptr, nullptr);
            node* tail = new node(nullptr, head);
            head->next = tail;
        }
};



int main() {

}