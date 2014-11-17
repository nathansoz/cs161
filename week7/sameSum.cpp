/* Author: Nathan Sosnovske
 *
 * Created: 11/16/2014
 *
 * Edited: 11/16/2014
 *
 * Files: sameSum.cpp
 *
 * Overview:
 *      Checks to see if the sum of rows, cols, and diags matches.
 *
 * Input:
 *      2d array.
 *
 * Output:
 *
 *      Result of sum test.
 *
 *
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

bool sameSum(int array[10][10], int dimension)
{
    // our authoritative totals survive the for loops so we can do a final comparison
    int authoritativeRowTotal = 0;
    int authoritativeColTotal = 0;
    int diagLeftTotal = 0;
    int diagRightTotal =0;

    //I tried to be as efficient as possible with these loops. I broke out as soon as anything didn't match.
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

    // Assuming all of our row sums match, we move on to columns
    // This looks like the row one, just reversed for loops

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

    //We can grab the diagonal values for our comparison below
    for(int row = 0, col = 0; row < dimension, col < dimension; row++, col++)
    {
        diagLeftTotal += array[row][col];
    }

    for(int row = (dimension - 1), col = 0; row < 0, col < dimension; row--, col++)
    {
        diagRightTotal += array[row][col];
    }

    if(diagLeftTotal == diagRightTotal)
    {
        if(authoritativeColTotal == diagLeftTotal)
        {
            if(authoritativeColTotal == authoritativeRowTotal)
            {
                //Only return true if everything equals everything
                return true;
            }
        }
    }
    //our default is to return false if something goes wrong
    return false;
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

//This function is mostly so that I don't have the const that c_str makes.
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
            getline(cin, userInput);

            char *userInputCString;
            userInputCString = new char[userInput.length() + 1];
            stringToCString(userInput, userInputCString);
            char *stopPointer = userInputCString;
            for (int j = 0; j < 10; j++) {

                long possibleInt = strtol(stopPointer, &stopPointer, 10);


                if (j < dimension - 1) {
                    userArray[j][i] = static_cast<int>(possibleInt);
                    if (*stopPointer == ' ')
                    {
                        stopPointer++;
                    }
                    else
                    {
                        //We had no input validation instructions...
                        cout << "Row not long enough. Assuming 0's for rest of row." << endl;
                        break;
                    }

                    continue;
                }

                else {
                    if(*stopPointer != '\0')
                    {
                        //Drop off too long input
                        cout << "Some elements dropped off due to non same-length input!" << endl;
                    }

                    userArray[j][i] = static_cast<int>(possibleInt);
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
        cout << "All the sums match.";
    }
    else
    {
        cout << "The sums do not match!";
    }

}