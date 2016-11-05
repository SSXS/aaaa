//
//  arrmanip.cpp
//  Linux_C++
//
//  Created by honglongsoo on 16/11/4.
//  Copyright © 2016年 honglongsoo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

#include "arrmanip.h"
#include "../lesson5/zyrandom.h"

using namespace std;

void GenerateIntegers(int a[], unsigned int n, int lower, int higher)
{
    unsigned int i;
    Randomize();
    for (i = 0; i < n; i++) {
        a[i] = GenerateRandomNumber(lower, higher);
    }
}

void ReverseIntegers(int a[], unsigned int n)
{
    unsigned int i;
    for (i = 0; i < n / 2; i++) {
        SwapIntegers(a, i, n - i - 1);
    }
}

void SwapIntegers(int a[], unsigned int i, unsigned int j)
{
    int t;
    t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void PrintIntegers(int a[], unsigned int n)
{
    unsigned int i;
    for (i = 0; i < n; i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
}