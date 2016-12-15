// FILE: ola4.cpp

// AUTHOR: Isha Mudgal

// Instructor: Dr. Yoo

// COURSE: CSCI 1170-002

// DATE Due: 20 October 2016

// DESCRIPTION: Using this system a Robot keeps the distance it has traveled since operation as well as the current position.

// INPUT: data file from robotTravel.txt

// OUTPUT: Print the current location of the Robot, the total accumulated distance traveled since operation after each travel 

//*****************************************************************************//

#include "robot.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{  
	int x, y;        //variables for input location
	char movement;   //variable for next movement command
	Robot  myRobot;  //object of class robot
	ifstream input;  

	//open input file
	input.open("robotTravel.txt");

	//read initial location from data file
	input >> x;
	input >> y;

	myRobot.setRobot(x, y);
	
	//read the movement from data file
	input >> movement;
		while (input) //read till the end of input file
		{   
			myRobot.moveTo(movement);  //call moveTo that Moves robot to next poisition in the input file
			myRobot.displayRobot();    //call displayRobot that displays robot's position and distance travelled
			input >> movement;         //read the next movement from input file
		}
		
		return 0;
}