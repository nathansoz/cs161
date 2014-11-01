#include <iostream>
#include <sys/time.h>

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
    //The timer code I used came from this stackoverflow article
    // http://stackoverflow.com/questions/275004/c-timer-function-to-provide-time-in-nano-seconds

    int fibNumber;

    timespec beg1;
    timespec end1;
    timespec beg2;
    timespec end2;

    cout << "Please enter the number of the sequence that you want (1-46 only): ";
    cin >> fibNumber;

    //Get time on each side of function run. We can subtract to get running time.
    clock_gettime(CLOCK_REALTIME, &beg1);
    cout << fib(fibNumber) << endl;
    clock_gettime(CLOCK_REALTIME, &end1);

    if((end1.tv_nsec - beg1.tv_nsec) < 0 || fibNumber > 42)
    {
        cout << "Calculation took: " << (end1.tv_sec - beg1.tv_sec) << " second(s). (imprecise)."  << endl;
    }
    else
    {
        cout << "Calculation took " << (end1.tv_nsec - beg1.tv_nsec) << " nanoseconds." << endl;
    }


    //Create int array to hold previous fib values
    //This is orders of magnitude more efficient.
    int sequence[fibNumber];
    for(int x = 0; x < fibNumber; x++)
    {
        sequence[x] = 0;
    }

    sequence[0] = 1;
    sequence[1] = 1;


    clock_gettime(CLOCK_REALTIME, &beg2);
    cout << fibEfficient(fibNumber, sequence) << endl;
    clock_gettime(CLOCK_REALTIME, &end2);
    cout << "Calculation took: " << (end2.tv_nsec - beg2.tv_nsec) << " nanoseconds." << endl;

    return 0;
}