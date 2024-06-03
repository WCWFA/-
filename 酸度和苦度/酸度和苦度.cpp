#include<bits/stdc++.h>
using namespace std;
const int N = 19;
int n;
int s[N], b[N], alls[N], allb[N], dp[N];
void dfs(int pos)
{
	if (pos == n + 1)
	{
		cout << dp[n];
	}
	for (int i = pos; i <= n; ++i)
	{
		alls[i] = alls[i - 1] * s[i];
		allb[i] = allb[i - 1] + b[i];
		dp[i] = min(dp[i - 1], abs(alls[i] - allb[i]));
		dfs(pos + 1);
		alls[i] /= alls[i];
		allb[i] -= allb[i];
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	alls[0] = 1;
	alls[1] = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s[i] >> b[i];
		alls[i] = 1, allb[i] = 0;
		dp[i-1] = INT_MAX;
	}
	dfs(1);
	return 0;
}