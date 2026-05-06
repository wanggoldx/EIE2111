//Name: Lau Wang Chun
//ID: 21100151D
#include<iostream>
#include <iomanip>
using namespace std;

double pi(int term)
{
	double save, judge, denominator;
	judge = 0;
	save = 4;
	denominator = 3;
	if (term == 1)
		return 4;
	else
		for (int i = 1; i <= (term - 1); i = i + 1)
			if (judge == 0)
			{
				judge = judge + 1;
				save = save - 4 / denominator;
				denominator = denominator + 2;
			}
			else
			{
				judge = judge - 1;
				save = save + 4 / denominator;
				denominator = denominator + 2;
			}
	return save;
}

int main()
{
	int input, q4save, setwd;
	double save, count;

	input = 0;
	save = 0;
	count = 0;
	cout << "Question 1\n";
	cout << "Enter integers (-100 to end): ";
	cin >> input;
	for (int i = 1; input != -100; i = i + 1)
	{
		save = save + input;
		count = i;
		cin >> input;
	}
	save = save / count;
	cout << "The average is: " << save << endl << endl;

	cout << "Question 2\n";
	cout << "Enter integers (the first one is the number of integers): ";
	cin >> count;
	cin >> input;
	save = input;	
	if (count == 1)
		cout << "The smallest integer is: " << save;
	else
	{
		for (int i = 1; i<=(count-1); i = i + 1)
		{
			if (save>input)
				save = input;
			cin >> input;
		}
		cout << "The smallest integer is: " << save;
	}
	cout << endl << endl;

	cout << "Question 3\n";
	save = 5;
	for (int i = 1; i <= 10; i = i + 1)
	{
		for (int j = 1; j <= i; j = j + 1)
			cout << "*";
		for (int j = 14; j >= i; j = j - 1)
			cout << " ";
		for (int j = 10; j >= i; j = j - 1)
			cout << "*";
		for (int j = 1; j <= save; j = j +1)
			cout << " ";
		for (int j = 10; j >= i; j = j - 1)
			cout << "*";
		for (int j = 14; j >= i; j = j - 1)
			cout << " ";
		for (int j = 1; j <= i; j = j + 1)
			cout << "*";
		save = save + 2;
		cout << endl;
	}
	cout << endl << endl;

	cout << "Question 4\n";
	cout << "acccuracy set at: ";
	cin >> input;
	cout << endl;
	cout << setw(1) << "term" << setw(15) << "pi" << endl;
	if (input <= 0)
		cout << "a wrong input!!!";
	else
	{
		q4save = input / 100;
		if (q4save < 0)
			cout << "1" << setw(17) << "4" << endl;
		else
		{
			cout << "1" << setw(17) << "4" << endl;
			save = 100;
			setwd = 0;
			for (int i = 1; i <= q4save; i = i + 1)
			{
				input = save;
				do
				{ 
					input = input / 10;
					setwd = setwd + 1;
				} while (input >= 10);
				cout << fixed << setprecision(0) << save << setw(23 - setwd) << fixed << setprecision(5) << pi(save) << endl;
				save = save + 100;
				setwd = 0;
			}
		}
	}
}