#include "lib/func.h"

using namespace std;

/*

      ___                       ___           ___                    ___           ___           ___           ___                                     ___           ___           ___     
     /\  \                     /\__\         /\__\                  /\__\         /\  \         /\  \         /\__\                                   /\  \         /\  \         /\__\    
    |::\  \       ___         /:/ _/_       /:/  /                 /:/ _/_        \:\  \        \:\  \       /:/  /          ___         ___         /::\  \        \:\  \       /:/ _/_   
    |:|:\  \     /\__\       /:/ /\  \     /:/  /                 /:/ /\__\        \:\  \        \:\  \     /:/  /          /\__\       /\__\       /:/\:\  \        \:\  \     /:/ /\  \  
  __|:|\:\  \   /:/__/      /:/ /::\  \   /:/  /  ___            /:/ /:/  /    ___  \:\  \   _____\:\  \   /:/  /  ___     /:/  /      /:/__/      /:/  \:\  \   _____\:\  \   /:/ /::\  \ 
 /::::|_\:\__\ /::\  \     /:/_/:/\:\__\ /:/__/  /\__\          /:/_/:/  /    /\  \  \:\__\ /::::::::\__\ /:/__/  /\__\   /:/__/      /::\  \     /:/__/ \:\__\ /::::::::\__\ /:/_/:/\:\__\
 \:\~~\  \/__/ \/\:\  \__  \:\/:/ /:/  / \:\  \ /:/  /          \:\/:/  /     \:\  \ /:/  / \:\~~\~~\/__/ \:\  \ /:/  /  /::\  \      \/\:\  \__  \:\  \ /:/  / \:\~~\~~\/__/ \:\/:/ /:/  /
  \:\  \        ~~\:\/\__\  \::/ /:/  /   \:\  /:/  /            \::/__/       \:\  /:/  /   \:\  \        \:\  /:/  /  /:/\:\  \      ~~\:\/\__\  \:\  /:/  /   \:\  \        \::/ /:/  / 
   \:\  \          \::/  /   \/_/:/  /     \:\/:/  /              \:\  \        \:\/:/  /     \:\  \        \:\/:/  /   \/__\:\  \        \::/  /   \:\/:/  /     \:\  \        \/_/:/  /  
    \:\__\         /:/  /      /:/  /       \::/  /                \:\__\        \::/  /       \:\__\        \::/  /         \:\__\       /:/  /     \::/  /       \:\__\         /:/  /   
     \/__/         \/__/       \/__/         \/__/                  \/__/         \/__/         \/__/         \/__/           \/__/       \/__/       \/__/         \/__/         \/__/    

*/

struct item {
    
    // Data

    int data;
    int priority;

    item(int data_in, int priority_in) {
        data = data_in;
        priority = priority_in;
    }

    ~item() {}
};

void print(vector<int> lector) {
    cout << left;
    for (int i = 0; i < 100; i++)
    {
        cout << setw(4) << lector[i];
        int j = i + 1;
        if (j % 10 == 0) { cout << endl;}
    }
}

void print(vector<item> lector) {
    cout << left;
    for (int i = 0; i < 100; i++)
    {
        cout << setw(4) << lector[i].priority;
        int j = i + 1;
        if (j % 10 == 0) { cout << endl;}
    }
}

void swap(int i, int j, vector<int> &mocter) {
    int temp = mocter[i];
    mocter[i] = mocter[j];
    mocter[j] = temp;
}

void swap(int i, int j, vector<item> &mocter) {
    item temp = mocter[i];
    mocter[i] = mocter[j];
    mocter[j] = temp;
}

