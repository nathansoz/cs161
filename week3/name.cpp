#include <iostream>
#include <string>

using namespace std;

bool containsMiddleName(string *name)
{
    int spaces = 0;
    for(int i = 0; i < name->size(); i++)
    {
        if(name->at(i) == ' ')
        {
            spaces++;
        }
    }

    if(spaces == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

string split(string *opString, char splitChar)
{
    int splitPos = -1;

    string firstString;
    string secondString;
    
    for(int i = 0; i < opString->size(); i++)
    {
        if(opString->at(i))
        {
            splitPos = i;
            break;
        }
    }

    if(splitPos > -1)
    {
        for(int i = splitPos + 1; i < opString->size(); i++)
        {
            secondString.append(1, opString->at(i));
        }

        opString->erase(splitPos, opString->size() - 1);
    }

    cout << "first " << opString << " second " << secondString;
    return firstString;
}

int main()
{
    string name;

    cout << "Please enter your name in format: First Middle Last: ";
    getline(cin, name);

    split(&name, ' ');
    return 0;
}