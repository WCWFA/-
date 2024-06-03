#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, k, summ, len = 3, maxx;
int a[N], vis[N];
void dfs(int x)
{
	if (x == len + 1)
	{
		if (summ % k == 0)
		{
			maxx = max(summ, maxx);
		}
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (vis[i] == 0)
		{
			if (x == 1 && i > n - 3 + 1)
				break;
			summ += a[i];
			vis[i] = 1;
			dfs(x + 1);
			vis[i] = 0;
			summ -= a[i];
		}
	}
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	dfs(1);
	cout << maxx;
	return 0;
}