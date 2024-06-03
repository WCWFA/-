#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll a[N], c[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	ll n;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
		}
		memset(c, 0, sizeof(c));
		ll ret = 0;
		int i = 1, j = 0;
		while (j < n)
		{
			if (c[a[j + 1]])
			{
				c[a[i]]--;
				i++;
			}
			else
			{
				c[a[j + 1]]++;
				j++;
			}
			ret = max(ret, ll(j - i + 1));
		}
		cout << ret << '\n';
	}
	return 0;
}