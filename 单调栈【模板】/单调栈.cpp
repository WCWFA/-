#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 9;
struct node
{
	int value;
	int pos;
};
int f[N];
vector<node> vv;
stack<node> st;
int n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int v1, p1;
		cin >> v1;
		p1 = i;
		vv.push_back({ v1,p1 });
	}
	for (int i = 0; i < vv.size(); ++i)
	{
		while (!st.empty() && vv[i].value > st.top().value)
		{
			node tmp = st.top();
			f[tmp.pos] = vv[i].pos;
			st.pop();
		}
		st.push(vv[i]);
	}
	for (int i = 1; i <= n; ++i)
		cout << f[i] << ' ';
	return 0;
}