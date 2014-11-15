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
    for(int i = 0; i < length; i++)
    {
        cin >> array[i];
    }
    if(cin.peek() != '\n')
    {
        cout << "You entered too many numbers! Extra input will be discarded.";
        cin.clear();
        cin.ignore(1000000, '\n');
    }
}

bool CheckSymmetry(int array[], int length)
{
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
            numbers[i -1] = static_cast<int>(strtol(argv[i], &endPtr, 10));

            if(numbers[i - 1] <= 0)
            {
                cout << "Invalid num at argument " << i << cout << "!" << endl;
                cout << "Numbers must be positive." << endl;
                validNumbers = false;
            }
        }
        else
        {
            cout << "Invalid num at argument " << i << "i" << endl;
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
    char helpString[] = "--help";
    char shortHelpString[] = "-h";

    if(argc != (NUM_COMMAND_LINE_ARGS + 1))
    {
        if(argc == 2 && (StrCmp(argv[1], helpString) || StrCmp(argv[1], shortHelpString)))
        {
            PrintHelp();
            return 0;
        }
        else
        {
            cout << "Invalid number of arguments!" << endl;
            cout << "This program only takes ";
            cout << NUM_COMMAND_LINE_ARGS;
            cout << " arguments!" << endl;
            cout << endl << endl;
            PrintHelp();
            return 1;
        }
    }
    else
    {
        int arrayLengths[NUM_COMMAND_LINE_ARGS];

        if(ValidInput(argv, arrayLengths))
        {
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

            return 0;
        }


    }

}