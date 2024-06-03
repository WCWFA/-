#include<bits/stdc++.h>
using namespace std;
const int N = 109;
int  used[N][N], sum;
char a[N][N] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', 'U', 'D', 'D', 'L', 'U', 'U', 'L', 'R', 'U', 'L'},
		{' ', 'U', 'U', 'R', 'L', 'L', 'L', 'R', 'R', 'R', 'U'},
		{' ', 'R', 'R', 'U', 'U', 'R', 'L', 'D', 'L', 'R', 'D'},
		{' ', 'R', 'U', 'D', 'D', 'D', 'D', 'U', 'U', 'U', 'U'},
		{' ', 'U', 'R', 'U', 'D', 'L', 'L', 'R', 'R', 'U', 'U'},
		{' ', 'D', 'U', 'R', 'L', 'R', 'L', 'D', 'L', 'R', 'L'},
		{' ', 'U', 'L', 'L', 'U', 'R', 'L', 'L', 'R', 'D', 'U'},
		{' ', 'R', 'D', 'L', 'U', 'L', 'L', 'R', 'D', 'D', 'D'},
		{' ', 'U', 'U', 'D', 'D', 'U', 'D', 'U', 'D', 'L', 'L'},
		{' ', 'U', 'L', 'R', 'D', 'L', 'U', 'U', 'R', 'R', 'R'}
};
struct node
{
	int x;
	int y;
};
void bfs(int xx, int yy)
{
	memset(used, 0, sizeof(used));
	queue<node> que;
	node st;
	st.x = xx;
	st.y = yy;
	used[xx][yy] = 1;
	que.push(st);
	while (!que.empty())
	{
		node tmp = que.front();
		node ret;
		if (a[tmp.x][tmp.y] == 'L')
		{
			ret.x = tmp.x;
			ret.y = tmp.y - 1;
		}
		else if (a[tmp.x][tmp.y] == 'R')
		{
			ret.x = tmp.x;
			ret.y = tmp.y + 1;
		}
		else if (a[tmp.x][tmp.y] == 'U')
		{
			ret.x = tmp.x - 1;
			ret.y = tmp.y;
		}
		else if (a[tmp.x][tmp.y] == 'D')
		{
			ret.x = tmp.x + 1;
			ret.y = tmp.y;
		}
		if (ret.x <= 0 || ret.x > 10 || ret.y <= 0 || ret.y > 10)
		{
			sum++;
			return;
		}
		else if (used[ret.x][ret.y] == 0)
		{
			que.push(ret);
			used[ret.x][ret.y] = 1;
		}
		que.pop();
	}
}
int main()
{
	for (int i = 1; i <= 10; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			bfs(i, j);
		}
	}
	cout << sum;
	return 0;
}