#include <iostream>

using namespace std;

int main() {

    int *array{ new int[5] {10, 7, 15, 3, 11} };

    cout << "Array Elements: " << endl;

    for (int i = 0; i < 5; i++) 
    {
        cout << array[i] << endl;
    }

    return 0;
}