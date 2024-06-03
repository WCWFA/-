#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
map<int, vector<int>> mp;
int a[N], used[N];
int n;
struct node
{
	int x;
	int step;
};
void bfs()
{
	queue<node> q;
	node st;
	st.x = 1;
	st.step = 0;
	q.push(st);
	used[st.x] = 1;
	a[st.x] = 0;
	while (!q.empty())
	{
		node tmp = q.front();
		for (auto& e : mp[tmp.x])
		{
			node ret;
			ret.x = e;
			ret.step = tmp.step + 1;
			if (used[ret.x] == 0)
			{
				used[ret.x] = 1;
				q.push(ret);
				a[ret.x] = ret.step;
			}
		}
		q.pop();
	}
}
void bfs1()
{
	queue<node> q;
	node st;
	st.x = 1;
	st.step = 0;
	q.push(st);
	int dx[2] = { 1,-1 };
	while (!q.empty())
	{
		node tmp = q.front();
		for (int i = 0; i < 2; ++i)
		{
			node ret;
			ret.x = tmp.x + dx[i];
			ret.step = tmp.step + 1;
			if (ret.x >= 1 && ret.x <= n)
			{
				if (a[ret.x] != -1 && used[ret.x] == 0)
				{
					a[ret.x] = min(a[ret.x], ret.step);
					q.push(ret);

				}
				else if (a[ret.x] == -1)
				{
					a[ret.x] = ret.step;
					q.push(ret);
				}
			}
			cout << 1;
		}
		q.pop();
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int tmp;
		cin >> tmp;
		mp[i].push_back(tmp);
	}
	memset(a, -1, sizeof(a));
	bfs();
	bfs1();
	for (int i = 1; i <= n; ++i)
	{
		cout << a[i] << ' ';
	}
	return 0;
}