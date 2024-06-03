#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 9;
int used[N], a[N], fa[N];
int n, m, k;
vector<int>v[N];
vector<int>ret;
void init()
{
	for (int i = 0; i < n; ++i)
		fa[i] = i;
}
int find(int x)
{
	if (x == fa[x])
		return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int i, int j)
{
	int fi = find(i);
	int fj = find(j);
	if (fi != fj)
		fa[fi] = fj;
}
int main()
{
	cin >> n >> m;
	init();
	for (int i = 1; i <= m; ++i)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		v[tmp1].push_back(tmp2);
		v[tmp2].push_back(tmp1);
	}
	cin >> k;
	for (int i = 1; i <= k; ++i)
	{
		cin >> a[i];
		used[a[i]] = 1;
	}
	int ans = n - k;
	for (int i = 0; i < n; ++i)
	{
		if (used[i] == 0)
		{
			for (auto e : v[i])
			{
				if (used[e] == 0)
				{
					if (find(i) != find(e))
						ans--;
					merge(i, e);
				}
			}
		}
	}
	ret.push_back(ans);
	for (int i = k; i > 0; --i)
	{
		ans++;
		for (auto e : v[a[i]])
		{
			if (used[e] == 0)
			{
				if (find(a[i]) != find(e))
					ans--;
				merge(e, a[i]);
			}
		}
		used[a[i]] = 0;
		ret.push_back(ans);
	}
	for (int i = ret.size() - 1; i >= 0; --i)
		cout << ret[i] << '\n';
}