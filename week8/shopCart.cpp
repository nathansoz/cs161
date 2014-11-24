/* Author: Nathan Sosnovske
 *
 * Created: 11/16/2014
 *
 * Edited: 11/16/2014
 *
 * Files: shopCart.cpp
 *
 * Overview:
 *      Simulates a shopping cart
 *
 * Input:
 *      Asks for a menu option and then:
 *      -- Allows user to input an item
 *      -- Allows user to print out items
 *      -- Gives the total
 *
 * Output:
 *
 *      See above
 *
 *
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

//basic struct... though I wonder why we can't put functions in it.
//the only difference between a struct and a class is if the members are private/public by default...
struct Item
{
    string name;
    double price;
    int quantity;
};

void AddItem(Item items[], int &cartTotal)
{
    //clear the input buffer
    cin.ignore(1000, '\n');

    Item newItem;
    string priceInput;

    cout << "Please enter the name of the item: ";
    getline(cin, newItem.name);
    cout << "Please enter the price of the item: ";
    getline(cin, priceInput);
    newItem.price = strtod(priceInput.c_str(), NULL);
    cout << "Please enter how many of this item you would like: ";
    cin >> newItem.quantity;

    items[cartTotal] = newItem;
    cartTotal++;
}


void ListContents(Item items[], int &cartTotal)
{
    cout << endl << endl << "Cart items" << endl;


    for(int i = 0; i < cartTotal; i++)
    {
        cout << endl << "Item " << i + 1 << ":" << endl;
        cout << "Name: " << items[i].name << endl;
        cout << "Price: $" << fixed << setprecision(2) << items[i].price << endl;
        cout << "Quantity: " << items[i].quantity << endl;

    }
}

void TotalPrice(Item items[], int &cartTotal)
{
    double total = 0.0;

    for(int i = 0; i < cartTotal; i++)
    {
        total += (items[i].price * items[i].quantity);
    }

    cout << endl << "The cart total is: $" << fixed << setprecision(2) << total << endl << endl;
}

int main()
{
    int cartTotal = 0;
    //we were told that there would be max 100 items. I made the array able to hold 101 items.
    Item items[100];

    do
    {
        int choice = 0;

        cout << "Welcome to the shopping cart!" << endl;
        cout << "Please chose a number:" << endl << endl;
        cout << "1) Add item" << endl;
        cout << "2) List contents" << endl;
        cout << "3) Display total price of cart items" << endl;
        cout << "4) Quit" << endl;
        cout << "Choice [1-4]: ";

        cin >> choice;

        //this is probably the best use for a switch statement.
        //I tried to keep most of the program logic outside of the main block

        switch(choice)
        {
            case 1:
                AddItem(items, cartTotal);
                break;
            case 2:
                ListContents(items, cartTotal);
                break;
            case 3:
                TotalPrice(items, cartTotal);
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