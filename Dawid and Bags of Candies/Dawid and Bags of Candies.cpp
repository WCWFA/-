#include<bits/stdc++.h>
using namespace std;
int a[10];
void dfs(int pos,int sum1, int sum2)
{
	if (pos == 5)
	{
		if (sum1 == sum2)
		{
			cout << "YES";
			exit(0);
		}
		return;
	}
	dfs(pos + 1, sum1 + a[pos], sum2);
	dfs(pos + 1, sum1, sum2 + a[pos]);
}
int main()
{
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 1; i <= 4; ++i)
	{
		cin >> a[i];
	}
	dfs(1, 0, 0);
	cout << "NO";
	return 0;
}