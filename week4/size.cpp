/* Author: Nathan Sosnovske
 *
 * Created: 10/26/2014
 *
 * Edited: 10/26/2014
 *
 * Files: size.cpp
 *
 * Overview:
 *      Calculates sizes for clothes.
 *
 * Input:
 *      Height, weight and age (double, double, int)
 *
 * Output:
 *
 *      hat size, jacket size, and waist size
 *
 *
 */

#include <iostream>

using namespace std;

const double HAT_SIZE_CONST = 2.9;
const double JACKET_SIZE_CONST = 288;
const double JACKET_SIZE_ADJ_CONST = .125;
const double WAIST_SIZE_CONST = 5.7;
const double WAIST_SIZE_ADJ_CONST = .10;

double hatSize(double weight, double height)
{
    double hatSize = (weight / height) * HAT_SIZE_CONST;

    return hatSize;
}

double jacketSize(double weight, double height, int age)
{
    int adjustmentFactor = ((age - 29) / 10);
    double adjustment = static_cast<double>(adjustmentFactor) * JACKET_SIZE_ADJ_CONST;
    double jacketSize = ((height * weight) / JACKET_SIZE_CONST) + adjustment;

    return jacketSize;
}

double waistSize(double weight, int age)
{
    int adjustmentFactor = ((age - 28) / 2);
    double adjustment = static_cast<double>(adjustmentFactor) * WAIST_SIZE_ADJ_CONST;
    double waistSize = (weight / WAIST_SIZE_CONST) + adjustment;

    return waistSize;

}


int main()
{
    char runAgain = 'n';

    do
    {
        double weight;
        double height;
        int age;

        cout << "Please enter your weight: ";
        cin >> weight;

        cout << "Please enter your height: ";
        cin >> height;

        cout << "Please enter your age: ";
        cin >> age;

        cout << "Your hat size is " << hatSize(weight, height) << ". Your jacket size is " << jacketSize(weight, height, age) <<
                ". Your waist size is: " << waistSize(weight, age) << "." << endl << endl;

        cout << "Run again? (y/n): ";
        cin >> runAgain;

        runAgain = tolower(runAgain);

    }
    while (runAgain == 'y');

    return 0;
}
