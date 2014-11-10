/* Author: Nathan Sosnovske
 *
 * Created: 11/9/2014
 *
 * Edited: 11/9/2014
 *
 * Files: wordShift.cpp
 *
 * Overview:
 *      Shifts a word based on commands
 *
 * Input:
 *      string. commands.
 *
 * Output:
 *
 *      changed string.
 *
 *
 */


#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

void Reverse(char stringToReverse[])
{
    int strLen = strlen(stringToReverse);
    char tmpArray[strLen];

    for(int i = 0; i < strLen; i++)
    {
        tmpArray[i] = stringToReverse[(strLen - 1) - i];
    }

    for(int i = 0; i < strLen; i++)
    {
        stringToReverse[i] = tmpArray[i];
    }
}

void ShiftLeft(char stringToShift[], long spaces)
{
    int strLen = strlen(stringToShift);
    char tmpArray[strLen];

    if (spaces == strLen)
    {
       // do nothing
    }
    else if(spaces < strLen)
    {
        for(int i = 0; i < spaces; i++)
        {
            tmpArray[strLen - spaces + i] = stringToShift[i];
        }
        for(int i = 0; i < (strLen - (spaces)); i++)
        {
            tmpArray[i] = stringToShift[i + spaces];
        }

        for(int i = 0; i < strLen; i++)
        {
            stringToShift[i] = tmpArray[i];
        }
    }
    else
    {
        while(spaces > strLen)
        {
            spaces -= strLen;
        }
        ShiftLeft(stringToShift, spaces);
    }


}

void ShiftRight(char stringToShift[], long spaces)
{
    int strLen = strlen(stringToShift);

    if (spaces == strLen)
    {
        // do nothing
    }
    else if(spaces < strLen)
    {
        ShiftLeft(stringToShift, (strLen - spaces));
    }
    else
    {
        while(spaces > strLen)
        {
            spaces -= strLen;
        }
        ShiftRight(stringToShift, spaces);
    }
}

void stringToCString(string input, char* output)
{
    for(int x = 0; x < input.length(); x++)
    {
        output[x] = input.at(x);
    }

    output[input.length()] = '\0';

}

string StringToLower(string possibleCaps)
{
    string loweredString;

    for(int i = 0; i < possibleCaps.length(); i++)
    {
        loweredString.append(string(1, tolower(possibleCaps.at(i))));
    }

    return loweredString;
}

int main()
{
    string target;

    bool runAgain = true;

    cout << "Please enter a string: ";
    getline(cin, target);


    char targetCString[target.length()];
    stringToCString(target, targetCString);

    do
    {
        string command = "";
        do
        {
            cout << "Please enter a command: ";
            cin >> command;


            if(command.length() < 2)
            {
                cout << "Invalid command!" << endl;
                cout << "Your string: " << targetCString << endl;
            }
        }
        while(command.length() < 2);

        if(StringToLower(command) == "quit")
        {
            exit(0);
        }
        else if(StringToLower(command) == "rev")
        {
            Reverse(targetCString);
            cout << "New string: " << targetCString << endl;
        }
        else
        {
            if(toupper(command.at(0)) == 'L') {
                //long* space;
                char* stopped;
                command.erase(command.begin());
                long numSpace = strtol(command.c_str(), &stopped, 10);
                if (stopped >= (command.c_str() + command.length())) {
                    ShiftLeft(targetCString, numSpace);
                    cout << "New string: " << targetCString << endl;
                }
                else {
                    cout << "Invalid left number!" << endl;
                    cout << "Your string: " << targetCString << endl;
                }
            }
            else if (toupper(command.at(0)) == 'R') {
                //long* space;
                char* stopped;
                command.erase(command.begin());
                long numSpace = strtol(command.c_str(), &stopped, 10);
                if (stopped >= (command.c_str() + command.length())) {
                    ShiftRight(targetCString, numSpace);
                    cout << "New string: " << targetCString << endl;
                }
                else {
                    cout << "Invalid right number!" << endl;
                    cout << "Your string: " << targetCString << endl;

                }
            }
            else
            {
                cout << "Invalid command!" << endl;
                cout << "Your string: " << targetCString << endl;
            }
        }
    }
    while(runAgain);
}
