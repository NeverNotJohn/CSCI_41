#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void rand_array(int array[], int size) {
    for (int i = 0; i < size; i++) 
    {
        array[i] = rand() % 101;
    }
}

void swap(int array[], int n, int min) {

    int temp = array[n];
    array[n] = array[min];
    array[min] = temp;

}

void print(int array[], int size) {
    cout << "The new array: ";
    for (int i = 0; i<size; i++) 
    {
        cout << array[i] << ", ";
    }
    cout << endl;
}

void selection_sort(int array[], int size) {

    for (int j=0; j<size; j++) {    // outter loop

        int min = array[j];
        int min_i = j;

        for (int point_i=j+1; point_i<size; point_i++)
        {
            int point = array[point_i];

            if (point >= min)           // not min
            {
                continue;
            }

            else if (point < min)       // min found
            {
                min_i = point_i;
                min = array[min_i];
            }
        }
        swap(array, min_i, j);
    }
}

void insertion_sort(int array[], int size) {

    for (int right_i = 1; right_i < size; right_i++)  // outter for loop
    {    
        int left_i = right_i - 1;
        int left = array[left_i];
        int right = array[right_i];

        while (right < left && right_i != 0)
        {  
            swap(array, left_i, right_i);
            right_i = left_i;
            left_i = right_i - 1;

            int left = array[left_i];
            int right = array[right_i];

        }
    }
}

void bubble_sort(int array[], int size) {
    for (int unsorted_size = size; unsorted_size > 1; unsorted_size--)
    {
        for (int left_i = 0; left_i < unsorted_size - 1; left_i++)
        {
            int right_i = left_i+1;
            int left = array[left_i];
            int right = array[right_i];

            if (left >= right)
            {
                swap(array, left_i, right_i);
            }
        }
    }
}

int binary_it(int array[], int size, int num) {
    int left_i = 0;
    int right_i = size - 1;

    if (num == array[left_i])
    {
        return left_i;
    }

    if (num == array[right_i])
    {
        return right_i;
    }


    while ((right_i - left_i) != 1)
    {
        int mid_i = (left_i + right_i) / 2;
        int mid = array[mid_i];
        
        if (num < mid)
        {
            right_i = mid_i;
        }

        if (num > mid)
        {
            left_i = mid_i;
        }

        if (num == mid)
        {
            return mid_i;
        }

    }

    cout << num << " is not in the array" << endl;
    return -1;
    
}

int binary_rec(int array[], int num, int right_i=10, int left_i=0) {
    int left = array[left_i];
    int right = array[right_i];

    if (left == num) {return left_i;}

    if (right == num) {return right_i;}

    if (right_i-left_i == 1)
    {
        cout << "Not in array" << endl;
        return -1;
    }

    int mid_i = (left_i + right_i) / 2;
    int mid = array[mid_i];

    if (num < mid)
    {
        return binary_rec(array, num, mid_i, left_i);
    }

    if (num > mid)
    {
        return binary_rec(array, num, right_i, mid_i);
    }

    if (num == mid)
    {
        return mid_i;
    }

    return -1;
}

int main () {

    srand(time(NULL));
    
    cout << "array creation: " << endl;
    int array[10];
    rand_array(array, 10);
    print(array, 10);

    cout << endl;

    cout << "Selection sort: " << endl;
    selection_sort(array, 10);
    print(array, 10);

    cout << endl;

    cout << "Array rescramble: " << endl;
    rand_array(array, 10);
    print(array, 10);

    cout << endl;

    cout << "Insertion sort: " << endl;
    insertion_sort(array, 10);
    print(array, 10);

    cout << endl;

    cout << "Array rescramble: " << endl;
    rand_array(array, 10);
    print(array, 10);

    cout << endl;

    cout << "Bubble sort: " << endl;
    bubble_sort(array, 10);
    print(array, 10);

    cout << endl;

    int num = rand() % 10;
    cout << "Index of " << array[num] << " in array is: " << binary_it(array, 10, array[num]) << " using iterative binary search";

    cout << endl;

    int bum = rand() % 10;
    cout << "Index of " << array[bum] << " in array is: " << binary_rec(array, array[bum]) << " using recursive binary search";

    return 0;
}