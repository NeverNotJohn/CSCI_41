#include "func.h"

using namespace std;

/*

 _______  ______    ___   _______  ______    ___   _______  __   __    _______  __   __  _______  __   __  _______    _     _  ___   _______  __   __    __   __  _______  _______  _______ 
|       ||    _ |  |   | |       ||    _ |  |   | |       ||  | |  |  |       ||  | |  ||       ||  | |  ||       |  | | _ | ||   | |       ||  | |  |  |  | |  ||       ||   _   ||       |
|    _  ||   | ||  |   | |   _   ||   | ||  |   | |_     _||  |_|  |  |   _   ||  | |  ||    ___||  | |  ||    ___|  | || || ||   | |_     _||  |_|  |  |  |_|  ||    ___||  |_|  ||    _  |
|   |_| ||   |_||_ |   | |  | |  ||   |_||_ |   |   |   |  |       |  |  | |  ||  |_|  ||   |___ |  |_|  ||   |___   |       ||   |   |   |  |       |  |       ||   |___ |       ||   |_| |
|    ___||    __  ||   | |  |_|  ||    __  ||   |   |   |  |_     _|  |  |_|  ||       ||    ___||       ||    ___|  |       ||   |   |   |  |       |  |       ||    ___||       ||    ___|
|   |    |   |  | ||   | |       ||   |  | ||   |   |   |    |   |    |      | |       ||   |___ |       ||   |___   |   _   ||   |   |   |  |   _   |  |   _   ||   |___ |   _   ||   |    
|___|    |___|  |_||___| |_______||___|  |_||___|   |___|    |___|    |____||_||_______||_______||_______||_______|  |__| |__||___|   |___|  |__| |__|  |__| |__||_______||__| |__||___|    

*/

// Misc Functions

bool priorityQueueHeap::is_valid(int parent_index)
{
    bool valid = true;
    int left_index = leftChild_index(parent_index);
    int right_index = rightChild_index(parent_index);

    if (left_index >= myVector.size() || right_index >= myVector.size() )
    {
        return true;
    }

    else if (myVector[parent_index].priority > myVector[left_index].priority || myVector[parent_index].priority > myVector[right_index].priority)
    {
        cout << "Parent: " << myVector[parent_index].priority << endl;
        cout << "Left: " << myVector[left_index].priority << endl;
        cout << "Right: " << myVector[right_index].priority << endl;
        return false;
    }

    if (left_index < myVector.size() - 1) { return is_valid(left_index); }
    else { return is_valid(right_index); }

}

// Functions

void priorityQueueHeap::swim(int i)
{
    int current_prio = (myVector[i]).priority;
    int parent_prio = (myVector[parent_index(i)]).priority;

    while (i > 0 && parent_prio > current_prio) {
        swap(parent_index(i), i, myVector);
        i = parent_index(i);

        parent_prio = (myVector[parent_index(i)]).priority;

    }
}

void priorityQueueHeap::sink(int i)
{
    while (true) {
        int min = i;

        int L = leftChild_index(i);
        int R = rightChild_index(i);

        if (L < myVector.size() && myVector[L].priority < myVector[min].priority)
        {
            min = L;
        }

        if (R < myVector.size() && myVector[R].priority < myVector[min].priority)
        {
            min = R;
        }

        if (i != min)
        {
            swap(i, min, myVector);
            i = min;
        } else {
            break;
        }

    }
}

void priorityQueueHeap::insert(int data, int priority)
{
    item stuff(data, priority);
    myVector.push_back(stuff);
    swim(myVector.size() - 1);
}

item priorityQueueHeap::delMax()
{
    item temp = myVector[0];
    swap(0, myVector.size()-1, myVector);       // Switch Largest and smallest      

    myVector.pop_back();  
    
    sink(0);                                    // Heapify
    return temp;
}