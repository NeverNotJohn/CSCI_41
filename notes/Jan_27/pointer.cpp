#include <iostream>

using namespace std;

/*

    Pointer variables:
        contains memory addresses
        Pointers contain address of var w/ specific variable

    Indirections:
        references value through pointer

*/

int* get_int_address(int &a) { // returns address of any int
    int *ptr = &a;
    return ptr;
}

int* get_int_address_2(int &a) { // second way to get address
    return &a;
}

int main() {

    int hello = 69;
    int *ptr = &hello; // retries address

    cout << "*ptr: " << ptr << endl;
    cout << "get_int_address(hello): " << get_int_address(hello) << endl;

     cout << "get_int_address_2(hello): " << get_int_address_2(hello) << endl;

    int *empty;

    cout << "Empty: " << empty << endl;

    return 0;
}