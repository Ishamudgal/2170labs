// FILE: ola1.cpp

// AUTHOR: Isha Mudgal

// Instructor: Dr. Yoo

// COURSE: CSCI 1170-002

// DATE Due: 13 September 2016

// DESCRIPTION: This program calculates remainder of long numbers

// INPUT: List of numbers from data file longNumber.txt

// OUTPUT: remainder after divinding by 97 for all numbers in the list

// FORMULAS: Remainder = Dividend/Divisor

//*****************************************************************************//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <errno.h>

using namespace std;

int main()

{

	//variable declarations

	int divider = 97; //two digit number

	int remainder;
	
	string data; // input data

	ifstream myIn;	//input file

					//open data file

	myIn.open("longNumber.txt"); //input file name

								 //first data - priming read

	myIn >> data;   //enter data to intialize myIn for the loop


	while (myIn) //not end of file

	{

		cout <<"Dividend is: " << data << endl;
		cout <<"Divider is: " << divider << endl;  //print number and divider

		//process data -- this may be the focus
		string newStr = data.substr(0, 9);      //grabs the first nine digits and stores it in newStr

		int number = atoi((newStr).c_str());    //converts string newStr into integer
		
		remainder = number % divider;           //calculating remainder of the first nine digits
		
		
	    int strLength = data.length() - 9;      //initializing new integer length for loop by subtracting 9 from total length
		int i = 9;    //i is a tracker for position currently at position 9
		while (strLength > 0) //while string is not empty
		{
			if (strLength >= 7) //if 7 or more numbers are left after grabbing nine digits
			{
				remainder = remainder * 10000000;  //multiply remainder with 10000000 to concatinate with rest of the string by addn
				newStr = data.substr(i,7);     // saves the string from i to the next 7 numbers in newStr
				
				remainder = ((remainder + atoi(newStr.c_str())) % divider); //converts newStr to integer, divides it by the divider
				                                                            //and adds it to the remainder
				strLength = strLength - 7; //decrements length by 7 since its already been processed    
				i = i + 7;         //increments position seven places ahead       
			}

			else
			{
				newStr = data.substr(data.length() - strLength);   //newStr is substring starting from 'total length-string 
				                                                   //that has been processed
				remainder = remainder * pow(10, newStr.length());  //remainder is multiplied to 10 to the power of 
				                                                   //the number of digits in newStr
				remainder = ((remainder + atoi(newStr.c_str())) % divider); //converts newStr to integer, divides it by the divider
					                                                        //and adds it to the remainder
				strLength = strLength - 7;  //decrements length by 7 since its already been processed
			}

		}


		cout <<"Remainder is: " << remainder << endl;  //print final remainder
		cout << "_______________________________________________________________" << endl;
		//next data to process

		myIn >> data;       //read next data
	 }
	


	return 0;

}
