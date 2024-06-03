#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
int a[N][N], n, m, used[N][N], summ;
struct node
{
	int x;
	int y;
};
int bfs(int i, int j)
{
	int all_sum = 0;
	queue<node> que;
	node st;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	st.x = i;
	st.y = j;
	que.push(st);
	used[i][j] = 1;
	all_sum += a[i][j];
	while (!que.empty())
	{
		node tmp = que.front();
		for (int i = 0; i < 4; ++i)
		{
			node ret;
			ret.x = tmp.x + dx[i];
			ret.y = tmp.y + dy[i];
			if (a[ret.x][ret.y] != 0 &&
				ret.x > 0 && ret.x <= n &&
				ret.y > 0 && ret.y <= m &&
				used[ret.x][ret.y] == 0)
			{
				all_sum += a[ret.x][ret.y];
				a[ret.x][ret.y] = 0;
				used[ret.x][ret.y] = 1;
				que.push(ret);
			}
		}
		que.pop();
	}
	return all_sum;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(used, 0, sizeof(used));
		summ = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (a[i][j] != 0)
				{
					summ = max(summ, bfs(i,j));
				}
			}
		}
		cout << summ << endl;
	}
	return 0;
}