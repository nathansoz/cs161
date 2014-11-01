/* Author: Nathan Sosnovske
 *
 * Created: 11/1/2014
 *
 * Edited: 11/1/2014
 *
 * Files: retFun.cpp
 *
 * Overview:
 *      Takes two strings and sees if they match.
 *
 * Input:
 *      Two strings, sequentially.
 *
 * Output:
 *
 *      -The strings match
 *      OR
 *      -The strings do not match
 *
 *
 */

#include <iostream>
#include <string>

using namespace std;

bool StrComp(string &string1, string &string2)
{
    //Check to see if the length matches.

    if(string1.length() != string2.length())
    {
        // Cut this one off before we have to loop through the characters
        return false;
    }
    else
    {
        for(int i = 0; i < string1.length(); i++)
        {
            if(string1.at(i) == string2.at(i))
            {
                // Move to next char
                continue;
            }
            else
            {
                // Oops! We didn't match!
                return false;
            }
        }

        // If we made it out of the for loop, that means we didn't return false and all chars matched.

        return true;
    }

}

int main()
{
    string string1;
    string string2;

    cout << "Enter two strings." << endl;
    cout << "String 1: ";
    getline(cin, string1);
    cout << "String 2: ";
    getline(cin, string2);

    bool same = StrComp(string1, string2);

    if(same)
    {
        cout << "The strings are the same." << endl;
    }
    else
    {
        cout << "The strings are different." << endl;
    }

    return 0;
}