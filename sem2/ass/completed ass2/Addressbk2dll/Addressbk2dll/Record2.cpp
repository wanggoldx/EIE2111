#include<iostream>
#include<string>
using namespace std;

#include"Record2.h"

void Record2::setname(string a)
{
	const char* nameptr = a.data();
	int length = a.size();
	length = (length < 100 ? length : 99);
	strncpy_s(name, nameptr, length);
}

string Record2::getname() const
{
	return name;
}

void Record2::setemail(string b)
{
	const char* nameptr = b.data();
	int length = b.size();
	length = (length < 100 ? length : 99);
	strncpy_s(email, nameptr, length);
}

string Record2::getemail() const
{
	return email;
}

void Record2::setphonenum(int c)
{
	phonenum = c;
}

int Record2::getphonenum() const
{
	return phonenum;
}

void Record2::setnext(Record2* ptr)
{
	nextptr = ptr;
}Record2* Record2::getnext() const
{
	return nextptr;
}