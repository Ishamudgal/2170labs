// FILE: ola3.cpp

// AUTHOR: Isha Mudgal

// Instructor: Dr. Yoo

// COURSE: CSCI 1170-002

// DATE Due: 6 October 2016

// DESCRIPTION: This program determines how long it takes a robot to get out of the grid or how the robot loops around.

// INPUT: data from data file robotmotion.txt

// OUTPUT: robot path

// FORMULAS: go up for north, down for south, right for east and left for west

//*****************************************************************************//
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <fstream>

using namespace std;

//finds the path of the robot and prints it out
void robotMotion(char grid[10][10], int row, int col, int start);

//finds the next position from current position and returns the value to function robotMotion
int nextpos(char grid[10][10],int currow, int curcol, char curpos);

int main()
{
	ifstream myIn;        //file input variable
	int row, col, start;  //number of rows, columns and the starting column
	char grid[10][10];    //grid of directions for the robot
	
	myIn.open("robotmotion.txt");  //open file robotmotion.txt

	myIn >> row >> col >> start;   //enter value of row column and starting point

	while (myIn)                   //while the file input continues
	{
		
		while (row != 0)           //while row is assinged a value of zero(end of file)
		{
			for (int i = 0; i < row; i++)       //iterating through rows
			{
				for (int j = 0; j < col;j++)    //iterating through columns
				{
					myIn >> grid[i][j];         //enter elements in the grid
					cout << grid[i][j];         //print elements at the same time
				} cout<< endl;
			}
			cout << endl;
			robotMotion(grid, row, col, start); //call funtion robotMotion to find the path and print it
			myIn >> row >> col >> start;        //enter row column and starting point for next array
		} 
	}

	

	return 0;
}

//finds the path of the robot and prints it out
void robotMotion(char grid[10][10], int row, int col, int start)
{
	
	
	cout << "number of rows = " << row << " column= " << col << " starting column= " << start << endl;
	int currow = 0;                        //current row is zero
	int curcol = start;                    //current column is the starting point                                                             

	char curpos = grid[currow][curcol];    //current position is the current row and column


	//while the robot is still in the bounds of the array and next position is not already one(ie, psition is repeating)
	while ((currow != -1) && (curcol != -1))
	{
		if (nextpos(grid, currow, curcol, curpos) != '1')
		{
			if (curpos == 'N')                      //North means UP
			{
				currow = currow - 1;               //move one row up
				curpos = grid[currow][curcol];
				grid[currow + 1][curcol] = '1';          //set this position in map to 1

			}

			else if (curpos == 'S')                //South means DOWN
			{
				currow = currow + 1;               //move one row down
				curpos = grid[currow][curcol];
				grid[currow - 1][curcol] = '1';          //set this position in map to 1

			}

			else if (curpos == 'E')                //East means right
			{
				curcol = curcol + 1;               //move one column right
				curpos = grid[currow][curcol];
				grid[currow][curcol - 1] = '1';          //set this position in map to 1
			}

			else
			{                                      //West means left
				curcol = curcol - 1;               //move one column left
				curpos = grid[currow][curcol];
				grid[currow][curcol + 1] = '1';          //set this position in map to 1
			}

		}
		else if (nextpos(grid, currow, curcol, curpos) == '1')
		{break;}
	}
		
	if ( nextpos(grid, currow, curcol, curpos)=='1')   //if path wasnt found because of a loop
		cout << "Robot stuck in a loop!" << endl;
	else
		cout <<  "Robot found a path!" << endl;     //if path was found and robot went out of bounds
	
	for (int i = 0;i < row;i++)                     //print out path map
	{
		for (int j = 0;j < col;j++)
		{
			if (grid[i][j] != '1')
			{
				grid[i][j] = '0';
				
			}cout << grid[i][j];
			
		} cout << endl;
	}          
	

	
	cout << endl;
	return;
}

//finds the next position from current position and returns the value to function robotMotion
int nextpos(char grid[10][10], int currow,int  curcol, char curpos)
{
	if (curpos == 'N')                     //North means UP
	{
		currow = currow - 1;               //move one row up
		return grid[currow][curcol];        //return this position as next
	}

	else if (curpos == 'S')                //South means DOWN
	{
		currow = currow + 1;               //move one row down
		return grid[currow][curcol];           //return this position as next
	}

	else if (curpos == 'E')                //East means right
	{
		curcol = curcol + 1;               //move one column right
		return grid[currow][curcol];           //return this position as next
	}

	else
	{                                      //West means left
		curcol = curcol - 1;               //move one column left
		return grid[currow][curcol];          //return this position as next
	}

}