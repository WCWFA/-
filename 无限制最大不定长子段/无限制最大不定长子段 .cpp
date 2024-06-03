#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, max_sum, ans = INT_MIN;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int tmp;
		cin >> tmp;
		if (i == 1)
		{
			max_sum = tmp;
			continue;
		}
		max_sum = max(max_sum + tmp, tmp);
		ans = max(max_sum, ans);
	}
	cout << ans;
	return 0;
}