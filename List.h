// FILE: List.h

// AUTHOR: Isha Mudgal

// Instructor: Dr. Yoo

// COURSE: CSCI 1170-002

// DATE Due: 3 November 2016

// DESCRIPTION: This program determines how long it takes a robot to get out of the grid or how the robot loops around.

// INPUT: Program expects input from stdin by prompting the user for choice of operation and appropriate value for that operation

// OUTPUT: The program prints the list or node value from the removed node  onto the stdout:

// FORMULAS: --


typedef int ListItemType;

class List
{
public:
	// constructors and destructor:
	List();                  // default constructor

							 // list operations:
	bool isEmpty() const;   //is list empty
	void insertFront(ListItemType newItem);  //insert a new node at the front

	void insertBack(ListItemType newItem);   //insert a new node at the back
	void insertOrdered(ListItemType newItem);  //insert a new node in ascending order

	void removeFront(ListItemType& dataItem);//remove a node from the front 
	void removeBack(ListItemType& dataItem); //remove a node from the end 

	void printList();  //print linked list in a form of   list ?10 ? 5

private:
	struct ListNode // a node on the list
	{
		ListItemType item; // a data item on the list
		ListNode *next;    // pointer to next node
	}; // end struct

	ListNode *head; // pointer to linked list of items

}; // end class
