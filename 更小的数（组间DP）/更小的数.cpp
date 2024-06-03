#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 9;
int ans, dp[N][N];//dp[i][j]表示从i到j是否要进行翻转
int main()
{
	string num;
	cin >> num;
	for (int i = 0; i < num.size(); ++i)//首先对邻近进行判断
	{
		if (num[i] > num[i + 1])
			dp[i][i + 1] = 1;
	}
	for (int len = 3; len <= num.size(); ++len)//进行组间dp
	{
		for (int j = 0; j + len - 1 < num.size(); ++j)
		{
			int ends = j + len - 1;
			if (num[j] == num[ends])
				dp[j][ends] = dp[j + 1][ends - 1];
			else if (num[j] > num[ends])
			{
				dp[j][ends] = 1;
			}
		}
	}
	for (int i = 0; i < num.size(); ++i)//将所有的结果进行加和（因为dp只表示是否要进行翻转）
	{
		for (int j = 0; j < num.size(); ++j)
		{
			ans += dp[i][j];
		}
	}
	cout << ans;
	return 0;
}