#include<bits/stdc++.h>
using namespace std;
int n;
int sum = 0;
int r[15], l1[30], l2[30], fina[15];
void dfs(int x)
{
	if (x == n + 1)
	{
		sum++;
		if (sum <= 3)
		{
			for (int i = 1; i <= n; ++i)
			{
				cout << fina[i] << ' ';
			}
			cout << '\n';
		}
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		int tmp1 = x + i;
		int tmp2 = x - i + n;
		if (r[i] == 0 && l1[tmp1] == 0 && l2[tmp2] == 0)
		{
			fina[x] = i;
			r[i] = 1;
			l1[tmp1] = 1;
			l2[tmp2] = 1;
			dfs(x + 1);
			r[i] = 0;
			l1[tmp1] = 0;
			l2[tmp2] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	dfs(1);
	cout << sum;
	return 0;
}