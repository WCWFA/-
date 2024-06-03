#include<bits/stdc++.h>
using namespace std;
const int N = 109;
int m, n;
char a[N][N];
int used[N][N];
int cnt;
struct node
{
	int x;
	int y;
	bool operator==(const node& other) const {
		return x == other.x && y == other.y;
	}
};
list<node> li;
void bfs()
{
	memset(used, 0, sizeof(used));
	int dx[8] = { 0,0,1,1,1,-1,-1,-1 };
	int dy[8] = { 1,-1,1,0,-1,1,0,-1 };
	queue<node> que;
	node st;
	st.x = 1;
	st.y = 1;
	que.push(st);
	used[1][1] = 1;
	if (a[st.x][st.y] == '@')
	{
		li.push_back(st);
	}
	while (!que.empty())
	{
		node tmp = que.front();
		for (int i = 0; i < 8; ++i)
		{
			node ret;
			ret.x = tmp.x + dx[i];
			ret.y = tmp.y + dy[i];
			if (ret.x > 0 && ret.x <= m && ret.y > 0 && ret.y <= n && used[ret.x][ret.y] == 0)
			{
				used[ret.x][ret.y] = 1;
				que.push(ret);
				if (a[ret.x][ret.y] == '@')
				{
					li.push_back(ret);
				}
			}
		}
		que.pop();
	}
}
void yBFS()
{
	memset(used, 0, sizeof(used));
	int dx[8] = { 0,0,1,1,1,-1,-1,-1 };
	int dy[8] = { 1,-1,1,0,-1,1,0,-1 };
	while (!li.empty())
	{
		node st = li.front();
		queue<node> que;
		que.push(st);
		used[st.x][st.y] = 1;
		while (!que.empty())
		{
			node tmp = que.front();
			for (int i = 0; i < 8; ++i)
			{
				node ret;
				ret.x = tmp.x + dx[i];
				ret.y = tmp.y + dy[i];
				if (ret.x > 0 && ret.x <= m && ret.y > 0 && ret.y <= n
					&& used[ret.x][ret.y] == 0 && a[ret.x][ret.y] == '@')
				{
					used[ret.x][ret.y] = 1;
					que.push(ret);
					//li.remove(ret);
				}
			}
			li.remove(tmp);
			que.pop();
		}
		cnt++;
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (1)
	{
		cin >> m >> n;
		if (m == 0 && n == 0)
			break;
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				cin >> a[i][j];
			}
		}
		bfs();
		yBFS();
		cout << cnt << endl;
		cnt = 0;
		li.clear();
	}
	return 0;
}