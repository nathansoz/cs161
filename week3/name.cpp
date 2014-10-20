/* Author: Nathan Sosnovske
 *
 * Created: 10/19/2014
 *
 * Edited: 10/19/2014
 *
 * Files: name.cpp
 *
 * Overview:
 *      Prompts for a First Middle and Last name. Displays them in: Last, First Middle order.
 *
 * Input:
 *      One line of text.
 *
 * Output:
 *      - Last, First Middle
 *      OR
 *      - Last, First M.
 *      OR
 *      - Last, First
 *
 *
 */

#include <iostream>
#include <string.h>

using namespace std;

// Change this for longer or shorter names
const int STRING_LENGTH = 100;

void PrintReformattedName(char name[])
{
    //Setting the splits to -1 allows us to see if they actually get set
    int split1 = -1;
    int split2 = -1;
    int len = strlen(name);

    char firstName[STRING_LENGTH] = "\0";
    char middleName[STRING_LENGTH] = "\0";
    char lastName[STRING_LENGTH] = "\0";

    for(int i = 0; i < STRING_LENGTH; i++)
    {
        if(name[i] == ' ' && split1 == -1)
        {
            split1 = i;
            continue;
        }
        if(name[i] == ' ' && split2 == -1)
        {
            split2 = i;
            continue;
        }
    }

    //If both splits are set, we have three words

    if(split1 != -1 && split2 != -1)
    {
        for(int i = 0; i < split1; i++)
        {
            // This could probably become a function
            // that takes a cstring and returns a cstring
            // with the appended char
            int tmpLen = strlen(firstName);
            firstName[tmpLen] = name[i];
            firstName[tmpLen + 1] = '\0';

        }

        for(int i = split1 + 1; i < split2; i++)
        {
            int tmpLen = strlen(middleName);
            middleName[tmpLen] = name[i];
            middleName[tmpLen + 1] = '\0';
        }

        for(int i = split2 + 1; i < len; i++)
        {
            int tmpLen = strlen(lastName);
            lastName[tmpLen] = name[i];
            lastName[tmpLen + 1] = '\0';
        }

        // Finally, add a period to the middle name if it is only one character
        if(strlen(middleName) == 1)
        {
            middleName[1] ='.';
            middleName[2] = '\0';
        }

        cout << lastName << ", " << firstName << " " << middleName << endl;
    }

    //Otherwise I will make the assumption that only a first and last name were entered.
    else
    {
        for(int i = 0; i < split1; i++)
        {
            int tmpLen = strlen(firstName);
            firstName[tmpLen] = name[i];
            firstName[tmpLen + 1] = '\0';

        }

        for(int i = split1 + 1; i < len; i++)
        {
            int tmpLen = strlen(lastName);
            lastName[tmpLen] = name[i];
            lastName[tmpLen + 1] = '\0';
        }

        cout << lastName << ", " << firstName << endl;
    }
}

int main()
{
    char name[STRING_LENGTH];

    cout << "Please enter your name in the format First Middle Last: ";

    cin.getline(name, STRING_LENGTH);

    PrintReformattedName(name);

    return 0;
}