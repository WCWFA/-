#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
using ll = long long;
ll a[N], hh = 1, tt = 0, q[N];
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		//如果头比尾小，并且此时队列已经满（即i减去头的位置比k大）
		if (hh <= tt && k < i - q[hh] + 1)
		{
			hh++;
		}
		//开始循环，寻找此时队列中的最大值或者最小值（此时找最小值）
		while (hh <= tt && a[q[tt]] >= a[i])
			tt--;
		q[++tt] = i;
		//如果此时队列满
		if (i + 1 > k)
			cout << a[q[hh]] << ' ';
	}
	cout << endl;
	memset(q, 0, sizeof(q));
	hh = 1, tt = 0;
	for (int i = 1; i <= n; ++i)
	{
		//如果头比尾小，并且此时队列已经满（即i减去头的位置比k大）
		if (hh <= tt && k < i - q[hh] + 1)
		{
			hh++;
		}
		//开始循环，寻找此时队列中的最大值或者最小值（此时找最大值）
		while (hh <= tt && a[q[tt]] <= a[i])
			tt--;
		q[++tt] = i;
		//如果此时队列满
		if (i + 1 > k)
			cout << a[q[hh]] << ' ';
	}
	return 0;
}