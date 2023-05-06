#include <iostream>

using namespace std;

// FACTORIAL:

unsigned long long int factorial_for(int input) {
    unsigned long long int output = 1;

    for (int i = input; i >= 1; i--) {
        output = output * i;
    }

    return output;
}

unsigned long long int factorial_while(int input) {
    unsigned long long int output = 1;
    int i = input;

    while (i >= 1) {
        output = output * i;
        i--;
    }

    return output;
}

unsigned long long int factorial_rec(unsigned long long int input) {
    if (input > 1) {
        return input * factorial_rec(input -1);
    }
    else {
        return 1;
    }
}

// FIBONACCI

unsigned long int fibonacci_for(int n) {
    unsigned long int first = 0;
    unsigned long int second = 1;
    unsigned long int fn = 1;

    for (int i = 0; i < n; i++) {
        fn = first + second;
        first = second;
        second = fn;
    }

    return fn;
}



unsigned long int fibonacci_while(int n) {
    unsigned long int first = 0;
    unsigned long int second = 1;
    unsigned long int fn = 1;

    int i = 0;

    while (i < n) {
        fn = first + second;
        first = second;
        second = fn;
        i++;
    }

    return fn;
}

unsigned long int fibonacci_rec(int n) {
    
    if (n == 0) {
        return 1; 
    }

    else if (n == 1) {
        return 1;
    }

    else {
        return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
    }

}

unsigned long int hanoi_rec(int level) {
    if (level == 0) {
        return 1;
    }

    else {
        return 2 * (hanoi_rec(level - 1)) + 1;
    }
}

unsigned long int hanoi_not_rec(int level) {
    unsigned long int last = 1;
    unsigned long int ans = 1;

    for (int i = 0; i < level; i++) {
        ans = (last * 2) + 1;
        last = ans;
    }
    return ans;
}


int main() {

    cout << "factorial_for(10) = " << factorial_for(10) << endl;
    cout << "factorial_while(10) = " << factorial_while(10) << endl;
    cout << "factorial_rec(10) = " << factorial_rec(10) << endl;

    cout << endl << endl << endl;

    cout << "First 20 fibonacci_for sequence: " << endl;

    for (int i = 0; i < 20; i++) {
        cout << fibonacci_for(i) << ", ";
    }
    cout << endl << endl;

    cout << "First 20 fibonacci_while sequence: " << endl;

    for (int i = 0; i < 20; i++) {
        cout << fibonacci_while(i) << ", ";
    }
    cout << endl << endl;

    cout << "First 20 fibonacci_rec sequence: " << endl;

    for (int i = 0; i < 20; i++) {
        cout << fibonacci_rec(i) << ", ";
    }

    cout << endl << endl << endl << endl;

    cout << "First 15 tower of hanoi sequence using recursion: " << endl;

    for (int i = 0; i < 15; i++) {
        cout << hanoi_rec(i) << ", ";
    } 
    cout << endl << endl;

    cout << "First 15 tower of hanoi sequence NOT using recursion: " << endl;

    for (int i = 0; i < 15; i++) {
        cout << hanoi_not_rec(i) << ", ";
    } 


    return 0;
}