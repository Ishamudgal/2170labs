#ifndef DATE_H
#define DATE_H
#include <iostream>  
using namespace std; 

					 
class date
{
private:
	
	int month;        
	int day;        
	int year;        
	

public:
	
	void setDate(int m, int d, int y);

	void displayDate();

};	
#endif