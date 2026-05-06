#include<iostream>
using namespace std;

int checkprime(int num)
{
	int count;
	count = 0;
	for (int i=1;i<=num;i=i+1)
	{ 
		if ((num % i) == 0)
			count = count + 1;
	}
	if (count == 2)
		return num;
	else
		return 0;
}

int calpowerrecus(int base, int power)
{
	static int save = 1;

	if (power == 0)
		return save;
	else
	{ 
		save = save * base;
		power = power - 1;
		calpowerrecus(base,power);
	}
}

int main()
{
	int int1, int2, count, primetotal;
	cout << "Question 1\n";
	cout << "Input the first integer: ";
	cin >> int1;
	cout << "Input the second integer: ";
	cin >> int2;
	cout << endl;
	cout << "The prime numbers from " << int1 << " to " << int2 << " are:" << endl;
	count = 0;
	primetotal = 0;
	for (int i = int1; i <= int2; i = i + 1)
	{ 
		if (checkprime(i) != 0)
			{ 
				cout << "  " << checkprime(i);
				count = count + 1;
				primetotal = primetotal + 1;
			}
		if (count == 10)
			{ 
				cout << endl;
				count = 0;
			}
	}
	if (count == 10)
		cout << endl << endl;
	else
		cout << endl;
	cout << "Total of " << primetotal << " prime numbers between " << int1 << " and " << int2 << ".";

	cout << endl << endl;
	cout << "Question 2\n";
	cout << "Enter the base and an exponent: ";
	cin >> int1 >> int2;
	cout << int1 << " raised to the " << int2 << " is " << calpowerrecus(int1,int2);

}