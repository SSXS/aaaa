//
//  lesson3.cpp
//  Linux_C++
//
//  Created by honglongsoo on 16/10/31.
//  Copyright © 2016年 honglongsoo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

#include "lesson3.h"

using namespace std;



int lesson3Main()
{
//    float a, b, sum;
//    cout << "a: ";
//    cin >> a;
//    cout << "b: ";
//    cin >> b;
//    sum = Add(a, b);
//    cout << a << " + " << b << " = " << sum << endl;
    
    int x, y, l, g;
    x = GetInteger_3(1);
    y = GetInteger_3(2);
    
    g = gcd_3(x, y);
    l = lcm_3(x, y);
    cout << "g: " << g << endl << "l: " << l << endl;
    
    return 0;
}

int Add_3(int x, int y)
{
    int t;
    t = x + y;
    return t;
}

float Add_3(float x, float y)
{
    float t;
    t = x + y;
    return t;
}

bool IsPrime_3(unsigned int x)
{
    if (x <= 2)
    {
        cout << "Put in error!\n";
        return false;
    }
    int i = 2;
    while (i < x) {
        if ( x % i == 0)
            return false;
        i++;
    }
    return true;
}

unsigned int gcd_3(unsigned int x, unsigned int y)
{
    unsigned int i = x < y ? x : y;
    
    while (x % i != 0 || y % i != 0) {
        i--;
    }
    return i;
}

unsigned int lcm_3(unsigned int x, unsigned int y)
{
    unsigned int i = x > y ? x : y;
    
    while (i % x != 0 || i % y != 0) {
        i++;
    }
    return i;
}

int GetInteger_3(int idx)
{
    int t;
    cout << "No." << idx << ":";
    cin >> t;
    return t;
}


