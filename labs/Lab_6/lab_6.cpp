#include <iostream>
#include <cmath>

using namespace std;

int natural_num(int num=1) {
    if (num == 51) 
    {
        return 51;
    }

    else 
    {
        cout << num << " ";
        if (num % 10 == 0) 
        {
            cout << endl;
        }
        return natural_num(num + 1);
    }
}

unsigned long long int factorial(unsigned long long int n) {

    if (n > 1) {
        unsigned long long int result = n * factorial(n - 1); 
        cout << result << " ";
        return result;
    }

    else {
        cout << 1 << " ";
        return 1;
    }
}

unsigned long int fibonacci(int n, bool print=true) {

    if (n == 1) {
        if (print) {
            cout << 1 << " ";
        }
        return 1;
    }

    else if (n == 2) {
        if (print) {
            cout << 1 << " ";
            cout << 1 << " ";
        }
        return 1;
    }

    else {

        unsigned long int result;

        if (print) {
            result = fibonacci(n - 1, true) + fibonacci(n - 2, false);
            cout << result << " ";
        }

        else {
            result = fibonacci(n - 1, false) + fibonacci(n - 2, false);
        }

        return result;
    }

}

void print(int array[], int size) {
    if (size > 0) 
    {
        cout << array[size-1] << " ";
        size--;
        print(array, size);
    }

}

int digits(int num, int dig=0) {
    if (num == 0) 
    {
        cout << dig;
        return dig;
    }

    else 
    {
        return digits(num/10, dig + 1);
    }
}


int gcd(int num1, int num2) {
    if (num1 == num2) 
    {
        return num1;
    }

    else if (num1 % num2 == 0)
    {
        return num2;
    }

    else if (num2 % num1 == 0)
    {
        return num1;
    }

    else if (num1 > num2)
    {
        return gcd(num1%num2, num2);
    }

    else
    {
        return gcd(num1, num2%num1);
    }
}

int large(int array[], int small_i, int big_i) {
    int small = array[small_i];
    int big = array[big_i];

    if (small == 0) 
    {
        return big;
    }

    if (small <= big) {
        return large(array, small_i-1, big_i);
    }

    else
    {
        return large(array, small_i - 1, small_i);
    }

}

int binary(int num, int index=0) {
    if (num == 0) 
    {
        return 0;
    }

    else 
    {
        return (num%2 * pow(10, index)) + binary(num/2, index + 1);
    }
}

bool prime(int num, int div=3) {

    if (div >= num/2)
    {
        return true;
    }

    if (num % 3 != 0)       // NOT DIVISIBLE
    {
        return prime(num, div + 1);
    }

    if (num % 3 == 0)
    {
        return false;
    }

    cout << "Error";
    return false;
}

int main() {

    cout << "The natural numbers are: " << endl;
    natural_num();

    cout << endl;

    cout << "Factorials of numbers 1-5 is: ";
    factorial(5);

    cout << endl << endl;

    cout << "Input number of terms for the series (< 20): ";
    int n;
    cin >> n;
    fibonacci(n);

    cout << endl << endl;

    int array[7] = {1, 2, 3, 4, 9999, -15, 22};
    cout << "The elements in the array are from last to first: ";
    print(array, 7);

    cout << endl << endl;

    cout << "The number of digits in the number 1234 is: ";
    digits(1234);

    cout << endl << endl;

    cout << "The GCD of 50 and 15 is " << gcd(50, 15);

    cout << endl << endl;

    cout << "The biggest numbers in the array is: " << large(array, 7, 7);

    cout << endl << endl;

    cout << "The Binary Value of decimal no. 66 is: " << binary(66);

    cout << endl << endl;

    cout << "Is 97 prime?: " << prime(97) << endl;
    cout << "^ If 0, it is not prime, if 1 it is prime" << endl;

    return 0;
}