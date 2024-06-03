#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3+9;
ll time1[N], val[N], a[N][N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T, M;
	cin >> T >> M;
	for (int i = 1; i <= M; ++i)
	{
		cin >> time1[i] >> val[i];
	}
	for (int i = 1; i <= M; ++i)
	{
		for (int j = 1; j <= T; ++j)
		{
			if (j < time1[i])
				a[i][j] = a[i - 1][j];
			else
			{
				a[i][j] = max(a[i - 1][j], a[i - 1][j - time1[i]] + val[i]);
			}
		}
	}
	cout << a[M][T] << '\n';
	return 0;
}