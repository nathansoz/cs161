/* Author: Nathan Sosnovske
 *
 * Created: 10/9/2014
 *
 * Edited: 10/9/2014
 *
 * Files: arcade1.cpp
 *
 * Overview:
 *      Prompts for number of tickets. Returns how many candy bars and gumballs
 *      a user will get.
 *
 * Input:
 *      One integer.
 *
 * Output:
 *      - Number of Candy Bars
 *      - Number of Gumballs
 *      - Number of leftover tickets
 *
 *
 */

#include <iostream>

using namespace std;

int main()
{
    const int TICKETS_TO_CANDY_BARS = 10;
    const int TICKETS_TO_GUMBALLS = 3;

    int tickets = -1;

    while(tickets < 0)
    {
        cout << "Please enter the number of tickets that you earned: ";
        cin >> tickets;

        if(tickets < 0)
        {
            cout << "It is impossible to have negative tickets. Please try again." << endl;
        }
    }


    int numberOfCandyBars = 0;
    int numberOfGumballs = 0;
    int remainderTickets = tickets;

    while(remainderTickets >= TICKETS_TO_CANDY_BARS)
    {
        numberOfCandyBars++;
        remainderTickets = remainderTickets - TICKETS_TO_CANDY_BARS;
    }

    while(remainderTickets >= TICKETS_TO_GUMBALLS)
    {
        numberOfGumballs++;
        remainderTickets = remainderTickets - TICKETS_TO_GUMBALLS;
    }

    cout << "Your tickets will get you: " << numberOfCandyBars << " candy bar(s) and " <<
            numberOfGumballs << " gumball(s). You will have " << remainderTickets <<
            " tickets left over.\n";

    return 0;
}