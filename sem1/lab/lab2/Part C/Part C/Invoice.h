//Name: Lau Wang Chun
//Student ID: 21100151D
#include <string> 
using std::string;

class Invoice 
{
public:
	Invoice(string a, string b, int c, int d)
	{
		partnumber = a;
		partname = b;
		quantity = c;
		price = d;
	}

	void setPartNumber(string a)
	{
		partnumber = a;
	}

	void setPartDescription(string b)
	{
		partname = b;
	}

	void setQuantity(int c)
	{
		if (c < 0)
		{
			cout << "quantity cannot be negetive.\nquantity set to 0.\n";
			quantity = 0;
		}
		else
			quantity = c;
	}

	void setPricePerItem(int d)
	{
		if (d < 0)
		{
			cout << "PricePerItem cannot be negetive.\nPricePerItem set to 0.\n";
			price = 0;
		}
		else
			price = d;
	}

	string getPartNumber()
	{
		return partnumber;
	}
	string getPartDescription()
	{
		return partname;
	}
	int getQuantity()
	{
		return quantity;
	}
	int getPricePerItem() 
	{
		return price;
	}
	int getInvoiceAmount() 
	{
		return quantity * price;
	}
private:
	string partnumber; 
	string partname;
	int quantity; 
	int price;

};
