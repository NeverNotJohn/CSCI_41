#ifndef func_h
#define func_h

#include <iostream>
#include <vector>
#include <stdlib.h>    
#include <time.h>   
#include <ctime>    
#include <iomanip>

using namespace std;

// Misc Functions

struct item{

    // Data
    int data;
    int priority;

    // Constructors
    item(int data_in, int priority_in) {
    data = data_in;
    priority = priority_in;
    }

    ~item() {}
};

void print(vector<int> lector);                         // Output first 100 values of int vector
void print(vector<item> lector);                        // Output first 100 priority values of item vector
void swap(int i, int j, vector<int> &mocter);           // swap int vector
void swap(int i, int j, vector<item> &mocter);          // swap item vector


// Quick Sort

int partition(int low, int high, vector<int> &vocter);
void quickSort(vector<int> &vicky, int low, int high);


// Priority Queue using vector

struct priorityQueueSortedVector {

    // Data
    vector<item> myVector;

    //Constructors
    priorityQueueSortedVector() {}
    ~priorityQueueSortedVector() {}

    // Functions
    void insert(int data, int priority);                // Linear Search and insert O(N^2) sort
    void insert_but_better(int data, int priority);     // Binary Search and insert O(NlogN) sort
    void delMax()   {myVector.pop_back();}
};

struct priorityQueueHeap {                              // Priority Queue using heap

    /*
        MIN HEAP
    */

    // Data
    vector<item> myVector;

    // Constructors
    priorityQueueHeap() {}
    ~priorityQueueHeap() {}

    // Misc Functions
    int parent_index(int i) { return ( (i - 1) / 2); }
    int leftChild_index(int i) { return ( (2 * i) + 1 ); }
    int rightChild_index(int i) { return ( (2 * i) + 2);}
    bool is_valid(int parent_index=0);

    // Functions
    void insert(int data, int priority);                // Kind of also heapify
    void swim(int i);
    void sink(int i);
    item delMax();

};

// HEAP USING Binary Tree

struct node {
    
    // data
    int data;
    int priority;

    // pointers
    node* parent;
    node* left_child;
    node* right_child;

    // Constructors
    node(int data_in, int priority_in, node* parent_in);
    ~node();
    
};

struct heap_BT {

    // Data
    static node* root;
    static node* tail;

    // Constructors
    heap_BT() {};
    ~heap_BT() {};                                  // dont forget to delete all
    
    // Misc Functions
    void swap(node* left, node* bottom);
    void display(node* current = root, int level = 0);
    void push_back(node* item, node* current=tail, int level = 0);
    void pop_back(node* current = tail, int level = 0);
    void delete_node(node* node);

    node* find_right_most(node* current);                       // returns right most node
    node* find_left_most(node* current);                        // returns left most node


    // Assignment Functions
    void insert(int data, int priority);
    void swim(node* current);
    void sink(node* current);
    int delMax();

    int computeHeight(node* current = root, int level = 1);
    int computeLeaves(node* current = root);
    bool lookup(int key, node* current = root);
    vector<node*> sameLevel(node* current);
    bool descendant(node* current, node* aNode);

    // Functions

};


#endif