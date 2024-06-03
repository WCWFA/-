#include <iostream>
using namespace std;
using ll = long long;
const ll N = 1e5 + 9;
ll a[N], l, r, q, T, n, pre[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> n >> q;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		for (int i = 1; i <= n; ++i)
		{
			pre[i] = pre[i - 1] + a[i];
		}
		while (q--)
		{
			cin >> l >> r;
			cout << pre[r] - pre[l - 1] << '\n';
		}
	}
	return 0;
}