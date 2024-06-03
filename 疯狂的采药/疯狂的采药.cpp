#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
ll dp[N], v[N], lose[N], win[N];
int main()
{
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; ++i)
	{
		cin >> lose[i] >> win[i] >> v[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = x; j >= 0; --j)
		{
			if (j >= v[i])
				dp[j] = max(dp[j] + lose[i], dp[j - v[i]] + win[i]);
			else
				dp[j] = dp[j] + lose[i];
		}
	}
	ll ret = 5 * dp[x];
	cout << ret<<endl;
	cout << dp[x];
	return 0;
}