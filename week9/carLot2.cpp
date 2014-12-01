/* Author: Nathan Sosnovske
 *
 * Created: 11/30/2014
 *
 * Edited: 11/30/2014
 *
 * Files: carLot2.cpp
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
#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class Date
{
    private:
        int day;
        int month;
        int year;

        bool ValidMonthDayCombo(int Month, int Day);

    public:
        Date() {};
        Date(int Day, int Month, int Year)
        {
            if(ValidMonthDayCombo(Month, Day))
            {
                month = Month;
                day = Day;
                year = Year;
            }
            else
            {
                month = 0;
                day = 0;
                year = 0;
            }

        }
        //getters
        int GetMonth()
        {
            return month;
        }
        int GetDay()
        {
            return day;
        }
        int GetYear()
        {
            return year;
        }

        //quick check to make sure that the date is valid.
        //really all this is doing is making sure the month isn't set to 0, which would indicate that
        //the validdaymonthcombo function in the constructor flagged a bad date
        bool DateValid()
        {
            if(month > 0 && month < 13)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

class Car
{
    private:
        string make;
        string model;
        int year;
        double purchasePrice;
        double salePrice;
        Date datePurchased;
        Date dateSold;
        bool isSold;

    public:
        Car() {};

        Car(string Make, string Model, int Year, double PurchasePrice, Date DatePurchased, bool IsSold,
            double SalePrice, Date DateSold)
        {
            make = Make;
            model = Model;
            year = Year;
            purchasePrice = PurchasePrice;
            datePurchased = DatePurchased;
            isSold = IsSold;
            salePrice = SalePrice;
            dateSold = DateSold;
        }

        Car(string Make, string Model, int Year, double PurchasePrice, Date DatePurchased, bool IsSold)
        {
            make = Make;
            model = Model;
            year = Year;
            purchasePrice = PurchasePrice;
            datePurchased = DatePurchased;
            isSold = IsSold;
        }

        //getters
        string GetMake() { return make; }
        string GetModel() { return model; }
        int GetYear() { return year; }
        double GetPurchasePrice() { return purchasePrice; };
        double GetSalePrice() { return salePrice; }
        Date GetDatePurchased() { return datePurchased; }
        Date GetDateSold() { return dateSold; }
        bool GetIsSold() { return isSold; }

        //we can use this later to have a cleaner getprofit function
        double GetProfit()
        {
            if(isSold)
            {
                return salePrice - purchasePrice;
            }
            else
            {
                return NAN;
            }
        }


};

class CarLot
{
    private:
        vector<Car> cars;

    public:
        CarLot() {};

        void AddCar();
        void ListCurrentInv();
        void GetMonthProfit();
};

//function prototypes
bool ValidDouble(string convert, double&);
bool ValidInt(string convert, int&);

//Adds a car to a vector passed by reference. Calls conversion and validation functions as needed
//This is a somewhat meaty function and could probably benefit from some refactoring.
void CarLot::AddCar()
{
    //There are a lot of things in this function. I'm mostly using them for input validation...
    //It might be better to organize these by data type? I'm not really sure...
    string make;
    string model;
    int year;
    string modelYearString;
    double purchasePrice;
    string purchasePriceString;
    int purchaseMonth;
    string purchaseMonthString;
    int purchaseDay;
    string purchaseDayString;
    int purchaseYear;
    string purchaseYearString;
    double salePrice;
    string salePriceString;
    int saleMonth;
    string saleMonthString;
    int saleDay;
    string saleDayString;
    int saleYear;
    string saleYearString;

    bool isSold;

    Date purchaseDate;
    Date saleDate;

    cin.ignore(1000, '\n');

    cout << "Enter the make of the car: ";
    getline(cin, make);
    cout << "Enter the model of the car: ";
    getline(cin, model);
    cout << "Enter the year of the car: ";
    do
    {
        getline(cin, modelYearString);
        if(ValidInt(modelYearString, year))
        {
            break;
        }
        else
        {
            cout << "Invalid int!" << endl;
            continue;
        }
    }
    while(true);
    do
    {
        cout << "Enter the purchase price of the car: ";
        getline(cin, purchasePriceString);
        if(ValidDouble(purchasePriceString, purchasePrice))
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
            if(ValidInt(purchaseMonthString, purchaseMonth))
            {
                if(purchaseMonth > 0 && purchaseMonth < 13)
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
            if(ValidInt(purchaseDayString, purchaseDay))
            {
                break;
            }
        }
        while(true);

        do {
            cout << "Enter the year the car was purchased: ";
            getline(cin, purchaseYearString);
            if (ValidInt(purchaseYearString, purchaseYear))
            {
                if (purchaseYear > 0)
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

        Date tmpDate(purchaseDay, purchaseMonth, purchaseYear);

        if(tmpDate.DateValid())
        {
            purchaseDate = tmpDate;
            break;
        }
        else
        {
            cout << "Invalid date!" << endl;
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
                isSold = false;
                break;
            }
            else if(tolower(tmpSold.at(0)) == 'y')
            {
                isSold = true;
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

    if(isSold)
    {
        cin.ignore(1000, '\n');

        do
        {
            cout << "Enter the sale price of the car: ";
            getline(cin, salePriceString);
            if(ValidDouble(salePriceString, salePrice))
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
                if(ValidInt(saleMonthString, saleMonth))
                {
                    if(saleMonth > 0 && saleMonth < 13)
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
                if(ValidInt(saleDayString, saleDay))
                {
                    break;
                }
            }
            while(true);

            do
            {
                cout << "Enter the year the car was purchased: ";
                getline(cin, saleYearString);
                if(ValidInt(saleYearString, saleYear))
                {
                    if(saleYear > 0)
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

            Date tmpDate(saleDay, saleMonth, saleYear);

            if(tmpDate.DateValid())
            {
                saleDate = tmpDate;
            }
            else
            {
                continue;
            }

            if(saleDate.GetYear() > purchaseDate.GetYear())
            {
                break;
            }
            else if(saleDate.GetYear() == purchaseDate.GetYear())
            {
                if(saleDate.GetMonth() > purchaseDate.GetMonth())
                {
                    break;
                }
                else if(saleDate.GetMonth() == purchaseDate.GetMonth())
                {
                    if(saleDate.GetDay() >= saleDate.GetDay())
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

    if(isSold)
    {
        Car tmpCar(make, model, year, purchasePrice, purchaseDate, isSold, salePrice, saleDate);
        cars.push_back(tmpCar);
    }
    else
    {
        Car tmpCar(make, model, year, purchasePrice, purchaseDate, isSold);
        cars.push_back(tmpCar);
    }

    cout << endl << endl;
}

//Calculates the profit of a given vector passed by reference.
//Handles input, calling validataion functions, and printing actual profit.
//Tells the user if there are no cars sold in given time period.

void CarLot::GetMonthProfit()
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
        if(cars.at(i).GetDateSold().GetYear() == profitYear && cars.at(i).GetDateSold().GetMonth() == profitMonth)
        {
            //If there are, increment number of cars sold and profit number.
            //We will also use carsSold to verify that something was actually sold in the time period

            carsSold++;
            profit += cars.at(i).GetProfit();
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

//Loops through the inventory in the CarLot and prints formatted lists of what it contains. This is mostly formatting
//junk... there isn't a lot of exciting logic here.
void CarLot::ListCurrentInv()
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
        cout << "Make: " << cars.at(i).GetMake() << endl;
        cout << "Model: " << cars.at(i).GetModel() << endl;
        cout << "Year: " << cars.at(i).GetYear() << endl;
        cout << "Purchase price: $" << setprecision(2) << fixed << cars.at(i).GetPurchasePrice() << endl;
        cout << "Date purchased: " << cars.at(i).GetDatePurchased().GetMonth() << "/" << cars.at(i).GetDatePurchased().GetDay() <<
                "/" << cars.at(i).GetDatePurchased().GetYear() << endl;
        if(cars.at(i).GetIsSold())
        {
            cout << "Status: SOLD" << endl;
            cout << "Sale Price: $" << setprecision(2) << fixed << cars.at(i).GetSalePrice() << endl;
            cout << "Date sold: " << cars.at(i).GetDateSold().GetMonth() << "/" << cars.at(i).GetDateSold().GetDay() <<
                    "/" << cars.at(i).GetDateSold().GetYear() << endl;
            cout << "Profit: $" << setprecision(2) << fixed << (cars.at(i).GetSalePrice() - cars.at(i).GetPurchasePrice()) << endl;

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

bool Date::ValidMonthDayCombo(int month, int day)
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
    CarLot carLot;

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
                carLot.AddCar();
                break;
            case 2:
                carLot.ListCurrentInv();
                break;
            case 3:
                carLot.GetMonthProfit();
                break;
            case 4:
                exit(0);
            default:
                break;
        }

    }
    while(true);

    return 0;
}