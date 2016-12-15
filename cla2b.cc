// FILE:    cla2b.cc
// Purpose:  This program is supposed to determine the average
//           of three test scores.  However, it contains several
//           errors.  Look at the comments in the program to
//           determine the errors.
// Here is our error.  All comments starts with two slashes //
//Author: your name here

#include <iostream>              //the 3 needs to be a pound symbol (#)

using namespace std;

int main() 
{
	// Variable declarations... 
	int test1;             // first score
	int test2;             // second score
	int test3;             // third score
	float average;         // the average of the three scores

	// Read in the three test scores
	cout << "Enter the first test score:  "; 
	cin >> test1;            
	cout << "Enter the second test score:  "; 
	cin >> test2;           
	cout << "Enter the third test score:  "; 
	cin >> test3;           

	// calculate the average of the test scores
	average = (test1 + test2 + test3)/3;  

	// Display the results
	cout << "The average of the three scores is:  "; 
	cout << average;    
	cout << endl; 

	return 0; 
} 
