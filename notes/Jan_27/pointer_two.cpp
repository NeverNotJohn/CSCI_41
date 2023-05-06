#include <iostream>

using namespace std;

/*

    int *A;

        (some code)

    delete A;

    ALWAYS DELETE POINTER LOL

*/

int main() {

    int a;
    int *aPtr; // points to integer (written as -> on paper)

    a = 7;
    aPtr = &a; // assigns address of a to aPtr

    cout << "Address of a is: " << &a << endl;
    cout  << "Value of aPtr is: " << aPtr << endl;

    cout << "The value of a is: " << a << endl;
    cout << "The value of *aPtr is: " << *aPtr << endl;

    cout << "Showing that * and & are inverses of each other" << endl;
    cout << "&*Ptr: " << &*aPtr << endl;
    cout << "*&Ptr: " << *&aPtr << endl;

    return 0;
}