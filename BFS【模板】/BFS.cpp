#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 4E2 + 9;
int map1[N][N], used[N][N];
int n, m, x, y;

struct node
{
	int x;
	int y;
	int step;
};
void BFS()
{
	queue<node> que;
	node st;
	st.x = x;
	st.y = y;
	st.step = 0;
	map1[x][y] = st.step;
	used[st.x][st.y] = 1;
	int dx[8] = { -1,1,2,2,1,-1,-2,-2 };
	int dy[8] = { 2,2,1,-1,-2,-2,-1,1 };
	que.push(st);
	while (!que.empty())
	{
		auto temp = que.front();
		for (int i = 0; i < 8; ++i)
		{
			if (temp.x + dx[i] > 0 && temp.x + dx[i] <= n &&
				temp.y + dy[i] > 0 && temp.y + dy[i] <= m
				&& used[temp.x + dx[i]][temp.y + dy[i]] == 0)
			{
				used[temp.x + dx[i]][temp.y + dy[i]] = 1;
				node ret;
				ret.x = temp.x + dx[i];
				ret.y = temp.y + dy[i];
				ret.step = temp.step + 1;
				map1[ret.x][ret.y] = ret.step;
				que.push(ret);
			}
		}
		que.pop();
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> x >> y;
	memset(map1, -1, sizeof(map1));
	BFS();
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			printf("%-5d", map1[i][j]);
		}
		printf("\n");
	}
	return 0;
}