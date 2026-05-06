#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#include"Record2.h"

void check()
{
	int number_of_record = 0;
	fstream addressbk2("addressbk2.dat", ios::binary | ios::out | ios::in);
	if (!addressbk2)
	{
		cerr << "File not find!";
		exit(1);
	}

	Record2* temp_record_ptr = new Record2, * first_record_ptr = new Record2, * last_record_ptr = new Record2;
	addressbk2.read(reinterpret_cast<char*>(temp_record_ptr), sizeof(Record2));
	while (!addressbk2.eof())
	{
		number_of_record = number_of_record + 1;
		if (number_of_record == 1)
		{
			first_record_ptr = temp_record_ptr;
			last_record_ptr = temp_record_ptr;
			first_record_ptr->setnext(0);
			temp_record_ptr = new Record2;
		}
		else
		{
			last_record_ptr->setnext(temp_record_ptr);
			last_record_ptr = temp_record_ptr;
			last_record_ptr->setnext(0);
			temp_record_ptr = new Record2;
		}
		addressbk2.read(reinterpret_cast<char*>(temp_record_ptr), sizeof(Record2));
	}

	addressbk2.close();

	temp_record_ptr = first_record_ptr;
	while (temp_record_ptr != 0)
	{
		cout << "Name is: " << temp_record_ptr->getname() << endl;
		cout << "Email is: " << temp_record_ptr->getemail() << endl;
		cout << "Telephone number is: " << temp_record_ptr->getphonenum() << endl;
		temp_record_ptr = temp_record_ptr->getnext();
	}

	while (first_record_ptr != 0)
	{
		delete first_record_ptr;
		first_record_ptr = first_record_ptr->getnext();
	}
}

void file_cout_content()
{

	fstream addressbk2("addressbk2.dat", ios::binary | ios::out | ios::in);
	if (!addressbk2)
	{
		cerr << "File not find!";
		exit(1);
	}

	Record2* temp_record_ptr = new Record2;
	addressbk2.read(reinterpret_cast<char*>(temp_record_ptr), sizeof(Record2));
	while (!addressbk2.eof())
	{
		cout << "Name is: " << temp_record_ptr->getname() << endl;
		cout << "Email is: " << temp_record_ptr->getemail() << endl;
		cout << "Telephone number is: " << temp_record_ptr->getphonenum() << endl;
		addressbk2.read(reinterpret_cast<char*>(temp_record_ptr), sizeof(Record2));
	}

	addressbk2.close();
}

void initialization()
{
	fstream addressbk2("addressbk2.dat", ios::binary | ios::out);
	if (!addressbk2)
	{
		cerr << "File not find!";
		exit(1);
	}

	Record2* temp_record = new Record2;
	temp_record->setname("Lawrence Cheung");
	temp_record->setemail("enccl@eie.polyu.edu.hk");
	temp_record->setphonenum(27666131);
	addressbk2.write(reinterpret_cast<const char*>(temp_record), sizeof(Record2));

	temp_record->setname("Helon Wong");
	temp_record->setemail("helonwong@yahoo.com.hk");
	temp_record->setphonenum(94665888);
	addressbk2.write(reinterpret_cast<const char*>(temp_record), sizeof(Record2));

	temp_record->setname("Simon Sui");
	temp_record->setemail("ss123@gmail.com");
	temp_record->setphonenum(64441234);
	addressbk2.write(reinterpret_cast<const char*>(temp_record), sizeof(Record2));

	temp_record->setname("Mary Ho");
	temp_record->setemail("ho.mary10@netvigator.com");
	temp_record->setphonenum(21111112);
	addressbk2.write(reinterpret_cast<const char*>(temp_record), sizeof(Record2));

	addressbk2.close();
}

void print_4_record()
{
	fstream addressbk2("addressbk2.dat", ios::binary | ios::out | ios::in);
	if (!addressbk2)
	{
		cerr << "File not find!";
		exit(1);
	}

	Record2* temp_record = new Record2;
	addressbk2.read(reinterpret_cast<char*>(temp_record), sizeof(Record2));
	while (addressbk2 && !addressbk2.eof())
	{
		if (temp_record->getphonenum() > 0)
		{
			cout << "Name is: " << temp_record->getname() << endl;
			cout << "Email is: " << temp_record->getemail() << endl;
			cout << "Telephone number is: " << temp_record->getphonenum() << endl;
		}
		addressbk2.read(reinterpret_cast<char*>(temp_record), sizeof(Record2));
	}

	addressbk2.close();
}

