#include "lib/func.h"

using namespace std;

int main() {

    /*
    ///////////////////////////
    //      QUICKSORT       //
    /////////////////////////
    */

   
    // Creating BIG vector

    srand(time(NULL));

    vector<int> bigBoy = {};

    for (int i = 0; i < 100000; i++) {
        int num = rand() % 100000;
        bigBoy.push_back(num);
    }

    cout << "Vector size: " << bigBoy.size() << endl;
    cout << "quickSort Start!!!" << endl;

    double total_time = 0;

    for (int i = 0; i < 5; i++) {       // take average time of 5 quick sort trial
        
        vector<int> temp = bigBoy;

        unsigned long long int start = clock();
        quickSort(temp, 0, temp.size() - 1);
        unsigned long long int end = clock();

        double tome = (end - start) / (double)CLOCKS_PER_SEC;
        total_time += tome;
    }

    total_time = total_time / 5;

    cout << "Average quickSort execution time: " << total_time << " seconds" << endl;

    // One final sort to print
    vector<int> temp = bigBoy;
    quickSort(temp, 0, temp.size() - 1);
    print(temp);

    cout << endl << endl << endl;

    
    /////////////////////////////////////////////////////////
    //      Priority Queue w/ Vector w/ O(N^2) sorting     //
    /////////////////////////////////////////////////////////
    

    cout << "Priority Queue w/ Vector - O(N^2)" << endl;

    priorityQueueSortedVector PQvector1;

    for (int i = 0; i < 5; i++) {
        PQvector1.myVector = {};
        vector<item> unsorted_vector;

        // Create unsorted vector
        for (int i = 0; i < 100000; i++)
        {
            int data = rand() % 100000;
            int prio = rand() % 100000;
            item temp(data, prio);
            unsorted_vector.push_back(temp);
        }

        unsigned long long int start = clock();

        for (int i = 0; i < unsorted_vector.size(); i++) {                              // INSERT N ITEMS O(N)
            PQvector1.insert(unsorted_vector[i].data, unsorted_vector[i].priority);     // Linear insert O(N)
        }

        // Total time complexity = O(N * N) = O(N^2)

        unsigned long long int end = clock();

        double tome = (end - start) / (double)CLOCKS_PER_SEC;
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

    for (int i = 0; i < 5; i++) {
        PQVector2.myVector = {};
        vector<item> unsorted_vector;

        // Create unsorted vector
        for (int i = 0; i < 100000; i++)
        {
            int data = rand() % 100000;
            int prio = rand() % 100000;
            item temp(data, prio);
            unsorted_vector.push_back(temp);
        }

        unsigned long long int start = clock();

        for (int i = 0; i < unsorted_vector.size(); i++) {      // INSERT N ITEMS O(N)
            PQVector2.insert_but_better(unsorted_vector[i].data, unsorted_vector[i].priority);     // Binary Search insert O(logN)
        }

        // Total time complexity = O(N * logN) = O(NlogN)

        unsigned long long int end = clock();

        double tome = (end - start) / (double)CLOCKS_PER_SEC;
    }

    cout << "Average Priority Queue O(NlogN) sort execution time: " << total_time/5 << " seconds" << endl;
    print(PQVector2.myVector);
    cout << endl << endl << endl;


    /////////////////////////////////////
    //      Priority Queue w/ Heap     //
    /////////////////////////////////////

    priorityQueueHeap PQvector3;

    PQvector3.myVector = {};
    vector<item> unsorted_vector;

    // Create unsorted vector
    for (int i = 0; i < 100000; i++)
    {
        int num = rand() % 100000;
        item temp(i, num);
        unsorted_vector.push_back(temp);
    }


    for (int i = 0; i < unsorted_vector.size(); i++) {      // INSERT N ITEMS O(N)
            PQvector3.insert(unsorted_vector[i].data, unsorted_vector[i].priority);     // Binary Search insert O(logN)
    }

    print(PQvector3.myVector);
    if (PQvector3.is_valid()) { cout << "Heap is valid";}
    else {cout << "Heap isn't valid";}

    cout << endl;

    

    system("pause");
}