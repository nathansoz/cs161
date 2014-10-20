/* Author: Nathan Sosnovske
 *
 * Created: 10/19/2014
 *
 * Edited: 10/19/2014
 *
 * Files: randNum.cpp
 *
 * Overview:
 *      Generates a sequence of 10 random numbers
 *
 * Input:
 *      N/A
 *
 * Output:
 *
 *      Random numbers (10)
 *
 *
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    // this loop will always produce the same results (on the same computer) because it uses the same seed
    // a better program would use the line that is commented out below:
    // srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        cout << rand() << endl;
    }

    return 0;
}