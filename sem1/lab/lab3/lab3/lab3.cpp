#include<iostream>
using namespace std;

double factorial(int num)
{
	int save1;
	if (num == 0 || num == 1)
		return 1;
	else
	{
		save1 = 1;
		for (int i = 0; i <= (num - 1); i = i + 1)
			save1 = save1 * (num - i);
		return save1;
	}
}

double e(double num)
{

	double save2;
	if (num == 1)
		return 1;
	else
	{
		save2 = 1;
		for (double i = 1; i <= (num - 1); i = i + 1)
			save2 = save2 + (1 / factorial(i));
		return save2;
	}
}

double ex(double xpow, double num)
{
	double save2, power;
	if (num == 1)
		return 1;
	else
	{
		save2 = 1;
		power = xpow;
		for (double i = 1; i <= (num - 1); i = i + 1)
		{
			save2 = save2 + (xpow / factorial(i));
			xpow = xpow * power;
		}
		return save2;
	}
}


int main()
{
	double grosssales;
	int squareside, q3num1, q3num2, q3num3, q3num4, part4cin, acc;

	grosssales = 0;
	cout << "Question 1\n";
	cout << "Enter sales in dollars (-1 to end): ";
	cin >> grosssales;
	while (grosssales != -1)
	{
		cout << "Salary is: $" << (200 + grosssales * 0.09) << endl;
		cout << "Enter sales in dollars (-1 to end): ";
		cin >> grosssales;
	}

	cout << endl << "Question 2\n";
	cout << "Enter length of side: ";
	cin >> squareside;
	for (int i = 1; i <= squareside; i = i + 1)
	{
		for (int j = 1; j <= squareside; j = j + 1)
		{
			if (i == 1 || i == squareside || j == 1 || j == squareside)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}

	cout << endl << "Question 3\n";
	cout << "Enter a four-digit number: ";
	cin >> part4cin;

	q3num1 = part4cin / 1000 % 10;
	q3num2 = part4cin / 100 % 10;
	q3num3 = part4cin / 10 % 10;
	q3num4 = part4cin % 10;

	q3num1 = (q3num1 + 7) % 10;
	q3num2 = (q3num2 + 7) % 10;
	q3num3 = (q3num3 + 7) % 10;
	q3num4 = (q3num4 + 7) % 10;

	cout << "Encrypted number is ";
	cout << q3num3 << q3num4 << q3num1 << q3num2 << endl;
	cout << "Enter an encrypted number: ";
	cin >> part4cin;

	q3num1 = part4cin / 1000 % 10;
	q3num2 = part4cin / 100 % 10;
	q3num3 = part4cin / 10 % 10;
	q3num4 = part4cin % 10;

	if (q3num1 >= 7)
		q3num1 = q3num1 - 7;
	else q3num1 = q3num1 + 3;

	if (q3num2 >= 7)
		q3num2 = q3num2 - 7;
	else q3num2 = q3num2 + 3;

	if (q3num3 >= 7)
		q3num3 = q3num3 - 7;
	else q3num3 = q3num3 + 3;

	if (q3num4 >= 7)
		q3num4 = q3num4 - 7;
	else q3num4 = q3num4 + 3;
	cout << "Decrypted number is ";
	cout << q3num3 << q3num4 << q3num1 << q3num2 << endl;

	cout << endl << "Question 4\n";
	part4cin = 1 / 2;
	cout << part4cin;
	cout << "Enter a positive Integer: ";
	cin >> part4cin;
	while (part4cin < 0)
	{
		cout << "This is not a positive number!";
		cout << "Enter a positive Integer: ";
		cin >> part4cin;
	}
	cout << part4cin << "! is " << factorial(part4cin) << endl;
	cout << "Enter desired accuracy: ";
	cin >> acc;
	cout << "e is " << e(acc) << endl;

	cout << "Enter exponent x: ";
	cin >> part4cin;
	cout << "Enter desired accuracy: ";
	cin >> acc;
	cout << "e^x = " << ex(part4cin, acc);
}