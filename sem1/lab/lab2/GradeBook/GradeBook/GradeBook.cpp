//GradeBook.cpp
//Name: Lau Wang Chun
//Student ID: 21100151d
#include <iostream>
using std::cout;
using std::endl;
#include "GradeBook.h"
GradeBook::GradeBook(string name)
{
	setCourseName(name);
}
void GradeBook::setCourseName(string name)
{
	courseName = name;
}
string GradeBook::getCourseName()
{
	return courseName;
}
void GradeBook::displayMessage()
{
	cout << "Welcome to the gradebook for\n" << getCourseName() << "!" <<
		endl;
}
