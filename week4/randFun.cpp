/* Author: Nathan Sosnovske
 *
 * Created: 10/25/2014
 *
 * Edited: 10/25/2014
 *
 * Files: randFun.cpp
 *
 * Overview:
 *      Generates a random number within a given range (inclusive).
 *
 * Input:
 *      Two ints (range)
 *
 * Output:
 *
 *      One random number in range.
 *
 *
 */

#include <iostream>
#include <string>
#include <limits.h>
#include <stdlib.h>

using namespace std;

int rand_int(int min, int max)
{
    // The c++ documentation shows how to generate a string range from 0-num with
    // the modulo operator. From there we just add the lowerBound to get us in the right range.

    int randomNumber = rand() % ((max - min) + 1) + min;
    return randomNumber;
}

int main()
{
    //seed the random number generator
    srand(time(NULL));

    int lowerBound;
    int upperBound;

    // I used this stackoverflow question page to discover that cin can be read as a bool
    // http://stackoverflow.com/questions/7354009/c-cin-positive-integers-only
    // This made input validation pretty easy!

    // I chose to drop off any characters after an alpha, which doesn't allow for perfect input validation, but works
    // pretty well.

    cout << "Please enter two integers." << endl;
    do {
        do {

            if (!cin) {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }

            cout << "Number 1: ";
            cin >> lowerBound;
            cin.ignore(INT_MAX, '\n');
        }
        while (!cin);

        do {

            if (!cin) {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
            cout << "number 2: ";
            cin >> upperBound;
            cin.ignore(INT_MAX, '\n');
        }
        while (!cin);
    }
    while(lowerBound >= upperBound);

    cout << rand_int(lowerBound, upperBound) << endl;

    return 0;
}
