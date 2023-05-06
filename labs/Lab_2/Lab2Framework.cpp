// John Herrera CSCI 41
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
	Array IndexEqualToX(double); //function to return an object Array containing all elements equal to x.
	void SwapAllElements(double, double); //function to swpa all elements equal to the value x to the value y.
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
	
	for (int i = 0; i < sizeOfArray; i++) {
		if (x == *(arrData + i)) {
			return true;
		}
		else {continue;}
	}

	return false;

}

//iterative search with a while loop
bool Array::Search2(double x) {
	
	int i = 0;

	while (i < sizeOfArray) {
		if (x == *(arrData + i)) {
			return true;
		}
		else {continue;}
		i++;
	}

	return false;

}

//iterative search with a do while loop
bool Array::Search3(double x) {
	int i = 0;

	do {
		if (x == *(arrData + i)) {
			return true;
		}
		else {continue;}
		i++;
	}
	while (i < sizeOfArray);

	return false;
}

//recursive search
bool Array::Search4(double x, int index) {

	double temp = *(arrData + index);
	if (temp == x) {
		return true;
	}

	else {
		if (index < sizeOfArray) {
			return false;
		}
		index++;
		Search4(x, index);
		return false;
	}

}

//iterative function with a for loop
bool Array::IsAllEven1() {
	
	for (int i = 0; i < sizeOfArray; i++) {

		double num = *(arrData + i);
		int temp2 = num;
		int num2 = temp2 % 2;

		if (num2 == 0) {
			continue;
		}

		else {
			return false;
		}
	}

	return true;
}

//iterative function with a while loop
bool Array::IsAllEven2() {
	
	int i = 0; 

	while (i < sizeOfArray) {
		double num = *(arrData + i);
		int temp2 = num;
		int num2 = temp2 % 2;

		if (num2 == 0) {
			i++;
			continue;
		}

		else {
			return false;
		}
	}

	return true;
}

//iterative function with a do while loop
bool Array::IsAllEven3() {
	
	int i = 0;

	do {
		double num = *(arrData + i);
		int temp2 = num;
		int num2 = temp2 % 2;

		if (num2 == 0) {
			i++;
			continue;
		}

		else {
			return false;
		}
	}

	while (i < sizeOfArray);

	return true;
}

//recursive function
bool Array::IsAllEven4(int index) {
	
	double num = *(arrData + index);
	int temp2 = num;
	int num2 = temp2 % 2;

	if (num2 == 0) {

		if (index < sizeOfArray) {
			return true;
		}
		
		index++;
		return IsAllEven4(index);
	}

	else {
		return false;
	}

}

//function to return an object Array containing all elements equal to x.
Array Array::IndexEqualToX(double x) {
	Array temp;

	for (int i = 0; i < sizeOfArray; i++) {
		double num = *(arrData + i);

		if (num == x) {
			temp.AddToEnd(i);
		}
		else {
			continue;
		}
	}

	return temp;
}

//function to swpa all elements equal to the value x to the value y.
void Array::SwapAllElements(double x, double y) {
	for (int i = 0; i < sizeOfArray; i++) {
		double num = *(arrData + i);

		if (num == x) {
			arrData[i] = y;
		}

	}
}

//function to remove all the elements equal to a particular value
void Array::RemoveAll(double x) {

	Array temp;

	for (int i = 0; i < sizeOfArray; i++) {
		double num = *(arrData + i);

		if (num != x) {
			temp.AddToEnd(num);
		}

	}

	sizeOfArray = temp.sizeOfArray;

	for (int i = 0; i < sizeOfArray; i++) {
		arrData[i] = temp.arrData[i];
	}
	
}

int main()
{
	Array arr;
	arr.AddToBeginning(4.0);
	arr.AddToEnd(2.0);
	arr.AddToEnd(2.0);
	arr.AddToBeginning(1.0);
	arr.RemoveFromBeginning();
	arr.RemoveFromEnd();
	arr.AddToEnd(2.0);
	arr.AddToEnd(10.0);
	arr.AddToEnd(16.0);
	arr.DisplayArray();

	cout << "Search1: " << arr.Search1(4.0) << endl;
	cout << "Search2: " << arr.Search2(4.0) << endl;
	cout << "Search3: " << arr.Search3(4.0) << endl;
	cout << "Search4: " << arr.Search4(4.0, 0) << endl;

	cout << "IsAllEven1: " << arr.IsAllEven1() << endl;
	cout << "IsAllEven2: " << arr.IsAllEven2() << endl;
	cout << "IsAllEven3: " << arr.IsAllEven3() << endl;
	cout << "IsAllEven4: " << arr.IsAllEven4(0) << endl;

	cout << "IndexEqualToX: " << 2.0 << endl;
	(arr.IndexEqualToX(2.0)).DisplayArray();

	cout << "SwapAllElements(2.0, 5.0)" << endl;
	arr.SwapAllElements(2.0, 5.0);
	arr.DisplayArray();

	cout << "RemoveALL(5.0)" << endl;
	arr.RemoveAll(5.0);
	arr.DisplayArray();
	

	return 0;
}