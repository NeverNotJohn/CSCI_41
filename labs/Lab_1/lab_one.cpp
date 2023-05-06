#include <iostream>
#include <cmath>

using namespace std;

string isOdd(int num) {

    string ans;
    (num % 2 == 0) ? (ans = "Even") : (ans = "Odd");
    return ans;
}

string MonthToString(int num) {
    switch (num) {
        case (1): {
            return "January";
            break;
        }
        case (2): {
            return "February";
            break;
        }
        case (3): {
            return "March";
            break;
        }
        case (4): {
            return "April";
            break;
        }
        case (5): {
            return "May";
            break;
        }
        case (6): {
            return "June";
            break;
        }
        case (7): {
            return "July";
            break;
        }
        case (8): {
            return "August";
            break;
        }
        case (9): {
            return "September";
            break;
        }
        case (10): {
            return "October";
            break;
        }
        case (11): {
            return "November";
            break;
        }
        case (12): {
            return "December";
            break;
        }
    }
    return "Invalid month num";
}

double x1_for(int n) {
    double ans = 0.0;
    for (int i = 1; i <= n; i++) {
        ans += i / (i + 1.0);
        
    }
    return ans;
}

double x1_while(int n) {
    double ans = 0.0;
    int i = 1;
    while (i <= n) {
        ans += i / (i + 1.0);
        i++;
    }
    return ans;
}

int x2_for(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans += i * j;
        }
    }
    return ans;
}

int x2_while(int n) {
    int ans = 0;
    int i = 1;

    while (i <= n) {
        int j = i;
        while (j <= n) {
            ans += i * j;
            j++;
        }
        i++;
    }

    return ans;
}

double x3_for(int n) {
    double ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                ans += 1.0 / (sqrt(i + j + k));
            }
        }
    }
    return ans;
}

double x3_while(int n) {
    double ans = 0.0;
    int i = 1;
    

    while (i <= n) {
        int j = 1;
        while (j <= n) {
            int k = 1;
            while (k <= n) {
                ans += 1.0 / (sqrt(i + j + k));
                k++;
            }
            j++;
        }
        i++;
    }

    return ans;
}

int x4_for(int n) {
    int ans = 1;

    for (int i = 1; i<= n; i++) {
        
        // get inner series
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += j;
        }

        // get product of i ans series
        int product = i * sum;
        ans = ans * product;

    }

    return ans;

}

int x4_while(int n) {
    int ans = 1;
    int i = 1;
    while (i <= n) {

        int sum = 0;
        int j = 1;

        while (j <= n) {
            sum += j;
            j++;
        }

        int product = i * sum;
        ans = ans * product;

        i++;
    }

    return ans;

}

int x5_for(int n) {
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        if ( (i % 2) == 1) { // odd
            sum += 4;
        }

        else { // even
            sum += 9;
        }
    }
    return sum;
}

int x5_while(int n) {
    int sum = 0;
    int i = 1;
    while (i <= n) {

        if ( (i % 2) == 1) { // odd
            sum += 4;
        }

        else { // even
            sum += 9;
        }

        i++;
    }

    return sum;
}


int main() {

    // Question 1
    cout << isOdd(1) << endl; // returns if num is odd or even

    cout << endl << endl << endl;

    // Question 2
    for (int i = 1; i < 14; i++) { // return all months and num month (Includng false num)
        cout << "Month number: " << i << " Month String: " << MonthToString(i) << endl;
    }

    cout << endl << endl << endl;

    // Question 3

    cout << "x1_for(10): " << x1_for(10) << endl;
    cout << "x1_for(100): " << x1_for(100) << endl;
    cout << "x1_for(1000): " << x1_for(1000) << endl;

    cout << "x1_while(10): " << x1_while(10) << endl;
    cout << "x1_while(100): " << x1_while(100) << endl;
    cout << "x1_while(1000): " << x1_while(1000) << endl;

    cout << endl;

    cout << "x2_for(10): " << x2_for(10) << endl;
    cout << "x2_for(100): " << x2_for(100) << endl;
    cout << "x2_for(1000): " << x2_for(1000) << endl;

    cout << "x2_while(10): " << x2_while(10) << endl;
    cout << "x2_while(100): " << x2_while(100) << endl;
    cout << "x2_while(1000): " << x2_while(1000) << endl;

    cout << endl;

    cout << "x3_for(10): " << x3_for(10) << endl;
    cout << "x3_for(100): " << x3_for(100) << endl;
    cout << "x3_for(1000): " << x3_for(1000) << endl;

    cout << "x3_while(10): " << x3_while(10) << endl;
    cout << "x3_while(100): " << x3_while(100) << endl;
    cout << "x3_while(1000): " << x3_while(1000) << endl;

    cout << endl;

    cout << "x4_for(10): " << x4_for(10) << endl;
    cout << "x4_for(100): " << x4_for(100) << endl; // too big it breaks
    cout << "x4_for(1000): " << x4_for(1000) << endl; // too big it breaks

    cout << "x4_while(10): " << x4_while(10) << endl;
    cout << "x4_while(100): " << x4_while(100) << endl; // too big it breaks
    cout << "x4_while(1000): " << x4_while(1000) << endl; // too big it breaks

    cout << endl;

    cout << "x5_for(10): " << x5_for(10) << endl;
    cout << "x5_for(100): " << x5_for(100) << endl;
    cout << "x5_for(1000): " << x5_for(1000) << endl; 

    cout << "x5_while(10): " << x5_while(10) << endl;
    cout << "x5_while(100): " << x5_while(100) << endl;
    cout << "x5_while(1000): " << x5_while(1000) << endl;     

    return 0;
}