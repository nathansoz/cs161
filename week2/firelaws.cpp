/* Author: Nathan Sosnovske
 *
 * Created: 10/9/2014
 *
 * Edited: 10/9/2014
 *
 * Files: firelaws.cpp
 *
 * Overview:
 *      Prompts for room capacity and number of guests. Does calculations
 *      to ensure the user is meeting the fire code.
 *
 * Input:
 *      The program will prompt for two integers, one at a time.
 *
 * Output:
 *      The program will calculate and output instructions to as how 
 *      many guests (if any) the user needs to get rid of (or invite).
 *      The program will loop until it gets valid input.
 *
 *
 */

#include <iostream>

using namespace std;

int main()
{
	int maxCapacity = 0;
	int numGuests = -1;

	while(maxCapacity < 1 || numGuests < 0)
	{
		cout << "Please enter the room capacity: ";
		cin >> maxCapacity;
	
		cout << "Please enter the number of guests: ";
		cin >> numGuests;

		if(maxCapacity < 1)
		{
			cout << "A room cannot have zero or negative capacity!" << endl;
		}
		
		if(numGuests < 0)
		{
			cout << "You cannot have negative guests!" << endl;
		}
	}

	if(maxCapacity < numGuests)
	{
		int overflow = numGuests - maxCapacity;

		if(overflow == 1)
		{
			cout << "You have too many guests. Please get rid of " <<
				overflow << " person." << endl;
			
		}
		else
		{
			cout << "You have too many guests. Please get rid of " <<
				overflow << " people." << endl;
		}
	}

	if(maxCapacity >= numGuests)
	{
		int underflow = maxCapacity - numGuests;

		if(underflow == 1)
		{
			cout << "You can invite " << underflow << " more guest." << endl;
		}
		else
		{
			cout << "You can invite " << underflow << " more guests." << endl;
		}

	}
	

	return 0;
}
