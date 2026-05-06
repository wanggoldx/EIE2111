#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <string> 
#include <iomanip> 
using namespace std;

#include "class.h" 


void input_record_info(int a,string b,int c,double d)
{

	fstream list("hardware.dat", ios::in | ios::out | ios::binary);

	if (!list)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}

	ToolList blanklist;

	blanklist.setRecordNumber(a);
	blanklist.setToolname(b);
	blanklist.setquantity(c);
	blanklist.setcost(d);

	list.seekp((a - 1) * sizeof(ToolList));
	list.write(reinterpret_cast<const char*>(&blanklist), sizeof(ToolList));

	list.close();
}

void outputLine(ostream& output, const ToolList& record)
{
	output << left << setw(10) << record.getRecordNumber()
		<< setw(16) << record.getToolname()
		<< setw(11) << record.getquantity()
		<< setw(10) << setprecision(2) << right << fixed
		<< showpoint << record.getcost() << endl;
} 

int main()
{
	int recordno, quantity;
	double cost;
	string toolname, temp;
	bool endfile;

	fstream list("hardware.dat", ios::in | ios::out | ios::binary);
	if (!list)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}

	ToolList blanklist;

	for (int i = 0; i < 100; i++)
		list.write(reinterpret_cast<const char*>(&blanklist),
			sizeof(ToolList));
	list.close();

	recordno = 3;
	toolname = "Electric sander";
	quantity = 7;
	cost = 57.98;
	input_record_info(recordno, toolname, quantity, cost);
	recordno = 17;
	toolname = "Hammer";
	quantity = 76;
	cost = 11.99;
	input_record_info(recordno, toolname, quantity, cost);
	recordno = 24;
	toolname = "Jig saw";
	quantity = 21;
	cost = 11.00;
	input_record_info(recordno, toolname, quantity, cost);
	recordno = 39;
	toolname = "Lawn mower";
	quantity = 3;
	cost = 79.50;
	input_record_info(recordno, toolname, quantity, cost);
	recordno = 56;
	toolname = "Power saw";
	quantity = 18;
	cost = 99.99;
	input_record_info(recordno, toolname, quantity, cost);
	recordno = 68;
	toolname = "Screwdriver";
	quantity = 106;
	cost = 6.99;
	input_record_info(recordno, toolname, quantity, cost);
	recordno = 77;
	toolname = "Sledge hammer";
	quantity = 11;
	cost = 21.50;
	input_record_info(recordno, toolname, quantity, cost);
	recordno = 83;
	toolname = "Wrench";
	quantity = 34;
	cost = 7.50;
	input_record_info(recordno, toolname, quantity, cost);

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
			ifstream inCredit("hardware.dat", ios::in | ios::binary);

			if (!inCredit)
			{
				cerr << "File could not be opened." << endl;
				exit(1);
			} 
			
			cout << left << setw(10) << "Record" << setw(16)
				<< "Tool name" << setw(11) << "Quantity" << left
				<< setw(10) << right << "Cost" << endl;

			ToolList client;

			inCredit.read(reinterpret_cast<char*>(&client),
				sizeof(ToolList));

			while (inCredit && !inCredit.eof())
			{
				if (client.getRecordNumber() != 0)
					outputLine(cout, client);

				inCredit.read(reinterpret_cast<char*>(&client),
					sizeof(ToolList));
			}
			inCredit.close();
			cout << endl;
			break;
		}
		case '2':
		{
			int recordNumber;
			cout << "Input the record number you want to delete >> ";
			cin >> recordNumber;

			fstream list("hardware.dat", ios::in | ios::out | ios::binary);

			if (!list)
			{
				cerr << "File could not be opened." << endl;
				exit(1);
			}
				
			ToolList client;
			list.seekg((recordNumber - 1) * sizeof(ToolList));
			list.read(reinterpret_cast<char*>(&client),
					sizeof(ToolList));

			if (client.getRecordNumber() == recordNumber)
				{
					ToolList blankClient; 

					list.seekp((recordNumber - 1) *
						sizeof(ToolList));

					list.write(
						reinterpret_cast<const char*>(&blankClient),
						sizeof(ToolList));

					cout << "Account #" << recordNumber << " deleted.\n";
				} 
				else 
					cerr << "Account #" << recordNumber << " is empty.\n";
			list.close();
			break;
		}
		case '3':
		{
			int recordNumber;
			string update_type, dummy;

			fstream list("hardware.dat", ios::in | ios::out | ios::binary);
			if (!list)
			{
				cerr << "File could not be opened" << endl;
				exit(1);
			}

			cout << "input record number which you want to update >> ";
			cin >> recordNumber;

			ToolList changed_record;
			list.seekg((recordNumber - 1) * sizeof(ToolList));
			list.read(reinterpret_cast<char*>(&changed_record),
				sizeof(ToolList));

			if (changed_record.getRecordNumber() == recordNumber)
			{
				cout << "which information of record you want to update?" << endl << "(recordno, toolname, quantity, cost) ";
				cin >> update_type;
				if (update_type == "recordno")
				{
					cout << "input the new information ";
					cin >> recordno;
					changed_record.setRecordNumber(recordno);

					ToolList blanklist;
					list.seekp((recordNumber - 1) * sizeof(ToolList));
					list.write(reinterpret_cast<char*>(&blanklist),
						sizeof(ToolList));

					list.seekp((recordno - 1) *
						sizeof(ToolList));

					list.write(
						reinterpret_cast<const char*>(&changed_record),
						sizeof(ToolList));
					cout << "Updated!" << endl << endl;
				}
				else if (update_type == "toolname")
				{
					cout << "input the new information >>";
					getline(cin, dummy);
					getline(cin, toolname);
					changed_record.setToolname(toolname);
					list.seekp((recordNumber - 1) * sizeof(ToolList));

					list.write(
						reinterpret_cast<const char*>(&changed_record),
						sizeof(ToolList));
					cout << "Updated!" << endl << endl;
				}
				else if (update_type == "quantity")
				{
					cout << "input the new information ";
					cin >> quantity;
					changed_record.setquantity(quantity);
					list.seekp((recordNumber - 1) *
						sizeof(ToolList));

					list.write(
						reinterpret_cast<const char*>(&changed_record),
						sizeof(ToolList));
					cout << "Updated!" << endl << endl;
				}
				else if (update_type == "cost")
				{
					cout << "input the new information ";
					cin >> cost;
					changed_record.setcost(cost);
					list.seekp((recordNumber - 1) *
						sizeof(ToolList));

					list.write(
						reinterpret_cast<const char*>(&changed_record),
						sizeof(ToolList));
					cout << "Updated!" << endl << endl;
				}
				else  cout << "wrong input!Back to the main menu!" << endl;
			}
			else
				cout << "wrong input!No this record in the file!" << endl;
			list.close();
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
	} while (endfile == false);

    return 0;
} 
