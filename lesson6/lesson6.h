//
//  lesson6.h
//  Linux_C++
//
//  Created by honglongsoo on 16/11/4.
//  Copyright © 2016年 honglongsoo. All rights reserved.
//

#ifndef lesson6_h
#define lesson6_h

struct DATE;
struct POINT;

int lesson6Main();

void GenerateIntegers(int a[], int n);

unsigned int GetDateCount(DATE date);

POINT GeneratePoint();

void SortByAscend(int a[], unsigned int n);

bool SearchInteger(int a[], unsigned int n, int key);

#endif /* lesson6_h */
