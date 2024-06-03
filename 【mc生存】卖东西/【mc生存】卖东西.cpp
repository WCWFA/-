#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int w[N], vv[N], dp[N];
struct thing
{
	int a;
	int b;
	int c;
	string s;
	thing(int& aa, int& bb, int& cc, string& ss)
	{
		a = aa;
		b = bb;
		c = cc;
		s = ss;
	}
};
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int m, n;
	cin >> m >> n;
	int real_v = 21 - m;
	vector<thing> v;
	for (int i = 1; i <= n; ++i)
	{
		int ta, tb, tc;
		string ts;
		cin >> ta >> tb >> tc >> ts;
		int flag = 1, j = 0;
		for (j = 0; j < v.size(); ++j)
		{
			if (ts == v[j].s)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			thing tmp(ta, tb, tc, ts);
			v.push_back(tmp);
		}
		else
		{
			v[j].a += ta;
		}
	}
	int cnt = 1;
	for (int i = 0; i < v.size(); ++i)
	{
		int mnt = v[i].c;
		while (v[i].a >= mnt)
		{
			w[cnt] = 1;
			vv[cnt] = v[i].b * mnt;
			v[i].a -= mnt;
			cnt++;
		}
		if (v[i].a > 0)
		{
			w[cnt] = 1;
			vv[cnt] = v[i].b * v[i].a;
			cnt++;
		}
	}
	for (int i = 1; i <= cnt; ++i)
	{
		for (int j = real_v; j >= w[i]; --j)
		{
			dp[j] = max(dp[j], dp[j - w[i]] + vv[i]);
		}
	}
	cout << dp[real_v];
	return 0;
}