#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int n0, n1, n;
int a0[N], a1[N];
void div0(int n)
{
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			int tmp1 = i;
			int tmp2 = n / i;
			a0[tmp1] = 1;
			a0[tmp2] = 1;
		}
	}
}
void div1(int n)
{
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			int tmp1 = i;
			int tmp2 = n / i;
			a1[tmp1] = 1;
			a1[tmp2] = 1;
		}
	}
}
int main()
{
	cin >> n0 >> n1 >> n;
	int minn = INT_MAX;
	int min0, min1;
	div0(n0);
	div1(n1);
	if (n0 != 1)
		a0[1] = 1;
	if (n1 != 1)
		a1[1] = 1;
	for (int i = 1; i < n; ++i)
	{
		if (a0[i] && a1[n - i])
		{
			int tmp1 = n0 / i;
			int tmp2 = n1 / (n - i);
			if (minn > abs(tmp1 - tmp2))
			{
				minn = abs(tmp1 - tmp2);
				min0 = i;
				min1 = n - i;
			}
		}
	}
	if (minn == INT_MAX)
		cout << "No Solution";
	else
		cout << min0 << ' ' << min1;
	return 0;
}