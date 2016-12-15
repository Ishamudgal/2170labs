// FILE: ola2.cpp

// AUTHOR: Isha Mudgal

// Instructor: Dr. Yoo

// COURSE: CSCI 1170-002

// DATE Due: 27 September 2016

// DESCRIPTION: This program inputs data, creates an 2D array, calculates the minimum and maximum data
// and finds the lowest elevation path and prints it

// INPUT: numbers from data file mapdata.txt

// OUTPUT: array, minimum number, max number, lowest elevation path

// FORMULAS: -

//*****************************************************************************//
#include <iostream>
#include <time.h> //for time function
#include <stdlib.h> //for random function
#include <fstream> //for input file
#include <iomanip>
#include <stdio.h>

using namespace std;

void mapData(int Map[100][100], int rowCount, int colCount);
//read data from given file into a 2D array

int findMin(int Map[100][100], int rowCount, int colCount);
//return the minimum value in the map

int findMax(int Map[100][100], int rowCount, int colCount); 	    //return the max value in the map

void drawMap(int Map[100][100], int rowCount, int colCount);
//draw(print the 2D array) this map 

int drawLowestElevPath(int Map[100][100], int rowCount, int colCount, int startingRow);
//finds the lowest path and prints it


int main()
{
	int Map[100][100];  //array map initialised to contain 100 x 100 elements
	
	int rowCount=100, colCount=100;    //row = 100, column=100
	int min, max, startingRow;     //minimum, maximum, and user input 'starting row'

	mapData(Map, rowCount, colCount);  //calls function mapData that reads input values from file into array map

	cout <<setw(15)<<"MAP"<< endl;

	drawMap(Map, rowCount,colCount);   //calls function drawMap that print out values in array Map

	min = findMin(Map, rowCount, colCount); //calls function findMin and assigns return value to variable min
	max = findMax(Map, rowCount, colCount); //calls function findMax and assigns return value to variable max

	cout <<"Minimum value in the map is : "<< min << endl;    //print out minimum and maximum value
	cout <<"Maximum value in the map is : "<< max << endl;

	cout << "Enter starting point (row number): ";
	cin >> startingRow;                        //user inputs starting row

	drawLowestElevPath(Map,rowCount,colCount,startingRow);    //calls function drawLowestElevPath that finds and prints greedy 
	                                                          //path
	cin.get();

	return 0;
}

//FUNCTION DEFINITIONS

//Function mapData reads data from given file into a 2D array Map
void mapData(int Map[100][100], int rowCount, int colCount)
{
	ifstream myIn;        //variable to read inout from file
	
	myIn.open("mapdata.txt");   //opens text file
	

	for (int i= 0; i<rowCount; i++)         //iterating through row of array Map
	{
		for (int j = 0; j <colCount; j++)    //iterating through Column of array Map
			myIn >> Map[i][j];               //inputs data from file into array Map
	}
	return;
}

//Function drawMap prints out elements of array Map
void drawMap(int Map[100][100], int rowCount, int colCount)
{
	    
	for (int i = 0; i<rowCount; i++)     //iterating through row of array Map
	{
		for (int j = 0; j<colCount; j++) //iterating through Column of array Map
		{
			cout << Map[i][j]<<" ";      //prints out data from array Map
		}
		cout<<endl;
		
	}
	cout << endl;
	return;
}

//Function findMin finds the smallest element in the array Map
int findMin(int Map[100][100], int rowCount, int colCount)
{
	int min = Map[0][0];       //variable minimum initialized to the first element of array Map

	for (int i = 1; i<rowCount; i++)   //iterating through row of array Map
	{
		for (int j = 0; j<colCount; j++)  //iterating through Column of array Map
		{
			if (min>Map[i][j])             //if value of minimum is greater than next value, it
				min = Map[i][j];           //is reassigned that smaller value
		}
	}
	return min;  //returns the smallest value to main function
}

//Function findMax finds the greatest element in the array Map
int findMax(int Map[100][100], int rowCount, int colCount)
{
	int max = Map[0][0];       //variable maximum initialized to the first element of array Map

	for (int i = 1; i<rowCount; i++)     //iterating through row of array Map
	{
		for (int j = 0; j<colCount; j++)  //iterating through Column of array Map
		{
			if (max<Map[i][j])        //if value of maximum is smaller than next value, i
				max = Map[i][j];      //is reassigned that smaller value
		}
	}
	return max;  //returns the greatest value to main function
}

