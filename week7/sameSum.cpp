#include <iostream>
#include <stdlib.h>

using namespace std;


void initArray(int array[10][10])
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            array[j][i] = 0; //fill entire array with known data
        }
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

int main()
{
    int possibleRows = 10;
    int possibleCol = 10;
    int userArray[10][10];
    initArray(userArray);

    cout << "Please enter the first row of your square array. Please note, your array must be square." << endl;


    for(int i = 0; i < 10; i++) {
        if (i < possibleCol) {

            string userInput;
            cout << "Row " << i << ": ";
            getline(cin, userInput);
            //userInput = "5 10 15 254";

            char *userInputCString;

            userInputCString = new char[userInput.length() + 1];
            //userInputCString = userInput.c_str();
            stringToCString(userInput, userInputCString);
            char *stopPointer = userInputCString;
            for (int j = 0; j < 10; j++) {

                long possibleInt = strtol(stopPointer, &stopPointer, 10);

                //todo: fix
                if (*stopPointer != '\0' && j < possibleCol) {
                    userArray[j][i] = possibleInt;
                    if (*stopPointer == ' ') {
                        stopPointer++;
                    }
                    continue;
                }

                else {
                    if(*stopPointer != '\0')
                    {
                        cout << "Some elements dropped off due to non same-length input!" << endl;
                    }

                    userArray[j][i] = possibleInt;
                    possibleRows = j + 1;
                    possibleCol = j + 1;
                    break;
                }
            }

            //free memory after each iteration
            delete userInputCString;
        }
        else
        {
            break;
        }
    }

}