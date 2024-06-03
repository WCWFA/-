#include<bits/stdc++.h>
using namespace std;
int main()
{
	int sum = 0;
	for (int i = 1901; i <= 2000; ++i)
	{
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			sum += 366;
		else
			sum += 365;
	}
	cout << sum / 7;
	return 0;
}