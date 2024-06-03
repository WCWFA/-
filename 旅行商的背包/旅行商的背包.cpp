#include<iostream>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll dp[N], w[N], v[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, C;
	cin >> n >> m >> C;
	int cnt = 1;
	for (int i = 1; i <= n; ++i)
	{
		int V, W, D;
		cin >> V >> W >> D;
		int mnt = 1;
		while (D >= mnt)
		{
			w[cnt] = mnt * W;
			v[cnt] = mnt * V;
			D -= mnt;
			mnt *= 2;
			cnt++;
		}
		if (D > 0)
		{
			w[cnt] = D * W;
			v[cnt] = D * V;
			cnt++;
		}
	}
	for (int i = 1; i <= cnt; ++i)
	{
		for (int j = C; j >= v[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = C; j >= 0; j--)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[j] = max(dp[j], dp[j - k] + 1ll * a * k * k + b * k + c);
			}
		}
	}
	cout << dp[C];
	return 0;
}