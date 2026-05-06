//Name: Lau Wang Chun 
//Student ID: 21100151d

#include<iostream>
#include<string>
#include <iomanip> 
#include<cstdlib>
using namespace std;

class abc
{
	int check;
	string name;
	public:
		void initialize()
		{
			check = 0;
		}

		int space()
		{
			if (check == 0)
				return 0;
			else
				return 1;
		}

		void reservation(string a)
		{
			name = a;
			check = 1;
		}
		
		void planeseating()
		{
			cout << name;
		}

};

int main()
{
	int dice1, dice2, q2seed, choose, temp, number,finalfc,finalec;
	double freqofsum[13],expectpercent, actualpercent;
	string name,level,dummy;

	abc arrayOfObjects[6];
	for (int i = 0; i <= 5; i = i + 1)
		arrayOfObjects[i].initialize();

	cout << "Question 1\n";
	do 
	{
	cout << "Reservation (Press '0'), Check (Press '1'), or Exit (Press '2')? ";
	cin >> choose;
	switch (choose) 
	{
	case 0:
		cout << "Please input the following information\n";
		cout << "Name: ";
		getline(cin, dummy);
		getline(cin, name);
		cout << "First class (Press '1') or Economy class (Press '0')? ";
		cin >> level;
		cout << "Number of seats: ";
		cin >> number;
		finalfc = number;
		if (level == "1")
		{
			for (int i = 0; i <= 2; i = i + 1)
			{
				if ((arrayOfObjects[i].space() == 0) && (number != 0))
				{
					arrayOfObjects[i].reservation(name);
					number = number - 1;
				}
			}
			if (number == 0)
				cout << "Reserved. " << finalfc << " seats are first class";
			else
			{
				finalec = number;
				cout << "Not enough seats! Do you accept some seats are economy class?\n";
				cout << "(Press '1' to accept or '0' to reject) ";
				cin >> temp;
				if (temp==1)
				{ 
				for (int i = 3; i <= 5; i = i + 1)
				{
					if (arrayOfObjects[i].space() == 0 && number != 0)
					{
						arrayOfObjects[i].reservation(name);
						number = number - 1;
					}
				}
				cout << "Reserved. " << (finalfc-finalec) << " seats are first class and "<< finalec <<" seats are economy class";
				}
				else
					cout << "Next flight leaves in 3 hours.";
			}

			cout << endl << endl;
		}
		if (level == "0")
		{
			for (int i = 3; i <= 5; i = i + 1)
			{
				if ((arrayOfObjects[i].space() == 0) && (number != 0))
				{
					arrayOfObjects[i].reservation(name);
					number = number - 1;
				}
			}
			if (number != 0)
			{ 
				cout << "No enough seats!\n";
				cout << "Next flight leaves in 3 hours.\n\n";
			}
			
		}
		break;
	case 1:
		cout << "First class:\n";
		for (int i = 0; i <= 2; i = i + 1)
		{
			if (arrayOfObjects[i].space() == 1)
			{ 
				cout << "Seat " << (i + 1) << " : ";
				arrayOfObjects[i].planeseating();
				cout << endl;
			}
		}
		cout << "Economy class:\n";
		temp = 1;
		for (int i = 3; i <= 5; i = i + 1)
		{
			if (arrayOfObjects[i].space() == 1)
			{
				cout << "Seat " << (temp) << " : ";
				arrayOfObjects[i].planeseating();
				cout << endl;
				temp = temp + 1;
			}
		}
		cout << endl;
		break;
	case 2:
		break;
	default:
		cout << "Error! The operator is not correct";
	}
	} while (choose != 2);
}

	
	/*
	cout << "Question 2\n";
	cout << "Please enter the seed: ";
	cin >> q2seed;
	for (int i = 1; i <= 12; i = i + 1)
		freqofsum[i] = 0;

	srand(q2seed);
	for (int i = 1; i <= 3600; i = i + 1)
	{
		dice1 = 1 + rand() % 6;
		dice2 = 1 + rand() % 6;
		freqofsum[dice1 + dice2] = freqofsum[dice1 + dice2] + 1;
	}
	
	cout << "       " << "Sum" << "     " << "Total" << "  " << "Expected" << "   " << "Actual";
	cout << endl;
	temp = 0;
	for (int i = 2; i <= 12; i = i + 1)
	{
		if (i > 7)
			temp = temp - 1;
		else
			temp = temp + 1;
		expectpercent = (double(temp)/ 36)*100;
		actualpercent = (freqofsum[i]/ 3600) * 100;
		cout << setw(10) << i << setw(10) << int(freqofsum[i]) << setw(9) <<fixed <<setprecision(3) << expectpercent << "%" << setw(9) <<fixed<< setprecision(3) << actualpercent << "%";
		cout << endl;
	}*/
