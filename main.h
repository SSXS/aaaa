#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath> //linux 链接时默认不装载math库 方法：g++ -lm main.cpp


void PrintWelcomeInfo();
unsigned int GetInteger();
void Swap(int a, int b);
int Add(int a, int b);
int Compare(int a, int b);
bool IsLeep(int year);