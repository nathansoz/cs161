/* Author: Nathan Sosnovske
 *
 * Created: 10/25/2014
 *
 * Edited: 10/25/2014
 *
 * Files: mpg.cpp
 *
 * Overview:
 *      Calculates MPG from liters and miles traveled
 *
 * Input:
 *      Two doubles (liters and miles)
 *
 * Output:
 *
 *      One number back. MPG.
 *
 *
 */

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

const double GALLONS_IN_LITER = 0.264179;

double mpgCalc(double liters, double miles)
{
    //Converts liters and miles to MPG
    double gallons = liters * GALLONS_IN_LITER;
    double mpg = miles / gallons;

    return mpg;
}

int main()
{
    double miles = 0;
    double liters = 0;
    char tryAgain = 'n';

    cout << "Welcome to the MPG tool!" << endl << endl;

    do {

        do
        {
            cout << "Please enter number of miles traveled: ";
            cin >> miles;

            cout << "Please enter number of liters consumed: ";
            cin >> liters;

            //We won't mess with divide by 0 errors
            if(miles == 0 || liters == 0)
            {
                cout << "0 values are invalid. Please try again!" << endl;
            }
        }
        while (miles == 0 || liters == 0);

        cout << "You got " << mpgCalc(liters, miles) << " MPG while traveling." << endl;

        cout << "Run again? (y/n): ";
        cin >> tryAgain;
        tryAgain = tolower(tryAgain);
    }
    while(tryAgain == 'y');

    return 0;
}