int drawLowestElevPath(int Map[100][100], int rowCount, int colCount, int startingRow)
{
	
	int path[100][100];     //new array path stores greedy path values
	int currRow = startingRow, currCol = 0;  //currRow tracks row and is assigned to user input
	                                         //currCol tracks column and is assigned to first column
	path[currRow][currCol] = 1;  //first element in the path
	
	for(currCol=0;currCol<colCount;currCol++) //moving from first column to the last
	{
		
		if (currRow == 0) //if current element is in top row or row zero
		{
			
			
			if (abs(Map[currRow][currCol + 1] - Map[currRow][currCol]) > abs(Map[currRow + 1][currCol + 1] - Map[currRow][currCol]))
			{
				path[currRow + 1][currCol + 1] = 1;     //if difference of lower element is less than forward element
				                                        //assign 1 to element in the same row and column of array PATH
				currRow = currRow + 1;  //increment row by one    
			}
			else
				path[currRow][currCol + 1] = 1;          //else assign 1 to the index of forward element
				//row remains same
		}
			    
		

		
		else if (currRow == 99)  //if current element is in the last row
		{
			
			
			if (abs(Map[currRow][currCol + 1] - Map[currRow][currCol]) > abs(Map[currRow - 1][currCol + 1] - Map[currRow][currCol]))
			{
				path[currRow - 1][currCol + 1] = 1; //if difference of upper element is less than forward element
				                                    //assign 1 to element in the same row and column of array PATH
				currRow = currRow - 1;    //decrement row by one
			}
			else
				path[currRow][currCol + 1] = 1;  //else assign 1 to the index of forward element
			    //row remains same
		}

		else   //current element is not in the first or the last row
		{   int coin, num1, num2, num3; //variable coin is used for a coin toss
		    
			num1 = abs(Map[currRow - 1][ currCol + 1] - Map[currRow][currCol]); //num1 stores diff of current element
			                                                                    //and upper element
			num2 = abs(Map[currRow][ currCol + 1] - Map[currRow][currCol]);     //num2 stores diff of current element
			                                                                    //and middle element
			num3 = abs(Map[currRow + 1][ currCol + 1] - Map[currRow][currCol]); //num3 stores diff of current element
			                                                                    //and lower element
			if (num1 < num2 && num1 < num3) //absolute value of num 1 is the smallest
			{
				path[currRow - 1][currCol + 1] = 1; //assign 1 to element in the same row and column of array PATH
				currRow = currRow - 1;  //decrement row by one
			}

			else if (num2 < num1 && num2 < num3)  //absolute value of num2 is smallest
				path[currRow][currCol + 1] = 1;     //assign 1 to element in the same row and column of array PATH
			    //row remains same

			else if (num3 < num1 && num3 < num2) //absolute value of row 3 is smallest
			{
				path[currRow + 1][currCol + 1] = 1;  //assign 1 to element in the same row and column of array PATH
				currRow = currRow + 1;   //increment row by one
			}

			else if ((num1 == num2) || (num3 == num2)) //middle row element is equal to either top or bottom row element
				path[currRow][currCol + 1] = 1;      //assign 1 to element in the same row and column of array PATH
			    //row remains same

			else //absolute value of num1 and num3 is equal
			{
				srand(time(0));   //new seed
				coin = rand() % 2;  //generating random value from 0 or 1
				if (coin = 0)  //choose lower row
				{
					path[currRow - 1][currCol + 1] = 1; //assign 1 to element in the same row and column of array PATH
					currRow = currRow - 1; //decrement row by one 
				}
				else  //choose upper row
				{
					path[currRow + 1][currCol + 1] = 1; //assign 1 to element in the same row and column of array PATH
					currRow = currRow + 1; //increment row by one
				}
			}

		}
	}

	for (int i = 0; i < 100;i++) //iterating through row of path
	{
		for (int j = 0;j < 100;j++)  //iterating through column of path
		{
			if (path[i][j] != 1)  //changes all elements of path that are not one to zero
				path[i][j] = 0;
		}
	}
	
	drawMap(path, 100, 100);  //call drawMap to print path

	cin.get();
	return 0;
}



