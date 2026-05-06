#include<iostream>
#include <fstream>
#include<string>
#include <iomanip>
using namespace std;

int recordno, quantity;
double cost;
string toolname, temp;
bool endfile;

void outputLine(int recordno, const string name, int quantity, double cost)
{
	cout << left << setw(10) << recordno << setw(20) << name << setw(7) << quantity << right << setw(10) << setprecision(2) << fixed << cost << endl;
}

void writerecordback()
{
	ofstream inClientFile1("hardware.txt", ios::out);
	if (!inClientFile1)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	}
	ifstream tempfile1("temp.txt", ios::in);
	if (!tempfile1)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	}

	while (tempfile1 >> recordno >> toolname >> quantity >> cost)
	{
		inClientFile1 << recordno << ' ' << toolname << ' ' << quantity << ' ' << cost << endl;
	}
	inClientFile1.close();
	tempfile1.close();

}

int main()
{
	ofstream outClientFile("hardware.txt", ios::out);
	if (!outClientFile)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	}

	recordno = 3;
	toolname = "Electric_sander";
	quantity = 7;
	cost = 57.98;
	outClientFile << recordno << ' ' << toolname << ' ' << quantity << ' ' << cost << endl;
	recordno = 17;
	toolname = "Hammer";
	quantity = 76;
	cost = 11.99;
	outClientFile << recordno << ' ' << toolname << ' ' << quantity << ' ' << cost << endl;
	recordno = 24;
	toolname = "Jig_saw";
	quantity = 21;
	cost = 11.00;
	outClientFile << recordno << ' ' << toolname << ' ' << quantity << ' ' << cost << endl;
	recordno = 39;
	toolname = "Lawn_mower";
	quantity = 3;
	cost = 79.50;
	outClientFile << recordno << ' ' << toolname << ' ' << quantity << ' ' << cost << endl;
	recordno = 56;
	toolname = "Power_saw";
	quantity = 18;
	cost = 99.99;
	outClientFile << recordno << ' ' << toolname << ' ' << quantity << ' ' << cost << endl;
	recordno = 68;
	toolname = "Screwdriver";
	quantity = 106;
	cost = 6.99;
	outClientFile << recordno << ' ' << toolname << ' ' << quantity << ' ' << cost << endl;
	recordno = 77;
	toolname = "Sledge_hammer";
	quantity = 11;
	cost = 21.50;
	outClientFile << recordno << ' ' << toolname << ' ' << quantity << ' ' << cost << endl;
	recordno = 83;
	toolname = "Wrench";
	quantity = 34;
	cost = 7.50;
	outClientFile << recordno << ' ' << toolname << ' ' << quantity << ' ' << cost << endl;
	outClientFile.close();

	char choice = 0;
	do
	{
		endfile = false;
		cout << "**************Main Menu****************" << endl;
		cout << "1.List out all the record" << endl;
		cout << "2.Delete the record" << endl;
		cout << "3.Update information of current records" << endl;
		cout << "4.End of using file" << endl;
		cout << "Input your choice >> ";
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			cout << endl;
			ifstream inClientFile("hardware.txt", ios::in);
			if (!inClientFile)
			{
				cerr << "File could not be opened" << endl;
				exit(1);
			}

			cout << left << setw(10) << "Record" << setw(20) << "Tool name" << setw(7) << "Quantity" << right << setw(8) << setprecision(2) << fixed << "Cost" << endl;
		
			while (inClientFile >> recordno >> toolname >> quantity >> cost)
			{
				for (int i = 0; i < toolname.length(); i = i + 1)
					if (toolname.at(i) == '_')
						toolname.at(i) = ' ';
				outputLine(recordno, toolname, quantity, cost);
			}
			cout << endl;
			inClientFile.close();
			break;
		}
		case '2':
		{
			int recordno3;
			cout << "enter the record number of the tool >> ";
			cin >> recordno3;

			ifstream inClientFile("hardware.txt", ios::in);
			if (!inClientFile)
			{
				cerr << "File could not be opened" << endl;
				exit(1);
			}
			ofstream tempfile("temp.txt", ios::out);
			if (!tempfile)
			{
				cerr << "File could not be opened" << endl;
				exit(1);
			}

			while (inClientFile >> recordno >> toolname >> quantity >> cost)
			{
				if (recordno != recordno3)
					tempfile << recordno << ' ' << toolname << ' ' << quantity << ' ' << cost << endl;
			}
			inClientFile.close();
			tempfile.close();

			writerecordback();
			cout << endl;
			break;
		}
		case '3':
		{
			int recordno4;
			string update_type, dummy;

			cout << "input record number which you want to update ";
			cin >> recordno4;

			ifstream inClientFile("hardware.txt", ios::in);
			if (!inClientFile)
			{
				cerr << "File could not be opened" << endl;
				exit(1);
			}
			ofstream tempfile("temp.txt", ios::out);
			if (!tempfile)
			{
				cerr << "File could not be opened" << endl;
				exit(1);
			}

			while (inClientFile >> recordno >> toolname >> quantity >> cost)
			{
				if (recordno == recordno4)
				{
					cout << "which information of record you want to update?" << endl << "(recordno, toolname, quantity, cost) ";
					cin >> update_type;
					if (update_type == "recordno")
					{
						cout << "input the new information ";
						cin >> recordno;
						tempfile << recordno << ' ' << toolname << ' ' << quantity << ' ' << cost << endl;
					}
					else if (update_type == "toolname")
					{
						cout << "input the new information ";
						getline(cin, dummy);
						getline(cin, toolname);
						for (int i = 0; i < toolname.length(); i = i + 1)
							if (toolname.at(i) == ' ')
								toolname.at(i) = '_';
						tempfile << recordno << ' ' << toolname << ' ' << quantity << ' ' << cost << endl;
					}
					else if (update_type == "quantity")
					{
						cout << "input the new information ";
						cin >> quantity;
						tempfile << recordno << ' ' << toolname << ' ' << quantity << ' ' << cost << endl;
					}
					else if (update_type == "cost")
					{
						cout << "input the new information ";
						cin >> cost;
						tempfile << recordno << ' ' << toolname << ' ' << quantity << ' ' << cost << endl;
					}
					else  cout << "wrong input!Back to the main menu!";
				}
				else
					tempfile << recordno << ' ' << toolname << ' ' << quantity << ' ' << cost << endl;
			}
			inClientFile.close();
			tempfile.close();

			writerecordback();
			cout << endl;
			break;
		}
		case '4':
		{
			endfile = true;
			cout << "end of editing";
			break;
		}
		default:
		{
			cout << "Wrong input! Input again >> ";
			cin >> choice;
			cout << endl;
		}
		}
	} while (endfile==false);

}