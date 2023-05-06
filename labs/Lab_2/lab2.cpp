// FirstName LastName CSCI 41
// Lab2.cpp 
#include <iostream>
using namespace std;
class Array
{
public:
Array(); //default constructor for the class
~Array(); //destructor
int GetSize(); //Accessor: Retrieve the size of the array
void AddToBeginning(double); //function to add an element at the beginning
void AddToEnd(double); //function to add an element at the end
void RemoveFromBeginning(); //function to remove an element at the beginning
void RemoveFromEnd(); //function to remove an element at the end
void DisplayArray(); //display the content of the array
bool Search1(double); //iterative search with a for loop
bool Search2(double); //iterative search with a while loop
bool Search3(double); //iterative search with a do while loop
bool Search4(double, int); //recursive search
bool IsAllEven1(); //iterative function with a for loop
bool IsAllEven2(); //iterative function with a while loop
bool IsAllEven3(); //iterative function with a do while loop
bool IsAllEven4(int); //recursive function
Array IndexEqualToX(double); //function to return an object Array containing 
all elements equal to x.
void SwapAllElements(double, double); //function to swpa all elements equal 
to the value x to the value y.
void RemoveAll(double); //function to 
protected:
private:
int sizeOfArray; //array size
double* arrData; //double array
};
// Default Constructor for the class
Array::Array()
{
sizeOfArray = 0;
arrData = nullptr;
}
// Destructor for the class
Array::~Array()
{
delete[] arrData;
}
// Accessor: Function to retrieve the size of the array
int Array::GetSize()
{
return sizeOfArray;
}
//Function to insert an element to the beginning of the array
void Array::AddToBeginning(double element)
{
double* temp = new double[sizeOfArray + 1];
temp[0] = element;
for (int i = 0; i < sizeOfArray; i++)
{
temp[i + 1] = arrData[i];
}
arrData = temp;
sizeOfArray++;
}
//function to insert an element to the end of the array
void Array::AddToEnd(double element)
{
double* temp = new double[sizeOfArray + 1];
for (int i = 0; i < sizeOfArray; i++)
{
temp[i] = arrData[i];
}
temp[sizeOfArray] = element;
arrData = temp;
sizeOfArray++;
}
//function to remove an element at the beginning of the array
void Array::RemoveFromBeginning()
{
double* temp = new double[sizeOfArray - 1];
for (int i = 0; i < sizeOfArray - 1; i++)
{
temp[i] = arrData[i + 1];
}
arrData = temp;
sizeOfArray--;
}
//function to remove an element at the end of the array
void Array::RemoveFromEnd()
{
double* temp = new double[sizeOfArray - 1];
for (int i = 0; i < sizeOfArray - 1; i++)
{
temp[i] = arrData[i];
}
arrData = temp;
sizeOfArray--;
}
void Array::DisplayArray() // Function to Display the content of the array
{
cout << endl;
for (int i = 0; i < sizeOfArray; i++)
{
cout << *(arrData + i) << " ";
}
cout << endl;
}
//iterative search with a for loop
bool Array::Search1(double x) {
//your code here
}
//iterative search with a while loop
bool Array::Search2(double x) {
//your code here
}
//iterative search with a do while loop
bool Array::Search3(double x) {
//your code here
}
//recursive search
bool Array::Search4(double x, int index) {
//your code here
}
//iterative function with a for loop
bool Array::IsAllEven1() {
//your code here
}
//iterative function with a while loop
bool Array::IsAllEven2() {
//your code here
}
//iterative function with a do while loop
bool Array::IsAllEven3() {
//your code here
}
//recursive function
bool Array::IsAllEven4(int index) {
//your code here
}
//function to return an object Array containing all elements equal to x.
Array Array::IndexEqualToX(double x) {
//your code here
}
//function to swpa all elements equal to the value x to the value y.
void Array::SwapAllElements(double x, double y) {
//your code here
}
//function to remove all the elements equal to a particular value
void Array::RemoveAll(double x) {
//your code here
}
int main()
{
Array arr;
arr.AddToBeginning(4.0);
arr.AddToEnd(3.0);
cout << arr.GetSize() << endl;
arr.DisplayArray();
arr.AddToEnd(2.0);
arr.AddToBeginning(1.0);
cout << arr.GetSize() << endl;
arr.DisplayArray();
arr.RemoveFromBeginning();
cout << arr.GetSize() << endl;
arr.DisplayArray();
arr.RemoveFromEnd();
cout << arr.GetSize() << endl;
arr.DisplayArray();
return 0;