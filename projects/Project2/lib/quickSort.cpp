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

void quickSort(vector<int> &vicky, int low, int high) {     // O(NlogN) average

    if (low < high) 
    {
        int pivot_location = partition(low, high, vicky);
        quickSort(vicky, low, pivot_location-1);
        quickSort(vicky, pivot_location+1, high);
    }

}