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
    parent_in = nullptr;
    left_child = nullptr;
    right_child = nullptr;
}

node::~node() {}                 


// Heap

node* heap_BT::root = nullptr;      // allows for default params
node* heap_BT::tail = nullptr;

// MISC FUNCTIONS

void heap_BT::swap(node* left, node* right)
{
    int temp_data = left->data;
    int temp_prio = left->priority;

    if (left == nullptr || right == nullptr) {return;}

    left->data = right->data;
    left->priority = right->priority;

    right->data = temp_data;
    right->priority = temp_prio;
}

void heap_BT::display(node* root, int level)
{

    // if (level == 12) {return;}

    /* Format:

    |--1
       |--2         (Right Child of 1)
       |   |--2                         (Right Child of 2)
       |   |--4                         (Left Child of 2)
       |--3         (Left Child of 1)
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
    if (R != nullptr) {display(R, (level+1));}
    if (L != nullptr) {display(L, (level+1));}
}

/*

void heap_BT::push_back(node* item, node* current, int level)
{

    tail = item;

    if (current == nullptr)
    {
        root = item;
        tail = root;
        item->parent = nullptr;
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

*/

void heap_BT::push_back(node* item, node* current, int level)
{

    tail = item;

    if (root == nullptr)                                        // empty list
    {
        root = item;
        tail = item;
        return;
    }

    else if (current == root)                                   // Move up until u hit root
    {

        if (level == 0)                                         // List of 1
        {
            current->left_child = item;
            item->parent = root;
            return;
        }

        current = find_left_most(current);

        current->left_child = item;
        item->parent = current;
        return;
    }   

    else if (level == 0)                                        // checks for immediate right
    {
        if (current->parent->left_child == current)             // is left
        {
            current->parent->right_child = item;
            item->parent = current->parent;
            return;
        }
        else                                                    // is right
        {
            push_back(item, current->parent, level+1);
            return;
        }
    }

    else
    {
        if (current->parent->left_child == current)             // is left
        {
            current = find_left_most(current->parent->right_child);
            current->left_child = item;
            
            item->parent = current;
            return;
        }
        else                                                    // is right
        {
            push_back(item, current->parent, level+1);
            return;
        }
    }

}

/*

void heap_BT::pop_back(node* current, int level)
{
    if (current == root)
    {

        if (level == 0)     // Delete root into empty tree
        {
            tail = nullptr;
            root = nullptr;
            delete current;
            return;
        }

        while (current->right_child != nullptr)     // Go all the way down to the right
        {
            current = current->right_child;
        }

        tail = current;
        return;
    }

    switch (level)
    {
    case 0:
        if (current->parent->right_child == current)
        {
            tail = current->parent->left_child;
            delete current;
            return;
        }
        else
        {
            node* temp = current->parent;
            delete current;
            pop_back(temp, level+1);
            return;
        }                

    default:        // FIXME
        
        if (current->parent->right_child == current)    // Go until right child is found OR root is found
        {
            current = current->parent->left_child;

            while (current->right_child != nullptr)     // Go all the way down to the right
            {
                current = current->right_child;
            }

            tail = current;

            return;
        }

        else { pop_back(current->parent, level+1); return; }    // Go up until right child is found
    }
}

*/

void heap_BT::delete_node(node* node)       // assumes node is at bottom
{
    if (node == root)
    {
        root = nullptr;
        tail = nullptr;
        delete node;
        return;
    }

    if (node->parent->right_child == node)
    {                                       // Node is a right child
        node->parent->right_child = nullptr;
        delete node;
    }
    else
    {
        node->parent->left_child = nullptr;
        delete node;
    }
    
}

node* heap_BT::find_right_most(node* current)
{
    while (current->right_child != nullptr)
    {
        current = current->right_child;
    }
    return current;
}

node* heap_BT::find_left_most(node* current)
{
    while (current->left_child != nullptr)
    {
        current = current->left_child;
    }
    return current;
}

void heap_BT::pop_back(node* current, int level)
{
    if (current == root)                    // Root node special case
    {
        if (level == 0)
        {
            delete_node(current);
            return;
        }
        else                                // At left most node
        {   
            tail = find_right_most(current);
            return;
        }
    }

    if (level == 0)
    {
        if (current == current->parent->right_child)        // curr is right
        {
            tail = current->parent->left_child;
            delete_node(current);
            return;
        }
        else                                                // curr is left
        {
            node* temp = current->parent;
            delete_node(current);
            pop_back(temp, level+1);                        // Move one level up
            return;
        }
    }

    else 
    {
        if (current == current->parent->right_child)        // curr is right
        {
            tail = find_right_most(current->parent->left_child);    // find most right in left subtree
            return;
        }
        else
        {
            pop_back(current->parent, level+1);
            return;
        }
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

    if (current == nullptr) { return;}

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

int heap_BT::delMax()
{
    int temp = root->priority;
    swap(root, tail);

    pop_back();
    sink(root);

    return temp;
}

int heap_BT::computeHeight(node* current, int level)
{
    if (current->left_child == nullptr)
    {
        return level;
    }

    else { return computeHeight(current->left_child, level+1); }
}