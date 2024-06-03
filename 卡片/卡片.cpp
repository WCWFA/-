#include<bits/stdc++.h>
using namespace std;
int a[10];
int summ = 0;
int main()
{
	for (int i = 0; i <= 9; ++i)
	{
		a[i] = 2021;
	}
	while (1)
	{
		int tmp = summ;
		if (tmp == 0)
		{
			a[tmp]--;
		}
		while (tmp > 0)
		{
			int tmp1 = tmp % 10;
			a[tmp1]--;
			if (a[tmp1] < 0)
			{
				cout << summ;
				exit(0);
			}
			tmp = tmp / 10;
		}
		summ++;
	}
	return 0;
}