Record2* file_to_linked_list()
{
	int number_of_record = 0;
	fstream addressbk2("addressbk2.dat", ios::binary | ios::out | ios::in);
	if (!addressbk2)
	{
		cerr << "File not find!";
		exit(1);
	}

	Record2* temp_record_ptr = new Record2, * first_record_ptr = new Record2, * last_record_ptr = new Record2;
	addressbk2.read(reinterpret_cast<char*>(temp_record_ptr), sizeof(Record2));
	while (!addressbk2.eof())
	{
		number_of_record = number_of_record + 1;
		if (number_of_record == 1)
		{
			first_record_ptr = temp_record_ptr;
			last_record_ptr = temp_record_ptr;
			first_record_ptr->setnext(0);
			temp_record_ptr = new Record2;
		}
		else
		{
			last_record_ptr->setnext(temp_record_ptr);
			last_record_ptr = temp_record_ptr;
			last_record_ptr->setnext(0);
			temp_record_ptr = new Record2;
		}
		addressbk2.read(reinterpret_cast<char*>(temp_record_ptr), sizeof(Record2));
	}

	addressbk2.close();
	return first_record_ptr;
}

void linked_list_to_file(Record2* ptr)
{
	fstream addressbk2("addressbk2.dat", ios::binary | ios::out | ios::in);
	if (!addressbk2)
	{
		cerr << "File not find!";
		exit(1);
	}

	int number_of_record = 0;
	Record2* tempptr = ptr;
	while (tempptr !=0)
	{
		number_of_record = number_of_record + 1;
		tempptr = tempptr->getnext();
	}
	cout << number_of_record<<endl;

	for (int i = 0; i < number_of_record; i = i + 1)
	{ 
		addressbk2.write(reinterpret_cast<const char*>(ptr), sizeof(Record2));
		ptr=ptr->getnext();
	}
	addressbk2.close();
}

void print_linked_list(Record2* ptr)
{
	while (ptr != 0)
	{
		cout << "Name is: " << ptr->getname() << endl;
		cout << "Email is: " << ptr->getemail() << endl;
		cout << "Telephone number is: " << ptr->getphonenum() << endl;
		ptr = ptr->getnext();
	}
}

bool search_by_name(string a)
{
	//file to linked list
	int number_of_record = 0;
	fstream addressbk2("addressbk2.dat", ios::binary | ios::out | ios::in);
	if (!addressbk2)
	{
		cerr << "File not find!";
		exit(1);
	}

	Record2* temp_record_ptr = new Record2, * first_record_ptr = new Record2, * last_record_ptr = new Record2;
	addressbk2.read(reinterpret_cast<char*>(temp_record_ptr), sizeof(Record2));
	while (!addressbk2.eof())
	{
		number_of_record = number_of_record + 1;
		if (number_of_record == 1)
		{
			first_record_ptr = temp_record_ptr;
			last_record_ptr = temp_record_ptr;
			first_record_ptr->setnext(0);
			temp_record_ptr = new Record2;
		}
		else
		{
			last_record_ptr->setnext(temp_record_ptr);
			last_record_ptr = temp_record_ptr;
			last_record_ptr->setnext(0);
			temp_record_ptr = new Record2;
		}
		addressbk2.read(reinterpret_cast<char*>(temp_record_ptr), sizeof(Record2));
	}

	addressbk2.close();

	//search by name
	Record2* searchptr = first_record_ptr;
	bool judge = false;
	do
	{
		if (searchptr->getname() == a)
		{
			judge = true;
			return judge;
		}
		else
		{ 
			judge = false;
			return judge;
		}
		searchptr = searchptr->getnext();
	} while (searchptr != 0);
}

