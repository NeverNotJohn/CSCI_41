#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


using namespace std;

struct BSTNode {

    // DATA

    int data;

    BSTNode* left_child;
    BSTNode* right_child;
    BSTNode* parent;

    // Constructors & Deconstructor

    BSTNode() {
        data = 99999;                           // no null value for int
        left_child = nullptr;
        right_child = nullptr;
        parent = nullptr;
    }

    BSTNode(int data_in) {
        data = data_in;
        left_child = nullptr;
        right_child = nullptr;
        parent = nullptr;
    }

    ~BSTNode() {}

    // Functions

    bool leaf() {
        if (left_child == nullptr && right_child == nullptr) { return true;}
        else { return false;}
    }

    int child_num() {
        int num = 0;

        if (left_child != nullptr) { num++; }
        if (right_child != nullptr) { num++; }

        return num;
    }

};

struct BST {

    static BSTNode *root_node;

    // Constructor/Deconstructor

    BST() {}
    ~BST() {}

    // misc functions
    void insert(int data);
    void display(BSTNode *root = root_node, int level = 0);
    BSTNode* find_min_right(BSTNode *current);
    void remove(BSTNode *current);
    void remove2(BSTNode* &current);
    // BSTNode* parent(BSTNode* child, BSTNode* parent = root_node);

    // Assignment Functions

    BSTNode* Delete1(int data, BSTNode *root = root_node);
    void Delete2(BSTNode** root, int data);
    void Delete3(BSTNode* &root, int data);
};

// MISC FUNCTIONS

BSTNode* BST::root_node = nullptr;                          // idk why this work for default param but it does

void BST::insert(int data) {

    if (root_node == nullptr) {root_node = new BSTNode(data); return;}

    BSTNode* current = root_node;

    while (true) {
        BSTNode* L = current->left_child;
        BSTNode* R = current->right_child;

        if (L == nullptr && data <= current->data)          // insert to left child
        {
            current->left_child = new BSTNode(data);
            current->left_child->parent = current;
            break;
        } else if (R == nullptr && data > current->data)   // insert to right child
        {
            current->right_child = new BSTNode(data);
            current->right_child->parent = current;
            break;
        } else if (data <= current->data)                  // Left side
        {
            current = L;
        } else if (data > current->data)                   // right side
        {
            current = R;
        }
    }
    
}

void BST::display(BSTNode* root, int level) {               // outputs horizontal tree... 

    /* Format:

    |--5
       |--3         (Left Child of 5)
       |   |--2                         (Left Child of 3)
       |   |--4                         (Right Child of 3)
       |--8         (Right Child of 5)
       |   |--6
       |   |--9

    */

    if (level == 0) {cout << "|--" << root->data << endl;}
    else
    {
        cout << "   ";
        for (int i = 1; i < level; i++)
        {
            cout << "|   ";
        }
        cout << "|--" << root->data << endl;
    }
    BSTNode* L = root->left_child;
    BSTNode* R = root->right_child;

    if (L == nullptr && R == nullptr) {return;}
    if (L != nullptr) {display(L, (level+1));}
    if (R != nullptr) {display(R, (level+1));}
}
BSTNode* BST::find_min_right(BSTNode* current) {
    BSTNode* L = current->left_child;

    if (L == nullptr)
    {
        return current;
    }
    else
    {
        return find_min_right(L);
    }

}

void BST::remove(BSTNode* current) {
    // IS ROOT

    // NON ROOT

    int num_child = current->child_num();

    switch (num_child)
    {
    case 0:
        
        if (current->data <= current->parent->data)  // Left
        {
            current->parent->left_child = nullptr;
        }
        else 
        {
            current->parent->right_child = nullptr;
        }

        delete current;

        break;
    case 1:
        
        if (current->data < current->parent->data)  // Left
        {
            if (current->left_child == nullptr) { current->parent-> left_child = current->right_child;}
            else { current->parent->left_child = current->left_child;}

            current->left_child->parent = current->parent;

        }
        else 
        {
            if (current->left_child == nullptr) { current->parent->right_child = current->right_child;}
            else { current->parent->right_child = current->left_child;}

            current->right_child->parent = current->parent;
        }

        delete current;

        break;
    case 2:
        
        BSTNode* min = find_min_right(current->right_child);

        int temp = current->data;
        current->data = min->data;
        
        if (min->parent == current)
        {
            min->data = current->data + 1;
        }

        remove(min);
        break;
    }
}

