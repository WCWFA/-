#include<iostream>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll a[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		ll ret = 0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			ret = a[i] ^ ret;
		}
		cout << ret << '\n';
	}
	return 0;
}