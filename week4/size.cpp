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
    double adjustment = static_cast<double>(adjustmentFactor) * JACKET_SIZE_CONST;
    double jacketSize = ((height * weight) / JACKET_SIZE_CONST) + adjustment;

    return adjustment;
}

double waistSize(double weight, int age)
{
    int adjustmentFactor = ((age - 28) / 2);
    double adjustment = static_cast<double>(adjustmentFactor) * WAIST_SIZE_ADJ_CONST;
    double waistSize = (weight / WAIST_SIZE_CONST) + adjustment;

}

