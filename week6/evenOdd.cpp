/* Author: Nathan Sosnovske
 *
 * Created: 11/9/2014
 *
 * Edited: 11/9/2014
 *
 * Files: evenOdd.cpp
 *
 * Overview:
 *      Calculates even and odd differences in a given array
 *
 * Input:
 *      One int (length of array), n number of ints
 *
 * Output:
 *
 *      one int, difference of evens and odds
 *
 *
 */

#include <iostream>
#include <limits.h>
#include <sstream>

using namespace std;


int calculateEvenOddDifference(int array[], int size)
{
    int evenTotal = 0;
    int oddTotal = 0;

    for(int x = 0; x < size; x++)
    {

        // if value is even...
        if((array[x] % 2) == 0)
        {
            evenTotal += array[x];
        }
        else
        {
            oddTotal += array[x];
        }
    }
    //easy way to calculate what is asked for
    return evenTotal - oddTotal;
}

void getInt(int* varToPopulate, string promptText)
{
    do {
        // this is a validation function I have been using to make sure input is an int
        if (!cin) {
            cout << "Invalid! Not an int!" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        cout << promptText;
        cin >> *varToPopulate;
        cin.ignore(INT_MAX, '\n');
    }
    while (!cin);
}

int main()
{
    int size;

    string prompt = "Please enter an array size: ";
    getInt(&size, prompt);

    int calcArray [size];
    for(int x = 0; x < size; x++)
    {
        //let's use a stream to combine a string and an int
        string prompt = "Please enter the value of element ";
        ostringstream promptStream;
        promptStream << prompt << x << ": ";

        // this function places the string value into our array
        getInt(&calcArray[x], promptStream.str());

    }

    //blah blah... long function name.... wheeeeeeeeee
    int difference = calculateEvenOddDifference(calcArray, size);

    cout << "The difference of the even numbers and odd numbers is: " << difference << endl;

    return 0;
}