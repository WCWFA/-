#include<bits/stdc++.h>
using namespace std;
int n, m, k;
const int N = 509;
int used[N][N];
char a[N][N];
struct node
{
	int x;
	int y;
};
vector<node> vv;
vector<node> v_er;
vector<node> v_pp;
void bfs1()
{
	queue<node> que;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	node st;
	st.x = 1;
	st.y = 1;
	used[1][1] = 1;
	que.push(st);
	while (!que.empty())
	{
		node tmp = que.front();
		if (a[tmp.x][tmp.y] == '.')
		{
			vv.push_back(tmp);
		}
		for (int i = 0; i < 4; ++i)
		{
			node ret;
			ret.x = tmp.x + dx[i];
			ret.y = tmp.y + dy[i];
			if (ret.x > 0 && ret.x <= n && ret.y > 0 && ret.y <= m
				&& used[ret.x][ret.y] == 0)
			{
				used[ret.x][ret.y] = 1;
				que.push(ret);
			}
		}
		que.pop();
	}
}
void bfs2()
{
	queue<node> que;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	node st;
	st.x = vv[0].x;
	st.y = vv[0].y;
	used[st.x][st.y] = 1;
	que.push(st);
	while (!que.empty())
	{
		node tmp = que.front();
		if (a[tmp.x][tmp.y] == '.')
		{
			if (v_pp.size() < vv.size() - k)
			{
				v_pp.push_back(tmp);
			}
			else
			{
				v_er.push_back(tmp);
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			node ret;
			ret.x = tmp.x + dx[i];
			ret.y = tmp.y + dy[i];
			if (ret.x > 0 && ret.x <= n && ret.y > 0 && ret.y <= m
				&& used[ret.x][ret.y] == 0 && a[ret.x][ret.y] == '.')
			{
				used[ret.x][ret.y] = 1;
				que.push(ret);
			}
		}
		que.pop();
	}
}
int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> a[i][j];
		}
	}
	bfs1();
	memset(used, 0, sizeof(used));
	bfs2();
	for (int i = 0; i < v_er.size(); ++i)
	{
		a[v_er[i].x][v_er[i].y] = 'X';
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			cout << a[i][j];
		cout << '\n';
	}
	return 0;
}