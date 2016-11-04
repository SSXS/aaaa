//
//  lesson5.cpp
//  Linux_C++
//
//  Created by honglongsoo on 16/11/2.
//  Copyright © 2016年 honglongsoo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#include "lesson5.h"
//#include "../lesson4.h"
#include "zyrandom.h"
#include "guess.h"

using namespace std;

//static int func(int x);

int lesson5Main()
{
//    cout << "On this computer, the RAND_MAX is " << RAND_MAX << endl;
//    cout << "Five numbers the rand function generates as follows: \n";
    
//    srand((int)time(0));
//    Randomize();
//    TestGenerateRandomNumber();
//    TestGenterateRandomReal();
    
//    int i ;
//    for (i = 0; i < 4; i++) {
//        cout << "Invoke func" << i << " time(s): Return " << func(i) << ".\n";
//    }
    
//    double prevailed_ratio;
//    PrintWelcomeInfo();
//    InitializeGame();
//    prevailed_ratio = PlayGame();
//    PrintGameOverInfo(prevailed_ratio);
    
    GeneratePoker();
    return 0;
}

//static int func(int x)
//{
//    static int count = 0;
//    cout << "x = " << x << ".\n";
//    return ++count;
//}


//---------------------Programming Practice---------------------
//编写函数，返回1～52之间的随机数
//GenerateRandomNumber(1,52)


//可以将上题生成的随机数模拟为不含大小王牌的扑克牌。编写函数，重复生成52个随机数，并映射为每张扑克牌。说明：重复生成的典型原则是按照花色（梅花、方块、红桃、黑桃）和大小（2～10、J、Q、K、A）顺序进行映射，例如梅花2小于梅花3，……，梅花A小于方块2，……，黑桃K小于黑桃A。需要注意的是，一旦生成某张牌后，即不允许再次生成它，如何解决此问题？

enum PokerType { MEIHUA, FANGKUAI, HONGTAO, HEITAO };

struct Poker
{
    PokerType poker_type;
    int number;
};

static Poker SwitchToPoker(int number);
static void PrintPoker(Poker poker);

void GeneratePoker()
{
    const int low = 1;
    const int high = 52;
    
    int record[high] = {};//记录数组
//    int poker[high] = {};
        Poker poker[high] = {};
    
    int count = 0;
    int i;
    
    for (i = 0; i < high; i++) {
        record[i] = 0;
    }
    
    Randomize();
    while (count < high) {
        int n = GenerateRandomNumber(low, high);
        if (record[n-1] == 0) {
            cout << n << ", " << count << endl;
            record[n-1] = n;
            poker[count] = SwitchToPoker(n);
//            poker[count] = n;
            count++;
        }
    }
    
    for (i = 0; i < high; i++) {
        PrintPoker(poker[i]);
    }
    
    cout << endl;
}


static Poker SwitchToPoker(int number)
{
    Poker poker;
    
    if (number >= 1 && number <= 13)
    {
        poker.poker_type = MEIHUA;
        poker.number = number;
    }
    else if (number >= 14 && number <= 26)
    {
        poker.poker_type = FANGKUAI;
        poker.number = number - 13;
    }
    else if (number >= 27 && number <= 39)
    {
        poker.poker_type = HONGTAO;
        poker.number = number - 26;
    }
    else
    {
        poker.poker_type = HEITAO;
        poker.number = number - 39;
    }
    
    return poker;
}

static void PrintPoker(Poker poker)
{
    switch (poker.poker_type) {
        case MEIHUA:
            cout << "♣️ ";
            break;
        case FANGKUAI:
            cout << "♦️ ";
            break;
        case HONGTAO:
            cout << "♥️ ";
            break;
        case HEITAO:
            cout << "♠️ ";
            break;
    }
    
    if (poker.number == 1)
        cout << "A" << endl;
    else if (poker.number == 11)
        cout << "J" << endl;
    else if (poker.number == 12)
        cout << "Q" << endl;
    else if (poker.number == 13)
        cout << "K" << endl;
    else
        cout << poker.number << endl;
}
