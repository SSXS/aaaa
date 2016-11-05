//
//  lesson5.h
//  Linux_C++
//
//  Created by honglongsoo on 16/11/2.
//  Copyright © 2016年 honglongsoo. All rights reserved.
//

#ifndef lesson5_h
#define lesson5_h

struct Poker;

int lesson5Main();

//static int func(int x);

void GeneratePoker(Poker cards[], unsigned int card_number);

void PrintCards(Poker cards[], unsigned int card_number);

void DealCards(Poker cards[]);

unsigned int CountPlayerPoint(Poker a[], unsigned int card_number);

unsigned int GetCardPoint(Poker poker);

void SortByType(Poker a[], unsigned int card_number);

void SortByNumber(Poker a[], unsigned int card_number);

void SortByTypeAndNumber(Poker a[], unsigned int card_number);
//void SwitchToPoker(int number);

#endif /* lesson5_h */
