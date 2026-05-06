//Name: Lau Wang Chun
//Student ID: 21100151D
#include <string> 
using std::string;

#include <iostream>
using namespace std;

#include "Invoice.h"


Invoice::Invoice(string a, string b, int c, int d)
	{
		partnumber = a;
		partname = b;
		quantity = c;
		price = d;
	}

void Invoice::setPartNumber(string a)
	{
		partnumber = a;
	}

void Invoice::setPartDescription(string b)
	{
		partname = b;
	}

void Invoice::setQuantity(int c)
	{
		if (c < 0)
		{
			cout << "quantity cannot be negetive.\nquantity set to 0.\n";
			quantity = 0;
		}
		else
			quantity = c;
	}

void Invoice::setPricePerItem(int d)
	{
		if (d < 0)
		{
			cout << "PricePerItem cannot be negetive.\nPricePerItem set to 0.\n";
			price = 0;
		}
		else
			price = d;
	}

string Invoice::getPartNumber()
	{
		return partnumber;
	}
string Invoice::getPartDescription()
	{
		return partname;
	}
int Invoice::getQuantity()
	{
		return quantity;
	}
int Invoice::getPricePerItem()
	{
		return price;
	}
int Invoice::getInvoiceAmount()
	{
		return quantity * price;
	}



