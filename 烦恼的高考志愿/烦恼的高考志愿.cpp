#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, m;
int a[N], b[N];
int main()
{
	cin >> m >> n;
	int minn_all = 0;
	for (int i = 1; i <= m; ++i)
		cin >> a[i];
	sort(a + 1, a + m + 1);
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int minn = INT_MAX;
		int left = 1, right = m;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			minn = min(minn, abs(a[mid] - b[i]));
			if (a[mid] > b[i])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		minn_all += minn;
	}
	cout << minn_all;
	return 0;
}