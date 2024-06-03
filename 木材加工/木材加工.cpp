#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N];
int n, k, maxx;
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	int left = 0, right = maxx;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (mid == 0)
			break;
		int summ = 0;
		for (int i = 1; i <= n; ++i)
		{
			int tmp = a[i] / mid;
			summ += tmp;
		}
		if (summ < k)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	if ((left + right) == 0)
		cout << 0;
	else
		cout << left - 1;
	return 0;
}