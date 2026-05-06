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
	Singly_linked_list *GetNext()
	{
		return nextPtr;
	}

	// set the next pointer
	void SetNext(Singly_linked_list *ptr)
	{
		nextPtr = ptr;
	}

private:
	int	n;
	Singly_linked_list	*nextPtr = 0;
};

void Print_Singly_linked_list(Singly_linked_list *ptr)
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
Singly_linked_list *Insert_node_at_front(Singly_linked_list *ptr, Singly_linked_list *firstPtr)
{
	Singly_linked_list *tempPtr = 0;

	tempPtr = firstPtr;
	firstPtr = ptr;
	ptr->SetNext(tempPtr);
	return ptr;
}

// remove a node at the front
Singly_linked_list *Remove_node_at_front(Singly_linked_list *firstPtr)
{
	Singly_linked_list *tempPtr = 0;

	tempPtr = firstPtr;
	firstPtr = firstPtr->GetNext();
	delete tempPtr;
	return firstPtr;
}

// insert a node at the back
Singly_linked_list *Insert_node_at_back(Singly_linked_list *ptr, Singly_linked_list *firstPtr)
{
	Singly_linked_list *prevPtr = 0, *currPtr = 0;

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
Singly_linked_list *Remove_node_at_back(Singly_linked_list *firstPtr)
{
	Singly_linked_list *prevPtr = 0, *currPtr = 0;

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
Singly_linked_list *Insert_node(int n, Singly_linked_list *ptr, Singly_linked_list *firstPtr)
{
	Singly_linked_list *prevPtr = 0, *currPtr = 0;

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
Singly_linked_list *Remove_node(int n, Singly_linked_list *firstPtr)
{
	Singly_linked_list *prevPtr = 0, *currPtr = 0;

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
