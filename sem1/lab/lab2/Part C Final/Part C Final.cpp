//Name: Lau Wang Chun
//Student ID: 21100151d

#include <iostream> 
using std::cout;
using std::endl;

#include "Account.h" 
#include "Invoice.h" 

int main() {
	Account myAccount1(100);
	Account myAccount2(-10);

	cout << "myAccount1: Balance = $" << myAccount1.getBalance() << endl;
	cout << endl;
	cout << "Deposit $100 into the account." << endl;
	myAccount1.credit(100);
	cout << "myAccount1: Balance = $" << myAccount1.getBalance() << endl;
	cout << endl;
	cout << "Withdraw $500 from the account." << endl;
	myAccount1.debit(500);
	cout << "myAccount1: Balance = $" << myAccount1.getBalance() << endl;
	cout << endl;
	cout << "Withdraw $50 from the account." << endl;
	myAccount1.debit(50);
	cout << "myAccount1: Balance = $" << myAccount1.getBalance() << endl;
	cout << endl;

	Invoice myInvoice("12345", "Hammer", 100, 5);

	cout << "Part number: " << myInvoice.getPartNumber() << endl;
	cout << "Part description: " << myInvoice.getPartDescription() << endl;
	cout << "Quantity: " << myInvoice.getQuantity() << endl;
	cout << "Price per item: $" << myInvoice.getPricePerItem() << endl;
	cout << "Invoice amount: $" << myInvoice.getInvoiceAmount() << endl;
	cout << endl;

	myInvoice.setPartNumber("123456");
	myInvoice.setPartDescription("Saw");
	myInvoice.setQuantity(-5);
	myInvoice.setQuantity(5);
	myInvoice.setPricePerItem(-10);
	myInvoice.setPricePerItem(10);  cout << endl;

	cout << "After modification, " << endl;
	cout << "Part number: " << myInvoice.getPartNumber() << endl;
	cout << "Part description: " << myInvoice.getPartDescription() << endl;
	cout << "Quantity: " << myInvoice.getQuantity() << endl;
	cout << "Price per item: $" << myInvoice.getPricePerItem() << endl;
	cout << "Invoice amount: $" << myInvoice.getInvoiceAmount() << endl;

	return 0;
}
