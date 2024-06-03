#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int w[N], v[N], dp[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, V;
	cin >> V >> n;
	for (int i = 1; i <= n; ++i)
	{
		int tmp = 0;
		cin >> tmp;
		w[i] = v[i] = tmp;
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = V; j >= v[i]; --j)
		{
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
		}
	}
	cout << V - dp[V];
	return 0;
}