#ifndef CLOCK_H
#define CLOCk_H
#include <iostream>  // this is needed because of
using namespace std; // the "string" data type below.

//The Clock class SPECIFICATION starts here. 
class Clock 
{ 
  private:
    //declarations of data members that are private
    int hour;          //an hour in the range 1 - 12
    int minute;        //a minute in the range 0 - 59
    int second;        //a second in the range 0 - 59
    string meridian;   //is the time AM or PM

public: 
    // publically accessible methods,i.e., public interface 

    //Set the clock to the specified time 
    void setClock (int h, int m, int s, string mer);
    //Display the time in standard notation
    void displayStandard();
    //Display the time in military notation
    void displayMilitary();
};

#endif