void print_out_name(int a)
{
	fstream addressbk2("addressbk2.dat", ios::binary | ios::out | ios::in);
	if (!addressbk2)
	{
		cerr << "File not find!";
		exit(1);
	}
	
	Record2* temp = new Record2;
	for (int i = 0; i < a; i = i + 1)
	{
		addressbk2.read(reinterpret_cast<char*>(temp), sizeof(Record2));
	}

	addressbk2.close();
	ofstream gocsharp("temp.txt", ios::out);
	if (!gocsharp)
	{
		cerr << "File not find!";
		exit(1);
	}

	gocsharp << temp->getname();
	gocsharp.close();
}

void print_out_email(int a)
{
	fstream addressbk2("addressbk2.dat", ios::binary | ios::out | ios::in);
	if (!addressbk2)
	{
		cerr << "File not find!";
		exit(1);
	}

	Record2* temp = new Record2;
	for (int i = 0; i < a; i = i + 1)
	{
		addressbk2.read(reinterpret_cast<char*>(temp), sizeof(Record2));
	}

	addressbk2.close();
	ofstream gocsharp("temp.txt", ios::out);
	if (!gocsharp)
	{
		cerr << "File not find!";
		exit(1);
	}

	gocsharp << temp->getemail();
	gocsharp.close();
}

int print_out_phonenumber(int a)
{
	fstream addressbk2("addressbk2.dat", ios::binary | ios::out | ios::in);
	if (!addressbk2)
	{
		cerr << "File not find!";
		exit(1);
	}

	Record2* temp = new Record2;
	for (int i = 0; i < a; i = i + 1)
	{
		addressbk2.read(reinterpret_cast<char*>(temp), sizeof(Record2));
	}

	addressbk2.close();
	return temp->getphonenum();
}

int record_total_number()
{
	int number_of_record = 0;
	fstream addressbk2("addressbk2.dat", ios::binary | ios::out | ios::in);
	if (!addressbk2)
	{
		cerr << "File not find!";
		exit(1);
	}

	Record2* temp_record_ptr = new Record2;
	addressbk2.read(reinterpret_cast<char*>(temp_record_ptr), sizeof(Record2));
	while (!addressbk2.eof())
	{
		number_of_record = number_of_record + 1;
		addressbk2.read(reinterpret_cast<char*>(temp_record_ptr), sizeof(Record2));
	}
	
	addressbk2.close();
	return number_of_record;
}

void create_new_record()
{
	int number_of_record = 0;
	string name, email, phonenum;
	ifstream csharptoc("temp.txt", ios::in);

	if (!csharptoc)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	} // end if 

	csharptoc >> name >> email >> phonenum;
	for (unsigned int i = 0; i < name.length(); i = i + 1)
	{
		if (name.at(i) == '_')
		{
			name.at(i) = ' ';
		}
	}
	csharptoc.close();

	fstream addressbk2("addressbk2.dat", ios::binary | ios::out | ios::in);
	if (!addressbk2)
	{
		cerr << "File not find!";
		exit(1);
	}

	Record2* temp_record_ptr = new Record2, * first_record_ptr = new Record2, * last_record_ptr = new Record2;
	addressbk2.read(reinterpret_cast<char*>(temp_record_ptr), sizeof(Record2));
	while (!addressbk2.eof())
	{
		number_of_record = number_of_record + 1;
		if (number_of_record == 1)
		{
			first_record_ptr = temp_record_ptr;
			last_record_ptr = temp_record_ptr;
			first_record_ptr->setnext(0);
			temp_record_ptr = new Record2;
		}
		else
		{
			last_record_ptr->setnext(temp_record_ptr);
			last_record_ptr = temp_record_ptr;
			last_record_ptr->setnext(0);
			temp_record_ptr = new Record2;
		}
		addressbk2.read(reinterpret_cast<char*>(temp_record_ptr), sizeof(Record2));
	}

	addressbk2.close();
	
	//add record to linked list
	Record2* tempptr = new Record2;
	tempptr->setname(name);
	tempptr->setemail(email);
	tempptr->setphonenum(stoi(phonenum));
	tempptr->setnext(0);

	Record2* lastptr = new Record2;
	lastptr = first_record_ptr;
	while (lastptr->getnext() != 0)
	{
		lastptr = lastptr->getnext();
	}
	lastptr->setnext(tempptr);
	number_of_record = number_of_record + 1;

	//linked list to file
	fstream addressbk("addressbk2.dat", ios::binary | ios::out | ios::in);
	if (!addressbk)
	{
		cerr << "File not find!";
		exit(1);
	}

	for (int i = 0; i < number_of_record; i = i + 1)
	{
		addressbk.write(reinterpret_cast<const char*>(first_record_ptr), sizeof(Record2));
		first_record_ptr = first_record_ptr->getnext();
	}
	addressbk.close();
}

