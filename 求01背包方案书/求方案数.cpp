#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 9;
int dp[N], a[N], ret[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	ret[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = m; j >= a[i]; --j)
		{
			if (dp[j] > dp[j - a[i]])
			{
				dp[j] = dp[j];
				ret[j] = ret[j];
			}
			else
			{
				dp[j] = dp[j - a[i]];
				ret[j] += ret[j - a[i]];
			}
		}
	}
	cout << ret[m];
	return 0;
}