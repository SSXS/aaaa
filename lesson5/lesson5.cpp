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

enum PokerType { MEIHUA, FANGKUAI, HONGTAO, HEITAO };

struct Poker
{
    PokerType poker_type;
    int number;
};

static Poker ConvertToPoker(int number);
static void PrintPoker(Poker poker);

const int TOTAL_CARD_NUM = 52;
const int MEAN_CARD_NUM = 13;

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
    
    Poker cards[TOTAL_CARD_NUM] = {};
    GeneratePoker(cards, TOTAL_CARD_NUM);

//    SortByNumber(cards, TOTAL_CARD_NUM);
//    SortByType(cards, TOTAL_CARD_NUM);
//    PrintCards(cards, TOTAL_CARD_NUM);
    DealCards(cards);
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

void GeneratePoker(Poker cards[], unsigned int card_number)
{
    int record[TOTAL_CARD_NUM] = {};//记录数组
    
    int count = 0;
    int i;
    
    for (i = 0; i < card_number; i++) {
        record[i] = 0;
    }
    
    Randomize();
    while (count < card_number) {
        int n = GenerateRandomNumber(1, card_number);
        if (record[n-1] == 0) {
//            cout << n << ", " << count << endl;
            record[n-1] = n;
            cards[count] = ConvertToPoker(n);
//            poker[count] = n;
            count++;
        }
    }
}


static Poker ConvertToPoker(int number)
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

void PrintCards(Poker cards[], unsigned int card_number)
{
    unsigned int i;
    for (i = 0; i < card_number; i++) {
        PrintPoker(cards[i]);
    }
//    cout << endl;
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

//继续编程实践题5.2。将去除大小王的52张扑克牌平均分配给四个玩家，每家13张牌。为描述问题方便，2～9的牌张使用对应字符‘2’～‘9’，字符‘T’表示10，‘J’、‘Q’、‘K’、‘A’表示四类大牌。记每张2～10为0点，J为1点，Q为2点，K为3点，A为4点，统计每家大牌点值。上述牌点计算方法主要用于桥牌游戏。
void DealCards(Poker cards[])
{
    unsigned int i;
    unsigned int a, b, c;
    unsigned int player_a_point, player_b_point, player_c_point, player_d_point;
    Poker player_a[MEAN_CARD_NUM] = {};
    Poker player_b[MEAN_CARD_NUM] = {};
    Poker player_c[MEAN_CARD_NUM] = {};
    Poker player_d[MEAN_CARD_NUM] = {};
    a = MEAN_CARD_NUM;
    b = MEAN_CARD_NUM * 2;
    c = MEAN_CARD_NUM * 3;
    
    for (i = 0; i < TOTAL_CARD_NUM; i++) {
        if (i < a)
            player_a[i] = cards[i];
        else if ( i >= a && i < b)
            player_b[i - a] = cards[i];
        else if ( i >= b && i < c)
            player_c[i - b] = cards[i];
        else
            player_d[i - c] = cards[i];
    }
    
//    SortByNumber(player_a, MEAN_CARD_NUM);
//    SortByType(player_a, MEAN_CARD_NUM);
    SortByTypeAndNumber(player_a, MEAN_CARD_NUM);
    PrintCards(player_a, MEAN_CARD_NUM);
    player_a_point = CountPlayerPoint(player_a, MEAN_CARD_NUM);
    cout << "Total point of player A: " << player_a_point << endl;
    
    SortByNumber(player_b, MEAN_CARD_NUM);
//    SortByType(player_b, MEAN_CARD_NUM);
    PrintCards(player_b, MEAN_CARD_NUM);
    player_b_point = CountPlayerPoint(player_b, MEAN_CARD_NUM);
    cout << "Total point of player B: " << player_b_point << endl;
    
    SortByNumber(player_c, MEAN_CARD_NUM);
//    SortByType(player_c, MEAN_CARD_NUM);
    PrintCards(player_c, MEAN_CARD_NUM);
    player_c_point = CountPlayerPoint(player_c, MEAN_CARD_NUM);
    cout << "Total point of player C: " << player_c_point << endl;
    
    SortByNumber(player_d, MEAN_CARD_NUM);
//    SortByType(player_d, MEAN_CARD_NUM);
    PrintCards(player_d, MEAN_CARD_NUM);
    player_d_point = CountPlayerPoint(player_d, MEAN_CARD_NUM);
    cout << "Total point of player D: " << player_d_point << endl;
}

unsigned int CountPlayerPoint(Poker a[], unsigned int card_number)
{
    unsigned int total_point, i;
    total_point = 0;
    for (i = 0; i < card_number; i++) {
        total_point += GetCardPoint(a[i]);
    }
    return total_point;
}

unsigned int GetCardPoint(Poker poker)
{
    if (poker.number == 1)
        return 4;
    else if (poker.number == 11)
        return 1;
    else if (poker.number == 12)
        return 2;
    else if (poker.number == 13)
        return 3;
    else
        return 0;
}

void SortByType(Poker a[], unsigned int card_number)
{
    unsigned int i, j;
    Poker temp;
    for (i = 0; i < card_number; i++) {
        for (j = 0; j < card_number - i - 1; j++) {
            if (a[j].poker_type > a[j + 1].poker_type) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void SortByNumber(Poker a[], unsigned int card_number)
{
    unsigned int i, j;
    Poker temp;
    for (i = 0; i < card_number; i++) {
        for (j = 0; j < card_number - i - 1; j++) {
            if (a[j].number == 1 || (a[j + 1].number != 1 && a[j].number > a[j + 1].number)) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void SortByTypeAndNumber(Poker a[], unsigned int card_number)
{
    unsigned int i, j;
    Poker temp;
    for (i = 0; i < card_number; i++) {
        for (j = 0; j < card_number - i - 1; j++) {
            if (a[j].poker_type > a[j + 1].poker_type) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            else if (a[j].poker_type == a[j + 1].poker_type) {
                if (a[j].number == 1 || (a[j + 1].number != 1 && a[j].number > a[j + 1].number)) {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }
}