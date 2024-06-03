#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
long long n = 0;
int main()
{
	cin >> n;
	long long sum = 0;
	if (n % 2 == 0)
	{
		sum = n / 2;
		sum = sum * (n + 1);
	}
	else
	{
		sum = (n + 1) / 2;
		sum = sum * n;
	}
	cout << sum;
	return 0;
}