#include <iostream>

using namespace std;


// using reference in function...

int make(int &a, int &b) { // will change original variable... MUST BE VARIABLE
    a = 10; // changes original address
    return b;
}

int make_not(int a, int b) { // will not change
    a = 10; // only changes temporary var
    return b;
}

int main() {
    /* references:

        can be used as aliases for other variables within function
        operations are done on the ALIAS (the reference) and dont on the original varial

        Alias: name for the original variable

        MUST be initialized in declarations
            Cannot be reassigned after
            one left side of "="

        REFERENCES STORE THE ORIGINAL ADDRESS OF THE VARIABLE

    */ 

    int count = 1;
    int &cRef = count;
    cRef++; // changed both cRef and count

    cout << "count: " << count << endl;
    cout << "cRef: " << cRef << endl;

    int help = 1;
    int what = 0;
    cout << "Help: " << help << " make(): " << make(help, what) << " New Help: " << help << endl;
    cout << endl;

    cout << "What: " << what << " make_not(help, what): " << make_not(help, what) << " New What: " << what << endl;

    // Because of reference, the original address is changed
}

// reference REFERS to original variable