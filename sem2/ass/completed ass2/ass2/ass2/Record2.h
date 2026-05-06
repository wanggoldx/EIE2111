#include <string> 
using namespace std;

class Record2
{
public:
	void setname(string);
	string getname() const;
	void setemail(string);
	string getemail() const;
	void setphonenum(int);
	int getphonenum() const;
	void setnext(Record2*);
	Record2* getnext() const;
private:
	char name[100];
	char email[100];
	int phonenum;
	Record2* nextptr;
};
