//I ALSO INCLUDED A BONUS FILE! Check out grades.rs for a version of this in rust, mozilla's new systems
// programming language. see:  http://en.wikipedia.org/wiki/Rust_(programming_language)

/* Author: Nathan Sosnovske
 *
 * Created: 11/9/2014
 *
 * Edited: 11/9/2014
 *
 * Files: grades.cpp
 *
 * Overview:
 *      Takes an abitrary number of ints (0-5) and returns an array with the number for each int.
 *
 * Input:
 *      n number of ints 0-5
 *
 * Output:
 *
 *      n number 0...n number 5
 *
 *
 */

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

const int NUM_GRADE_COLUMNS = 6;

void addGrade(int grade, int gradeArray[])
{
    gradeArray[grade]++;
}

void printGrades(int gradeArray[], int gradeColumns)
{
    for(int x = 0; x < gradeColumns; x++)
    {
        cout << gradeArray[x] << " grade(s) of " << x << endl;
    }
}

int main()
{
    cout << "Welcome to the grading program!" << endl;
    cout << "Please type each grade, followed by the return key." << endl;
    cout << "Grades can be in the range of 0-5. Type 'exit' to leave." << endl << endl;

    bool continueGrading = true;
    int gradeArray[NUM_GRADE_COLUMNS] = { 0 };

    do
    {
        string input;
        cout << "Grade: ";
        cin >> input;

        if(input == "exit")
        {
            printGrades(gradeArray, NUM_GRADE_COLUMNS);
            continueGrading = false;
            continue;
        }

        char* stopped;
        long grade = strtol(input.c_str(), &stopped, 10);


        //we can use pointer arithmetic in order to figure out if strtol stopped before the end of the string
        //This is documented in the c++ online reference. If it reads in the whole string it should be pointing
        //At the \0 (end) of the string

        if(stopped >= (input.c_str() + input.length()))
        {
            if(grade >= 0 && grade < NUM_GRADE_COLUMNS)
            {
                addGrade(static_cast<int>(grade), gradeArray);
            }
            else
            {
                cout << "Invalid grade number. Please enter a number between 0 and " << (NUM_GRADE_COLUMNS - 1) << endl;
                continue;
            }
        }
        else
        {
            cout << "Invalid non-numeric string!" << endl;
            continue;
        }




    }
    while(continueGrading);
}