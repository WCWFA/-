#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<math.h>
using namespace std;
long long a, b, p;
long long QuickPow(long long a, long long b,long long p)
{
	long long ret = 1;
	while (b)
	{
		if (b & 1)
		{
			ret = ret * a % p;
		}
		a = a * a % p;
		b = b >> 1;
	}
	return ret;
}
int main()
{
	cin >> a >> b >> p;
	long long sum = QuickPow(a, b, p);
	printf("%ld^%ld mod %ld=%ld", a, b, p, sum);
	return 0;
}