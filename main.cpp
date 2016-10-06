#include "main.h"
#include "lesson4.h"
#include "lesson5.h"

using namespace std;

int main()
{
	cout << "hello world!" << endl;
	
	//int a, b;
	//a = GetInteger();
	//b = GetInteger();
	//Swap(a, b);

	//int sum = Add(a, b);
	//cout << sum << endl;
	//cout << sum << " is prime£º" << IsPrime(sum) << endl;
	//cout << a << " , " << b << " the gcd is " << gcd(a, b) << endl;
	//cout << sum << " ,Factorial : " << GetFactorial(sum) << endl;
	//cout << sum << " ,Fibonacci : " << GetFibonacci(sum) << endl;
	
	//PrintAAA();

	unsigned int n;
	PrintHanoiInfo();
	n = GetPlateNumber();
	MoveHanoi(n, X, Y, Z);

	return 0;
}

void PrintWelcomeInfo()
{
	cout << "The program shows the moving process of Hanoi Tower.\n";
}

unsigned int GetInteger()
{
	unsigned int i;
	//cout << "Put an Integer:" << endl;
	cout << "Put number of plate: ";
	cin >> i;
	return i;
}


void Swap(int a, int b)
{
	//int t;
	//t = a;
	//a = b;
	//b = t;

	a = b - a;
	b = b - a;
	a = a + b;

	cout << a << "," << b << endl;
}

int Add(int a, int b)
{
	int sum;
	sum = a + b;
	return sum;
}

int Compare(int a, int b)
{
	int t;
	if (a == b)
		t = 0;
	else if (a > b)
		t = 1;
	else
		t = -1;
	return t;
}

bool IsLeep(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}