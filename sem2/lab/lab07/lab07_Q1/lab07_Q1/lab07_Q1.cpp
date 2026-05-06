#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int temp,a[6];

	if (argc > 6)
		cout << "You cannot input more than 5 integers!";
	else
	{
		for (int i = 1; i <= (argc - 1); i = i + 1)
			a[i] = atoi(argv[i]);

		for (int i = 1; i <= argc; i = i + 1)
		{ 
			for (int j = 1; j <= (argc-1); j = j + 1)
			{
				if (a[j] < a[j+1])
				{
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
		
	for (int i = 1; i <= (argc-1); i = i + 1)
		cout << a[i] << " ";

	}
	return 0;
}


