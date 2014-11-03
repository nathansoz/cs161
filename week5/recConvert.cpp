#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits.h>
#include <math.h>


using namespace std;

int convertBinaryToDecimal(string binary)
{
    int decimal = 0;

    if(binary.at(0) == '0')
    {
        if(binary.length() == 1)
        {
            return 0;
        }
        else
        {
            binary.erase(binary.begin());
            return convertBinaryToDecimal(binary);
        }
    }
    else
    {
        if(binary.length() == 1)
        {
            return 1;
        }
        else
        {
            int len = binary.length();
            binary.erase(binary.begin());
            decimal = (pow(2, (len - 1))) + convertBinaryToDecimal(binary);

            return decimal;
        }
    }
}


void convertDecimalToBinary(int decimal, string &appendString)
{

    if ((decimal / 2) != 0)
    {
        convertDecimalToBinary(decimal / 2, appendString);
    }

    //I took this method of changing an int to char from:
    //     http://stackoverflow.com/questions/1114741/how-to-convert-int-to-char-c
    char digit = '0' + (decimal % 2);
    string tmpString(1, digit);
    appendString.append(tmpString);
}

bool validateBinaryNumber(string validate)
{
    for(int x = 0; x < validate.length(); x++)
    {
        if(validate.at(x) == '0' || validate.at(x) == '1')
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool validatePositiveDecimalNumber(string validate)
{
    for(int x = 0; x < validate.length(); x++)
    {
        if(isalpha(validate.at(x)))
        {
            return false;
        }
    }

    if(atoi(validate.c_str()) < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int choice;
    string userInput;
    string appendString = "";

    cout << "Welcome to number converter!" << endl;

    do
    {
        do
        {
            cout << "Please choose from the following menu options:" << endl;
            cout << "1) Convert binary number to decimal." << endl;
            cout << "2) Convert decimal number to binary." << endl;
            cout << "3) Exit." << endl;

            do
            {

                if (!cin)
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                }

                cout << "Choice: ";
                cin >> choice;
                cin.ignore(INT_MAX, '\n');
            }
            while (!cin);

            if (choice > 3 || choice < 1)
            {
                cout << "Invalid selection!" << endl << endl;
            }
        }
        while (choice > 3 || choice < 1);

        switch (choice)
        {
            case 1:
                do
                {
                    cout << "Please enter a binary number to convert: ";
                    cin >> userInput;
                    if (!validateBinaryNumber(userInput))
                    {
                        cout << "Invalid binary number! Please try again." << endl << endl;
                    }
                }
                while (!validateBinaryNumber(userInput));

                cout << convertBinaryToDecimal(userInput) << endl << endl;
                break;
            case 2:
                do
                {
                    cout << "Please enter a decimal number to convert (int): ";
                    cin >> userInput;
                    if (!validatePositiveDecimalNumber(userInput))
                    {
                        cout << "Invalid positive decimal number! Please try again." << endl << endl;
                    }
                }
                while (!validatePositiveDecimalNumber(userInput));

                convertDecimalToBinary(atoi(userInput.c_str()), appendString);
                cout << appendString << endl << endl;
                break;
            case 3:
                exit(0);
                // no break statement needed
            default:
                cout << "This is never reached.";
                //this is never reached.
        }

    }
    while(true); //the user will always exit using the menu system.

}