int search()
{
	int number_of_record = 0;
	string search_information;
	ifstream csharptoc("temp.txt", ios::in);

	if (!csharptoc)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	} // end if 

	csharptoc >> search_information;
	for (unsigned int i = 0; i < search_information.length(); i = i + 1)
	{
		if (search_information.at(i) == '_')
		{
			search_information.at(i) = ' ';
		}
	}
	csharptoc.close();

	fstream addressbk2("addressbk2.dat", ios::binary | ios::out | ios::in);
	if (!addressbk2)
	{
		cerr << "File not find!";
		exit(1);
	}

	Record2* temp_record_ptr = new Record2, * first_record_ptr = new Record2, * last_record_ptr = new Record2;
	addressbk2.read(reinterpret_cast<char*>(temp_record_ptr), sizeof(Record2));
	while (!addressbk2.eof())
	{
		number_of_record = number_of_record + 1;
		if (number_of_record == 1)
		{
			first_record_ptr = temp_record_ptr;
			last_record_ptr = temp_record_ptr;
			first_record_ptr->setnext(0);
			temp_record_ptr = new Record2;
		}
		else
		{
			last_record_ptr->setnext(temp_record_ptr);
			last_record_ptr = temp_record_ptr;
			last_record_ptr->setnext(0);
			temp_record_ptr = new Record2;
		}
		addressbk2.read(reinterpret_cast<char*>(temp_record_ptr), sizeof(Record2));
	}

	addressbk2.close();
	//search record from linked list
	Record2* searchptr = first_record_ptr;
	int judge = 0;
	string name, email, phonenum;
	do
	{
		if (searchptr->getname() == search_information)
		{
			judge = 1;
			email = searchptr->getemail();
			phonenum = to_string(searchptr->getphonenum());
			ofstream outClientFile("temp.txt", ios::out);

			if (!outClientFile) // overloaded ! operator
			{
				cerr << "File could not be opened" << endl;
				exit(1);
			} // end if 

			outClientFile << email << ' ' << phonenum;

			outClientFile.close();
		}
		if (searchptr->getemail() == search_information)
		{
			judge = 2;
			name = searchptr->getname();
			for (unsigned int i = 0; i < name.length(); i = i + 1)
			{
				if (name.at(i) == ' ')
				{
					name.at(i) = '_';
				}
			}
			phonenum = to_string(searchptr->getphonenum());
			ofstream outClientFile("temp.txt", ios::out);

			if (!outClientFile) // overloaded ! operator
			{
				cerr << "File could not be opened" << endl;
				exit(1);
			} // end if 

			outClientFile << name << ' ' << phonenum;

			outClientFile.close();
		}
		if (to_string(searchptr->getphonenum()) == search_information)
		{
			judge = 3;
			name = searchptr->getname();
			for (unsigned int i = 0; i < name.length(); i = i + 1)
			{
				if (name.at(i) == ' ')
				{
					name.at(i) = '_';
				}
			}
			email = searchptr->getemail();
			ofstream outClientFile("temp.txt", ios::out);

			if (!outClientFile) // overloaded ! operator
			{
				cerr << "File could not be opened" << endl;
				exit(1);
			} // end if 

			outClientFile << name << ' ' << email;

			outClientFile.close();
		}
		searchptr = searchptr->getnext();
	} while (searchptr != 0);
	
	return judge;
}

