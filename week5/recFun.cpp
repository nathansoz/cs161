/* Author: Nathan Sosnovske
 *
 * Created: 11/1/2014
 *
 * Edited: 11/1/2014
 *
 * Files: recFun.cpp
 *
 * Overview:
 *      Generates nth number of fibonacci sequence.
 *
 * Input:
 *     One int
 *
 * Output:
 *
 *      Nth number of fibonacci sequence (2x), one calculated slow and one calculated fast.
 *
 *
 */

#include <iostream>

using namespace std;

int fib(int n)
{
    if(n > 1)
    {
        return fib(n - 1) + fib(n - 2);
    }
    else if(n == 1)
    {
        return 1;
    }
    else if(n == 0);
    {
        return 0;
    }
}

int fibEfficient(int n, int* sequence)
{
    //Here we use an array to hold our calculations from the
    //sequence. That way we don't have to recalculate every value.

    if(sequence[n-1] == 0 && sequence[n-2] == 0)
    {
        fibEfficient(n-1, sequence);
        sequence[n-1] = sequence[n-2] + sequence[n-3];
    }
    else
    {
        sequence[n-1] = sequence[n-2] + sequence [n-3];
    }

    return sequence[n-1];
}

int main()
{

    int fibNumber;

    cout << "Please enter the number of the sequence that you want (1-46 only): ";
    cin >> fibNumber;

    cout << "Starting inefficient calculation... (you will see the difference as n gets higher) " << endl;
    cout << fib(fibNumber) << endl;

    //Create int array to hold previous fib values
    //This is orders of magnitude more efficient.
    int sequence[fibNumber];
    for(int x = 0; x < fibNumber; x++)
    {
        sequence[x] = 0;
    }

    sequence[0] = 1;
    sequence[1] = 1;

    cout << "Starting efficient calculation... " << endl;
    cout << fibEfficient(fibNumber, sequence) << endl;


    return 0;
}