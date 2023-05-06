#include "func.h"

using namespace std;

/*

  ___   __ __  ____     __  __  _       _____  ___   ____   ______ 
 /   \ |  |  ||    |   /  ]|  |/ ]     / ___/ /   \ |    \ |      |
|     ||  |  | |  |   /  / |  ' /     (   \_ |     ||  D  )|      |
|  Q  ||  |  | |  |  /  /  |    \      \__  ||  O  ||    / |_|  |_|
|     ||  :  | |  | /   \_ |     \     /  \ ||     ||    \   |  |  
|     ||     | |  | \     ||  .  |     \    ||     ||  .  \  |  |  
 \__,_| \__,_||____| \____||__|\_|      \___| \___/ |__|\_|  |__|  
                                                                   
*/

int partition(vector<int> &vocter, int low, int high){

    int pivot = vocter[low];

    int num = 0;

    for (int i = low + 1; i <= high; i++)
    {
        if (vocter[i] <= pivot) {num++;}
    }

    int p_index = low + num;
    swap(p_index, low, vocter);

    int i = low;
    int j = high;

    while (i < p_index && j > p_index)
    {
        while (vocter[i] <= pivot) { i++; }
        while (vocter[j] > pivot) {j--;}
        if (i < p_index && j > p_index) { swap(i++, j--, vocter);}
    }
    

    return p_index;
}

void quickSort(vector<int> &vicky, int low, int high) {     // O(NlogN) average

    if (low < high) 
    {
        int pivot_location = partition(vicky, low, high);
        quickSort(vicky, low, pivot_location-1);
        quickSort(vicky, pivot_location+1, high);
    }

}