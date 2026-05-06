#include<iostream>
using namespace std;

class Doubly_linked_list // Use a class Doubly_linked_list to represent an object
{
public:
	// constructor initialize the nextPtr
	Doubly_linked_list()
	{
		prevPtr = 0; // point to null at the beginning
		nextPtr = 0; // point to null at the beginning
	}
	// get a number
	int GetNum()
	{
		return number;
	}
	// set a number
	void SetNum(int num)
	{
		number = num;
	}
	// get the prev pointer
	Doubly_linked_list* GetPrev()
	{
		return prevPtr;
	}
	// set the prev pointer
	void SetPrev(Doubly_linked_list* ptr)
	{
		prevPtr = ptr;
	}
	// get the next pointer
	Doubly_linked_list* GetNext()
	{
		return nextPtr;
	}
	// set the next pointer
	void SetNext(Doubly_linked_list* ptr)
	{
		nextPtr = ptr;
	}
private:
	int number;
	Doubly_linked_list* prevPtr;
	Doubly_linked_list* nextPtr;
};

Doubly_linked_list* Create_Doubly_linked_list(int num_linkedlist)
{
	Doubly_linked_list* tempPtr;
	Doubly_linked_list* firstPtr = 0;
	Doubly_linked_list* lastPtr = 0;

	int i = 0;
	do
	{
		tempPtr = new Doubly_linked_list;
		tempPtr->SetNum(i);
		if (i == 0)
		{
			firstPtr = tempPtr;
			lastPtr = tempPtr;
			i++;
		}
		else
		{
			tempPtr->SetPrev(lastPtr);
			lastPtr->SetNext(tempPtr);
			lastPtr = tempPtr;
			i++;
		}
	} while (i < num_linkedlist);
	return firstPtr;

}

void Print_Doubly_linked_list(Doubly_linked_list* ptr)
{
	while (ptr != 0)
	{
		cout << "[" << ptr->GetNum() << "]->";
		ptr = ptr->GetNext();
	}
	cout << "Null" << endl;
	cout << endl;
}

void Print_Doubly_linked_list_reversely(Doubly_linked_list* ptr)
{
	Doubly_linked_list* tail = ptr;

	while (tail->GetNext()!=NULL)
	{
		tail = tail->GetNext();
	}

	while (tail != 0)
	{
		cout << "[" << tail->GetNum() << "]->";
		tail = tail->GetPrev();
	}
	cout << "Head" << endl;
	cout << endl;
}

Doubly_linked_list* Insert_node_at_front(Doubly_linked_list* newPtr, Doubly_linked_list* headPtr)
{
	newPtr->SetNext(headPtr);
	headPtr->SetPrev(newPtr);
	return newPtr;
}

Doubly_linked_list* Remove_node_at_front(Doubly_linked_list* headPtr)
{
	Doubly_linked_list* tempPtr = 0;

	headPtr = headPtr->GetNext();
	headPtr->SetPrev(NULL);
	delete tempPtr;
	return headPtr;
}

Doubly_linked_list* Insert_node_at_back(Doubly_linked_list* newPtr, Doubly_linked_list* headPtr)
{
	Doubly_linked_list* tempPtr = 0;

	tempPtr = headPtr;
	while (tempPtr->GetNext() != NULL)
	{
		tempPtr = tempPtr->GetNext();
	}
	tempPtr->SetNext(newPtr);
	newPtr->SetPrev(tempPtr);
	return headPtr;
}

Doubly_linked_list* Remove_node_at_back(Doubly_linked_list* headPtr)
{
	Doubly_linked_list* tempPtr = 0;

	tempPtr = headPtr;
	while (tempPtr->GetNext() != NULL)
	{
		tempPtr = tempPtr->GetNext();
	}
	(tempPtr->GetPrev())->SetNext(NULL);
	delete tempPtr;
	return headPtr;
}

Doubly_linked_list* Insert_node(int num, Doubly_linked_list* newPtr, Doubly_linked_list* headPtr)
{
	Doubly_linked_list* tempPtr = headPtr;
	while (tempPtr->GetNum() != num)
	{
		tempPtr = tempPtr->GetNext();
	}
	newPtr->SetNext(tempPtr);
	newPtr->SetPrev(tempPtr->GetPrev());
	(tempPtr->GetPrev())->SetNext(newPtr);
	tempPtr->SetPrev(newPtr);
	return headPtr;
}

Doubly_linked_list* Remove_node(int num, Doubly_linked_list* headPtr)
{
	Doubly_linked_list* tempPtr = headPtr;
	while (tempPtr->GetNum() != num)
	{
		tempPtr = tempPtr->GetNext();
	}
	(tempPtr->GetPrev())->SetNext(tempPtr->GetNext());
	(tempPtr->GetNext())->SetPrev(tempPtr->GetPrev());
	delete tempPtr;
	return headPtr;
}

int main()
{
	int num;
	Doubly_linked_list* headPtr;
	Doubly_linked_list* newPtr;
	cout << "How many items you want to create? ";
	cin >> num;
	headPtr = Create_Doubly_linked_list(num);
	Print_Doubly_linked_list(headPtr);
	Print_Doubly_linked_list_reversely(headPtr);
	newPtr = new Doubly_linked_list;
	newPtr->SetNum(num);
	cout << "Insert a node at the front of the list:" << endl;
	headPtr = Insert_node_at_front(newPtr, headPtr);
	Print_Doubly_linked_list(headPtr);
	Print_Doubly_linked_list_reversely(headPtr);
	cout << "Remove a node from the front of the list:" << endl;
	headPtr = Remove_node_at_front(headPtr);
	Print_Doubly_linked_list(headPtr);
	Print_Doubly_linked_list_reversely(headPtr);
	newPtr = new Doubly_linked_list;
	newPtr->SetNum(num);
	cout << "Insert a node at the end of the list:" << endl;
	headPtr = Insert_node_at_back(newPtr, headPtr);
	Print_Doubly_linked_list(headPtr);
	Print_Doubly_linked_list_reversely(headPtr);
	cout << "Remove a node from the back of the list:" << endl;
	headPtr = Remove_node_at_back(headPtr);
	Print_Doubly_linked_list(headPtr);
	Print_Doubly_linked_list_reversely(headPtr);
	cout << "Enter the number of a new node: ";
	cin >> num;
	newPtr = new Doubly_linked_list;
	newPtr->SetNum(num);
	cout << "Choose a number to add a node before the node with such value : ";
	cin >> num;
	cout << "Insert a node before the node with the value " << num << " in the list:"
		<< endl;
	headPtr = Insert_node(num, newPtr, headPtr);
	Print_Doubly_linked_list(headPtr);
	Print_Doubly_linked_list_reversely(headPtr);
	cout << "Choose a number to delete a node with such value : ";
	cin >> num;
	cout << "Remove a node with value " << num << " from the list:" << endl;
	headPtr = Remove_node(num, headPtr);
	Print_Doubly_linked_list(headPtr);
	Print_Doubly_linked_list_reversely(headPtr);
	return 0;
}