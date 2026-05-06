#include <string>
using namespace std;
class GradeBook
{
public:
	void displayMessage(string courseName)
	{
		cout << "Welcome to the grade book for \n" << courseName << "!" << endl;
	}
};