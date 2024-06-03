#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int dp[N], q[N], w[N], v[N], g[N], m[N];
int main()
{
	int n, W;
	cin >> n >> W;
	for (int i = 1; i <= n; ++i)
	{
		int v, w, m;
		cin >> w >> v >> m;
		memcpy(g, dp, sizeof(dp));
		for (int j = 0; j < v; ++j)
		{
			int head = 0, tail = -1;
			for (int k = j; k <= W; k += v)
			{
				if (head <= tail && m < (k - q[head]) / v)
					head++;
				if (head <= tail)
					dp[k] = max(g[k], g[q[head]] + (k - q[head]) / v * w);
				while (head <= tail && g[k] >= g[q[tail]] + (k - q[tail]) / v * w)
					tail--;
				q[++tail] = k;
			}
		}
	}
	cout << dp[W];
	return 0;
}