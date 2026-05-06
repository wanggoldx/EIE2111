#include <string>
using std::string;

class ToolList
{
public:

	ToolList(int = 0, string = "", int = 0, double = 0.0);

	void setRecordNumber(int);
	int getRecordNumber() const;

	void setToolname(string);
	string getToolname() const;

	void setquantity(int);
	int getquantity() const;

	void setcost(double);
	double getcost() const;
private:
	int record;
	char toolname[30];
	int quantity;
	double cost;
};