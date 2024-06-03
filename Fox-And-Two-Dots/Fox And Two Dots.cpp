#include<bits/stdc++.h>
using namespace std;
const int N = 55;
int n, m;
char a[N][N];
int used[N][N];
struct node
{
	int x;
	int y;
	bool operator!=(node& tmp)
	{
		return !(x == tmp.x && y == tmp.y);
	}
};
void bfs(int xx, int yy)
{
	queue<node>que;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	node st;
	st.x = xx;
	st.y = yy;
	node prev;
	prev.x = 0;
	prev.y = 0;
	que.push(st);
	while (!que.empty())
	{
		node tmp = que.front();
		for (int i = 0; i < 4; ++i)
		{
			node ret;
			ret.x = tmp.x + dx[i];
			ret.y = tmp.y + dy[i];
			if (ret.x > 0 && ret.x <= n && ret.y > 0 && ret.y <= m
				&& used[ret.x][ret.y] == 0 && a[ret.x][ret.y] == a[tmp.x][tmp.y]
				&& (ret != prev))
			{
				used[ret.x][ret.y] = 1;
				que.push(ret);
			}
		}
		prev.x = tmp.x;
		prev.y = tmp.y;
		que.pop();
	}
	if (used[xx][yy] == 1)
	{
		cout << "Yes";
		exit(0);
	}
	int i = 0, j = 0, flag = 0;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= m; ++j)
		{
			if (used[i][j] == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	if (i != 0 && j != 0)
	{
		bfs(i, j);
	}
	return;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	}
	bfs(1, 1);
	cout << "No";
	return 0;
}