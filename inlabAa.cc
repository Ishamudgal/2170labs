// This program reads a list of numbers from the command line and
// determines whether or not they are in descending order.
//
// usage:
//    inlabAa  number [number ...]
// i.e.,
//    ./a.out  13 12 8 7 5 4
// tells the program there will be 6 numbers in the list and the
// list consists of 13,12,8,7,5,4
// The program (when corrected) should report that the list
// is in descending order

// To get started, copy this file to your local directory, i.e.,
// cp $CLA/inlab2a.cc  inlab2a.cc
// Now compile the program. There should be no syntax errors.
// Now add cout statements that will allow you to locate 
// and correct logic errors.

// Please note there are errors dealing with the value of argc being
// used and which argv array item should be referenced.
// You need not fully understand what these are nor how they work at this time.

// ---------------------------------------------------------------

#include <cstdlib>
#include <iostream>
using namespace std;

const int SIZE = 10;                // size of the array

int main(int argc, char *argv[])
{
    int i;                // loop counter
    bool descending=false;      // true if the list is in descending order
    int list[SIZE];       // array to hold the list
    int listSize;          // the number of integers in the list

    // Set listSize to the number of integers on the command line,
    // or the size of the array, whichever is smaller.
    if ( argc-1 > SIZE )
        listSize = SIZE;
    else
        listSize = argc - 1;


    // convert the numbers on the command line from ASCII to
    // integer and store them in the list.
    for (i = 1; i < listSize; i++)
        list[i] = atoi(argv[i+1]);   // the atoi comes from the cstdlib library.
                                     // The atoi takes an alphanumeric string value and
                                     // converts it to an integer.  no error here :-)


    // Check each pair of adjacent integers to see if the one with
    // the lower index has a lower value.
    for (i = 0, descending = true; i < listSize ; ++i)
       { if(list[i] > list[i+1])
		    descending=true;
		   
		 else 
            descending=false;			 
	   }

    // Inform the user of the result
    if (descending)
        cout << "The list is in descending order.\n";
    else
        cout << "The list is NOT in descending order.\n";

    return 0;
}