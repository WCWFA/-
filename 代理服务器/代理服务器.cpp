#include<bits/stdc++.h>
using namespace std;
map<string, int> smp;
map<string, int> fmp;
int n, m;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		string tmp;
		cin >> tmp;
		smp[tmp] = 1;
	}
	cin >> m;
	for (int i = 1; i <= m; ++i)
	{
		string tmp;
		fmp[tmp] += 1;
		if (smp.count(tmp) != 0)
		{
			smp[tmp]++;
		}
	}
	return 0;
}