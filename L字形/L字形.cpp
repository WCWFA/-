#include<bits/stdc++.h>
const int N = 59;
char a[N][N];
int used[N][N], n, m;
using namespace std;
struct node
{
	int x;
	int y;
	int number;
};
bool bfs()
{
	node st;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	int ddx[4] = { 1,1,-1,-1 };
	int ddy[4] = { 1,-1,1,-1 };
	st.x = 1;
	st.y = 1;
	st.number = 0;
	queue<node> que;
	que.push(st);
	used[1][1] = 1;
	int all_sum = 0;
	int two_sum = 0;
	while (!que.empty())
	{
		node tmp = que.front();
		if (a[tmp.x][tmp.y] == '*')
			all_sum++;
		for (int i = 0; i < 4; ++i)
		{
			node ret;
			ret.x = tmp.x + dx[i];
			ret.y = tmp.y + dy[i];
			ret.number = 0;
			if (ret.x > 0 && ret.x <= n && ret.y > 0 && ret.y <= m)
			{
				if (used[ret.x][ret.y] == 0)
				{
					used[ret.x][ret.y] = 1;
					que.push(ret);
				}
				if (a[ret.x][ret.y] == '*' && a[tmp.x][tmp.y] == '*')
				{
					tmp.number++;
				}
			}
		}
		if (a[tmp.x][tmp.y] == '*' && tmp.number == 0)
		{
			//cout << tmp.x << ' ' << tmp.y << endl;
			//two_sum++;
			return false;
		}
		for (int i = 0; i < 4; ++i)
		{
			node ret;
			ret.x = tmp.x + ddx[i];
			ret.y = tmp.y + ddy[i];
			ret.number = 0;
			if (ret.x > 0 && ret.x <= n && ret.y > 0 && ret.y <= m)
			{
				if (used[ret.x][ret.y] == 0)
				{
					used[ret.x][ret.y] = 1;
					que.push(ret);
				}
				if (a[ret.x][ret.y] == '*' && a[tmp.x][tmp.y] == '*')
				{
					tmp.number++;
				}
			}
		}
		if (a[tmp.x][tmp.y] == '*' && tmp.number != 2)
		{
			//cout << tmp.x << ' ' << tmp.y << endl;
			//two_sum++;
			return false;
		}
		que.pop();
	}
	//cout << all_sum << ' ' << two_sum << endl;
	//if (all_sum!=two_sum)
	//	return false;
	if (all_sum % 3 != 0)
		return false;
	return true;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				cin >> a[i][j];
			}
		}
		memset(used, 0, sizeof(used));
		if (bfs())
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}

	}
	return 0;
}