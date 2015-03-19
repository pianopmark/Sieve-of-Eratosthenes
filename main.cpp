/**************************************************************************************************************************
Title: Sieve of Eratosthenes
Author: Mark Lindo
Created On: 02/25/2015
Build With: g++ main.cpp
Use: Demonstrate the use of the Sieve of Eratosthenes algorithm to find prime numbers
Revisions:
    02/25/15: Basic layout of main function, initial implementation of algorithm for generating prime numbers
    02/26/15: Adjusted main() to use array of size 10000 instead of vector, finished Sieve algorithm
    02/26/15: Testing of program
**************************************************************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int input;

    cout << "Enter a number larger than 1" << endl;
    cin >> input;

    if (input <= 1)                                                 //Check to see if user input is larger than 1, if not
    {                                                               //terminates the program
        cout << "Invalid input!" << endl;
        return -1;
    }

    int arr[10000] = {0};                                           //Initialize array of size 10000 all as 0s

    for (int i = 2; i < input; i++)
    {
        for (int x = i * i; x < input; x+=i)
        {
            arr[x - 1] = 1;                                         //Marks spots in array with 1 if element is a non-prime
        }
    }
    for (int i = 1; i < input; i++)
    {
        if (arr[i - 1] == 0)                                        //Checks to see if content of array has been changed (is a prime number)
            cout << i << endl;                                      //and if so prints it, skips it if not
    }
}
