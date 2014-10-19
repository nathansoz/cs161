#include <iostream>
#include <string>

using namespace std;

int GetNumAlphaCharsInString(string *my_str)
{
    //Use is alpha function to find alpha chars.
    int alphaCount = 0;

    for(int i = 0; i < my_str->length(); i++)
    {

        if(isalpha(my_str->at(i)))
        {
            alphaCount++;
        }
    }

    return alphaCount;
}

void PrintStringBackward(string *my_str)
{
    // To print the string in reverse we change our array index to be the string length
    // minus 1, minus our counter. This should start at the end for a zero-indexed array

    for(int i = 0; i < my_str->length(); i++)
    {
        cout << my_str->at(my_str->length() - i - 1) << endl;
    }

    cout << endl;
}


void PrintStringForward(string *my_str)
{
    //Pretty simple. For loop that prints letters.
    //Only cool thing is using the reference

    for(int i = 0; i < my_str->length(); i++)
    {
        cout << my_str->at(i) << endl;
    }

    cout << endl;
}

int main()
{

    string my_str;

    //Use getline to handle more than one word. (per discussion question g)
    cout << "Please enter a string: ";
    getline(cin, my_str);

    //Pass by reference so that we don't have to copy the string.
    PrintStringForward(&my_str);
    PrintStringBackward(&my_str);

    cout << "Your string contains " << GetNumAlphaCharsInString(&my_str) << " alphabetic characters.\n";
    cout << endl;

    return 0;
}

