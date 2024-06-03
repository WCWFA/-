#include<iostream>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int solve(int& a)
{
	int sum = 0;
	while (a != 0)
	{
		if (a & 1)
			sum++;
		a = a >> 1;
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int ret;
		cin >> ret;
		cout << solve(ret) << ' ';
	}

	return 0;
}