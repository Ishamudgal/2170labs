// FILE: ola6.cpp

// AUTHOR: Isha Mudgal

// Instructor: Dr. Yoo

// COURSE: CSCI 1170-002

// DATE Due: 17 November 2016

// DESCRIPTION: This program verifies if braces in an expression are balanced.

// INPUT: data from data file Robotinput.txt

// OUTPUT: The program prints the first error message with line number.

// FORMULAS: push and pop in stack using STL


#include <iostream>
#include <fstream>
#include <stack>
#include <string>


using namespace std;

int main()
{
  stack<char>sstack;   //declare stack

  //variables used in the program
  ifstream input;

  char symbol;
  
  bool balanced = true;  //bool balance is used as a control for loop and to verify is braces are balanced
  
  string line;
  
  int pos = 1, length;   //pos is set to the position of first line

  input.open("Robotinput.txt");
  getline(input, line);  //get first line

  cout << pos << "   " << line << endl;

  while (input && balanced)   //loop until end of input or first error is found
  {   
	  length = line.length();
	  
	  for (int i = 0; i < length; i++)     //loop until the end of the current line
	  {
		  symbol = line.at(i);             //get characters one by one from the entire string

		  if (symbol == '{' || symbol == '(' || symbol == '[')  //if braces are open then push onto stack
		  {
			  sstack.push(symbol);
		  }

		  else if (symbol == '}' || symbol == ')' || symbol == ']') //if braces are closing
		  {
			  if (!sstack.empty())                           //check if stack is empty
			  {
				  //if not check if closing bracket matches opening bracket and pop if its true
				  if (sstack.top() == '{' && symbol == '}')  
				 	  sstack.pop();
				  
				  else if (sstack.top() == '[' && symbol == ']')
					  sstack.pop();

				  else if (sstack.top() == '(' && symbol == ')')
					  sstack.pop();

				  //if they are not matching print error message with line number
				  else
				  {   
					  cout << "Syntax error: Braces are not balanced at line: " << pos << endl;
					  balanced = false;
				  }
			   }
			  else   //stack is empty but there are closed braces left to be matched so print balanced is false
				  balanced = false;
		   }

	  }
	  
	  pos++;  //keeps track of the line number
	 
	  getline(input, line);

	 cout << pos << "   " << line << endl;
  }
	
	
  if (balanced && sstack.empty())                 //if balanced is true AND stack is empty
	  cout << "The braces in the program are balanced." << endl;  //braces are matched
  
  else if (!sstack.empty() || !balanced)          //if stack is not empty OR balanced is false
	  cout << "The braces in the program are unbalanced" << endl; //braces are not matched
	
	return 0;
}  