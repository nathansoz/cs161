#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

const int GUESS_NUM = 10;

bool alreadyGuessed(char guess, char (&guesses)[10])
{
    for(int i = 0; i < 10; i++)
    {
        if(guesses[i] == guess && guesses[i] != 0)
        {
            return true;
        }
    }

    return false;
}

bool isAlphaString(string verify)
{
    bool alpha = true;

    for(int i = 0; i < verify.length(); i++)
    {
        if(!isalpha(verify.at(i)))
        {
            alpha = false;
        }
    }

    return alpha;
}

bool userWon(string verify, char (&guesses)[10])
{
    int correctGuesses = 0;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < verify.length(); j++)
        {
            if(verify.at(j) == guesses[i])
            {
                correctGuesses++;
            }
        }
    }

    if(correctGuesses == verify.length())
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    string secretWord;
    int num_guesses = 0;

    do
    {
        secretWord = "";

        cout << "Please enter a word (no numbers): ";
        cin >> secretWord;

    }
    while(!isAlphaString(secretWord));

    system("clear");

    char guesses[GUESS_NUM] = {0};

    while(num_guesses < GUESS_NUM)
    {
        bool boolAlreadyGuessed = false;
        char guess;

        cout << "Please enter a letter guess: ";
        cin >> guess;

        boolAlreadyGuessed = alreadyGuessed(guess, guesses);

        if(boolAlreadyGuessed)
        {
            cout << "blah" << endl;
            continue;
        }
        else
        {
            guesses[num_guesses] = guess;
        }

        if(userWon(secretWord, guesses))
        {
            cout << "You won with " << num_guesses << " guesses!";
            break;
        }

        num_guesses++;

    }

    cout << "You didn't win! The secret word is: " << secretWord << endl;
}