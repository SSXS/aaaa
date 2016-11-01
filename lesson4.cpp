#include <iostream>
#include <cmath>
#include <cstdlib>
#include "lesson4.h"

using namespace std;

int record = 0;

int lesson4Main()
{
//    unsigned int n;
//    cout << "Put a number: ";
//    cin >> n;
//    if (IsPrime_4(n))
//        cout << n << " is a prime." << endl;
//    else
//        cout << n << " is not a prime." << endl;
    
//    unsigned int n;
//    PrintHanoiInfo();
//    n = GetPlateNumber();
//    MoveHanoi(n, X, Y, Z);

    unsigned int n;
    record = 0;
    cout << "Input a non-negative number: ";
    cin >> n;
    cout << n << "=";
    resolve(n);
    cout << endl;
    
//    unsigned int n, r;
//    cout << "Input non-negative number n: ";
//    cin >> n;
//    cout << "Input non-negative number r: ";
//    cin >> r;
//    unsigned int binomialFactor = GetBinomialFactor(n, r);
//    cout << n << " and " << r << " binomial factor is " << binomialFactor << endl;
    
    return 0;
}

void PrintHanoiInfo()
{
	cout << "This program shows the moving process of Hanoi Tower\n";
}

void MoveHanoi(unsigned int n, HANOI from, HANOI temp, HANOI to)
{
    if (n == 1)
        MovePlate(n, from, to);
    else
    {
        MoveHanoi(n - 1, from, to, temp);
        MovePlate(n, from, to);
        MoveHanoi(n - 1, temp, from, to);
    }
}

char ConvertHanoiToChar(HANOI x)
{
	switch (x)
	{
	case X:
		return 'X';
	case Y:
		return 'Y';
	case Z:
		return 'Z';
	default:
		return '\0';
	}
}

unsigned int GetPlateNumber()
{
	unsigned int n;
	cout << "Put number of plate: " << endl;
	cin >> n;
	return n;
}

void MovePlate(unsigned int n, HANOI from, HANOI to)
{
	char fc, tc;
	fc = ConvertHanoiToChar(from);
	tc = ConvertHanoiToChar(to);
	cout << n << ": " << fc << " --> " << tc << endl;
}

const int failed_in_testing_primality = 1;
bool IsPrime_4(unsigned int n)
{
//	unsigned int i = 2;
//	while (i < n)
//	{
//		if (n % i == 0)
//			return false;
//		i++;
//	}
//	return true;
    
	unsigned int i = 3, t = (unsigned int)sqrt(n) + 1; //float -> unsigned int 完全平方数的的平方根舍去小数部分时产生的误差
	if (n <= 1)
    {
        cout << "IsPrime: Failed in testing the primality of " << n << endl;
        exit(failed_in_testing_primality);
        
    }
    if (n == 2)
        return true;
    if (n % 2 == 0)
		return false;

	while (i <= t)
	{
		if (n % i == 0)
			return false;
		i += 2;
	}
	return true;
}

unsigned int gcd(unsigned int x, unsigned int y)
{
	//穷举法
	//unsigned int n = x < y ? x : y;
	//
	//while (x % n != 0 || y % n != 0)
	//	n--;
	//return n;

	//欧几里德算法
	unsigned int n;
	while (true)
	{
		n = x % y;
		if (n == 0)
			return n;
		x = y;
		y = n;
	}
}

//阶乘函数
unsigned int GetFactorial(unsigned int n)
{
	//循环实现
	//unsigned int result = 1;
	//for (unsigned int i = 1; i <= n; i++)
	//	result *= i;
	//return result;

	//递归实现
	if (n == 1)
		return 1;
	else
		return n * GetFactorial(n - 1);
}

//斐波那契数列函数
unsigned int GetFibonacci(unsigned int n)
{
	//循环实现
	//unsigned int t1, t2;
	//unsigned int result;

	//if (n == 1 || n == 2)
	//	return 1;
	//t1 = 1, t2 = 1;

	//for (unsigned int i = 1; i <= n; i++)
	//{
	//	result = t1 + t2;
	//	t1 = t2;
	//	t2 = result;
	//}
	//return result;

	//递归实现
	if (n == 1 || n == 2)
		return 1;
	else
		return GetFibonacci(n - 1) + GetFibonacci(n - 2);
}

//---------------------Programming Practice---------------------
//将某个大于1的自然数n分解为其素因子的乘积，如6=2*3，7=7，8=2*2*2

void resolve(unsigned int n)
{
    if (IsPrime_4(n))
    {
        if (record == 0)
        {
            cout << n;
            record = 1;
        }
        else
            cout << "*" << n;
    }
    else
    {
        unsigned int n1 = GetFactor(n);
        unsigned int n2 = n / n1;
        resolve(n1);
        resolve(n2);
    }
}

unsigned int GetFactor(unsigned int n)
{
    unsigned int factor = n;
    
    unsigned int t = (unsigned int)sqrt(n) + 1;
    unsigned int i = 2;
    
    while (i <= t)
    {
        if (n % i == 0)
        {
            factor = i;
            break;
        }
        else
            i++;
    }
    return factor;
}

//分别使用循环和递归两种策略求二项式系数C(n,k)。其中，n为自然数，k为不大于n的非负整数
unsigned int GetBinomialFactor(unsigned int n, unsigned int k)
{
//    递归算法
    unsigned int n1, n2;
    if (n == k || k == 0)
        return 1;
    else
    {
        n1 = GetBinomialFactor(n - 1, k);
        n2 = GetBinomialFactor(n - 1, k - 1);
        return n1 + n2;
    }
    
//    循环算法
//    if (n == k || k == 0)
//        return 1;
//    
//    unsigned int n1 = 1, n2 = 1, n3 = 1;
//    for (int i = 1; i <= n; i++) {
//        n1 *= i;
//    }
//    for (int j = 1; j <= k; j++) {
//        n2 *= j;
//    }
//    for (int r = 1; r <= (n - k); r++) {
//        n3 *= r;
//    }
//    return n1 / (n2 * n3);
}





