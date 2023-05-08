#include "lib/func.h"

using namespace std;

int main() {

    /*
    ///////////////////////////
    //      QUICKSORT       //
    /////////////////////////
    */

    int size = 1000000;

    // Creating BIG vector

    srand(time(NULL));

    vector<int> bigBoy = {};

    for (int i = 0; i < size; i++) {
        int num = rand() % size;
        bigBoy.push_back(num);
    }

    cout << "Vector size: " << size << endl << endl;

    double total_time = 0;

    for (int i = 0; i < 5; i++) {       // take average time of 5 quick sort trial
        
        vector<int> temp = bigBoy;

        unsigned long long int start = clock();
        quickSort(temp, 0, temp.size() - 1);
        unsigned long long int end = clock();

        double tome = (end - start) / (double)CLOCKS_PER_SEC;

        cout << i << ": " << tome << " seconds" << endl;

        total_time += tome;
    }

    total_time = total_time / 5;

    cout << "Average quickSort execution time: " << total_time << " seconds" << endl;

    // One final sort to print
    vector<int> temp = bigBoy;
    quickSort(temp, 0, temp.size() - 1);
    print(temp);

    cout << endl << endl << endl;

    
    // Create unsorted vector

    vector<item> unsorted_vector = {};

    for (int i = 0; i < size; i++)
    {
        int num = rand() % size;
        item temp(i, bigBoy[i]);
        unsorted_vector.push_back(temp);
    }

    /////////////////////////////////////////////////////////
    //      Priority Queue w/ Vector w/ O(N^2) sorting     //
    /////////////////////////////////////////////////////////
    

    cout << "Priority Queue w/ Vector - O(N^2)" << endl;

    total_time = 0;
    priorityQueueSortedVector PQvector1;

    for (int i = 0; i < 5; i++) {
        PQvector1.myVector = {};

        unsigned long long int start = clock();

        for (int j = 0; j < unsorted_vector.size(); j++) {                              // INSERT N ITEMS O(N)
            PQvector1.insert(unsorted_vector[j].data, unsorted_vector[j].priority);     // Linear insert O(N)
        }

        // Total time complexity = O(N * N) = O(N^2)

        unsigned long long int end = clock();

        double tome = (end - start) / (double)CLOCKS_PER_SEC;

        cout << i << ": " << tome << " seconds" << endl;
        total_time += tome;
    }

    total_time = total_time / 5;

    cout << "Average Priority Queue O(n^2) sort execution time: " << total_time << " seconds" << endl;
    print(PQvector1.myVector);
    cout << endl << endl << endl;


    
    ////////////////////////////////////////////////////////////
    //      Priority Queue w/ Vector w/  O(NlogN) sorting     //
    ///////////////////////////////////////////////////////////
    
    cout << "Priority Queue w/ Vector - O(NlogN)" << endl;

    priorityQueueSortedVector PQVector2;
    total_time = 0;

    for (int i = 0; i < 5; i++) {
        PQVector2.myVector = {};

        unsigned long long int start = clock();

        for (int i = 0; i < unsorted_vector.size(); i++) {      // INSERT N ITEMS O(N)
            PQVector2.insert_but_better(unsorted_vector[i].data, unsorted_vector[i].priority);     // Binary Search insert O(logN)
        }

        // Total time complexity = O(N * logN) = O(NlogN)

        unsigned long long int end = clock();

        double tome = (end - start) / (double)CLOCKS_PER_SEC;

        cout << i << ": " << tome << " seconds" << endl;

        total_time += tome;
    }

    cout << "Average Priority Queue O(NlogN) sort execution time: " << total_time/5 << " seconds" << endl;
    print(PQVector2.myVector);
    cout << endl << endl << endl;


    /////////////////////////////////////
    //      Priority Queue w/ Heap     //
    /////////////////////////////////////

    priorityQueueHeap PQvector3;

    PQvector3.myVector = {};
    vector<int> output = {};

    total_time = 0;

    for (int i = 0; i < 5; i++) {

        PQvector3.myVector = {};
        output = {};

        unsigned long long int start = clock();

        for (int j = 0; j < unsorted_vector.size(); j++)        // Insert AND heapify
        {          
            PQvector3.insert(unsorted_vector[j].data, unsorted_vector[j].priority); 
        }
        
        for (int j = 0; j < PQvector3.myVector.size(); j++)                           // Heap Sort
        {
            output.push_back((PQvector3.delMax()).priority);
        }

        unsigned long long int end = clock();
        double tome = (end - start) / (double)CLOCKS_PER_SEC;

        cout << i << ": " << tome << " seconds" << endl;

        total_time += tome;
    }

    cout << "Average Heap sort execution time: " << total_time/5 << " seconds" << endl;
    print(output);

    cout << endl << endl << endl;

    /////////////////////////////////////////////////
    //      Priority Queue w/ Binary Tree Heap     //
    ////////////////////////////////////////////////

    total_time = 0;

    for (int i = 0; i < 5; i++)
    {
        heap_BT heapy;
        output = {};

        unsigned long long int start = clock();

        for (int j = 0; j < unsorted_vector.size(); j++)
        {
            heapy.insert(unsorted_vector[j].data, unsorted_vector[j].priority);
        }

        for (int j = 0; j < unsorted_vector.size(); j++)
        {
            output.push_back(heapy.delMax());
        }

        unsigned long long int end = clock();
        double tome = (end - start) / (double)CLOCKS_PER_SEC;

        cout << i << ": " << tome << " seconds" << endl;

        total_time += tome;

    }

    cout << "Average Heap Binary Tree execution time: " << total_time/5 << " seconds" << endl;
    print(output);

    // OTHER FUNCTIONS
    
    heap_BT heapy;
    for (int j = 0; j < unsorted_vector.size(); j++)
    {
        heapy.insert(unsorted_vector[j].data, unsorted_vector[j].priority);
    }

    cout << endl;
    
    cout << "Num of Leaves: " << heapy.computeLeaves() << endl << endl;
    cout << "Lookup(-1): ";

    if (heapy.lookup(-1)) { cout << "Num is in array";}
    else { cout << "Num is not in array";}

    cout << endl;

    cout << "Lookup(unsorted_vector[99].priority): ";
    if (heapy.lookup(unsorted_vector[99].priority)) { cout << "Num is in array";}
    else { cout << "Num is not in array";}

    cout << endl << endl;

    cout << "samelevel(root->left_child->right_child->left_child->left_child) - 4 Levels = 16 nodes: " << endl;
    vector<node*> stuff = heapy.sameLevel(heapy.root->left_child->right_child->left_child->left_child);

    cout << "Priority values: ";
    for (int i = 0; i < stuff.size(); i++)
    {
        cout << stuff[i]->priority << " ";
    }
    cout << endl << endl;

    cout << "descendant(root->left_child, tail):" << endl;
    if (heapy.descendant(heapy.root->left_child, heapy.tail)) { cout << "aNode is a descedant";}
    else {cout << "aNode isn't a descendant";}
    cout << endl;

    cout << "descendant(root->right_child, tail):" << endl;
    if (heapy.descendant(heapy.root->right_child, heapy.tail)) { cout << "aNode is a descedant";}
    else {cout << "aNode isn't a descendant";}
    cout << endl;



    cout << endl << endl << endl;
    system("pause");
}