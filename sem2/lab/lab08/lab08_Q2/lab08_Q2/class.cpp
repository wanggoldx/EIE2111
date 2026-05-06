#include <string>
using std::string;
#include "class.h"

ToolList::ToolList(int srecord, string stoolname, int squantity, double scost)
{
	setRecordNumber(srecord);
	setToolname(stoolname);
	setquantity(squantity);
	setcost(scost);
} 

int ToolList::getRecordNumber() const
{
	return record;
} 

void ToolList::setRecordNumber(int srecord)
{
	record = srecord; 
}

string ToolList::getToolname() const
{
	return toolname;
} 

void ToolList::setToolname(string stoolname)
{
	const char* lastNameValue = stoolname.data();
	int length = stoolname.size();
	length = (length < 30 ? length : 29);
	strncpy_s(toolname, lastNameValue, length);
} 

int ToolList::getquantity() const
{
	return quantity;
} 

void ToolList::setquantity(int squantity)
{
	quantity = squantity;
} 

double ToolList::getcost() const
{
	return cost;
}

void ToolList::setcost(double scost)
{
	cost = scost;
} 