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
		for (int i = a.size() - 1; i >= 0; i--)
		{
			for (int j = i + 1; j < a.size(); ++j)
			{
				dp[i][j] = dp[i + 1][j] + 1;
				for (int k = i + 1; i < a.size(); ++k)
				{
					if (b[i] == b[k])
						dp[i][j] = min(dp[i][j], dp[i + 1][k] + dp[k + 1][j]);
				}
			}
		}
		cout << dp[0][a.size() - 1] << endl;
	}
	return 0;
}