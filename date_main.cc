#include <iostream>
#include "date.h"
using namespace std;

int main()
{
	//Declare two Clock objects
	date myDate, gradDate;

	
	myDate.setDate(12, 13, 1996);

	
	gradDate.setDate(5, 31, 2018);

	
	cout << "Birthday is: ";
		myDate.displayDate();
		cout << endl;
	
		cout << "Tentative graduation date is: ";
		gradDate.displayDate();
		cout << endl;
		cin.get();
	return 0;
}