#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
int dp[N][N];
int main()
{
	string s;
	cin >> s;
	string s1;
	s1 = s;
	reverse(s.begin(), s.end());
	for (int i = 1; i <= s1.size(); ++i)
	{
		for (int j = 1; j <= s.size(); ++j)
		{
			if (s1[i - 1] == s[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << s.size() - dp[s1.size()][s.size()];
	return 0;
}