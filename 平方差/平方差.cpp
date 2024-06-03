#include<bits/stdc++.h>
using namespace std;
const int N = 39;
int dp[N];
//令x=b(b+2z)，此时若b为奇数，则x为奇数，若b为偶数，则x可被4整除。
int main()
{
	int l, r;
	cin >> l >> r;
	int ans = 0;
	for (int i = l; i <= r; ++i)
	{
		if (i % 2 != 0)
			ans++;
		else if (i % 4 == 0)
			ans++;
	}
	cout << ans;
	return 0;
}