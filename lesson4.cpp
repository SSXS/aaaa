#include "lesson4.h"

using namespace std;

//enum HANOI _HANOI;

int aaa = 100;

void PrintHanoiInfo()
{
	cout << "This program shows the moving process of Hanoi Tower\n";
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

bool IsPrime(unsigned int n)
{
	//unsigned int i = 2;
	//while (i < n)
	//{
	//	if (n % i == 0)
	//		return false;
	//	i++;
	//}
	//return true;

	unsigned int i = 3, t = (unsigned int)sqrt(n) + 1;
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

	//欧式算法
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

unsigned int GetFactorial(unsigned int n)
{
	//循环求阶乘
	//unsigned int result = 1;
	//for (unsigned int i = 1; i <= n; i++)
	//	result *= i;
	//return result;

	//递归求阶乘
	if (n == 1)
		return 1;
	else
		return n * GetFactorial(n - 1);
}

unsigned int GetFibonacci(unsigned int n)
{
	//循环求斐波那契数列
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

	//递归求斐波那契数列
	if (n == 1 || n == 2)
		return 1;
	else
		return GetFibonacci(n - 1) + GetFibonacci(n - 2);
}

//---------------------Programming Practice---------------------
//设计算法，将某个大于1的自然数n分解为其素因子的乘积，如6=2*3， 7=7，8=2*2*2。
void RecountNumber(unsigned int n)
{

}

unsigned int GetMaxFactor(unsigned int n)
{
	bool isPrime = IsPrime(n);
	if (isPrime)
		return n;
	
	unsigned int t = (unsigned int)sqrt(n) + 1;
	while (t > 1)
	{
		if (n % t == 0)
			return t;
		t--;
	}
    return 0;
}