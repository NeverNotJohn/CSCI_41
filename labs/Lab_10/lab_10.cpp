#include <iostream>
#include <vector>

using namespace std;

struct item {

    // data
    string data;
    int priority_value;

    // constructor and deconstructor

    item(string data_in, int priority_value_in) {
        data = data_in;
        priority_value = priority_value_in;
    }
    ~item() {}
};

class priorityQueue {

    private:

        // Data
        vector<item> heap;

        // Misc Functions

        int parent_index(int i) { return ((i - 1) / 2); }
        int leftChild_index(int i) { return ((2 * i) + 1);}
        int rightChild_index(int i) { return ((2 * i) + 2);}

        void swap(int i_index, int j_index)
        {
            item temp = heap[i_index];
            heap[i_index] = heap[j_index];
            heap[j_index] = temp; 
        }
        void sift_up(int i);
        void sift_down(int i);
        

    public:

        // Lab Functions

        void insert(string data_in, int priority_value);
        item poll();
        item peek();

        // cool extra function

        void print();
};

/*
    MISC FUNCTIONS
*/

void priorityQueue::sift_up(int i) {

    int current_prio = (heap[i]).priority_value;
    int parent_prio = (heap[parent_index(i)]).priority_value;

    while (i > 0 && parent_prio > current_prio) {
        swap(parent_index(i), i);
        i = parent_index(i);
    }
    
}

void priorityQueue::sift_down(int i) {         // FIXME

    while (true) {
        int min = i;

        int L = leftChild_index(i);
        int R = rightChild_index(i);

        if (L < heap.size() && heap[L].priority_value < heap[min].priority_value)
        {
            min = L;
        }

        if (R < heap.size() && heap[R].priority_value < heap[min].priority_value)
        {
            min = R;
        }

        if (i != min)
        {
            swap(i, min);
            i = min;
        } else {
            break;
        }

    }



}

void priorityQueue::print() {
    for (int i = 0; i < heap.size(); i++) {
        cout << "i: " << i << endl;
        cout << "data: " << heap[i].data << endl;
        cout << "prio val: " << heap[i].priority_value << endl << endl;
    }
}

/*
    LAB FUNCTIONS
*/

void priorityQueue::insert(string data_in, int priority_value) 
{
    item stuff(data_in, priority_value);
    heap.push_back(stuff);
    sift_up(heap.size() - 1);
}

item priorityQueue::poll() 
{
    if (heap.empty()) {
        cout << "HEAP EMPTY T-T" << endl;
        item temp("It's empty 0.0", -1);
        return temp;
    }

    item temp = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    sift_down(0);
    return temp;
}

item priorityQueue::peek()
{
    if (heap.empty()) {
        cout << "HEAP EMPTY T-T" << endl;
        item temp("It's empty 0.0", -1);
        return temp;
    }

    return heap[0];
}

int main() {

    priorityQueue myList;

    myList.insert("2", 4);
    myList.insert("2", 1);
    myList.insert("2",1);
    myList.insert("2",7);
    myList.insert("2",6);
    myList.insert("2",8);

    myList.print();

}