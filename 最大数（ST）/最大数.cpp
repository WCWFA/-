#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
using ll = long long;
ll dp[N][25], Log[N], a[N];
ll n;
void pre()
{
	Log[1] = 0;
	Log[2] = 1;
	for (int i = 3; i < N; ++i)
	{
		Log[i] = Log[i / 2] + 1;
	}
}
void ST()
{
	for (int i = 1; n - (1 << i) >= 0; ++i)//此时的ST表表示(i,i-2^(j-1)+1]的最值
	{
		dp[n][i] = max(dp[n][i - 1], dp[n - (1 << (i - 1))][i - 1]);
	}
}
int main()
{
	int m, d;
	cin >> m >> d;
	pre();
	ll t = 0;
	while (m--)
	{
		char ch;
		ll tmp;
		cin >> ch >> tmp;
		if (ch == 'A')
		{
			dp[++n][0] = (tmp + t) % d;
			a[n] = (tmp + t) % d;
			ST();
		}
		if (ch == 'Q')
		{
			int s = Log[tmp];
			//x=n-L+1,y=n;
			//y s	x+(1<<s)-1 s
			ll ans;
			if (tmp == 1)
			{
				ans = a[n];
			}
			else
			{
				ans = max(dp[n][s], dp[n - tmp + (1 << s)][s]);
			}
			t = ans;
			cout << t << endl;
		}
	}
	return 0;
}