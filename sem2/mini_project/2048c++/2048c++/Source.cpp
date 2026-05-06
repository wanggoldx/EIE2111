#include<iostream>
#include<iomanip>
#include<cstdlib> 
using namespace std;

int board[4][4];

void generatetwo();

void newgame()
{
	for (int x = 0; x <= 3; x++)
	{
		for (int y = 0; y <= 3; y++)
		{
			board[x][y] = 0;
		}
	}
	generatetwo();
}

void printUI()
{
	for (int x = 0; x <= 3; x++)
	{
		for (int y = 0; y <= 3; y++)
		{
			if (board[x][y] == 0)
				cout << setw(4) << ".";
			else
				cout << setw(4) << board[x][y] ;
		}
		cout << endl;
	}
}

void generatetwo()
{
	srand(time(NULL));
	int x = rand() % 4;
	int y = rand() % 4;
	while (board[x][y] != 0)
	{
		x = rand() % 4;
		y = rand() % 4;
	}
	board[x][y] = 2;
}

void moveleft()
{
	int no;
	do{
		no = 0;
		for (int x = 0; x <= 3; x = x + 1)
		{
			for (int y = 0; y <= 3; y = y + 1)
			{
				if (((board[x][y - 1] == 0) || (board[x][y - 1] == board[x][y])) && (y != 0)&&(board[x][y]))
				{
					board[x][y - 1] = board[x][y - 1] + board[x][y];
					board[x][y] = 0;
					no = 1;
				}		
			}
		}
	} while (no);
		
	generatetwo();
}

void moveright()
{

}

void moveup()
{

}

void movedown()
{

}

int main()
{
	char input;

	newgame();
	printUI();
	cin >> input;
	while (input!='q')
	{
		if (input == 'a')
		{
			moveleft();
		}
		else if (input == 'w')
		{
			moveup();
		}
		else if (input == 's')
		{
			movedown();
		}
		else if (input == 'd')
		{
			moveright();
		}
		printUI();
		cin >> input;
	}
	

}

//dirline(1,0,-1,0)
//dircolumn (0,1,0,-1)
//s0,d1,w2,a3
int no;
do {
	no = 0;
	for (int x = 0; x <= 3; x = x + 1)
	{
		for (int y = 0; y <= 3; y = y + 1)
		{
			if ((x<0 ||y-1<0 ||x>=4||y-1>=4 ||(board[x][y]!=board[x][y-1]&&board[x][y-1]!=0)&& (board[x][y]))
			{
				board[x][y - 1] = board[x][y - 1] + board[x][y];
				board[x][y] = 0;
				no = 1;
			}
		}
	}
} while (no);

(x > 0 || y - 1 > 0 || x <= 4 || y - 1 <= 4 || (board[x][y] == board[x][y - 1] && board[x][y - 1] == 0)