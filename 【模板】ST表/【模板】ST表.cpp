#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 9;
int a[N], dp[N][25], Log[N];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch>'9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
	return x * f;
}
void pre()
{
	Log[1] = 0;
	Log[2] = 1;
	for (int i = 3; i < N; ++i)
	{
		Log[i] = Log[i / 2] + 1;
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		int tmp = read();
		dp[i][0] = tmp;
	}
	pre();
	for (int j = 1; j <= 21; ++j)
	{
		for (int i = 1; i + (1 << j) - 1 <= n; ++i)
		{
			dp[i][j] = max(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		int x, y;
		x = read();
		y = read();
		int s = Log[y - x + 1];
		cout << max(dp[x][s], dp[y - (1 << s) + 1][s]) << '\n';
	}
	return 0;
}