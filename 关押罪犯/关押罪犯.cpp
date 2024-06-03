#include<bits/stdc++.h>
using namespace std;
const int N = 2e4 + 9;
int fa[N], fb[N];
int n, m;
struct node
{
	int x;
	int y;
	int grade;
};
struct re
{
	int summ;
	int pos;
};
vector<node>v;
bool cmp(node& x, node& y)
{
	return x.grade > y.grade;
}
void init()
{
	for (int i = 1; i <= n; ++i)
	{
		fa[i] = i;
	}
}
int find(int x)
{
	if (x == fa[x])
		return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
bool merge(int i, int j)
{
	int fi = find(i);
	int fj = find(j);
	if (fi == fj)
		return false;
	else
	{
		fa[fi] = fj;
		return true;
	}
}
int main()
{
	cin >> n >> m;
	init();
	for (int i = 1; i <= m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(node{ a,b,c });
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); ++i)
	{
		int p = v[i].x, q = v[i].y;
		if (find(p) == find(q))
			continue;
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
	int maxx = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		int tmp1 = v[i].x, tmp2 = v[i].y;
		int ft1 = find(tmp1), ft2 = find(tmp2);
		if (ft1 == ft2)
		{
			maxx = max(maxx, v[i].grade);
		}
	}
	cout << maxx;
	return 0;
}