#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N], dp[N][25], Log[N], b[N];
void pre()
{
	Log[1] = 0;
	Log[2] = 1;
	for (int i = 3; i < N; ++i)
	{
		Log[i] = Log[i / 2] + 1;
	}
}
int main()
{
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 1; i <= n; ++i)//����b[i]��ʾֵ��i���±꣬a[i]��ʾ��i����ǰ��b(a^b=x)���ֵ��±�
								//��ʱ��Ҫ�ҵ�a[i]�����ֵ�����Ƿ���ڵ���l(��Ϊa[i]<=i)	
	{
		int xx;
		cin >> xx;
		a[i] = b[xx ^ x];
		b[xx] = i;
	}
	pre();
	for (int i = 1; i <= n; ++i)
	{
		dp[i][0] = a[i];
	}
	for (int j = 1; j < 25; ++j)
	{
		for (int i = 1; i + (1 << j) - 1 <= n; ++i)
		{
			dp[i][j] = max(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		int x, y;
		cin >> x >> y;
		int s = Log[y - x + 1];
		int maxx = max(dp[x][s], dp[y - (1 << s) + 1][s]);
		if (maxx >= x)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}
	return 0;
}