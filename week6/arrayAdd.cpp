#include <iostream>

using namespace std;

void ArrayAdd(int array1[], int array2[], int totalArray[], int arraySize)
{
    for(int i = 0; i < arraySize; i++)
    {
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