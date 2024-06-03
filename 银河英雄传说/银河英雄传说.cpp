#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e4 + 9, n = 3e4;
int fa[N], height[N];
void init()
{
	for (int i = 1; i <= n; ++i)
	{
		fa[i] = i;
		height[i] = 1;
	}
}
int find(int x)
{
	if (fa[x] == x)
		return x;
	else
		return find(fa[x]);
}
void add(int i, int j)
{
	int tmp = fa[i];
	height[tmp] += height[j];
	if (tmp != i)
	{
		add(tmp, j);
	}
	return;
}
void merge(int i, int j)
{
	fa[j] = i;
	add(i, j);
	cout << height[i] << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	init();
	for (int i = 1; i <= T; ++i)
	{
		int a, b;
		char ch;
		cin >> ch >> a >> b;
		if (ch == 'M')
		{
			merge(a, b);
		}
		if (ch == 'C')
		{
			if (find(a) != find(b))
				cout << -1 << endl;
			else
			{
				cout << height[a] << ' ' << height[b] << endl;
				cout << abs(height[a] - height[b]) - 1 << endl;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << height[i] << ' ';
	}
	return 0;
}