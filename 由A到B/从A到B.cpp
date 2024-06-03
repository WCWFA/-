#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int ans[N], dp[N][N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a, b;
	while (cin >> a >> b)
	{
		for (int i = a.size() - 1; i >= 0; i--)//第一次dp是空串到B串的最小次数
		{
			for (int j = i ; j < a.size(); ++j)
			{
				dp[i][j] = dp[i + 1][j] + 1;
				for (int k = i + 1; k <= j; ++k)
				{
					if (b[i] == b[k])
						dp[i][j] = min(dp[i][j], dp[i + 1][k] + dp[k + 1][j]);
				}
			}
		}
		for (int i = 0; i < a.size(); ++i)//第二次dp是A串到B串的最小次数（要么不刷要么就是空串）
		{
			if (a[i] == b[i])
			{
				ans[i] = ans[i - 1];
			}
			else
			{
				ans[i] = dp[0][i];
				for (int j = 0; j <= i; ++j)
					ans[i] = min(ans[i], ans[j] + dp[j + 1][i]);
			}
		}
		cout << ans[a.size() - 1] << '\n';
	}
	return 0;
}