#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 9;
int fa[N];
int n, m, p;
void init()
{
	for (int i = 1; i <= n; ++i)
	{
		fa[i] = i;
	}
}
int find(int x)
{
	if (fa[x] == x)
		return x;
	else
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int i, int j)
{
	fa[find(i)] = find(j);
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> p;
	init();
	for (int i = 1; i <= m; ++i)
	{
		int mi, mj;
		cin >> mi >> mj;
		merge(mi, mj);
	}
	for (int i = 1; i <= p; ++i)
	{
		int pi, pj;
		cin >> pi >> pj;
		if (find(pi) == find(pj))
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
	}

	return 0;
}