#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
ll n, m;
ll a[N];
ll summ;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll left = 0, right = a[n];
	while (left <= right)
	{
		summ = 0;
		ll mid = (left + right) / 2;
		for (int i = 1; i <= n; ++i)
		{
			if (a[i] > mid)
			{
				summ += a[i] - mid;
			}
		}
		if (summ < m)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << left - 1;
	return 0;
}