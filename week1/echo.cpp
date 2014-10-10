/* Author: Nathan Sosnovske
 *
 * Created: 9/30/2014 
 *
 * Edited: 9/30/2014
 *
 * Files: echo.cpp
 *
 * Overview:
 * 	Prompts for an integer. Does some checking of the integer to ensure that 
 * 	it is in bounds and not rounded off. Does not check for letters or
 * 	symbols.
 *
 * Input:
 * 	The program will prompt for one integer.
 *
 * Output:
 * 	The program will output the integer it is given.
 * 	
 * 	If the program is given a string starting with a letter it will
 * 	return 0.
 *
 * 	If given a float other than x.0, the program will return an error.
 *
 * 	If given an integer out of bounds, the program will return an error.
 *
 *
 */ 

#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	double userInput;

	// Clear prompts to the user require some information gathering
	// about their current system. Let's figure out how big an
	// int is and then use that to calculate min and max values
	int lengthOfInteger = sizeof(int);
	int maxInt = pow(2, ((lengthOfInteger * 8) - 1)) - 1;
	int minInt = -(pow(2, ((lengthOfInteger * 8) - 1)));
	
	//you can use newline (\n) or endl to end lines...
	cout << "If you feed me an integer, I'll do great things!\n";
        cout << "The size of an integer on your system is: " << lengthOfInteger << " bytes." << endl;
        cout << "This means you have a range of " << minInt << " to " << maxInt << "." << endl;
	cout << "Integer please: ";

	//User input gathered here
	cin >> userInput;

	//We can use a bit of logic to figure out whether a floating point number was entered
	if(userInput == static_cast<int>(userInput))
	{
		cout << static_cast<int>(userInput) << endl;
		return 0;
	}
	
	else
	{
		cout << "The number " << userInput << " is not a valid interger on this system!" << endl;
		
		return 1;
	}

}
