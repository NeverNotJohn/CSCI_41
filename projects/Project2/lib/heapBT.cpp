#include "func.h"

using namespace std;

/*
                                                      )                 
   (                           *   )               ( /(                 
 ( )\(           ) (   (     ` )  /((     (   (    )\())  (    )        
 )((_)\  (    ( /( )(  )\ )   ( )(_))(   ))\ ))\  ((_)\  ))\( /( `  )   
((_)((_) )\ ) )(_)|()\(()/(  (_(_()|()\ /((_)((_)  _((_)/((_)(_))/(/(   
 | _ |_)_(_/(((_)_ ((_))(_)) |_   _|((_|_))(_))   | || (_))((_)_((_)_\  
 | _ \ | ' \)) _` | '_| || |   | | | '_/ -_) -_)  | __ / -_) _` | '_ \) 
 |___/_|_||_|\__,_|_|  \_, |   |_| |_| \___\___|  |_||_\___\__,_| .__/  
                       |__/                                     |_|     

*/

// Node:

node::node(int data_in, int priority_in, node* parent_in)
{
    data = data_in;
    priority = priority_in;
    parent_in = parent;
    left_child = nullptr;
    right_child = nullptr;
}

node::~node()                       // assumes node is at bottom
{ 
    if (parent->left_child == this)
    {
        parent->left_child = nullptr;
    }
    else
    {
        parent->right_child = nullptr;
    }
    delete this;
}

// Heap

node* heap_BT::root = nullptr;      // allows for default params
node* heap_BT::tail = nullptr;

// MISC FUNCTIONS

void heap_BT::swap(node* left, node* right)
{
    int temp_data = left->data;
    int temp_prio = left->priority;

    left->data = right->data;
    left->priority = right->priority;

    right->data = temp_data;
    right->priority = temp_prio;
}

void heap_BT::display(node* root, int level)
{

    if (level == 10) {return;}

    /* Format:

    |--1
       |--2         (Left Child of 1)
       |   |--2                         (Left Child of 2)
       |   |--4                         (Right Child of 2)
       |--3         (Right Child of 3)
       |   |--6
       |   |--7

    */

    if (level == 0) {cout << "|--" << root->priority << endl;}
    else
    {
        cout << "   ";
        for (int i = 1; i < level; i++)
        {
            cout << "|   ";
        }
        cout << "|--" << root->priority << endl;
    }
    node* L = root->left_child;
    node* R = root->right_child;

    if (L == nullptr && R == nullptr) {return;}
    if (L != nullptr) {display(L, (level+1));}
    if (R != nullptr) {display(R, (level+1));}
}

void heap_BT::push_back(node* item, node* current, int level)
{

    tail = item;

    if (current == nullptr)
    {
        root = item;
        tail = root;
        return;
    }

    if (current == root)
    {
        while (true)        // HAS TO INSERT TO THE VERY LEFT 
        {
            if (current->left_child == nullptr) { break;}
            else {current = current->left_child;}
        }
        current->left_child = item;
        item->parent = current;
        return;
    }

    switch (level)
    {
    case 0:             // Initial level
        if (current->parent->right_child == nullptr)
        {
            current->parent->right_child = item;
            item->parent = current->parent;
            return;
        }
        else
        {
            push_back(item, current->parent, level+1);
            return;
        }
        break;

    case 1:
        if (current->left_child == nullptr)
        {
            current->left_child = item;
            item->parent = current;
            return;
        }
        else if (current->right_child == nullptr)
        {
            current->right_child = item;
            item->parent = current;
            return;
        }
        else if (current == current->parent->left_child)
        {
            push_back(item, current->parent->right_child, level);
            return;
        }
    
    default:

        if (current == current->parent->right_child) 
        {
            push_back(item, current->parent, level + 1);
            return;
        }
        if (current == current->parent->left_child) 
        { 
            push_back(item, current->parent->right_child->left_child, level - 1); 
            return;
        }
        break;
    }
}

// ASSIGNMENTS FUNCTIONS

void heap_BT::swim(node* current)
{
    if (current == root) { return; }      // prevents breaking

    int current_prio = current->priority;
    int parent_prio = current->parent->priority;

    if (parent_prio <= current_prio) { return; }

    swap(current->parent, current);
    swim(current->parent);               // repeat recursively

}

void heap_BT::sink(node* current)
{
    while (true) {
        node* min = current;

        node* L = current->left_child;
        node* R = current->right_child;

        if (L != nullptr && L->priority < min->priority)
        {
            min = L;
        }

        if (R != nullptr && R->priority < min->priority)
        {
            min = R;
        }

        if (current != min)
        {
            swap(current, min);
            current = min;
        } else {
            break;
        }
    }
}

void heap_BT::insert(int data, int priority)
{
    node* item = new node(data, priority, nullptr);
    push_back(item);
    swim(item);
}