void remove_record()
{
	//file to linked list
	int number_of_record = 0;
	string remove_information;
	ifstream csharptoc("temp.txt", ios::in);

	if (!csharptoc)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	} // end if 

	csharptoc >> remove_information;
	for (unsigned int i = 0; i < remove_information.length(); i = i + 1)
	{
		if (remove_information.at(i) == '_')
		{
			remove_information.at(i) = ' ';
		}
	}
	csharptoc.close();

	fstream addressbk2("addressbk2.dat", ios::binary | ios::out | ios::in);
	if (!addressbk2)
	{
		cerr << "File not find!";
		exit(1);
	}

	Record2* temp_record_ptr = new Record2, * first_record_ptr = new Record2, * last_record_ptr = new Record2;
	addressbk2.read(reinterpret_cast<char*>(temp_record_ptr), sizeof(Record2));
	while (!addressbk2.eof())
	{
		number_of_record = number_of_record + 1;
		if (number_of_record == 1)
		{
			first_record_ptr = temp_record_ptr;
			last_record_ptr = temp_record_ptr;
			first_record_ptr->setnext(0);
			temp_record_ptr = new Record2;
		}
		else
		{
			last_record_ptr->setnext(temp_record_ptr);
			last_record_ptr = temp_record_ptr;
			last_record_ptr->setnext(0);
			temp_record_ptr = new Record2;
		}
		addressbk2.read(reinterpret_cast<char*>(temp_record_ptr), sizeof(Record2));
	}

	addressbk2.close();
	//delete function
	Record2* searchptr = first_record_ptr;
	do
	{
		if ((searchptr == first_record_ptr) && (searchptr->getname() == remove_information))
		{
			Record2* tempptr = new Record2;
			tempptr = first_record_ptr;
			first_record_ptr = first_record_ptr->getnext();
			searchptr = searchptr->getnext();
			delete tempptr;		
		}
		else if ((searchptr->getnext())->getname() == remove_information)
		{
			Record2* tempptr = new Record2;
			tempptr = searchptr->getnext();
			searchptr->setnext(tempptr->getnext());
			delete tempptr;
		}
		else if ((searchptr == first_record_ptr) && (searchptr->getemail() == remove_information))
		{
			Record2* tempptr = new Record2;
			tempptr = first_record_ptr;
			first_record_ptr = first_record_ptr->getnext();
			searchptr = searchptr->getnext();
			delete tempptr;
		}
		else if ((searchptr->getnext())->getemail() == remove_information)
		{
			Record2* tempptr = new Record2;
			tempptr = searchptr->getnext();
			searchptr->setnext(tempptr->getnext());
			delete tempptr;
		}
		else if ((searchptr == first_record_ptr) && (to_string(searchptr->getphonenum()) == remove_information))
		{
			Record2* tempptr = new Record2;
			tempptr = first_record_ptr;
			first_record_ptr = first_record_ptr->getnext();
			searchptr = searchptr->getnext();
			delete tempptr;
		}
		else if (to_string((searchptr->getnext())->getphonenum()) == remove_information)
		{
			Record2* tempptr = new Record2;
			tempptr = searchptr->getnext();
			searchptr->setnext(tempptr->getnext());
			delete tempptr;
		}
		else
		{
			searchptr = searchptr->getnext();
		}
	} while (searchptr->getnext() != 0);

	//linked list to file
	ofstream addressbk("addressbk2.dat", ios::binary | ios::out);
	if (!addressbk)
	{
		cerr << "File not find!";
		exit(1);
	}

	number_of_record = number_of_record - 1;
	for (int i = 0; i < number_of_record; i = i + 1)
	{
		addressbk.write(reinterpret_cast<const char*>(first_record_ptr), sizeof(Record2));
		first_record_ptr = first_record_ptr->getnext();

	}
	addressbk.close();
}

int main()
{
	initialization();

	int a,name;
	remove_record();
	file_cout_content();
	/*cout << "1.create ";
	string name, email;
	int phone;
	cin >> name >> email >> phone;
	create_new_record(name, email, phone);


	cin >> name;*/
}

