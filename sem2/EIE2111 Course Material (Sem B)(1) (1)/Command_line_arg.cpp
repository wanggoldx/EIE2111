// A testing program for command-line processing
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
	int i1, i2; // integers to store the 3rd and 4th arguments
	double d1, d2; // floating points to store 5th and 6th arguments

	//check number of command-line arguments
	if (argc != 6)
		cout << "Usage: Command_line_arg <sting> <integer> <integer> <double> <double>" << endl;
	else
	{
		// display each argument
		cout << "number of arguments = " << argc << endl;

		for (int i = 0; i < argc; i++)
			cout << "argv[" << i << "] = " << argv[i] << endl;

		// integer calculation
		i1 = atoi(argv[2]);
		i2 = atoi(argv[3]);
		cout << "argv[2] + argv[3] = " << i1 + i2 << endl;

		// floating point calcuation
		d1 = atof(argv[4]);
		d2 = atof(argv[5]);
		cout << "argv[4] * argv[5] = " << d1 * d2 << endl;
	}
	return 0;
}
