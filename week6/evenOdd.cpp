#include <iostream>
#include <limits.h>
#include <sstream>

using namespace std;


int calculateEvenOddDifference(int array[], int size)
{
    int evenTotal = 0;
    int oddTotal = 0;

    for(int x = 0; x < size; x++)
    {
        if((array[x] % 2) == 0)
        {
            evenTotal += array[x];
        }
        else
        {
            oddTotal += array[x];
        }
    }

    return evenTotal - oddTotal;
}

void getInt(int* varToPopulate, string promptText)
{
    do {

        if (!cin) {
            cout << "Invalid! Not an int!" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        cout << promptText;
        cin >> *varToPopulate;
        cin.ignore(INT_MAX, '\n');
    }
    while (!cin);
}

int main()
{
    int size;

    string prompt = "Please enter an array size: ";
    getInt(&size, prompt);

    int calcArray [size];
    for(int x = 0; x < size; x++)
    {
        string prompt = "Please enter the value of element ";
        ostringstream promptStream;
        promptStream << prompt << x << ": ";

        getInt(&calcArray[x], promptStream.str());

    }


    int difference = calculateEvenOddDifference(calcArray, size);

    cout << "The difference of the even numbers and odd numbers is: " << difference;

    return 0;
}