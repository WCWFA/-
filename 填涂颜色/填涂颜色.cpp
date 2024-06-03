#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 39;
int n;
int used[N][N], graph[N][N];
struct node
{
	int x;
	int y;
};
void bfs(int x, int y)
{
	if (graph[x][y] == 1)
		return;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	queue<node> que;
	node st;
	st.x = x;
	st.y = y;
	used[x][y] = 1;
	que.push(st);
	while (!que.empty())
	{
		node tmp = que.front();
		for (int i = 0; i < 4; ++i)
		{
			node ret;
			ret.x = tmp.x + dx[i];
			ret.y = tmp.y + dy[i];
			if (ret.x > 0 && ret.x <= n &&
				ret.y > 0 && ret.y <= n &&
				used[ret.x][ret.y] == 0 && graph[ret.x][ret.y] == 0)
			{
				que.push(ret);
				used[ret.x][ret.y] = 1;
			}
		}
		que.pop();
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			cin >> graph[i][j];
	}
	for (int i = 1; i <= n; ++i)
	{
		bfs(i, 1);
		bfs(i, n);
	}
	for (int j = 1; j <= n; ++j)
	{
		bfs(1, j);
		bfs(n, j);
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			cout << used[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}