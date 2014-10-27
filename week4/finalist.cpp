#include <iostream>
#include <stdlib.h>

using namespace std;

int rand_int(int min, int max)
{
    // The c++ documentation shows how to generate a string range from 0-num with
    // the modulo operator. From there we just add the lowerBound to get us in the right range.

    int randomNumber = rand() % ((max - min) + 1) + min;
    return randomNumber;
}

int main()
{
    srand(time(NULL));

    int numbers[] = {0, 0, 0, 0};

    for(int i = 0; i < 4; i++)
    {
        bool inArray;
        int rand;

        do {

            inArray = false;
            rand = rand_int(1, 25);

            for (int j = 0; j < 4; j++) {
                if (numbers[j] == rand)
                {
                    inArray = true;
                    srand(time(NULL));
                }
            }
        }
        while(inArray);

        numbers[i] = rand;

        cout << rand << endl;
    }
}