#include <iostream>

using namespace std;

/*

    Basic review of classes

    Access Review:

        Public:
            Can be accessed by class itself and by main
        Private:
            Can only be accessed by class itself (not main!)
        Protected:

    .h and .cpp review

        we do #include <(whatever header file)>

*/

class garbage {
    public: // access specifiers
        string brand;
        int size_kg;

        garbage(string x, int y); // constructor declaration

        ~garbage() {cout << "leave!";} // deconstructor
};

garbage::garbage(string x, int y) { // constructor 
    brand = x;
    size_kg = y;
}

int main() {
    garbage Japan("Mitsubishi", 23);
    garbage America("Pain", 99999);

    cout << Japan.brand << " " << Japan.size_kg << endl;
    cout << America.brand << " " << America.size_kg << endl;

    return 0;
}