/*


   _______    _______    __      ______     _______    __  ___________  ___  ___         ______    ____  ____   _______  ____  ____   _______      __   __  ___       ___         ______     _______   ________    _______   _______    _______  ________       ___      ___  _______   ______  ___________  ______     _______   
  |   __ "\  /"      \  |" \    /    " \   /"      \  |" \("     _   ")|"  \/"  |       /    " \  ("  _||_ " | /"     "|("  _||_ " | /"     "|    |"  |/  \|  "|     /"  |       /    " \   /"      \ |"      "\  /"     "| /"      \  /"     "||"      "\     |"  \    /"  |/"     "| /" _  "\("     _   ")/    " \   /"      \  
  (. |__) :)|:        | ||  |  // ____  \ |:        | ||  |)__/  \\__/  \   \  /       // ____  \ |   (  ) : |(: ______)|   (  ) : |(: ______)    |'  /    \:  |    /  //       // ____  \ |:        |(.  ___  :)(: ______)|:        |(: ______)(.  ___  :)     \   \  //  /(: ______)(: ( \___))__/  \\__/// ____  \ |:        | 
  |:  ____/ |_____/   ) |:  | /  /    ) :)|_____/   ) |:  |   \\_ /      \\  \/       /  /    )  )(:  |  | . ) \/    |  (:  |  | . ) \/    |      |: /'        |   /'  /       /  /    ) :)|_____/   )|: \   ) || \/    |  |_____/   ) \/    |  |: \   ) ||      \\  \/. ./  \/    |   \/ \        \\_ /  /  /    ) :)|_____/   ) 
  (|  /      //      /  |.  |(: (____/ //  //      /  |.  |   |.  |      /   /       (: (____/ //  \\ \__/ //  // ___)_  \\ \__/ //  // ___)_      \//  /\'    |  //  /       (: (____/ //  //      / (| (___\ || // ___)_  //      /  // ___)_ (| (___\ ||       \.    //   // ___)_  //  \ _     |.  | (: (____/ //  //      /  
 /|__/ \    |:  __   \  /\  |\\        /  |:  __   \  /\  |\  \:  |     /   /         \         \  /\\ __ //\ (:      "| /\\ __ //\ (:      "|     /   /  \\   | /  //         \        /  |:  __   \ |:       :)(:      "||:  __   \ (:      "||:       :)        \\   /   (:      "|(:   _) \    \:  |  \        /  |:  __   \  
(_______)   |__|  \___)(__\_|_)\"_____/   |__|  \___)(__\_|_)  \__|    |___/           \"____/\__\(__________) \_______)(__________) \_______)    |___/    \___||___/           \"_____/   |__|  \___)(________/  \_______)|__|  \___) \_______)(________/          \__/     \_______) \_______)    \__|   \"_____/   |__|  \___) 
                                                                                                                                                                                                                                                                                                                                  
Priority Queue w/ Ordered Vector
*/

struct priorityQueueSortedVector {         // Priority Queue using sorted vector

    // Data
    vector<item> myVector;

    // Constructors

    priorityQueueSortedVector() {}
    ~priorityQueueSortedVector() {}

    // Functions

    void insert(int data, int priority)     
    {
        int index = 0;
        while (index < myVector.size() && priority > myVector[index].priority ) // Lower priority int first!
        {
            index++;
        }

        // Linear search O(N)

        item temp(data, priority);
        myVector.insert(myVector.begin() + index, temp);      
    }

    void insert_but_better(int data, int priority)      // BINARY SEARCH O(logN)
    {
        int left_index = 0;
        int right_index = myVector.size() - 1;

        while (left_index < right_index) {
            int mid_index = (left_index + right_index) / 2;

            if (myVector[mid_index].priority == priority)
            {
                item temp(data, priority);
                myVector.insert(myVector.begin() + mid_index, temp);
                return;
            }
            else if (myVector[mid_index].priority > priority)
            {
                right_index = mid_index - 1;
            }
            else
            {
                left_index = mid_index + 1;
            }
        }

        // special cases and final handling

        if (myVector.empty()) 
        {
            item temp(data, priority);
            myVector.insert(myVector.begin(), temp);
            return;
        }
        else if (priority < myVector[left_index].priority)
        {
            item temp(data, priority);
            myVector.insert(myVector.begin() + left_index, temp);
            return;
        }
        else 
        {
            item temp(data, priority);
            myVector.insert(myVector.begin() + left_index + 1, temp);
            return;
        }


    }

