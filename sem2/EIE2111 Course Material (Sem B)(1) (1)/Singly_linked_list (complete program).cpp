#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Singly_linked_list
{
public:
	// constructor initialize the nextPtr
	Singly_linked_list()
	{
		nextPtr = 0; // point to null at the beginning
	}

	// get a number
	int GetNum()
	{
		return n;
	}

	// set a number
	void SetNum(int num)
	{
		n = num;
	}

	// get the next pointer
	Singly_linked_list* GetNext()
	{
		return nextPtr;
	}

	// set the next pointer
	void SetNext(Singly_linked_list* ptr)
	{
		nextPtr = ptr;
	}

private:
	int	n;
	Singly_linked_list* nextPtr = 0;
};

void Print_Singly_linked_list(Singly_linked_list* ptr)
{
	while (ptr != 0)
	{
		cout << "[" << ptr->GetNum() << "]->";
		ptr = ptr->GetNext();
	}
	cout << "Null" << endl;
	cout << endl;
}

// insert a node at the front
Singly_linked_list* Insert_node_at_front(Singly_linked_list* ptr, Singly_linked_list* firstPtr)
{
	Singly_linked_list* tempPtr = 0;

	tempPtr = firstPtr;
	firstPtr = ptr;
	ptr->SetNext(tempPtr);
	return ptr;
}

// remove a node at the front
Singly_linked_list* Remove_node_at_front(Singly_linked_list* firstPtr)
{
	Singly_linked_list* tempPtr = 0;

	tempPtr = firstPtr;
	firstPtr = firstPtr->GetNext();
	delete tempPtr;
	return firstPtr;
}

// insert a node at the back
Singly_linked_list* Insert_node_at_back(Singly_linked_list* ptr, Singly_linked_list* firstPtr)
{
	Singly_linked_list* prevPtr = 0, * currPtr = 0;

	currPtr = firstPtr;
	while (currPtr != 0)
	{
		prevPtr = currPtr;
		currPtr = currPtr->GetNext();
	}
	prevPtr->SetNext(ptr);
	return firstPtr;
}

// remove a node at the back
Singly_linked_list* Remove_node_at_back(Singly_linked_list* firstPtr)
{
	Singly_linked_list* prevPtr = 0, * currPtr = 0;

	currPtr = firstPtr;
	while (currPtr->GetNext() != 0)
	{
		prevPtr = currPtr;
		currPtr = currPtr->GetNext();
	}
	prevPtr->SetNext(0);
	delete currPtr;
	return firstPtr;
}

// insert a node after the node with the given value
Singly_linked_list* Insert_node(int n, Singly_linked_list* ptr, Singly_linked_list* firstPtr)
{
	Singly_linked_list* prevPtr = 0, * currPtr = 0;

	currPtr = firstPtr;
	while (currPtr->GetNum() != n)
	{
		prevPtr = currPtr;
		currPtr = currPtr->GetNext();
	}
	prevPtr->SetNext(ptr);
	ptr->SetNext(currPtr);
	return firstPtr;
}

// remove a node with the given value
Singly_linked_list* Remove_node(int n, Singly_linked_list* firstPtr)
{
	Singly_linked_list* prevPtr = 0, * currPtr = 0;

	currPtr = firstPtr;
	while (currPtr->GetNum() != n)
	{
		prevPtr = currPtr;
		currPtr = currPtr->GetNext();
	}
	prevPtr->SetNext(currPtr->GetNext());
	delete currPtr;
	return firstPtr;
}

// create a singly linked list
Singly_linked_list* Create_Singly_linked_list(int n)
{
	Singly_linked_list
		* tempPtr = 0, * firstPtr = 0, * lastPtr = 0;
		int i = 0;
	do
	{
		tempPtr = new Singly_linked_list;
		tempPtr->SetNum(i);
		if (i == 0)
		{
			firstPtr = tempPtr;
			lastPtr = tempPtr;
			i++;
		}
		else
		{
			lastPtr->SetNext(tempPtr);
			lastPtr = tempPtr;
			i++;
		}
	} while (i < n);
	return firstPtr;
}

int main()
{
	int num;
	Singly_linked_list* headPtr = 0;
	Singly_linked_list* newPtr = 0;
	
	cout << "How many items you want to create? ";
	cin >> num;
	headPtr = Create_Singly_linked_list(num);
	Print_Singly_linked_list(headPtr);
	newPtr = new Singly_linked_list;
	newPtr->SetNum(num);
	
	cout << "Insert a node at the front of the list:" << endl;
	headPtr = Insert_node_at_front(newPtr, headPtr);
	Print_Singly_linked_list(headPtr);
	
	cout << "Remove a node from the front of the list:" << endl;
	headPtr = Remove_node_at_front(headPtr);
	Print_Singly_linked_list(headPtr);
	
	newPtr = new Singly_linked_list;
	newPtr->SetNum(num);
	cout << "Insert a node at the end of the list:" << endl;
	headPtr = Insert_node_at_back(newPtr, headPtr);
	Print_Singly_linked_list(headPtr);
	
	cout << "Remove a node from the back of the list:" << endl;
	headPtr = Remove_node_at_back(headPtr);
	Print_Singly_linked_list(headPtr);
	
	cout << "Enter the number of a new node: ";
	cin >> num;
	newPtr = new Singly_linked_list;
	newPtr->SetNum(num);
	cout << "Choose a number to add a node before the node with such value : ";
	cin >> num;
	cout << "Insert a node before the node with the value " << num << " in the list : " << endl;
	headPtr = Insert_node(num, newPtr, headPtr);
	Print_Singly_linked_list(headPtr);

	cout << "Choose a number to delete a node with such value : ";
	cin >> num;
	cout << "Remove a node with value " << num << " from the list:" << endl;
	headPtr = Remove_node(num, headPtr);
	Print_Singly_linked_list(headPtr);

	return 0;
}