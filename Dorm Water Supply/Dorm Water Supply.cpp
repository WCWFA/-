#include<bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1e3 + 9;
int inn[N], out[N];
struct node
{
	int u;
	int v;
	int value;
};
vector<node> vv;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vv.push_back({ a,b,c });
		out[a]++;
		inn[a]++;
	}
	
	return 0;
}