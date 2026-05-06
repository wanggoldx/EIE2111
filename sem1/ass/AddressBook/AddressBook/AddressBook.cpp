#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

#include"Record.h"

int usedlocation = 0;
Record addressbk[100];

void readinfo(string a,string b,int c)
{
	addressbk[usedlocation].setname(a);
	addressbk[usedlocation].setemail(b);
	addressbk[usedlocation].setphonenum(c);
	usedlocation = usedlocation + 1;
}

bool checkvalid(string a, string b, int c)
{
	bool judge = true;
	bool actexist = false;

	for (unsigned int i = 0;i <= (a.length()-1); i = i + 1)
	{
		if ((a.at(i) != ' ') && (!isalpha(a.at(i))))
		{ 
			judge = false;
		}
	};

	for (unsigned int i = 0; i <= (b.length() - 1); i = i + 1)
	{
		if (b.at(i) == '@')
			actexist = true;
		if ((b.at(0) == '@') || (b.at(b.length() - 1) == '@'))
		{ 
			judge = false;
		}
	}
	if (actexist == false)
	{ 
		judge = false;
	}

	if ((c>99999999) || (c<10000000))
	{ 
		judge = false;
	}

	return judge;
}

void displayrecord(int head,int final)
{
	for (int i = head; i <= final; i = i + 1)
	{
		cout << "Name is: " << addressbk[i].getname() << endl;
		cout << "Email is: " << addressbk[i].getemail() << endl;
		cout << "Telephone number is: " << addressbk[i].getphonenum() << endl;
	}
}

int main()
{
	string name, email, no_creatrecord, userchoose, dummy;
	int telephonenum;
	char choosemain, choosesub;
	bool judge = false;

	do
	{
		cout << "***********MAIN MENU*************\n";
		cout << "[1] Initialize the address book\n";
		cout << "[2] Create person contact information\n";
		cout << "[3] Lookup person contact information\n";
		cout << "[4] Lookup all person contact information\n";
		cout << "[5] Quit\n\n";
		cout << "Please enter your choose (1, 2, 3, 4 or 5 to quit):\n";
		getline(cin, userchoose);
		if (userchoose == "1" || userchoose == "2" || userchoose == "3" || userchoose == "4" || userchoose == "5")
			choosemain = userchoose.at(0);
		else
			choosemain = 0;
		switch (choosemain)
		{
		case '1':
			usedlocation = 0;
			name = "Lawrence Cheung";
			email = "enccl@eie.polyu.edu.hk";
			telephonenum = 27666131;
			readinfo(name, email, telephonenum);
			name = "Helon Wong";
			email = "helonwong@yahoo.com.hk";
			telephonenum = 94665888;
			readinfo(name, email, telephonenum);
			name = "Simon Sui";
			email = "ss123@gmail.com";
			telephonenum = 64441234;
			readinfo(name, email, telephonenum);
			name = "Mary Ho";
			email = "ho.mary10@netvigator.com";
			telephonenum = 21111112;
			readinfo(name, email, telephonenum);
			displayrecord(0, usedlocation - 1);
			cout << "Initialization is completed." << endl << endl;
			break;
		case '2':
			cout << "Please enter the total number of records to be created>> ";
			getline(cin, no_creatrecord);
			while (no_creatrecord != "1" && no_creatrecord != "2" && no_creatrecord != "3" && no_creatrecord != "4" && no_creatrecord != "5" && no_creatrecord != "6" && no_creatrecord != "7" && no_creatrecord != "8" && no_creatrecord != "9" && no_creatrecord != "10")
			{
				cout << "The input is invalid.It must be an integer not greater than 10.\n";
				cout << "Please enter the total number of records to be created ";
				getline(cin, no_creatrecord);
			}
			for (int i = 0; i <= (stoi(no_creatrecord) - 1); i = i + 1)
			{
				cout << "Name: ";
				getline(cin, name);
				cout << "Email: ";
				getline(cin, email);
				cout << "Telephone number: ";
				cin >> telephonenum;
				while (checkvalid(name, email, telephonenum) == false)
				{
					cout << "Invalid input!Input again!\n";
					cout << "Name: ";
					getline(cin, dummy);
					getline(cin, name);
					cout << "Email: ";
					getline(cin, email);
					cout << "Telephone number: ";
					cin >> telephonenum;
				}
				readinfo(name, email, telephonenum);
				getline(cin, dummy);
			}
		cout << "All new records are saved!" << endl << endl;
		break;
		case '3':
			do
			{
				cout << "\n***********SUB-MENU*************\n";
				cout << "a. Search record by name\n";
				cout << "b. Search record by email address\n";
				cout << "c. Search record by telephone number\n";
				cout << "d. Return a main menu\n\n";
				cout << "Please enter your choose (a, b, c or d to quit):\n";
				getline(cin, userchoose);
				if (userchoose == "a" || userchoose == "b" || userchoose == "c" || userchoose == "d")
					choosesub = userchoose.at(0);
				else
					choosesub = 0;
				switch (choosesub)
				{
				case 'a':
					judge = false;
					cout << "\nPlease enter a name to search>> ";
					getline(cin, name);
					for (int i = 0; i <= usedlocation - 1; i = i + 1)
					{
						if (addressbk[i].getname() == name)
						{
							judge = true;
							displayrecord(i, i);
						}
					}
					if (judge == true)
						cout << "\nA record is found!\n";
					else
						cout << "\nSorry, no record is found!\n";
					break;
				case 'b':
					judge = false;
					cout << "\nPlease enter an email address to search>> ";
					getline(cin, email);
					for (int i = 0; i <= usedlocation - 1; i = i + 1)
					{
						if (addressbk[i].getemail() == email)
						{
							judge = true;
							displayrecord(i, i);
						}
					}
					if (judge == true)
						cout << "\nA record is found!\n";
					else
						cout << "\nSorry, no record is found!\n";
					break;
				case 'c':
					judge = false;
					cout << "\nPlease enter a telephone number to search>> ";
					cin >> telephonenum;
					getline(cin, dummy);
					for (int i = 0; i <= usedlocation - 1; i = i + 1)
					{
						if (addressbk[i].getphonenum() == telephonenum)
						{
							judge = true;
							displayrecord(i, i);
						}
					}
					if (judge == true)
						cout << "\nA record is found!\n";
					else
						cout << "\nSorry, no record is found!\n";
					break;
				case 'd':
					cout << endl;
					break;
				default:
					cout << "Invalid input. Please enter again!\n\n";
				}
			} while (choosesub != 'd');
			break;
		case '4':
			displayrecord(0, usedlocation - 1);
			cout << endl;
			break;
		case '5':
			cout << "Goodbye!";
			break;
		default:
			cout << "Invalid input. Please enter again!\n\n";
		}
	} while (choosemain != '5');
}





