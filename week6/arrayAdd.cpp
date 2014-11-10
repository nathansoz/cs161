/* Author: Nathan Sosnovske
 *
 * Created: 11/9/2014
 *
 * Edited: 11/9/2014
 *
 * Files: arrayAdd.cpp
 *
 * Overview:
 *      Adds two arrays of a given length.
 *
 * Input:
 *      One int (length of array), n number of ints x 2, for each array.
 *
 * Output:
 *
 *      n number of ints, totalled.
 *
 *
 */

#include <iostream>

using namespace std;

void ArrayAdd(int array1[], int array2[], int totalArray[], int arraySize)
{
    for(int i = 0; i < arraySize; i++)
    {
        //dereference the pointers to gain access to values in array

        *(totalArray + i) = *(array1 + i) + *(array2 + i);
    }

}

int main()
{
    int arraySize;

    cout << "Please enter an array size: ";
    cin >> arraySize;

    int array1[arraySize];
    int array2[arraySize];
    int totalArray[arraySize];

    cout << "Please enter the values for array 1." << endl;

    for(int i = 0; i < arraySize; i++)
    {
        cout << "Value " << i << ": ";
        cin >> array1[i];
    }

    cout << "Please enter the values for array 2." << endl;
    for(int i = 0; i < arraySize; i++)
    {
        cout << "Value " << i << ": ";
        cin >> array2[i];
    }

    ArrayAdd(array1, array2, totalArray, arraySize);

    for(int i = 0; i < arraySize; i++)
    {
        cout << totalArray[i] << endl;
    }


}