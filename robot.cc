#include "robot.h"
#include <iostream>


using namespace std;

void Robot::setRobot(int xlocation, int ylocation)   //set robots initial position from input file
{
	xloc = xlocation;   //set xloc to the value passed by client file
	yloc = ylocation;   //set yloc to the value passed by client file
	distTrav = 0;       //set distance travelled in the beginning to 0(no distance travelled)
	//print position of robot in the beginning
	cout << "Initial position of robot:" << xloc << " " << yloc << endl << endl; 
}

void Robot::displayRobot()  //display robot's position and distance travelled
{
	cout << "Position after movement is: " << xloc << " " << yloc << endl;
	cout << "Distance travelled after the movement is: " << distTrav << endl << endl;
}

void Robot::moveTo(char pos)  //Move to next poisition as passed from the client function
{
	ch = pos;                     //set equal to the input position passed from the client file

	if (ch == 'N')                //if position is North
	{
		xloc = xloc - 1;          //subtract one from row
		distTrav = distTrav + 1;  //add one to distance
	}

	else if (ch == 'S')          //if position is South
	{
		xloc = xloc + 1;         //add one to row
		distTrav = distTrav + 1; //addone to distance
	}

	else if (ch == 'E')         //if position is East
	{
		yloc = yloc + 2;        //add two to column
		distTrav = distTrav + 2;//add two to distance
	}

	else                        //if position is West
	{
		yloc = yloc - 2;        //subtract two from column
		distTrav = distTrav + 2;//add two to distance
	}
}