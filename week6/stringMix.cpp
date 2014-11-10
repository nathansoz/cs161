/* Author: Nathan Sosnovske
 *
 * Created: 11/9/2014
 *
 * Edited: 11/9/2014
 *
 * Files: stringMix.cpp
 *
 * Overview:
 *      Takes a string and mixes it up.
 *
 * Input:
 *      One string.
 *
 * Output:
 *
 *      Mixed string.
 *
 *
 */

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

bool NumberInArray(int, int[], int);
int rand_int(int, int);

void mixString(char stringToMix[], char mixedString[])
{

    int lengthOfString = strlen(stringToMix);
    int randomNumbers[lengthOfString];

    // fill the random number array with -1, so that we don't have garbage data
    fill_n(randomNumbers, lengthOfString, -1);


    for(int x = 0; x < lengthOfString; x++)
    {
        int randomNumber;

        // this loop repeats as long as we don't have a number that isn't in the array (and in range)
        do
        {
            randomNumber = rand_int(0, lengthOfString - 1);
        }
        while(NumberInArray(randomNumber, randomNumbers, lengthOfString));

        mixedString[x] = stringToMix[randomNumber];

        // In hindsight, this could go out of the for loop... but it works.
        mixedString[lengthOfString] = '\0';

        // add our generated number to the random numbers array so it isn't repeated
        randomNumbers[x] = randomNumber;
    }
}

bool NumberInArray(int number, int array[], int size)
{
    for(int x = 0; x < size; x++)
    {
        if(number == array[x])
        {
            return true;
        }
    }

    return false;
}

int rand_int(int min, int max)
{
    // The c++ documentation shows how to generate a string range from 0-num with
    // the modulo operator. From there we just add the lowerBound to get us in the right range.

    int randomNumber = rand() % ((max - min) + 1) + min;
    return randomNumber;
}

void stringToCString(string input, char* output)
{
    for(int x = 0; x < input.length(); x++)
    {
        output[x] = input.at(x);
    }

    output[input.length()] = '\0';

}

int main()
{
    //Seed the random number generator
    srand(time(NULL));

    string mixMe;
    char runAgain = 'n';

    cout << "Please enter a string to be mixed: ";
    getline(cin, mixMe);

    do
    {
        char mixCString[mixMe.length()];
        char mixedString[mixMe.length()];
        stringToCString(mixMe, mixCString);
        mixString(mixCString, mixedString);
        cout << mixedString << endl << endl;
        cout << "Generate another random iteration? (y/n): ";
        cin >> runAgain;
    }
    while(tolower(runAgain) == 'y');
}