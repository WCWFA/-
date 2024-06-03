#include<bits/stdc++.h>
using namespace std;
const int N = 9;
int n;
int dp[N];
void dfs(int pos, int sum)
{
	if (pos >= 3 && dp[pos - 1] < dp[pos - 2])
	{
		return;
	}
	if (sum == n)
	{
		for (int i = 1; i < pos; ++i)
		{
			cout << dp[i];
			if (i != pos - 1)
				cout << "+";
		}
		cout << '\n';
	}
	for (int i = 1; i < n && sum < n; ++i)
	{
		sum += i;
		dp[pos] = i;
		dfs(pos + 1, sum);
		sum -= i;
	}
}
int main()
{
	cin >> n;
	dfs(1, 0);
	return 0;
}