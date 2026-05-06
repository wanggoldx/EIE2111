//Lau Wang Chun / ID: 21100151d\

#include <iostream> // allows program to perform input and output
using std::cout; // program uses cout
using std::endl; // program uses endl
using std::cin; // program uses cin
int main() {
	int number1; // first integer read from user
	int number2; // second integer read from user
	int number3; // third integer read from user
	int largest,smallest;
	cout << "Input three different integers: "; // prompt
	cin >> number1 >> number2 >> number3; // read three integers
	largest = number1; // assume first integer is largest
	if (number2 > largest) // is number2 larger?
		largest = number2; // number2 is now the largest
	if (number3 > largest) // is number3 larger?
		largest = number3; // number3 is now the largest
	smallest = number1; // assume first integer is smallest
	if (number2 < smallest) // is number2 smaller?
		smallest = number2; // number2 is now the smallest
	if (number3 < smallest) // is number3 smaller?
		smallest = number3; // number3 is now the smallest
	cout << "Sum is " << number1 + number2 + number3
		<< "\nAverage is " << (number1 + number2 + number3) / 3
		<< "\nProduct is " << number1 * number2 * number3
		<< "\nSmallest is " << smallest
		<< "\nLargest is " << largest << endl
		return 0; // indicate successful termination
} // end main
