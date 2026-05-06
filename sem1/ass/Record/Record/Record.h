#include <string> 
using namespace std;

class Record
{
public:
	void setname(string);
	string getname();
	void setemail(string);
	string getemail();
	void setphonenum(int);
	int getphonenum();
private:
	string name, email;
	int phonenum;
};