    void delMax()       // assuming its sorted
    {
        myVector.pop_back();        // Last spot is HIGHEST int num
    }

};

/*

Priority Queue with Heap

*/

struct priorityQueueHeap {         // Priority Queue using sorted vector

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

    void insert(int data, int priority);
    void swim(int i);
    void sink(int i);
    void delMax();

};

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

/*

  ___   __ __  ____     __  __  _       _____  ___   ____   ______ 
 /   \ |  |  ||    |   /  ]|  |/ ]     / ___/ /   \ |    \ |      |
|     ||  |  | |  |   /  / |  ' /     (   \_ |     ||  D  )|      |
|  Q  ||  |  | |  |  /  /  |    \      \__  ||  O  ||    / |_|  |_|
|     ||  :  | |  | /   \_ |     \     /  \ ||     ||    \   |  |  
|     ||     | |  | \     ||  .  |     \    ||     ||  .  \  |  |  
 \__,_| \__,_||____| \____||__|\_|      \___| \___/ |__|\_|  |__|  
                                                                   
*/

int partition(int low, int high, vector<int> &vocter){

    int pivot = vocter[high];
    int leftWall = low;

    for (int i = low; i < high; i++)
    {
        if (vocter[i] <= pivot)
        {
            swap(i, leftWall, vocter);
            leftWall = leftWall + 1;
        }
    }

    swap(high, leftWall, vocter);

    return leftWall;

}

void quickSort(vector<int> &vicky, int low, int high) {

    if (low < high) 
    {
        int pivot_location = partition(low, high, vicky);
        quickSort(vicky, low, pivot_location-1);
        quickSort(vicky, pivot_location+1, high);
    }

}

int main() {

    // Creating BIG vector

    srand(time(NULL));

    vector<int> bigBoy = {};

    for (int i = 0; i < 100000; i++) {
        int num = rand() % 100000;
        bigBoy.push_back(num);
    }

    /*
    ///////////////////////////
    //      QUICKSORT       //
    /////////////////////////
    */

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
    

/*
    cout << "Priority Queue w/ Vector - O(N^2)" << endl;

    priorityQueueSortedVector PQvector1;

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
        }prin

        unsigned long long int start = clock();

        for (int i = 0; i < unsorted_vector.size(); i++) {      // INSERT N ITEMS O(N)
            PQVector2.insert_but_better(unsorted_vector[i].data, unsorted_vector[i].priority);     // Binary Search insert O(logN)
        }

        // Total time complexity = O(N * N) = O(N^2)

        unsigned long long int end = clock();

        double tome = (end - start) / (double)CLOCKS_PER_SEC;
        cout << i << ": " << tome << endl;
        total_time += tome;

    }

    total_time = total_time / 5;

    cout << "Average Priority Queue O(n^2) sort execution time: " << total_time << " seconds" << endl;
    print(PQvector1.myVector);
    cout << endl << endl << endl;

*/
/*
    
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
        cout << i << ": " << tome << endl;
        total_time += tome;

    }

    cout << "Average Priority Queue O(NlogN) sort execution time: " << total_time/5 << " seconds" << endl;
    print(PQVector2.myVector);
    cout << endl << endl << endl;

*/

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

/*

    for (int i = 0; i < 5; i++) {
        PQvector3.myVector = {};
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
            PQvector3.insert(unsorted_vector[i].data, unsorted_vector[i].priority);     // Binary Search insert O(logN)
        }

        // Total time complexity = O(N * logN) = O(NlogN)

        unsigned long long int end = clock();

        double tome = (end - start) / (double)CLOCKS_PER_SEC;
        cout << i << ": " << tome << endl;
        total_time += tome;

    }

    cout << "Average Priority Heap: " << total_time/5 << " seconds" << endl;
    print(PQvector3.myVector);
    cout << endl << endl << endl;

*/

    // Debug

}