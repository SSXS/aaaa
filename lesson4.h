#pragma once

#include <iostream>
#include <cmath>

typedef enum __HANOI {
	X, Y, Z
} HANOI;

//#ifdef __GLOBAL__
//#define _EXT
//#else
//#define _EXT_ extern
//#endifg
//
//_EXT_ HANOI _HANOI;

//enum HANOI {
//	X, Y, Z
//};

extern int aaa;

void PrintHanoiInfo();

char ConvertHanoiToChar(HANOI x);
unsigned int GetPlateNumber();

void MovePlate(unsigned int n, HANOI from, HANOI to);
void MoveHanoi(unsigned int n, HANOI from, HANOI temp, HANOI to);

bool IsPrime(unsigned int n);

unsigned int gcd(unsigned int x, unsigned int y);

unsigned int GetFactorial(unsigned int n);
unsigned int GetFibonacci(unsigned int n);

//---------------------------Programming Practice----------------
void RecountNumber(unsigned int n);
unsigned int GetMaxFactor(unsigned int n);