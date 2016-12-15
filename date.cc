#include "date.h"

void date::setDate(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}

void date::displayDate()
{
	cout << month<< '/' << day << '/' << year << endl;
}


