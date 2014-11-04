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
    fill_n(randomNumbers, lengthOfString, -1);


    for(int x = 0; x < lengthOfString; x++)
    {
        int randomNumber;

        do
        {

            randomNumber = rand_int(0, lengthOfString - 1);

        }
        while(NumberInArray(randomNumber, randomNumbers, lengthOfString));

        mixedString[x] = stringToMix[randomNumber];

        mixedString[lengthOfString] = '\0';
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
    while(runAgain == 'y');
}