void display(BSTNode* root, int level=0) {               // outputs horizontal tree... 

    /* Format:

    |--5
       |--3         (Left Child of 5)
       |   |--2                         (Left Child of 3)
       |   |--4                         (Right Child of 3)
       |--8         (Right Child of 5)
       |   |--6
       |   |--9

    */

    if (level == 0) {cout << "|--" << root->data << endl;}
    else
    {
        cout << "   ";
        for (int i = 1; i < level; i++)
        {
            cout << "|   ";
        }
        cout << "|--" << root->data << endl;
    }
    BSTNode* L = root->left_child;
    BSTNode* R = root->right_child;

    if (L == nullptr && R == nullptr) {return;}
    if (L != nullptr) {display(L, (level+1));}
    if (R != nullptr) {display(R, (level+1));}
}

// ASSIGNMENT FUNCTIONS

BSTNode* BST::Delete1(int data, BSTNode *root) {

    if (data == root_node->data)           // change root
    {
        int child_num = root->child_num();

        switch (child_num)
        {
        case 0:
            root_node = nullptr;
            break;
        
        case 1:
            if (root->left_child == nullptr) { root_node = root->right_child; }
            else {root_node = root->left_child; }
        default:
            break;
        }
    }

    if (root == nullptr)
    {
        cout << "Item not in BST!!!" << endl;
        return nullptr;
    }

    if (data == root->data) 
    {
        BSTNode* temp = root;
        remove(root);
        return temp;
    }

    else if (data < root->data)
    {
        return Delete1(data, root->left_child);
    }

    else
    {
        return Delete1(data, root->right_child);
    }
    
}

void BST::Delete3(BSTNode* &root, int data) {


    if (data == root_node->data)           // change root
    {
        int child_num = root->child_num();

        switch (child_num)
        {
        case 0:
            root_node = nullptr;
            break;
        
        case 1:
            if (root->left_child == nullptr) { root_node = root->right_child; }
            else {root_node = root->left_child; }
        default:
            break;
        }
    }

    if (root == nullptr)
    {
        cout << "Item not in BST!!!" << endl;
    }

    if (data == root->data) 
    {
        remove(root);
    }

    else if (data < root->data)
    {
        Delete3(root->left_child, data);
    }

    else
    {
       Delete3(root->right_child, data);
    }
    

};

void BST::Delete2(BSTNode** root, int data) {
    
    BSTNode* rot = *root;

    if (data == root_node->data)           // change rot
    {
        int child_num = root_node->child_num();

        switch (child_num)
        {
        case 0:
            root_node = nullptr;
            break;
        
        case 1:
            if (root_node->left_child == nullptr) { root_node = rot->right_child; }
            else {root_node = rot->left_child; }
        default:
            break;
        }
    }

    if (rot == nullptr)
    {
        cout << "Item not in BST!!!" << endl;
    }

    if (data == rot->data) 
    {
        remove(rot);
    }

    else if (data < rot->data)
    {
        Delete2(&(rot->left_child), data);
    }

    else
    {
        Delete2(&(rot->right_child), data);
    }
    
}

int main() {
    BST* t = new BST();

    t->insert(5);
    t->insert(3);
    t->insert(8);
    t->insert(2);
    t->insert(4);
    t->insert(6);
    t->insert(9);
    t->insert(10);
    t->insert(15);
    t->insert(-52);

    cout << "Original Binary Search Tree: " << endl;
    t->display();

    cout  << endl << endl;

    cout << "Delete1(5): " << endl;
    t->Delete1(5);
    t->display();

    cout << endl << endl;

    BSTNode** root = &(t->root_node);

    cout << "Delete2(3): " << endl;
    t->Delete2(root, 3);

    t->display();

    cout << endl;

    cout << "Delete3(-52): " << endl;
    t->Delete3(t->root_node, -52);

    t->display();

}