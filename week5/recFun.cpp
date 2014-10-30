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
}

int main()
{
    cout << fib(4);

    return 0;
}