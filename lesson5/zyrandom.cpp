//
//  zyrandom.cpp
//  Linux_C++
//
//  Created by honglongsoo on 16/11/3.
//  Copyright © 2016年 honglongsoo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

void Randomize()
{
    srand((int)time(NULL));
}

int GenerateRandomNumber(int low, int high)
{
//    int number;
//    double _d;
    if (low > high) {
        cout << "GenerateRandomNumber: Make sure low <= high.\n";
        exit(1);
    }
//    int n = rand();
    
//    _d = (double)rand() / ((double)RAND_MAX + 1.0);
//    return (low + (int)(_d * (high - low + 1)));
    
//    double _d = (double)rand() / (double)RAND_MAX;
//    number = ceil(_d * (high - low)) + low;
//    return number;
    
    return rand() % (high - low + 1) + low;
}

double GenerateRandomReal(double low, double high)
{
    double real;
    if (low > high) {
        cout << "GenerateRandomReal: Make sure low <= high.\n";
        exit(2);
    }
    double _d = (double)rand() / (double)RAND_MAX;
    real = _d * (high - low) + low;
    return real;
}

void TestGenerateRandomNumber()
{
    //    int low_n = 0, high_n = 0;
    //    int low = 2, high = 3;
    //
    //    for (int i = 0; i < 500; i++) {
    //        int n = GenerateRandomNumber(low, high);
    //        if (n == low)
    //            low_n++;
    //        else
    //            high_n++;
    //
    //    }
    //    cout << low << " : " << low_n << endl;
    //    cout << high << " : " << high_n << endl;
//    cout << RAND_MAX << endl;
    int low = 1, high = 52;
    for (int i = 0; i < high; i++) {
        int _n = GenerateRandomNumber(low, high);
        cout << _n << ", ";
    }
    cout << endl;
}

void TestGenterateRandomReal()
{
    double low = 1.0, high = 10.0;
    cout << setiosflags(ios::fixed) << setprecision(2);
    for (int i = 0; i < 10; i++) {
        double _d = GenerateRandomReal(low, high);
        cout << _d << "; ";
    }
    cout << endl;
}

