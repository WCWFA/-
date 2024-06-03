#include<bits/stdc++.h>
using namespace std;
struct node
{
	int s;
	int p;
};
bool cmp(const node& x1, const node& x2)
{
	return x1.s < x2.s;
}
vector<node> v;
int main()
{
	int n, k, s;
	int start;
	int summ = 0;
	cin >> n >> k >> s;
	for (int i = 1; i <= n; ++i)
	{
		int ss, pp;
		cin >> ss >> pp;
		v.push_back({ ss,pp });
	}
	sort(v.begin(), v.end(), cmp);
	
	return 0;
}