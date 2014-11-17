/* Author: Nathan Sosnovske
 *
 * Created: 11/16/2014
 *
 * Edited: 11/16/2014
 *
 * Files: symArrays.cpp
 *
 * Overview:
 *      Checks to see if an array is symmetrical
 *
 * Input:
 *      Thre ints on the command line. n number of ints for three arrays after that.
 *
 * Output:
 *
 *      Result of symmetrical test.
 *
 *
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

const int NUM_COMMAND_LINE_ARGS = 3;

void PrintHelp()
{
    cout << "symArrays" << endl;
    cout << "This program takes three, space separated, positive, integer arguments on the command line." << endl;
    cout << "These integers define the length of three arrays. You will then be asked for n number of" << endl;
    cout << "Integers to fill your arrays that you defined. The program will tell you if they are symmetrical" << endl;
    cout << endl;
    cout << "Example run: ./symArrays 2 3 4" << endl;
    cout << "Example symmetrical array: 1 2 3 3 2 1" << endl;
    cout << "Example asymmetrical array: 1 2 3 4 5" << endl << endl;
}

void GetUserArrayInput(int array[], int length)
{
    do {
        // we need a bool in order to break out of the do/while loop, because we are in a for loop.
        bool tooFew = false;

        for (int i = 0; i < length; i++)
        {
            cin >> array[i];

            //I'm not super happy with this input validation, mostly because it fails if the user enters a space before
            //pressing return.
            if(cin.peek() == '\n' && (i < length - 1))
            {
                cout << "You entered too few arguments!" << endl;
                cout << "Try again [" << length << "]: ";
                cin.clear();
                cin.ignore(1000000, '\n');
                tooFew = true;

                //breaks out of the for loop so that we can continue the do/while loop.
                break;
            }
        }
        if(tooFew)
        {
            continue;
        }
        if (cin.peek() != '\n')
        {
            //This detects if there is any other character besides a return after the last number. If there is
            //we know we had too much input!

            cout << "You entered too many numbers!" << endl;
            cout << "Try again [" << length << "]: ";

            //clear any errors, and ignore plenty of characters
            cin.clear();
            cin.ignore(1000000, '\n');

            //rinse... repeat
            continue;
        }
        else
        {
            break;
        }
    }
        while(true);
}

bool CheckSymmetry(int array[], int length)
{
    // This is somewhat inefficient because it technically checks everything twice.
    // A better way would probably be to do division and figure out where we can stop.
    // For a program like this though... it works.
    for(int i = 0, j = (length - 1); i < length; i++, j--)
    {
        if(array[i] != array[j])
        {
            return false;
        }
    }

    return true;
}

bool ValidInput(char *argv[], int numbers[])
{
    bool validNumbers = true;

    for(int i = 1; i < 4; i++)
    {

        char *endPtr;
        if(strtol(argv[i], &endPtr, 10))
        {
            numbers[i - 1] = static_cast<int>(strtol(argv[i], &endPtr, 10));

            if(numbers[i - 1] <= 0)
            {
                cout << "Invalid num at argument " << i << "!" << endl;
                cout << "Numbers must be positive." << endl;
                validNumbers = false;
            }
        }
        else
        {
            cout << "Invalid num at argument " << i << "!" << endl;
            validNumbers = false;
        }
    }

    return validNumbers;

}

//Not sure if I'm allowed to use the strcmp library function. I wrote my own.
bool StrCmp(char string1[], char string2[])
{
    int i = 0;

    //Infinite loop is ok because we have exit conditions.
    while(true)
    {
        if(string1[i] == string2[i])
        {
            if(string1[i] == '\0')
            {
                return true;
            }
            else
            {
                i++;
            }

        }
        else
        {
            return false;
        }
    }
}

int main(int argc, char* argv[])
{
    //Help files are helpful :)
    char helpString[] = "--help";
    char shortHelpString[] = "-h";

    //Not having the right number of command line args is a nonstarter
    if(argc != (NUM_COMMAND_LINE_ARGS + 1))
    {
        // If the user asks for help, give it to them and exit
        if(argc == 2 && (StrCmp(argv[1], helpString) || StrCmp(argv[1], shortHelpString)))
        {
            PrintHelp();
            return 0;
        }
        // if the user needs help, but doesn't ask for it, give it to them and exit.
        else
        {
            cout << "Invalid number of arguments!" << endl;
            cout << "This program only takes ";
            cout << NUM_COMMAND_LINE_ARGS;
            cout << " arguments!" << endl;
            cout << endl << endl;
            PrintHelp();

            //return bad exit status
            return 1;
        }
    }
        // once our trivial input check is done, we can make sure the subsance of the input is valid
    else
    {
        int arrayLengths[NUM_COMMAND_LINE_ARGS];

        if(ValidInput(argv, arrayLengths))
        {
            // And this is the acutal logic part of the program.

            int* array0;
            array0 = new int[arrayLengths[0]];
            cout << "Please enter values for array " << 1 << " [" << arrayLengths[0] << "]: ";
            GetUserArrayInput(array0, arrayLengths[0]);

            int* array1;
            array1 = new int[arrayLengths[1]];
            cout << "Please enter values for array " << 2 << " [" << arrayLengths[1] << "]: ";
            GetUserArrayInput(array1, arrayLengths[1]);

            int* array2;
            array2 = new int[arrayLengths[2]];
            cout << "Please enter values for array " << 3 << " [" << arrayLengths[2] << "]: ";
            GetUserArrayInput(array2, arrayLengths[2]);

            cout << "Array 1 is: ";
            CheckSymmetry(array0, arrayLengths[0]) ? cout << "symmetrical" : cout << "asymmetrical";
            cout << endl;

            cout << "Array 2 is: ";
            CheckSymmetry(array1, arrayLengths[1]) ? cout << "symmetrical" : cout << "asymmetrical";
            cout << endl;

            cout << "Array 3 is: ";
            CheckSymmetry(array2, arrayLengths[2]) ? cout << "symmetrical" : cout << "asymmetrical";
            cout << endl;

            //Clean up our memory
            delete array0;
            delete array1;
            delete array2;

            return 0;
        }


    }

}