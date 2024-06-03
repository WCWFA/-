#include<bits/stdc++.h>
using namespace std;
const int N = 109;
int a[N], dp[N][N],sum[N][N],q[N];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		q[i] = a[i] + q[i - 1];
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			sum[i][j] = q[j] - q[i - 1];
		}
	}
	for (int len = 1; len <= n; ++len)
	{
		for (int j = 1; j + len <= n + 1; ++j)
		{
			int ends = j + len - 1;
			dp[j][ends] = INT_MAX;
			for (int i = j; i < ends; ++i)
			{
				dp[j][ends] = min(dp[j][ends], dp[j][i] + dp[i + 1][ends] + q[ends] - q[j - 1]);
			}
		}
	}
	cout << dp[1][n];
	return 0;
}