#include<bits/stdc++.h>
using namespace std;
const int N = 29;
int n, ss = 1, bb = 0, m;
int s[N], b[N], dp[N], v[N];
void dfs(int x, int y)
{
	if (x == y + 1)
	{
		return;
	}
	ss *= s[x];
	bb += b[x];
	m = min(m, abs(ss - bb));
	dfs(x + 1, y);
	ss /= s[x];
	bb -= b[x];
}
int main()
{
	cin >> n;
	dp[0] = INT_MAX;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s[i] >> b[i];
		dp[i] = INT_MAX;
	}
	int mm = INT_MAX;
	for (int i = 1; i <= n; ++i)
	{
		ss = 1, bb = 0;
		m = INT_MAX;
		dfs(1, i);
		mm = min(mm, m);
	}
	cout << m << endl;
	return 0;
}