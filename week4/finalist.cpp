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

    //we aren't using zeros, so it is safe to init array with them.
    int numbers[] = {0, 0, 0, 0};

    cout << "The finalists are..." << endl;

    for(int i = 0; i < 4; i++)
    {
        bool inArray;
        int rand;

        do {

            inArray = false;
            //re-use this function I created for randFun.cpp
            rand = rand_int(1, 25);

            for (int j = 0; j < 4; j++) {
                if (numbers[j] == rand)
                {
                    //re-seed the generator if we get a similar number
                    inArray = true;
                    srand(time(NULL));
                }
            }
        }
        while(inArray);

        //store number so we can check it later

        numbers[i] = rand;

        cout << rand << endl;
    }

    return 0;
}