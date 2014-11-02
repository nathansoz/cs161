/* Author: Nathan Sosnovske
 *
 * Created: 11/1/2014
 *
 * Edited: 11/1/2014
 *
 * Files: hailstone.cpp
 *
 * Overview:
 *      Generates hailstone sequence and reports times ran.
 *
 * Input:
 *      One int
 *
 * Output:
 *
 *      hailstone sequence and times ran (ints)
 *
 *
 */

#include <iostream>

using namespace std;

void hailstone(int n, int &timesRun)
{
    if(n == 1)
    {
        cout << n << endl;
        //break
    }
    else
    {
        if((n % 2) == 0)
        {
            cout << n << endl;
            hailstone((n / 2), timesRun);
            timesRun++;
        }
        else
        {
            cout << n << endl;
            hailstone(((n * 3) + 1), timesRun);
            timesRun++;
        }
    }
}

int main()
{

    int initialNum;
    int numRun = 0;

    cout << "Enter an initial hailstone integer: ";
    cin >> initialNum;

    hailstone(initialNum, numRun);

    cout << "Ran " << numRun << " times.";


}