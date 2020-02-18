// StatsCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int fact(int numFact)
{
    int factorial = 1;
    for (int i = 2; i <= numFact; i++)
    {
        factorial = factorial * i;
    }
    return factorial;
}

int negBiNcr(int numTrials, int numSuccesses){
    int numTrialsMinus = numTrials - 1;
    int numSuccessesMinus = numSuccesses - 1;

    return fact(numTrialsMinus) / (fact(numSuccessesMinus) *
        fact(numTrialsMinus - numSuccessesMinus));
}

int nCr(int trials, int successes)
{
    return fact(trials) / (fact(successes) * 
        fact(trials - successes));
}

double negBi(double percent, int numTrials, int numSuccesses)
{
    const int whole = 1;
    int powNMinusK = numTrials - numSuccesses;
    double negBiAnswer = (negBiNcr(numTrials, numSuccesses) * (pow(percent, numSuccesses))) * (pow((whole - percent), powNMinusK));
    return negBiAnswer;
}

double negExVal(int numSuccesses, double percentVal)
{
    double exVal = numSuccesses / percentVal;
    return exVal;
}

double stdNegBi(int numSuccesses, double percentVal)
{
    const int whole = 1;
    const int squared = 2;
    double std;
    std = sqrt((numSuccesses * (whole - percentVal)) / (pow(percentVal, squared)));
    return std;
}

double biCal(double percentage, int numTrials, int numSuccesses)
{
    const int whole = 1;
    const int nMinusK = numTrials - numSuccesses;
    double biCalAns = (nCr(numTrials, numSuccesses) * (pow(percentage, numSuccesses)) * (pow((whole - percentage), nMinusK)));

    return biCalAns;
}

double biExVal(int numTrials, double percentage) 
{
    double ExVal = numTrials * percentage;

    return ExVal;
}

double stdBi(int numTrials, double percentage) 
{
    const int whole = 1;
    double std;
    std = sqrt(((numTrials * percentage) * (whole - percentage)));
    return std;
}

int main()
{
    //n = trials
    //k = successes
    int trials;
    int successes;
    double percent;
    string response;
    cout << "Stats Calculator" << endl;
    cout << endl;
    cout << "1. Binomial with Expected Value and Standard Deviation" << endl;
    cout << "2. Geometric with Expected Value and Standard Deviation" << endl;
    cout << "3. Negative Geometric with Expected Value and Standard Deviation" << endl;
    cout << "4. Quit" << endl;
    cout << endl;
    cout << "Which would you like to open (1, 2, 3, 4):";
    cin >> response;
    while (response != "4")
    {
        if (response == "1") {
            cout << "How many trials?" << endl;
            cin >> trials;
            cout << endl;
            cout << "What's your x value?" << endl;
            cin >> successes;
            cout << endl;
            cout << "What's your percentage?" << endl;
            cin >> percent;
            cout << endl;
            cout << "Your probability is: " << biCal(percent, trials, successes) << endl;
            cout << "Your Expected Value is: " << biExVal(trials, percent) << endl;
            cout << "Your Standard Deviation is: " << stdBi(trials, percent) << endl;
            //Stats Menu
            cout << endl;
            cout << "Stats Calculator" << endl;
            cout << endl;
            cout << "1. Binomial with Expected Value and Standard Deviation" << endl;
            cout << "2. Geometric with Expected Value and Standard Deviation" << endl;
            cout << "3. Negative Geometric with Expected Value and Standard Deviation" << endl;
            cout << "4. Quit" << endl;
            cout << endl;
            cout << "Which would you like to open (1, 2, 3, 4):";
            cin >> response;
        } 
        else if (response == "2") {
            cout << "Work in Progress" << endl;
        }
        else if (response == "3") {
            cout << "What's your percentage?" << endl;
            cin >> percent;
            cout << endl;
            cout << "How many trials?" << endl;
            cin >> trials;
            cout << endl;
            cout << "How many successes?" << endl;
            cin >> successes;
            cout << "Your probability is: " << negBi(percent, trials, successes) << endl;
            cout << "Your Expected Value is: " << negExVal(successes, percent) << endl;
            cout << "Your Standard Deviation is: " << stdNegBi(successes, percent) << endl;

            //Stats Cal Menu
            cout << endl;
            cout << "Stats Calculator" << endl;
            cout << endl;
            cout << "1. Binomial with Expected Value and Standard Deviation" << endl;
            cout << "2. Geometric with Expected Value and Standard Deviation" << endl;
            cout << "3. Negative Geometric with Expected Value and Standard Deviation" << endl;
            cout << "4. Quit" << endl;
            cout << endl;
            cout << "Which would you like to open (1, 2, 3, 4):";
            cin >> response;
        }
        else {
            cout << "Invalid Command Try Again" << endl;
            cout << endl;
            cout << "Stats Calculator" << endl;
            cout << endl;
            cout << "1. Binomial with Expected Value and Standard Deviation" << endl;
            cout << "2. Geometric with Expected Value and Standard Deviation" << endl;
            cout << "3. Negative Geometric with Expected Value and Standard Deviation" << endl;
            cout << "4. Quit" << endl;
            cout << endl;
            cout << "Which would you like to open (1, 2, 3, 4):";
            cin >> response;
        }
    }
    cout << "Closing Program" << endl;
    return 0;
}