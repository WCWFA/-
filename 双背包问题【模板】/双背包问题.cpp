#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
ll dp[N][N], v[N], w1[N], w2[N];
int main()
{
	int n, s1, s2;
	cin >> n >> s1 >> s2;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i] >> w1[i] >> w2[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = s1; j >= v[i]; --j)
		{
			for (int k = s2; k >= v[i]; --k)
			{
				ll tmp = max(dp[j - v[i]][k] + w1[i], dp[j][k - v[i]] + w2[i]);
				dp[j][k] = max(dp[j][k], tmp);
			}
		}
		for (int j = s1; j >= v[i]; --j)
		{
			for (int k = v[i] - 1; k >= 0; --k)
			{
				dp[j][k] = max(dp[j][k], dp[j - v[i]][k] + w1[i]);
			}
		}
		for (int j = v[i] - 1; j >= 0; --j)
		{
			for (int k = s2; k >= v[i]; --k)
			{
				dp[j][k] = max(dp[j][k], dp[j][k - v[i]] + w2[i]);
			}
		}
	}
	cout << dp[s1][s2];
	return 0;
}