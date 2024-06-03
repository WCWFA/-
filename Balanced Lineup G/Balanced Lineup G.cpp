#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 9;
int dp1[N][25], Log[N], dp2[N][21];
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
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
	{
		cin >> dp1[i][0];
		dp2[i][0] = dp1[i][0];
	}
	pre();
	for (int j = 1; j <= 20; ++j)
	{
		for (int i = 1; i + (1 << j) - 1 <= n; ++i)
		{
			dp1[i][j] = max(dp1[i][j - 1], dp1[i + (1 << (j - 1))][j - 1]);
			dp2[i][j] = min(dp2[i][j - 1], dp2[i + (1 << (j - 1))][j - 1]);
		}
	}
	for (int i = 1; i <= q; ++i)
	{
		int x, y;
		cin >> x >> y;
		int s = Log[y - x + 1];
		int maxx = max(dp1[x][s], dp1[y - (1 << s) + 1][s]);
		int minn = min(dp2[x][s], dp2[y - (1 << s) + 1][s]);
		cout << maxx - minn << '\n';
	}
	return 0;
}