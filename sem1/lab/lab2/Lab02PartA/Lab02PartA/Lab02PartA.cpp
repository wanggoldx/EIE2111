//Lab02PartA.cpp
//Name: Lau Wang Chun
//ID:21100151d

#include <iostream>
#include "GradeBook.h"

int main()
{
	string nameOfCourse;
	GradeBook myGradeBook;
	cout << "Please enter the course name:" << endl;
	getline(cin, nameOfCourse);
	cout << endl;
	myGradeBook.displayMessage(nameOfCourse);
}
