#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 9;
int a[N],dp[N][N];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i)//此时只剩一个，说明已经到了第五天了
	{
		dp[i][i] = a[i] * n;
	}
	for (int len = 1; len <= n; ++len)
	{
		for (int j = 1; j + len <= n + 1; j++)//此时天数应该是n-len+1
		{
			int ends = j + len - 1;
			dp[j][ends] = max(dp[j + 1][ends] + a[j] * (n - len + 1), dp[j][ends - 1] + a[ends] * (n - len + 1));
		}
	}
	cout << dp[1][n];
	return 0;
}