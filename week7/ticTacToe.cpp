#include <iostream>
#include <stdlib.h>

using namespace std;

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

void GameLoop(int games, int &player1Score, int &player2Score)
{
    int gameCount = 0;
    char board[3][3];

    do
    {
        InitializeBoard(board);
        PrintBoard(board);


        gameCount++;
    }
    while(gameCount < games);
}

int main(int argc, char* argv[])
{
    int player1Score = 0;
    int player2Score = 0;

    if(argc == 1)
    {
        GameLoop(1, player1Score, player2Score);
    }
    else if(argc == 2)
    {
        //validate input here
        GameLoop(atoi(argv[1]), player1Score, player2Score);
    }
    else
    {
        cout << "Invalid number of arguments.";
    }
}