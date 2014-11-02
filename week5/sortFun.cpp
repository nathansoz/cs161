/* Author: Nathan Sosnovske
 *
 * Created: 11/1/2014
 *
 * Edited: 11/1/2014
 *
 * Files: sortFun.cpp
 *
 * Overview:
 *      Sorts three ints
 *
 * Input:
 *      Three ints
 *
 * Output:
 *
 *      Three ints,sorted.
 *
 *
 */

#include <iostream>

using namespace std;

//pretty sure that using an array here would be better...
void sort3(int &val1, int &val2, int &val3)
{
    //This is basically a dumbed down bubble sort... It could be re-written with an array to take n values
    do
    {
        if(val1 > val2)
        {
            int tmpVar;

            tmpVar = val2;
            val2 = val1;
            val1 = tmpVar;
        }
        if(val2 > val3)
        {
            int tmpVar;
            tmpVar = val3;
            val3 = val2;
            val2 = tmpVar;
        }
    }
    while(val1 > val2 || val2 > val3 || val1 > val3);
}

int main()
{
    int a;
    int b;
    int c;

    cout << "Please enter int a: ";
    cin >> a;
    cout << "Please enter int b: ";
    cin >> b;
    cout << "Please enter int c: ";
    cin >> c;

    sort3(a, b, c);

    cout << "Sorted values: " << a << " " << b << " " << c << endl;

    sort3(c, a, b);

    cout << "Sorted values (c, a, b): " << c << " " << a << " " << b << endl;

}