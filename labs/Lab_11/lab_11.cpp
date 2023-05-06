#include <iostream>
#include <vector>

using namespace std;

struct BSTNode {

    // DATA

    int data;

    BSTNode* left_child;
    BSTNode* right_child;

    // Constructors & Deconstructor

    BSTNode() {
        data = 99999;                           // no null value for int
        left_child = nullptr;
        right_child = nullptr;
    }

    BSTNode(int data_in) {
        data = data_in;
        left_child = nullptr;
        right_child = nullptr;
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

// Misc Functions

void insert(BSTNode* parent, BSTNode* child) {

    if (child->data <= parent->data)                 // left node
    {
        parent->left_child = child;
    } else if (child->data > parent->data)          // right node
    {
        parent->right_child = child;
    }
    
}

BSTNode* getNode(BSTNode* root, int data) {
    BSTNode* L = root->left_child;
    BSTNode* R = root->right_child;

    if (root->data == data) {return root; }

    if (L == nullptr && R == nullptr) {return nullptr; }

    if ((L != nullptr && L->data == data)) { return L;}
    else if ((R != nullptr && R->data == data)) { return R;}

    else if (L != nullptr && data <= root->data)          // Left side
    {
        return getNode(L, data);
    } else if (R != nullptr && data > root->data)   // Right Side
    {
        return getNode(R, data);
    } else { return nullptr; }
}

// Assignment Functions

BSTNode* parent(BSTNode* parent, BSTNode* child) {

    int child_data = child->data;

    while (true) {

        BSTNode* L = parent->left_child;
        BSTNode* R = parent->right_child;

        if (child == nullptr)
        {
            cout << "Item not in list!" << endl;
            return nullptr;
        } else if (L != nullptr)
        {
            if (L == child)                         // node found
            {
                return parent;
            } else if (child->data <= L->data)
            {
                parent = L;
            }
        } else if (R != nullptr)
        {
            if (R == child)
            {
                return parent;
            } else if (child->data > R->data)
            {
                parent = R;
            }
            
        }
        
        
    }
}

void InsertNodeREC(BSTNode* root, int data) {
    BSTNode* L = root->left_child;
    BSTNode* R = root->right_child;

    if (L == nullptr && data <= root->data)          // insert to left child
    {
        root->left_child = new BSTNode(data);
    } else if (R == nullptr && data > root->data)   // insert to right child
    {
        root->right_child = new BSTNode(data);
    } else if (data <= root->data)                  // Left side
    {
        InsertNodeREC(L, data);
    } else if (data > root->data)                   // right side
    {
        InsertNodeREC(R, data);
    }
        
}

void InsertNodeITE(BSTNode* root, int data) {

    while (true) {
        BSTNode* L = root->left_child;
        BSTNode* R = root->right_child;

        if (L == nullptr && data <= root->data)          // insert to left child
        {
            root->left_child = new BSTNode(data);
            break;
        } else if (R == nullptr && data > root->data)   // insert to right child
        {
            root->right_child = new BSTNode(data);
            break;
        } else if (data <= root->data)                  // Left side
        {
            root = L;
        } else if (data > root->data)                   // right side
        {
            root = R;
        }
    }
}

bool SearchNodeREC(BSTNode* root, int data) {
    BSTNode* L = root->left_child;
    BSTNode* R = root->right_child;

    if ( (L != nullptr && L->data == data) || (R != nullptr && R->data == data)) { return true; }

    else if (L != nullptr && data <= root->data)          // Left side
    {
        return SearchNodeREC(L, data);
    } else if (R != nullptr && data > root->data)   // Right Side
    {
        return SearchNodeREC(R, data);
    } else { return false; }

}

bool SearchNodeITE(BSTNode* root, int data) {

    while (true) {
        BSTNode* L = root->left_child;
        BSTNode* R = root->right_child;

        if ( (L != nullptr && L->data == data) || (R != nullptr && R->data == data)) { return true; }

        else if (L != nullptr && data <= root->data)          // Left side
        {
            root = L;
        } else if (R != nullptr && data > root->data)   // Right Side
        {
            root = R;
        } else { return false; }

        }
}

int main() {
    BSTNode* root = new BSTNode(5);

    InsertNodeREC(root, 4);
    InsertNodeREC(root, -100);
    InsertNodeREC(root, 6);
    InsertNodeREC(root, 8);
    InsertNodeREC(root, 10);

    cout << "Is 10 a leaf? (Should be 1 for yes): " << (getNode(root, 10))->leaf() << endl;
    cout << "How many children does 10 have? (should be 0): " << (getNode(root, 10))->child_num() << endl;
    cout << "How many children does 5 have? (should be 2): " << (getNode(root, 5))->child_num() << endl;

    cout << endl;

    cout << "Parent of -100: " << (parent(root, getNode(root, -100)))->data << endl;

    // should be -100
    cout << "Smallest Number in Tree (InsertNodeREC): " <<root->left_child->left_child->data << endl;

    InsertNodeITE(root, 9999);
    InsertNodeITE(root, 7);
    
    cout << endl;

    // should be 7
    cout << "Some random number in the Tree (InsertNodeITE): " << root->right_child->right_child->left_child->data << endl;

    // SearchNodeREC
    cout << "(SearchNodeREC) Should be 1: " << SearchNodeREC(root, 6) << endl;
    cout << "(SearchNodeREC) Should be 0: " << SearchNodeREC(root, 69) << endl;

    cout << endl;

    // SearchNodeITE
    cout << "(SearchNodeITE) Should be 1: " << SearchNodeITE(root, 6) << endl;
    cout << "(SearchNodeITE) Should be 0: " << SearchNodeITE(root, 69) << endl;
   
    
}