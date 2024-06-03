#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int w[N], v[N], dp[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> v[i];
		cin >> w[i];
		w[i] *= v[i];
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = n; j >= v[i]; j--)
		{
			dp[j] = max(dp[j - v[i]] + w[i], dp[j]);
		}
	}
	cout << dp[n];
	return 0;
}