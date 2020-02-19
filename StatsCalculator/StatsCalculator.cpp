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

int nCr(int trials, int successes)
{
    return fact(trials) / (fact(successes) * 
        fact(trials - successes));
}

float negProBi(double percent, int numTrialsMinus, int numSuccessesMinus, int numTrials, int numSuccesses)
{
    const int whole = 1;
    int powNMinusK = numTrials - numSuccesses;
    float negBiAnswer = (nCr(numTrialsMinus, numSuccessesMinus) * (pow(percent, numSuccesses))) * (pow((whole - percent), powNMinusK));
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

float biProCal(double percentage, int numTrials, int numSuccesses)
{
    const int whole = 1;
    const int nMinusK = numTrials - numSuccesses;
    float biCalAns = (nCr(numTrials, numSuccesses) * (pow(percentage, numSuccesses)) * (pow((whole - percentage), nMinusK)));

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

float geoProCal(int numXValue, double percentage)
{
    const int whole = 1;
    int numXValueMinus = numXValue - 1;
    float geoCalVal = (pow((whole - percentage), numXValueMinus) * percentage);

    return geoCalVal;
}

double geoExVal(int numXValue, double percentage)
{
    const int whole = 1;
    double exVal = whole / percentage;

    return exVal;
}

double geoSTD(int numXValue, double percentage)
{
    const int whole = 1;
    const int squared = 2;
    double std;
    std = sqrt(((whole - percentage) / pow(percentage, squared)));

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
            cout << "Your probability is: " << biProCal(percent, trials, successes) << endl;
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
            cout << "What's your x value?" << endl;
            cin >> successes;
            cout << endl;
            cout << "What's your probabiltity?" << endl;
            cin >> percent;
            cout << endl;
            cout << "Your Probability is: " << geoProCal(successes, percent) << endl;
            cout << "Your expected value is: " << geoExVal(successes, percent) << endl;
            cout << "Your standard deviation is: " << geoSTD(successes, percent) << endl;

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
        else if (response == "3") {
            cout << "What's your percentage?" << endl;
            cin >> percent;
            cout << endl;
            cout << "How many trials?" << endl;
            cin >> trials;
            cout << endl;
            cout << "How many successes?" << endl;
            cin >> successes;
            int trialsMinus = trials - 1;
            int successesMinus = successes - 1;
            cout << "Your probability is: " << negProBi(percent, trialsMinus, successesMinus, trials, successes) << endl;
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