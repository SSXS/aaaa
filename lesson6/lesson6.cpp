//
//  lesson6.cpp
//  Linux_C++
//
//  Created by honglongsoo on 16/11/4.
//  Copyright © 2016年 honglongsoo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cctype>
#include <iomanip>

#include "lesson6.h"
#include "../lesson5/zyrandom.h"
#include "arrmanip.h"
#include "../lesson2.h"

using namespace std;

#define NUMBER_OF_ELEMENTS 2
//#define  NUM_OF_X_GRIDS  9
//#define  NUM_OF_Y_GRIDS  4

const int lower = 1;
const int higher = 1;

//static const double lake_region_depths[NUM_OF_Y_GRIDS][NUM_OF_X_GRIDS] =
//{
//    { 0.0, 0.0, 1.0, 2.0, 2.0, 3.0, 0.0, 0.0, 0.0 },
//    { 0.0, 2.0, 3.0, 5.0, 5.0, 3.0, 2.0, 0.0, 0.0 },
//    { 0.0, 1.0, 4.0, 3.0, 4.0, 2.0, 2.0, 1.0, 0.0 },
//    { 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0 }
//};
//
//const double lake_grid_width = 5.0;

struct DATE
{
    int year;
    int month;
    int day;
};

struct POINT
{
    int x;
    int y;
};
const int orignal_point_x = 0;
const int orignal_point_y = 0;
const int num_of_pixel_x = 1920;
const int num_of_pixel_y = 1920;

int lesson6Main()
{
//    int i, a[5], result = 0;
//    for (i = 0; i < 5; i++) {
//        cout << "Integer No." << i + 1 << ": ";
//        cin >> a[i];
//    }
//    
//    for (i = 0; i < 5; i++) {
//        result += a[i];
//    }
//    cout << "The sum of elements of the array is " << result << endl;
    
    int a[NUMBER_OF_ELEMENTS] = {};
    GenerateIntegers(a, NUMBER_OF_ELEMENTS, lower, higher);
//    cout << "Array generated at random as follow:\n";
//    PrintIntegers(a, NUMBER_OF_ELEMENTS);
    
//    ReverseIntegers(a, NUMBER_OF_ELEMENTS);
//    cout << "After all elements of the array reversed:\n";
//    PrintIntegers(a, NUMBER_OF_ELEMENTS);
    
    SortByAscend(a, NUMBER_OF_ELEMENTS);
    cout << "After all elements of the array sort:\n";
    PrintIntegers(a, NUMBER_OF_ELEMENTS);
    
    bool is_exist = SearchInteger(a, NUMBER_OF_ELEMENTS, 1);
    if (is_exist)
        cout << "exist" << endl;
    else
        cout << "not exist" << endl;
    
//    double num_of_lake_grids = 0.0, lake_area = 0.0;
//    double total_of_depth = 0.0, mean_lake_depth = 0.0, depth = 0.0;
//    
//    unsigned int i, j;
//    
//    for (i = 0; i < NUM_OF_Y_GRIDS; i++) {
//        for (j = 0; j < NUM_OF_X_GRIDS; j++) {
//            depth = lake_region_depths[i][j];
//            if (depth > 0) {
//                num_of_lake_grids += 1.0;
//                total_of_depth += depth;
//            }
//        }
//    }
//    lake_area = lake_grid_width * lake_grid_width * num_of_lake_grids;
//    mean_lake_depth = total_of_depth / num_of_lake_grids;
//    
//    cout << "Area of the lake is " << lake_area << "(m2)" << endl;
//    cout << setiosflags(ios::fixed) << setprecision(2);
//    cout << "Mean depth of the lake is " << mean_lake_depth << "(m)" << endl;
    
//    DATE date = {2016, 11, 5};
//    unsigned int date_count = GetDateCount(date);
//    cout << "2016-11-5: " << date_count << endl;
    
//    POINT p = GeneratePoint();
//    cout << p.x << ", " << p.y << endl;
    
    return 0;
}

void GenerateIntegers(int a[], int n, int lower, int upper)
{
    int i;
    Randomize();
    for (i = 0; i < n; i++) {
        a[i] = GenerateRandomNumber(lower, upper);
    }
}

unsigned int GetDateCount(DATE date)
{
    static unsigned int days_of_months[13] =
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    unsigned int i, date_id = 0;
    for (i = 1; i < date.month; i++) {
        date_id += days_of_months[i];
    }
    date_id += date.day;
    if (date.month > 2 && IsLeep(date.year)) {
        date_id++;
    }
    return date_id;
}

POINT GeneratePoint()
{
    POINT t;
    t.x = GenerateRandomNumber(orignal_point_x, num_of_pixel_x);
    t.y = GenerateRandomNumber(orignal_point_y, num_of_pixel_y);
    return t;
}

//---------------------Programming Practice---------------------
//编写函数Sort，对包含n个元素的整数数组a，按从小到大顺序排序。此问题有多种算法，不同算法的效率可能不同。
void SortByAscend(int a[], unsigned int n)
{
    unsigned int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                k = a[j];
                a[j] = a[j + 1];
                a[j + 1] = k;
            }
        }
    }
}

//编写函数Search，对于已排序的包含n个元素的整数数组a，在其中查找整数key。如果该整数在数组中，函数返回true，否则返回false。
bool SearchInteger(int a[], unsigned int n, int key)
{
    bool is_exist;
    unsigned int lower_index, middle_index, higher_index;
    lower_index = 0;
    higher_index = n;
    
    while (true) {
        if (higher_index - lower_index == 1) {
            is_exist = a[higher_index] == key || a[lower_index] == key;
            break;
        }
        
        middle_index = (higher_index - lower_index) / 2 + lower_index;
#ifndef NDEBUG
        cout << "1. " << lower_index << ", " << middle_index << ", " << higher_index << endl;
#endif
        if (a[middle_index] == key) {
            is_exist = true;
            break;
        }
        else if (a[middle_index] > key)
            higher_index = middle_index;
        else
            lower_index = middle_index;
#ifndef NDEBUG
        cout << "2. " << lower_index << ", " << middle_index << ", " << higher_index << endl;
#endif
    }
    return is_exist;
}

//继续编程实践题5.2。将去除大小王的52张扑克牌平均分配给四个玩家，每家13张牌。为描述问题方便，2～9的牌张使用对应字符‘2’～‘9’，字符‘T’表示10，‘J’、‘Q’、‘K’、‘A’表示四类大牌。记每张2～10为0点，J为1点，Q为2点，K为3点，A为4点，统计每家大牌点值。上述牌点计算方法主要用于桥牌游戏。
//见lesson5.cpp 168 开始

