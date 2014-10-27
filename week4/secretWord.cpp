/* Author: Nathan Sosnovske
 *
 * Created: 10/26/2014
 *
 * Edited: 10/26/2014
 *
 * Files: secretWord.cpp
 *
 * Overview:
 *      Hangman clone
 *
 * Input:
 *      user 1 word, user 2 guesses (10)
 *
 * Output:
 *
 *      correct? If so, number of guesses and word. If not, the word.
 *
 *
 */

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

const int GUESS_NUM = 10;

bool alreadyGuessed(char guess, char (&guesses)[GUESS_NUM])
{
    for(int i = 0; i < GUESS_NUM; i++)
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

bool userWon(string verify, char (&guesses)[GUESS_NUM])
{
    int correctGuesses = 0;

    for(int i = 0; i < GUESS_NUM; i++)
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
    char playAgain = 'n';

    do {
        string secretWord;
        bool won = false;
        int num_guesses = 0;

        do {
            secretWord = "";

            cout << "Please enter a word (no numbers): ";
            cin >> secretWord;

        }
        while (!isAlphaString(secretWord));

        system("clear");

        char guesses[GUESS_NUM] = {0};

        while (num_guesses < GUESS_NUM) {
            bool boolAlreadyGuessed = false;

            char guess;

            cout << "The word currently looks like: ";
            for (int i = 0; i < secretWord.length(); i++) {
                bool letterMatch = false;

                for (int j = 0; j < GUESS_NUM; j++) {
                    if (secretWord.at(i) == guesses[j]) {
                        letterMatch = true;
                        cout << guesses[j] << " ";
                    }
                }

                if (!letterMatch) {
                    cout << "_ ";
                }
            }

            cout << endl;

            if (num_guesses > 0) {
                cout << "You already have guessed: ";
                for (int i = 0; i < GUESS_NUM; i++) {
                    if (guesses[i] != 0) {
                        cout << guesses[i] << " ";
                    }
                }

                cout << endl;
            }

            cout << "Please enter a letter guess: ";
            cin >> guess;

            boolAlreadyGuessed = alreadyGuessed(guess, guesses);

            if (boolAlreadyGuessed) {
                cout << "You already guessed that letter:" << endl;
                continue;
            }
            else {
                guesses[num_guesses] = guess;
            }

            if (userWon(secretWord, guesses)) {
                num_guesses++;
                cout << "You won with " << num_guesses << " guesses!" << endl;
                won = true;
                break;
            }

            num_guesses++;
            system("clear");
        }

        if (!won) {
            cout << "You didn't win! The secret word is: " << secretWord << endl;
        }
        else {
            cout << "The secret word is: " << secretWord << endl;
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;
        playAgain = tolower(playAgain);

    }
    while(playAgain == 'y');
}