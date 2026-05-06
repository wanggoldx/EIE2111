//Name: Lau Wang Chun
//Student ID: 21100151D
#include <string> 
using std::string;

class Invoice
{
public:
	Invoice(string, string, int, int);
	void setPartNumber(string);
	void setPartDescription(string);
	void setQuantity(int);
	void setPricePerItem(int);
	string getPartNumber();
	string getPartDescription();
	int getQuantity();
	int getPricePerItem();
	int getInvoiceAmount();

private:
	string partnumber;
	string partname;
	int quantity;
	int price;

};

