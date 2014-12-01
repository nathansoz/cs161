/* Author: Nathan Sosnovske
 *
 * Created: 11/30/2014
 *
 * Edited: 11/30/2014
 *
 * Files: geom.cpp
 *
 * Overview:
 *      Takes two points and calculates the distance
 *
 * Input:
 *      - Asks for two points, separated by spaces

 *
 * Output:
 *
 *      - Distance and slope of two points
 *
 *
 */

#include <iomanip>
#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

class Point
{
    private:
        double x;
        double y;

    public:
        //default constructor
        Point() {}

        //this is the intended constructor for our users
        Point(double X, double Y)
        {
            x = X;
            y = Y;
        }

        double GetX() const
        {
            return x;
        }
        double GetY() const
        {
            return y;
        }

        double DistanceTo(const Point& otherPoint)
        {
            return sqrt(pow((otherPoint.GetX() - x), 2) + pow((otherPoint.GetY() - y), 2));
        }

};

class LineSegment
{
    private:
        Point p1;
        Point p2;

    public:
        LineSegment() {}
        LineSegment(Point P1, Point P2)
        {
            p1 = P1;
            p2 = P2;
        }

        //we don't define setters for this class, so it would technically be more efficient to calculate
        //length in our constructor and then store it as a property...
        double Length()
        {
            if (p1.GetX() == p2.GetX() && p1.GetY() == p2.GetY())
            {
                return 0;
            }
            else
            {
                return p1.DistanceTo(p2);
            }
        }

        double Slope()
        {
            return ((p2.GetY() - p1.GetY()) / (p2.GetX() - p1.GetX()));
        }

};

int main()
{
    bool loop;

    do {
        double p1X;
        double p1Y;
        double p2X;
        double p2Y;
        char loopChar;

        cout << "Please enter an X and Y coordinate, separated by a space: ";
        cin >> p1X >> p1Y;
        cin.ignore(1000, '\n');

        cout << "Please enter an X and Y coordinate, separated by a space: ";
        cin >> p2X >> p2Y;

        //build our objects. I guess i could make setter functions to make this a bit cleaner...
        Point p1(p1X, p1Y);
        Point p2(p2X, p2Y);
        LineSegment line(p1, p2);

        cout << "The distance between the two points is " << line.Length() << endl;
        if (isinf(line.Slope()))
        {
            cout << "The line is vertical." << endl;
        }
        else
        {
            cout << "The slope of the line is " << line.Slope() << endl;
        }

        cout << "Would you like to enter new points? (y/n): ";
        cin >> loopChar;
        if(tolower(loopChar) == 'y')
        {
            loop = true;
        }
        else if (loopChar == 'n')
        {
            loop = false;
        }
        else
        {
            cout << "Invalid input! Exiting." << endl;
            exit(0);
        }

    }
    while(loop);

    return 0;
}