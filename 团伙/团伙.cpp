#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
int fa[N], fb[N], n, m, sum;
void init()
{
	for (int i = 1; i <= n; ++i)
	{
		fa[i] = i;
	}
	sum = n;
}
int find(int x)
{
	if (fa[x] == x)
		return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int i, int j)
{
	int fi = find(i);
	int fj = find(j);
	if (fi != fj)
	{
		fa[fi] = fj;
		sum--;
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	init();
	for (int i = 1; i <= m; ++i)
	{
		char s;
		int p, q;
		cin >> s >> p >> q;
		if (s == 'F')
		{
			merge(p, q);
		}
		if (s == 'E')
		{
			if (fb[p] == 0)
			{
				fb[p] = q;
			}
			else
			{
				merge(fb[p], q);
			}
			if (fb[q] == 0)
			{
				fb[q] = p;
			}
			else
			{
				merge(fb[q], p);
			}
		}
	}
	cout << sum << '\n';
	return 0;
}