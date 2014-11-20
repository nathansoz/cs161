#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

struct Car
{
    string make;
    string model;
    int year;

    double purchasePrice;
    double salesPrice;

    Date datePurchased;
    Date dateSold;

    bool isSold = false;
};

//function prototypes
bool ValidMonthDayCombo(int, int);
bool ValidDouble(string convert, double&);
bool ValidInt(string convert, int&);

void AddCar()
{
    Car tmpCar;
    string modelYearString;
    string purchasePriceString;
    string purchaseMonthString;
    string purchaseDayString;

    cin.ignore(1000, '\n');

    cout << "Enter the make of the car: ";
    getline(cin, tmpCar.make);
    cout << "Enter the model of the car: ";
    getline(cin, tmpCar.model);
    cout << "Enter the year of the car: ";
    getline(cin, modelYearString);
    do
    {
        cout << "Enter the purchase price of the car: ";
        getline(cin, purchasePriceString);
        if(ValidDouble(purchasePriceString, tmpCar.purchasePrice))
        {
            break;
        }
    }
    while(true);
    do
    {
        do
        {
            cout << "Enter the purchase date month: ";
            getline(cin, purchaseMonthString);
            if(ValidInt(purchaseMonthString, tmpCar.datePurchased.month))
            {
                break;
            }
        }
        while(true);
        do
        {
            int tmpDay;

            cout << "Enter the purchase date day: ";
            getline(cin, purchaseDayString);
            if(ValidInt(purchaseDayString, tmpCar.datePurchased.day))
            {
                break;
            }
        }
        while(true);

        cout << tmpCar.datePurchased.month << endl;
        cout << tmpCar.datePurchased.day << endl;

        if(ValidMonthDayCombo(tmpCar.datePurchased.month, tmpCar.datePurchased.day))
        {
            break;
        }
    }
    while(true);

}

bool ValidDouble(string convert, double &setVal)
{
    const char* convertCString = convert.c_str();

    char* end;
    setVal = strtod(convertCString, &end);
    if(*end != '\0')
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool ValidInt(string convert, int &setVal)
{
    long tmpVal;
    const char* convertCString = convert.c_str();

    char* end;
    tmpVal = strtol(convertCString, &end, 10);

    if(*end != '\0' || tmpVal > INT_MAX)
    {
        return false;
    }
    else
    {
        setVal = static_cast<int>(tmpVal);
        return true;
    }
}

bool ValidMonthDayCombo(int month, int day)
{
    if(day >= 1 && day <= 28)
    {
        return true;
    }
    else if((day == 29 || day == 30) && month != 2)
    {
        return true;
    }
    else if(day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
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
    vector<Car> cars;

    do
    {
        int choice = 0;

        cout << "Welcome to the car inventory system!" << endl;
        cout << "Please chose a number:" << endl << endl;
        cout << "1) Add car" << endl;
        cout << "2) List inventory" << endl;
        cout << "3) Display profit" << endl;
        cout << "4) Quit" << endl;
        cout << "Choice [1-4]: ";

        cin >> choice;

        switch(choice)
        {
            case 1:
                AddCar();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                exit(0);
            default:
                break;
        }

    }
    while(true);

}