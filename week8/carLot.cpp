/* Author: Nathan Sosnovske
 *
 * Created: 11/23/2014
 *
 * Edited: 11/23/2014
 *
 * Files: carLot.cpp
 *
 * Overview:
 *      Simultates a carlot inventory
 *
 * Input:
 *      - Asks what the program should do then
 *      -- Inputs a new car OR
 *      -- Prints out the inventory OR
 *      -- Prints out the profit for a given month/year
 *
 * Output:
 *
 *      See above
 *
 *
 */

#include <iomanip>
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
    double salePrice;

    Date datePurchased;
    Date dateSold;

    bool isSold;
};

//function prototypes
bool ValidMonthDayCombo(int, int);
bool ValidDouble(string convert, double&);
bool ValidInt(string convert, int&);

//Adds a car to a vector passed by reference. Calls conversion and validation functions as needed
//This is a somewhat meaty function and could probably benefit from some refactoring.
void AddCar(vector<Car> &cars)
{
    Car tmpCar;
    string modelYearString;
    string purchasePriceString;
    string purchaseMonthString;
    string purchaseDayString;
    string purchaseYearString;
    string salePriceString;
    string saleMonthString;
    string saleDayString;
    string saleYearString;

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
                if(tmpCar.datePurchased.month > 0 && tmpCar.datePurchased.month < 13)
                {
                    break;
                }
                else
                {
                    cout << "Invalid month!" << endl;
                }
            }
        }
        while(true);
        do
        {

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

    do
    {
        cout << "Enter the year the car was purchased: ";
        getline(cin, purchaseYearString);
        if(ValidInt(purchaseYearString, tmpCar.datePurchased.year))
        {
            if(tmpCar.datePurchased.year > 0)
            {
                break;
            }
            else
            {
                cout << "They probably didn't have cars before the common era." << endl;
                continue;
            }
        }
        else
        {
            cout << "Invalid integer." << endl;
            continue;
        }

    }
    while(true);

    do
    {
        string tmpSold;
        cout << "Has the car been sold? [y/n]: ";
        cin >> tmpSold;

        if(tmpSold.size() == 1)
        {
            if(tolower(tmpSold.at(0)) == 'n')
            {
                tmpCar.isSold = false;
                break;
            }
            else if(tolower(tmpSold.at(0)) == 'y')
            {
                tmpCar.isSold = true;
                break;
            }
            else
            {
                cout << "Invalid character entry." << endl;
                continue;
            }

        }
        else
        {
            cout << "Invalid number of characters." << endl;
            continue;
        }

    }
    while(true);

    if(tmpCar.isSold)
    {
        cin.ignore(1000, '\n');

        do
        {
            cout << "Enter the sale price of the car: ";
            getline(cin, salePriceString);
            if(ValidDouble(salePriceString, tmpCar.salePrice))
            {
                break;
            }
        }
        while(true);
        do
        {
            do
            {
                cout << "Enter the month the car was sold: ";
                getline(cin, saleMonthString);
                if(ValidInt(saleMonthString, tmpCar.dateSold.month))
                {
                    if(tmpCar.dateSold.month > 0 && tmpCar.dateSold.month < 13)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Invalid month!" << endl;
                    }
                }
            }
            while(true);
            do
            {

                cout << "Enter the day the car was sold: ";
                getline(cin, saleDayString);
                if(ValidInt(saleDayString, tmpCar.dateSold.day))
                {
                    break;
                }
            }
            while(true);

            do
            {
                cout << "Enter the year the car was purchased: ";
                getline(cin, saleYearString);
                if(ValidInt(saleYearString, tmpCar.dateSold.year))
                {
                    if(tmpCar.dateSold.year > 0)
                    {
                        break;
                    }
                    else
                    {
                        cout << "They probably didn't have cars before the common era." << endl;
                        continue;
                    }
                }
                else
                {
                    cout << "Invalid integer." << endl;
                    continue;
                }

            }
            while(true);

            if(!ValidMonthDayCombo(tmpCar.dateSold.month, tmpCar.dateSold.day))
            {
                cout << "Invalid month/day combo!" << endl;
                continue;
            }

            if(tmpCar.dateSold.year > tmpCar.datePurchased.year)
            {
                break;
            }
            else if(tmpCar.dateSold.year == tmpCar.datePurchased.year)
            {
                if(tmpCar.dateSold.month > tmpCar.datePurchased.month)
                {
                    break;
                }
                else if(tmpCar.dateSold.month == tmpCar.datePurchased.month)
                {
                    if(tmpCar.dateSold.day >= tmpCar.datePurchased.day)
                    {
                        break;
                    }
                    else
                    {
                        cout << "A car cannot be sold before it it purchased! Please enter the sale date again." << endl;
                        continue;
                    }
                }
                else
                {
                    cout << "A car cannot be sold before it it purchased! Please enter the sale date again." << endl;
                    continue;
                }
            }
            else
            {
                cout << "A car cannot be sold before it it purchased! Please enter the sale date again." << endl;
                continue;
            }
        }
        while(true);
    }

    cars.push_back(tmpCar);
    cout << endl << endl;
}

