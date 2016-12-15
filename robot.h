#ifndef ROBOT_H 
#define ROBOT_H
#include <iostream>
using namespace std;

class Robot
{
	
private:
	int xloc, yloc;  //variables for location 
	char ch;         //variable for input command
	int distTrav;    //variable to keep track and print distance travelled
	
	
public:

void setRobot(int xLocation,int yLocation); //set robots initial position from input file

void displayRobot();                       //display robot's position and distance travelled

void moveTo(char pos);                     //move to next poisition

};


#endif