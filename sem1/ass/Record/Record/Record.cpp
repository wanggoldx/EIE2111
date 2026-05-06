#include<iostream>
#include<string>
using namespace std;

#include"Record.h"

void Record::setname(string a)
{
	name = a;
}

string Record::getname()
{
	return name;
}

void Record::setemail(string b)
{
	email = b;
}

string Record::getemail()
{
	return email;
}

void Record::setphonenum(int c)
{
	phonenum = c;
}

int Record::getphonenum()
{
	return phonenum;
}
