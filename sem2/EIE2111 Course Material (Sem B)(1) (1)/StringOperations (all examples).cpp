#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

void copy1(char*, const char*); // prototype 
void copy2( char *, const char * ); // prototype

int main()
{
	// first string example
	char string1[10];
	const char* string2 = "Hello";
	char string3[10];
	char string4[] = "Good Bye";
	copy1(string1, string2); // copy string2 into string1 
	cout << "string1 = " << string1 << endl;
	copy2(string3, string4); // copy string4 into string3 
	cout << "string3 = " << string3 << endl;

	// second string example
	char x[] = "Happy Birthday to You"; // string length 21 
	char y[ 25 ]; 
	char z[ 15 ]; 
	
	cout << endl;
	cout << "Input a string: ";
	cin.getline(y, 25, '\n');
	cout << y << endl;
	strcpy_s( y, x ); // copy contents of x into y 
	cout << "The string in array x is: " << x << "\nThe string in array y is: " << y << '\n';
	// copy first 14 characters of x into z 
	strncpy_s( z, x, 14 ); // does not copy null character 
	cout << "The string in array z is: " << z << endl;
	
	// third string example
	char s1[20] = "Happy "; // length 6 
	char s2[] = "New Year "; // length 9 
	char s3[ 40 ] = ""; 
	
	cout << endl;
	cout << "s1 = " << s1 << "\ns2 = " << s2; 
	strcat_s( s1, s2 ); // concatenate s2 to s1 (length 15) 
	cout << "\n\nAfter strcat(s1, s2):\ns1 = " << s1 << "\ns2 = " << s2;
	
	// concatenate first 6 characters of s1 to s3 
	strncat_s( s3, s1, 6 ); // places '\0' after last character
	cout << "\n\nAfter strncat(s3, s1, 6):\ns1 = " << s1 << "\ns3 = " << s3;
	strcat_s(s3, s1); // concatenate s1 to s3 
	cout << "\n\nAfter strcat(s3, s1):\ns1 = " << s1 << "\ns3 = " << s3 << endl;

	// fourth string example
	const char* ss1 = "Happy New Year"; 
	const char* ss2 = "Happy New Year";
	const char* ss3 = "Happy Holidays";

	cout << endl;
	cout << "ss1 = " << ss1 << "\nss2 = " << ss2 << "\nss3 = " << ss3 
		<< "\n\nstrcmp(ss1, ss2) = " << setw(2) << strcmp(ss1, ss2) 
		<< "\nstrcmp(ss1, ss3) = " << setw(2) << strcmp(ss1, ss3) 
		<< "\nstrcmp(ss3, ss1) = " << setw(2) << strcmp(ss3, ss1);
	cout << "\n\nstrncmp(ss1, ss3, 6) = " << setw(2) << strncmp(ss1, ss3, 6) 
		<< "\nstrncmp(ss1, ss3, 7) = " << setw(2) << strncmp(ss1, ss3, 7) 
		<< "\nstrncmp(ss3, ss1, 7) = " << setw(2) << strncmp(ss3, ss1, 7) << endl;

	// fifth string example
	char sentence[] = "This is a sentence with 7 tokens";
	char* tokenPtr;
	char* nextToken;
	char separators[] = " ,\t\n";

	cout << endl;
	cout << "The string to be tokenized is:\n" << sentence << "\n\nThe tokens are:\n\n";
	
	// begin tokenization of sentence
	tokenPtr = strtok_s(sentence, separators, &nextToken);
	// continue tokenizing sentence until tokenPtr becomes NULL
	while ( tokenPtr != NULL )
	{
		cout << tokenPtr << '\n';
		tokenPtr = strtok_s(NULL, separators, &nextToken); // get next token
	} // end while
	cout << "\nAfter strtok, sentence = " << sentence << endl;


	// sixth string example
	const char* sss1 = "abcdefghijklmnopqrstuvwxyz";
	const char* sss2 = "four";
	const char* sss3 = "Boston";
	
	cout << "The length of \"" << sss1 << "\" is " << strlen(sss1)
		<< "\nThe length of \"" << sss2 << "\" is " << strlen(sss2)
		<< "\nThe length of \"" << sss3 << "\" is " << strlen(sss3)
		<< endl;

	return 0;
}

void copy1(char* s1, const char* s2)
{
	for (int i = 0; (s1[i] = s2[i]) != '\0'; i++);
}

void copy2(char* s1, const char* s2)
{
	for (; (*s1 = *s2) != '\0'; s1++, s2++);
}