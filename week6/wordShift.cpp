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

void ShiftLeft(char stringToShift[], int spaces)
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
        //This doesn't really need to be a recursive function, it's just the first way I thought to solve it
        //Another way would be to change the above to else and use a while loop to reduce spaces
        spaces -= strLen;
        ShiftLeft(stringToShift, spaces);
    }


}

void ShiftRight(char stringToShift[], int spaces)
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
        //This doesn't really need to be a recursive function, it's just the first way I thought to solve it
        //Another way would be to change the above to else and use a while loop to reduce spaces
        spaces -= strLen;
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

bool ValidNumber(string numString, long* number)
{
    char* stopped;
    *number = strtol(numString.c_str(), &stopped, 10);

    if(stopped >= (numString.c_str() + numString.length()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string target;

    bool runAgain = true;

    cout << "Please enter a string: ";
    //getline(cin, target);
    target = "hello";

    char targetCString[target.length()];
    stringToCString(target, targetCString);

    do
    {
        string command = "";
        do
        {
            cout << "Please enter a command: ";
            //cin >> command;
            command = "R5";

            if(command.length() < 2)
            {
                cout << "Invalid command!" << endl;
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
            switch (toupper(command.at(0)))
            {
                case 'L':
                    long* leftSpace;
                    command.erase(command.begin());

                    if(ValidNumber(command, leftSpace))
                    {
                        ShiftLeft(targetCString, *leftSpace);
                        cout << "New string: " << targetCString << endl;
                    }
                    else
                    {
                        cout << "Invalid left number!" << endl;
                    }
                    break;
                case 'R':
                    long* rightSpace;
                    command.erase(command.begin());
                    if(ValidNumber(command, rightSpace))
                    {
                        ShiftRight(targetCString, *rightSpace);
                        cout << "New string: " << targetCString << endl;
                    }
                    else
                    {
                        cout << "Invalid right number!" << endl;
                    }
                    break;
                default:
                    cout << "Invalid command!";
            }
        }
    }
    while(runAgain);
}
