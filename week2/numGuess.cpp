/* Author: Nathan Sosnovske
 *
 * Created: 10/9/2014
 *
 * Edited: 10/9/2014
 *
 * Files: numGuess.cpp
 *
 * Overview:
 *      Prompts for a number between 1 - 100 (inclusive).
 *      Prompts for guesses three times and then allows
 *      users to play again.
 *
 * Input:
 *      - One integer
 *      - One guess (int), up to three times
 *      - Play again marker (char)
 *
 * Output:
 *      The program will display a range that player 2 can guess from.
 *      That range will adjust as the program goes on. It will then
 *      notify the player if they win or lose. It then asks to play again.
 *
 *
 */

#include <iostream>
#include <cstdlib>

using namespace std;


bool outOfBounds(int number, int min, int max)
{
    return number < min || number > max;
}


int main()
{
    const int NUM_GUESSES = 3;
    const int MIN_NUMBER = 1;
    const int MAX_NUMBER = 100;

    char playAgain = 'n';

    do
    {
        int magicNumber = MIN_NUMBER - 1;

        cout << endl << "Welcome to the number guessing game!" << endl;
        cout << endl;
        cout << "Player 1: Please enter an integer between " << MIN_NUMBER <<
                " and " << MAX_NUMBER << " (inclusive)." << endl;
        cout << "Floats will always be rounded down." << endl;

        while(outOfBounds(magicNumber, MIN_NUMBER, MAX_NUMBER))
        {

            cout << "Number please: ";
            cin >> magicNumber;

            if(outOfBounds(magicNumber, MIN_NUMBER, MAX_NUMBER))
            {
                cout << "Number is out of bounds. Please try again" << endl;
            }
        }

        // Guessing section
        int lowerBound = MIN_NUMBER;
        int upperBound = MAX_NUMBER;
        bool numGuessed = false;
        int closestGuess = -1;

        cout << "Player 2: Please guess the number that player 1 chose." << endl;

        for (int i = 0; i < NUM_GUESSES; i++)
        {

            int guess = MIN_NUMBER - 1;
            int remainingGuesses = NUM_GUESSES - i;


            cout << "You have " << remainingGuesses << " guesses remaining." << endl;
            cout << "Please choose a number between " << lowerBound << " and " << upperBound << ".\n";

            while(outOfBounds(guess, lowerBound, upperBound))
            {
                cout << "(" << lowerBound << " - " << upperBound << "): ";
                cin >> guess;

                if(outOfBounds(guess, lowerBound, upperBound))
                {
                    cout << "Number is out of bounds. Please try again" << endl;
                }
            }

            if(guess < magicNumber)
            {
                cout << "Your guess was too low!" << endl;
                lowerBound = guess + 1;

                if(closestGuess == -1)
                {
                    closestGuess = guess;
                }
                else
                {
                    if(abs(magicNumber - closestGuess) > abs(magicNumber - guess))
                    {
                        closestGuess = guess;
                    }
                }
            }
            else if(guess > magicNumber)
            {
                cout << "Your guess was too high!" << endl;
                upperBound = guess - 1;

                if(closestGuess == -1)
                {
                    closestGuess = guess;
                }
                else
                {
                    if(abs(magicNumber - closestGuess) > abs(magicNumber - guess))
                    {
                        closestGuess = guess;
                    }
                }
            }
            else
            {
                cout << "Congrats! You won!" << endl;
                numGuessed = true;
                break;
            }
        }

        if(!numGuessed)
        {
            cout << "Player 2 lost. Player 1 had number " << magicNumber << endl;
            cout << "Player 2's closest guess was " << closestGuess << endl;
        }

        cout << "Enter 'y' to play again: ";
        cin >> playAgain;

    } while (tolower(playAgain) == 'y');

    return 0;
}