/*#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#include"Record2.h";

int record_no = 0;

void initialization()
{
	Record2* addressbkhead = new Record2;
	addressbkhead->setname("Lawrence Cheung");
	addressbkhead->setemail("enccl@eie.polyu.edu.hk");
	addressbkhead->setphonenum(27666131);
	
	Record2* temp_record1 = new Record2;
	temp_record1->setname("Helon Wong");
	temp_record1->setemail("helonwong@yahoo.com.hk");
	temp_record1->setphonenum(94665888);
	addressbkhead->setnext(temp_record1);

	Record2* temp_record2 = new Record2;
	temp_record2->setname("Simon Sui");
	temp_record2->setemail("ss123@gmail.com");
	temp_record2->setphonenum(64441234);
	temp_record1->setnext(temp_record2);

	Record2* temp_record3 = new Record2;
	temp_record3->setname("Mary Ho");
	temp_record3->setemail("ho.mary10@netvigator.com");
	temp_record3->setphonenum(21111112);
	temp_record2->setnext(temp_record3);

	record_no = 4;
}

void print_4_record()
{
	fstream addressbk2("addressbk2.dat", ios::binary | ios::out | ios::in);
	if (!addressbk2)
	{
		cerr << "File not find!";
		exit(1);
	}
	
	Record2* temp_record = new Record2;
	addressbk2.read(reinterpret_cast<char*>(temp_record),sizeof(Record2));
	while (addressbk2 && !addressbk2.eof())
	{
		if (temp_record->getphonenum() > 0)
		{ 
		cout << "Name is: " << temp_record->getname() << endl;
		cout << "Email is: " << temp_record->getemail() << endl;
		cout << "Telephone number is: " << temp_record->getphonenum() << endl;
		}
		addressbk2.read(reinterpret_cast<char*>(temp_record), sizeof(Record2));
	}
	addressbk2.close();
}

void linked_list_to_file(Record2* record)
{
	fstream addressbk2("addressbk2.dat", ios::binary | ios::out | ios::in);
	if (!addressbk2)
	{
		cerr << "File not find!";
		exit(1);
	}

	while (record->getphonenum() != 0)
	{
		addressbk2.write(reinterpret_cast<const char*>(record), sizeof(Record2));
		record = record->getnext();
	}
	addressbk2.close();
}

Record2* file_to_link_list()
{
	fstream addressbk2("addressbk2.dat", ios::binary | ios::out | ios::in);
	if (!addressbk2)
	{
		cerr << "File not find!";
		exit(1);
	}

	Record2* tempPtr = 0, * firstPtr = 0, * lastPtr = 0;
	while (addressbk2 && !addressbk2.eof())
	{ 
		if (record_no = 0)
			cerr << "No record in files";
		else if (record_no=1)
		{ 
			addressbk2.read(reinterpret_cast<char*>(&tempPtr), sizeof(Record2));
			firstPtr = tempPtr;
			lastPtr = tempPtr;
		}
		else
		{ 
			addressbk2.read(reinterpret_cast<char*>(&tempPtr), sizeof(Record2));
			lastPtr->setnext(tempPtr);
			lastPtr = tempPtr;
		}
	}
	return firstPtr;
	addressbk2.close();
}

int main()
{
	ofstream addressbk2("addressbk2.dat", ios::binary | ios::out | ios::in);
	if (!addressbk2)
	{
		cerr << "File not find!";
		exit(1);
	}
	Record2* blankrecord = new Record2;
	for (int i = 0; i < 100; i++)
		addressbk2.write(reinterpret_cast<const char*>(blankrecord),sizeof(Record2));
	addressbk2.close();

	Record2* addressbkhead = new Record2;
	addressbkhead->setnext(0);

	initialization();
	cout << "good";
	linked_list_to_file(addressbkhead);
	addressbkhead = file_to_link_list();

	cout << addressbkhead->getname() << endl; 
	cout << (addressbkhead->getnext())->getname();


}

int record_in_file()
{
	int number_of_record = 0;
	fstream addressbk2("addressbk2.dat", ios::binary | ios::out | ios::in);
	if (!addressbk2)
	{
		cerr << "File not find!";
		exit(1);
	}

	Record2* temp_record = new Record2;
	addressbk2.read(reinterpret_cast<char*>(temp_record), sizeof(Record2));
	while (temp_record->getphonenum() > 0)
	{
		number_of_record = number_of_record + 1;
		addressbk2.read(reinterpret_cast<char*>(temp_record), sizeof(Record2));
	}

	addressbk2.close();
	return number_of_record;
}*/
