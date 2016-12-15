// FILE: List.cc

// AUTHOR: Isha Mudgal

// Instructor: Dr. Yoo

// COURSE: CSCI 1170-002

// DATE Due: 3 november 2016

// DESCRIPTION: Creating and maintaining dynamic data structure requires dynamic memory allocation

// INPUT: data from standard input

// OUTPUT: list of nodes

// FORMULAS: ***
#include "List.h"
#include <cstdlib>
#include <iostream>
using namespace std;

typedef int ListItemType;

List::List()
{
	head = NULL;	//initialize to NULL
}

bool List::isEmpty() const
{
	return (head == NULL);	//returns true if list is empty
}

void List::insertFront(ListItemType newItem)
{
	ListNode *newNode;		
	newNode = new ListNode;		//create new node
	newNode->item = newItem;		//store data 
	
	if (isEmpty())	//if list is empty
		head = newNode;		//head and newNode point to same node
	else
	{
		newNode->next = head; //newNode points to what head is pointing to
		head = newNode;	//point head to new node
	}
}

void List::insertBack(ListItemType newItem)
{
	ListNode *newNode;
	newNode = new ListNode;	//create new node
	newNode->item = newItem;	//store data

	ListNode *q;	//variable used for traversing list
	q = head;

	//traverse
	while (q->next != NULL)
	{
		q = q->next;	//until last item in list is found
	}
	q->next = newNode;		//point last item in list to new node
	newNode->next = NULL;		//new node next is NULL
	
}

void List::insertOrdered(ListItemType newItem)
{
	ListNode *newNode;
	newNode = new ListNode;	//create new node
	newNode->item = newItem;	//store data

	ListNode *curr, *prev;	//variable used for traversing list
	curr = head; //current pointer
	prev = curr; //previous follows one place behind

	//if list is empty, make head point to the new node
	if (isEmpty())	
		head = newNode;

	//if new item is smaller than the 1st element
	else if (newItem < head->item)
	{
		newNode->next = head;		//insert at the front
		head = newNode;
	}
	
	//if there is 1 node in the list
	else if (curr->next == NULL)		
	{
		//insert after the first element
		newNode->next = curr->next;
		curr->next = newNode;		
	}
	else
	{
		//traverse until current's item is greater than newNode's item
		while (curr->item <= newItem && curr->next != NULL)
		{
			prev = curr;
			curr = curr->next;
		}

		//if we traversed until the last node
		if (curr->next == NULL && curr->item < newItem)
		{
			//make the new node the last node
			newNode->next = NULL;
			curr->next = newNode;
		}

		//if not traversed until the last
		else
		{
			//insert between prev and current
			newNode->next = prev->next;
			prev->next = newNode;
		}
	}
}

void List::removeFront(ListItemType& dataItem)
{
	head = head->next;
}

void List::removeBack(ListItemType& dataItem)
{
	ListNode *newNode;	//variable used for traversing list
	newNode = head;

	//traverse until second last node in list
	while (newNode->next->next != NULL)
	{
		newNode = newNode->next;	
	}

	// newNode pointer is null
	newNode->next = NULL;
}

void List::printList()
{
	ListNode *p;	//variable used for traversing list
	p = head;
    cout<<"List -> ";
	//traverse	until the end is found
	while (p->next != NULL)
	{
		cout << p->item << " -> ";	//print node contents
		p = p->next;	
	}
	cout<<p->item;
	cout << endl;
}