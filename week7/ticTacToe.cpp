/* Author: Nathan Sosnovske
 *
 * Created: 11/16/2014
 *
 * Edited: 11/16/2014
 *
 * Files: ticTacToe.cpp
 *
 * Overview:
 *      A game of tic tac toe
 *
 * Input:
 *      number of games on the command line
 *      moves
 *
 * Output:
 *
 *      board and winner of each game
 *      overall winner
 *
 *
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

//checks to see if a move has already been made
bool MoveMade(int row, int col, char board[3][3])
{
    if(board[row][col] == '.')
    {
        return false;
    }
    else
    {
        return true;
    }
}

//checks to see if a player has won
bool PlayerWon(char board[3][3], int &playerXScore, int &playerOScore)
{
    for(int i = 0; i < 3; i++)
    {
        //loop through the rows checking for valid win conditions
        if(board[i][0] != '.' && board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            char playerWon = board[i][0];
            if(playerWon == 'X')
            {
                playerXScore++;
            }
            else
            {
                playerOScore++;
            }
            return true;
        }
        // we can take care of the columns at the same time to be more efficient
        else if(board[0][i] != '.' && board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            char playerWon = board[0][i];
            if(playerWon == 'X')
            {
                playerXScore++;
            }
            else
            {
                playerOScore++;
            }
            return true;
        }
    }

    //check the diagonals.
    if(board[0][0] != '.' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        char playerWon = board[0][0];
        if(playerWon == 'X')
        {
            playerXScore++;
        }
        else
        {
            playerOScore++;
        }
        return true;
    }
    else if(board[0][2] != '.' && board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        char playerWon = board[0][2];
        if(playerWon == 'X')
        {
            playerXScore++;
        }
        else
        {
            playerOScore++;
        }
        return true;
    }
    else
    {
        return false;
    }

}

//besides the game loop, this is the most important part. This parses user input and makes sure it is valid
void UserMove(char player, char board[3][3])
{
    string userInput;

    do
    {
        int row;
        int col;
        cout << "It is player " << player << "'s move." << endl;
        cout << "Please enter the coordinates for your move, separated by a space(row, column): ";

        getline(cin, userInput);
        if(userInput.length() == 3)
        {
            if(userInput.at(1) == ' ')
            {
                char rowChar[2];
                char colChar[2];
                rowChar[0] = userInput.at(0);
                colChar[0] = userInput.at(2);
                rowChar[1] = '\0';
                rowChar[1] = '\0';

                if(atoi(rowChar) < 3 && atoi(colChar) < 3)
                {
                    row = atoi(rowChar);
                    col = atoi(colChar);

                    if(!MoveMade(row, col, board))
                    {
                        board[row][col] = player;
                        break;
                    }
                    else
                    {
                        cout << "That move has already been made!" << endl;
                        continue;
                    }

                }
                else
                {
                    cout << "Invalid coordinates. Coordinates must be in range 0-2." << endl;
                    continue;
                }
            }
            else
            {
                cout << "Invalid input. Please separate your coordinates with a space." << endl;
                continue;
            }
        }
        else
        {
            cout << "Invalid input. A valid input string has two coordinate integers, separated by a space." << endl;
            continue;
        }
    }
    while(true);



}

//We need something to track unused squares that gives console visibility.
void InitializeBoard(char board[3][3])
{
    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            board[row][col] = '.';
        }
    }
}

//Simple function to print board and grid to screen
void PrintBoard(char board[3][3])
{
    cout << "  0 1 2" << endl;
    for(int row = 0; row < 3; row++)
    {
        cout << row << " ";

        for(int col = 0; col < 3; col++)
        {
            cout << board[row][col] << " ";
        }

        cout << endl;
    }

}

//This gameloop is called by main and only exits after all games have been played. We leave checking the total scores
//to main.
void GameLoop(int games, int &playerXScore, int &playerOScore)
{
    int gameCount = 0;
    char board[3][3];
    char playerWithNextFirstMove = 'X';
    char playerToMove;

    do
    {
        bool playerWon = false;
        int moves = 0;
        playerToMove = playerWithNextFirstMove;


        if(playerWithNextFirstMove == 'X')
        {
            playerWithNextFirstMove = 'O';
        }
        else
        {
            playerWithNextFirstMove = 'X';
        }



        cout << endl << "New game!" << endl;
        cout << "Player " << playerToMove << " to move first." << endl;
        InitializeBoard(board);
        PrintBoard(board);

        do
        {
            UserMove(playerToMove, board);
            moves++;
            PrintBoard(board);
            playerWon = PlayerWon(board, playerXScore, playerOScore);

            if(playerWon)
            {
                cout << "Congrats! Player " << playerToMove << " won!" << endl;
            }
            else if(moves == 9)
            {
                cout << "Tie game!" << endl;

                if(playerToMove == 'X')
                {
                    playerToMove = 'O';
                }
                else
                {
                    playerToMove = 'X';
                }

                break;
            }
            if(playerToMove == 'X')
            {
                playerToMove = 'O';
            }
            else
            {
                playerToMove = 'X';
            }

        }
        while(!playerWon);


        gameCount++;
    }
    while(gameCount < games);
}

int main(int argc, char* argv[])
{
    int playerXScore = 0;
    int playerOScore = 0;

    if(argc == 1)
    {
        //Call our game loop to only play one game, if we had no arguments.
        GameLoop(1, playerXScore, playerOScore);
    }
    else if(argc == 2)
    {
        //Play the game!
        GameLoop(atoi(argv[1]), playerXScore, playerOScore);
    }
    else
    {
        cout << "Invalid number of arguments.";
        exit(1);
    }

    cout << "Player X's score is: " << playerXScore << endl;
    cout << "Player O's score is: " << playerOScore << endl;
    if(playerXScore > playerOScore)
    {
        cout << "Player X wins!" << endl;
    }
    else if(playerOScore > playerXScore)
    {
        cout << "Player O wins!" << endl;
    }
    else
    {
        cout << "Player X and player O tied!" << endl;
    }

    return 0;

}