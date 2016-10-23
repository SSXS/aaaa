//
//  lesson1.cpp
//  C++Linux
//
//  Created by honglongsoo on 16/10/2.
//  Copyright © 2016年 honglongsoo. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>

#include "lesson1.h"

using namespace std;

void lesson1Main()
{
//    int sum = CalculateSum();
//    cout << "The sum of ten number: " << sum << endl;
    
    float sumOfMoney = CalculateDepositRate();
    
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "sum of money: " << sumOfMoney << endl;
   
    cout << setprecision(3) << 1.220323 << endl;
}

int CalculateSum()
{
    int sum = 0;
    const int integerNumber = 3;
    int integerArray[integerNumber] = {};
    
    for( int i = 0; i < integerNumber; i++ )
    {
        integerArray[i] = GetInteger(i);
    }
    
    for (int i = 0; i < integerNumber; i++)
    {
        sum = GetSum(sum, integerArray[i]);
    }
    
    return sum;
}

double CalculateDepositRate()
{
//    string message = "Put money number: ";
    float principal = GetFloat();
    float rate = GetFloat();
    
    rate = rate / 100;
    
    float sumOfMoney = principal * (rate + (float)1);
    
    return sumOfMoney;
}

int GetSum(int x, int y)
{
    return x + y;
}

int GetInteger(unsigned int n)
{
    int a;
    cout << "Put the " << n << "th integer: " << endl;
    cin >> a;
    return a;
}

//double GetFloat(string message)
float GetFloat()
{
    float a;
    cout << "Put a float: " << endl;
    cin >> a;
    return a;
}