//Calculates the profit of a given vector passed by reference.
//Handles input, calling validataion functions, and printing actual profit.
//Tells the user if there are no cars sold in given time period.

void CalculateProfit(vector<Car> &cars)
{

    if(cars.size() == 0)
    {
        //Exit to main right away if there are no cars
        cout << endl << "No cars in inventory!" << endl << endl;
        return;
    }

    string profitYearString;
    string profitMonthString;
    int profitYear;
    int profitMonth;
    int carsSold = 0;
    double profit = 0;


    //Readability and clear the input buffer
    cout << endl;
    cin.ignore(1000, '\n');


    do
    {
        cout << "Please enter the month for which you would like to calculate profit: ";
        getline(cin, profitMonthString);

        if(ValidInt(profitMonthString, profitMonth))
        {
            if(profitMonth > 0 && profitMonth < 13)
            {
                break;
            }
            else
            {
                cout << "Invalid month number." << endl;
                continue;
            }
        }
        else
        {
            cout << "Invalid integer." << endl;
            continue;
        }
    }
    while(true);

    do
    {
        cout << "Please enter the year for which you would like to calculate profit: ";
        getline(cin, profitYearString);

        if(ValidInt(profitYearString, profitYear))
        {
            if(profitYear > 0)
            {
                break;
            }
            else
            {
                cout << "Invalid year number." << endl;
                continue;
            }
        }
        else
        {
            cout << "Invalid integer." << endl;
            continue;
        }
    }
    while(true);

    for(int i = 0; i < cars.size(); i++)
    {
        //We check to see if there are any cars for a given time period
        if(cars.at(i).dateSold.year == profitYear && cars.at(i).dateSold.month == profitMonth)
        {
            //If there are, increment number of cars sold and profit number.
            //We will also use carsSold to verify that something was actually sold in the time period

            carsSold++;
            profit += (cars.at(i).salePrice - cars.at(i).purchasePrice);
        }
    }

    if(carsSold > 0)
    {
        cout << carsSold << " car(s) sold for given time period." << endl;
        cout << "Total profit: $" << setprecision(2) << fixed << profit << endl << endl;
    }
    else
    {
        cout << endl << "No cars sold in time period given." << endl << endl;
    }


}

//Loops through the inventory and prints formatted lists of what it contains. This is mostly formatting
//junk... there isn't a lot of exciting logic here.
void PrintInventory(vector<Car> &cars)
{

    if(cars.size() == 0)
    {
        cout << endl << "No cars in inventory!" << endl << endl;
        return;
    }

    cout << endl << endl;
    cout << "Inventory printout:";
    cout << endl << endl;

    for(int i = 0; i < cars.size(); i++)
    {
        cout << "Car " << (i + 1) << endl << endl;
        cout << "Make: " << cars.at(i).make << endl;
        cout << "Model: " << cars.at(i).model << endl;
        cout << "Year: " << cars.at(i).year << endl;
        cout << "Purchase price: $" << setprecision(2) << fixed << cars.at(i).purchasePrice << endl;
        cout << "Date purchased: " << cars.at(i).datePurchased.month << "/" << cars.at(i).datePurchased.day <<
                "/" << cars.at(i).datePurchased.year << endl;
        if(cars.at(i).isSold)
        {
            cout << "Status: SOLD" << endl;
            cout << "Sale Price: $" << setprecision(2) << fixed << cars.at(i).salePrice << endl;
            cout << "Date sold: " << cars.at(i).dateSold.month << "/" << cars.at(i).dateSold.day <<
                    "/" << cars.at(i).dateSold.year << endl;
            cout << "Profit: $" << setprecision(2) << fixed << (cars.at(i).salePrice - cars.at(i).purchasePrice) << endl;

        }
        else
        {
            cout << "Status: NOT SOLD" << endl;
            cout << "Sale price: N/A" << endl;
            cout << "Sale date: N/A" << endl;
            cout << "Profit: N/A" << endl;
        }

        cout << endl << endl;
    }
}

//verifies that a string contains a valid double. If it does, it returns true and also sets the double var
//passed in by reference

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

//Same Idea as validdouble, with integers!

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

//Boilerplate code to ensure that the right number of days are in a month

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


//Program loop. I tried to keep as little as possible in main, splitting logic off to purpose funcitons.
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
                AddCar(cars);
                break;
            case 2:
                PrintInventory(cars);
                break;
            case 3:
                CalculateProfit(cars);
                break;
            case 4:
                exit(0);
            default:
                break;
        }

    }
    while(true);

}