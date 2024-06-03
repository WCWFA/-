#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int a[N], q[N];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	int hh = 1;
	int tt = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (hh <= tt && i - q[hh] + 1 > m)
		{
			hh++;
		}
		while (hh <= tt && a[q[tt]] >= a[i])
			tt--;
		q[++tt] = i;
		if (m < i + 1)
			cout << a[q[hh]] << endl;
	}
	return 0;
}