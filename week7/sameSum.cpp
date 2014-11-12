#include <iostream>
#include <stdlib.h>

using namespace std;

bool sameSum(int array[10][10], int dimension)
{
    int authoritativeRowTotal = 0;
    int authoritativeColTotal = 0;
    int diagTotal = 0;

    for(int col = 0; col < dimension; col++)
    {
        int rowTotal = 0;

        //Steps through the array to make sure the rows are the same.
        //We return false if anything doesn't match
        for(int row = 0; row < dimension; row++)
        {
            if(col == 0)
            {
                authoritativeRowTotal += array[row][col];
                continue;
            }
            else
            {
                rowTotal += array[row][col];
            }
        }

        if(col > 0)
        {
            if(rowTotal != authoritativeRowTotal)
            {
                return false;
            }
        }
    }

    for(int row = 0; row < dimension; row++)
    {
        int colTotal = 0;
        for(int col = 0; col < dimension; col++)
        {
            if(row == 0)
            {
                authoritativeColTotal += array[row][col];
                continue;
            }
            else
            {
                colTotal += array[row][col];
            }
        }
        if((row == 0) && (authoritativeColTotal != authoritativeRowTotal))
        {
            return false;
        }

        if((row > 0) && (colTotal != authoritativeColTotal))
        {
            return false;
        }


    }

    return true;
}

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
    int dimension = 10;
    int userArray[10][10];
    initArray(userArray);

    cout << "Please enter the maximum dimensional size of your array. (ie. enter 5 for a 5x5 array): ";
    cin >> dimension;
    cin.ignore(100, '\n');
    cout << "Please enter the first row of your square array. Please note, your array must be square." << endl;


    for(int i = 0; i < dimension; i++) {
        if (i < dimension) {

            string userInput;
            cout << "Row " << i << ": ";
            //userInput = "1 2 3 4 5";
            getline(cin, userInput);


            char *userInputCString;

            userInputCString = new char[userInput.length() + 1];
            stringToCString(userInput, userInputCString);
            char *stopPointer = userInputCString;
            for (int j = 0; j < 10; j++) {

                long possibleInt = strtol(stopPointer, &stopPointer, 10);


                if (j < dimension - 1) {
                    userArray[j][i] = possibleInt;
                    if (*stopPointer == ' ')
                    {
                        stopPointer++;
                    }
                    else
                    {
                        cout << "Row not long enough. Assuming 0's for rest of row." << endl;
                        break;
                    }

                    continue;
                }

                else {
                    if(*stopPointer != '\0')
                    {
                        cout << "Some elements dropped off due to non same-length input!" << endl;
                    }

                    userArray[j][i] = possibleInt;
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


    bool test = sameSum(userArray, dimension);
    if(test)
    {
        cout << "The rows are the same.";
    }
    else
    {
        cout << "The rows are different.";
    }

}