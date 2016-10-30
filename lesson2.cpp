//
//  lesson2.cpp
//  Linux_C++
//
//  Created by honglongsoo on 16/10/26.
//  Copyright © 2016年 honglongsoo. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>

#include "lesson2.h"

using namespace std;

typedef enum {SUN, MON, TUE, WED, THU, FRI, SAT } WEEKDAY;

int lesson2Main()
{
//    ShowGreaterOne();
//    Calendar();
//    cout << endl;
//    NiceByNiceMultiplicationTable();
    PrintTriangle();
    
    return 0;
}

void ShowGreaterOne()
{
    int a, b, max;
    cout << "The program gets two numbers and prints the greater one.\n";
    cout << "The first number: \n";
    cin >> a;
    cout << "The second number: \n";
    cin >> b;
    
    max = a > b ? a : b;
    
    cout << "The greater one is " << max << endl;
}

bool IsLeep(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

//已知2006年12月1日为星期五。编制程序，接受用户输入的1~31之间的整数，按照下述格式将该日星期几信息打印在对应栏下。例如，2006年12月1日打印在星期五“Fr”下面：
int CalendarJustTheDate()
{
    int date, digitNumber;
    const WEEKDAY date_1 = FRI;
    WEEKDAY weekday;
    cout << "The program gets a date(1~31), \n";
    cout << "and prints a calendar of 2006-12(just the date).\n";
    cout << "The date: \n";
    cin >> date;
    if (date < 1 || date > 31)
    {
        cout << "Date error!\n";
        return 1;
    }
    weekday = (WEEKDAY)((date + (int)date_1 - 1) % 7);
    digitNumber = (int)weekday * 4 + 2;
    
    cout << "Calendar 2006-12\n";
    cout << "---------------------------\n";
    cout << "Su  Mo  Tu  We  Th  Fr  Sa\n";
    cout << setw(digitNumber) << date << endl;
    cout << "---------------------------\n";
    return 0;
}

void Calendar()
{
    WEEKDAY weekday;
    const WEEKDAY date_1 = SAT;
    const int dateNumber = 31;
    
    cout << "Calendar 2016-10\n";
    cout << "---------------------------\n";
    cout << "Su  Mo  Tu  We  Th  Fr  Sa\n";
    for (int date = 1; date <= dateNumber; date++)
    {
        int digitNumber = 2;
        if (date == 1)
            digitNumber = (int)date_1 * 4 + 2;
        
        cout << setw(digitNumber) << date;
        
        weekday = (WEEKDAY)((date + (int)date_1 - 1) % 7);
        if (weekday == SAT)
            cout << endl;
        else
            cout << "  ";
    }
    cout << endl;
}

void NiceByNiceMultiplicationTable()
{
    cout << "    Nice-by-nice Multiplication Table\n";
    cout << "---------------------------------------------\n";
    cout << "  ";
    for (int i = 1; i <= 9; i++) {
        cout << setw(4) << i;
    }
    cout << endl;
    cout << "---------------------------------------------\n";
    
    for (int i = 1; i <= 9; i++) {
        cout << setw(2) << i;
        for (int ii = i; ii <= 9; ii++) {
            if (ii == i)
                cout << setw(ii * 4) << i * ii;
            else
                cout << setw(4) << i * ii;
        }
        cout << endl;
    }
//    for (int i = 1; i <= 9; i++)
//    {
//        cout << setw(2) << i;
//        for (int j = 1; j <= i; j++) {
//            cout << setw(4) << i * j;
//        }
//        cout << endl;
//    }
    cout << "---------------------------------------------\n";
}

int PrintTriangle()
{
//    int rowNumber, spaceNumber;
//    cout << "The program prints tow triangle\n";
//    cout << "The Total row number: \n";
//    cin >> rowNumber;
//    
//    cout << "The space number: \n";
//    cin >> spaceNumber;
//    
//    int flagNunber = (rowNumber - 1) * 2 + 1;
//    int halfFlagNumber = ceil((float)flagNunber / 2.0);
//    
//    for (int i = 1; i <= rowNumber; i++) {
//        int min_1 = halfFlagNumber - (i - 1);
//        int max_1 = halfFlagNumber + (i - 1);
//        for (int j = 1; j <= flagNunber; j++) {
//            if (j >= min_1 && j <= max_1)
//                cout << "*";
//            else
//                cout << " ";
//        }
//        
//        for (int s = 1; s <= spaceNumber; s++) {
//            cout << " ";
//        }
//        
//        int min_2 = i;
//        int max_2 = flagNunber - (i - 1);
//        for (int k = 1; k <= flagNunber; k++) {
//            if (k >= min_2 && k <= max_2)
//                cout << "*";
//            else
//                cout << " ";
//        }
//        cout << endl;
//    }
//    return 0;
    
    int rowNumber, spaceNumber;
    cout << "The program prints tow triangles\n";
    
    cout << "The Total row number: \n";
    cin >> rowNumber;
    
    cout << "The space number: \n";
    cin >> spaceNumber;
    
    int starMaxNumber = (rowNumber - 1) * 2 + 1;
    int starMaxNumberHalf = ceil((float)starMaxNumber / 2.0);
    int totalCharInRow = starMaxNumber * 2 + spaceNumber;
    int secondTriangleBegin = starMaxNumber + spaceNumber + 1;
    
    for (int i = 1; i <= rowNumber; i++) {
        int begin_1 = starMaxNumberHalf - (i - 1);
        int end_1 = starMaxNumberHalf + (i - 1);
        int begin_2 = secondTriangleBegin + (i - 1);
        int end_2 = totalCharInRow - (i - 1);
        for (int j = 1; j <= totalCharInRow; j++) {
            if ((j >= begin_1 && j <= end_1) || (j >= begin_2 && j <= end_2))
                cout << "*";
            else
                cout << "-";
        }
        cout << endl;
    }

    return 0;
}







