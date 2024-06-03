#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int w[N], v[N], dp[N];
int ret(int number)
{
	if (number == 1)
		return 0;
	int sum = 0;
	for (int i = 1; i <= sqrt(number); ++i)
	{
		if (i == 1)
			sum += 1;
		else if (number % i == 0)
		{
			sum += i;
			if (i != number / i)
				sum += number / i;
		}
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int s;
	cin >> s;
	for (int i = 1; i <= s; ++i)
	{
		w[i] = i;
		v[i] = ret(i);
	}
	for (int i = 1; i <= s; ++i)
	{
		for (int j = s; j >= w[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[s];
	return 0;
}