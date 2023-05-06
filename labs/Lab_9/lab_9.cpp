#include <iostream>
#include <unordered_map>

using namespace std;

struct node {

    // data and pointer

    double data;
    int num = 1;
    node* next;
    node* prev;

    // constructors
    node(node* nxt, node* prv)              // creation of empty linked list
    {
        next = nxt;
        prev = prv;
    }

    node (double d, node* nxt, node* prv) 
    {
        data = d;
        next = nxt;
        prev = prv;
    }

    node (double d, node* nxt, node* prv, int n)
    {
        data = d;
        next = nxt;
        prev = prv;
        num = n;
    }

    ~node() {}

};


struct doubly_linked_list {

    node* head = new node(nullptr, nullptr);
    node* tail = new node(nullptr, head);

    doubly_linked_list() // initializes head and tail nodes
    {    
        head->next = tail;
    }

    ~doubly_linked_list() {}

    // Debug Functions

    void append(double data, int n);
    bool search(double input);
    node* search_node(double input);
    void remove(node* node);
    void remove_by_num(double input);
    void print();
    void swap(node* nodeOne, node* nodeTwo);
    node* partition(node* low, node* high);

    // Actual Lab Stuff

    void remove_duplicates_sorted();
    void remove_duplicates_unsorted();
    doubly_linked_list search_list();
    void quick_sort(node* left, node* right);

};

void doubly_linked_list::swap(node* nodeOne, node* nodeTwo) {
    double temp = nodeOne->data;
    nodeOne->data = nodeTwo->data;
    nodeTwo->data = temp;
}

void doubly_linked_list::print(){
    node* current = head->next;
    int index = 0;

    while(current != tail)
    {
        cout << "Node [" << index << "]" << endl;
        cout << "data: " << current->data << " num: " << current->num << endl;
        current = current->next;
        index++;
    }
}

void doubly_linked_list::remove(node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;

    delete node;
}

void doubly_linked_list::remove_by_num(double num) {
    node* current = head;
    while (current != nullptr)
    {
        if (current->data == num) 
        {
            node* temp = current ->next;
            remove(current);
            current = temp;
        }

        else { current = current->next;}
    }
}

void doubly_linked_list::append(double data, int n=0)
{
    node* last = new node(data, tail, tail->prev, n);
    tail->prev->next = last;
    tail->prev = last;
}

bool doubly_linked_list::search(double input) {

    node* current = head;

    while (current != nullptr)                  // keep looping till hits tail
    {
        if (current->data == input) { return true; }
        else {current = current-> next;}
    }
    return false;                            // executes only after finding null

}

node* doubly_linked_list::search_node(double input) {

    node* current = head;

    while (current != nullptr)                  // keep looping till hits tail
    {
        if (current->data == input) { return current; }
        else {current = current-> next;}
    }
    return current;                            // executes only after finding null

}

void doubly_linked_list::remove_duplicates_unsorted()
{
    node* current = head;
    unordered_map<double, int> umap;
    unordered_map<double,int> empty;

    while (current != nullptr)
    {
        double data = current->data;

        if (current == head || current == tail) {current = current -> next;}

        else if (umap.find(data) == umap.end())  // num is not in list
        {
            umap[data] = 1;
            current = current -> next;
        }

        else                                // num is in list
        {
            umap = empty;                   // resets umap
            remove_by_num(data);
            current = head;                 // avoids all errors               
        }
    }
}

void doubly_linked_list::remove_duplicates_sorted()
{
    node* current = head;
    
    while (current != tail)
    {
        double cur_data = current->data;
        double next_data = current->next->data;

        if (cur_data == next_data)
        {
            node* temp = current->prev;
            remove_by_num(cur_data);
            current = temp;
        }

        else {current = current -> next;}

    }
}


doubly_linked_list doubly_linked_list::search_list(){
    doubly_linked_list output;
    node* current = head->next;

    while (current != tail)
    {
        double data = current -> data;
        node* output_current = output.head->next;

        bool found_new = true;

        while (output_current != output.tail)       // loops through output
        {
            if (data == output_current->data)       // dup found
            {
                output_current->num = output_current->num + 1;
                found_new = false;
            }
            output_current = output_current->next;
        }

        if (found_new)
        {
            output.append(data, 1);         // append 
        }

        current = current->next;

    }

    return output;
}

node* doubly_linked_list::partition(node* low, node* high) {
    double pivot = high->data;

    node* current = low->prev;

    for (node* i = low; i != high; i = i->next)
    {
        double i_data = i->data;
        if (i_data <= pivot)
        {
    
            if (current == NULL) { current = low;}
            else {current = current->next;}
            
            swap(current, i);
        }
    }

    if (current == NULL) { current = low;}
    else {current = current->next;}
    swap(current, high);
    
    return current;
}

void doubly_linked_list::quick_sort(node* low, node* high) {

    if (high != nullptr && low != high && low != high->next)
    {
        node* pivot_location = partition(low, high);
        quick_sort(low, pivot_location->prev);
        quick_sort(pivot_location->next, high);
    }

}


int main() {

    // remove_duplicated_unsorted

    cout << "Remove Duplicates (if all 0, then test was successful): " << endl;

    doubly_linked_list list;

    list.append(5.0);
    list.append(5.0);
    list.append(5.0);
    list.append(2.0);
    list.append(2.1);
    list.append(2.1);
    list.append(3.0);
    list.append(6.0);

    list.remove_duplicates_unsorted();

    cout << "remove_duplicates_unsorted: " << list.search(5.0) << list.search(2.1) << endl;           // should output 0
  
    // List: 2, 3, 6

    list.append(6.0);
    list.append(6.0);
    list.append(7.0);
    list.append(7.0);


    list.remove_duplicates_sorted();
    cout << "remove_duplicates_sorted: " << list.search(6.0) << list.search(7.0) << endl << endl;

    // search_list
    doubly_linked_list test;
    test.append(1.0);
    test.append(1.0);
    test.append(1.0);
    test.append(2.2);
    test.append(1.0);
    test.append(0);
    test.append(2.2);

    cout << "Normal List: " << endl;
    test.print();
    cout << endl;

    doubly_linked_list pog = test.search_list();

    cout << "Search List: " << endl;
    pog.print();

    cout << endl << endl;

    // Quick Sort

    doubly_linked_list stuff;   // head <-> 5.0 <-> 4.0 <-> 3.0 <-> 2.0 <-> 1.0 <-> -99.0 <-> tail
    stuff.append(5.0);
    stuff.append(4.0);
    stuff.append(3.0);
    stuff.append(9999.0);
    stuff.append(2.0);
    stuff.append(1.0);
    stuff.append(-99.0);

    cout << "Before Quick Sort: " << endl;
    stuff.print();
    cout << endl;

    stuff.quick_sort(stuff.head->next, stuff.tail->prev);

    cout << "After Quick Sort: " << endl;
    stuff.print();

    cout << endl << endl;


    return 0;
}