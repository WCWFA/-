#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 9;
int a[N], q[N];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int hh = 1, tt = 0;
	cout << 0 << endl;
	for (int i = 1; i < n; ++i)
	{
		if (hh <= tt && m < i - q[hh] + 1) hh++;
		while (hh <= tt && a[q[tt]] > a[i])tt--;
		q[++tt] = i;
		cout << a[q[hh]] << '\n';
	}
	return 0;
}