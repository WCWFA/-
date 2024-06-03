#include<bits/stdc++.h>
using namespace std;
int n, k;
const int N = 2e5 + 9;
int height, used[N][3];
char a[N][3];
struct node
{
	int x;
	int y;
};
bool bfs()
{
	queue<node>que;
	node st;
	int dx[3] = { 1,-1,k };
	st.x = 1;
	st.y = 1;
	que.push(st);
	used[1][1] = 1;
	while (!que.empty())
	{
		node tmp = que.front();
		for (int i = 0; i < 3; ++i)
		{
			node ret;
			ret.x = tmp.x + dx[i];
			if (i == 2)
			{
				if (tmp.y == 1)
					ret.y = 2;
				else
					ret.y = 1;
			}
			else
			{
				ret.y = tmp.y;
			}
			if (ret.x > 0 && used[ret.x][ret.y] == 0
				&& a[ret.x][ret.y] != 'X' && ret.x > height)
			{
				if (ret.x > n)
					return true;
				used[ret.x][ret.y] = 1;
				que.push(ret);
			}
		}
		que.pop();
		height++;
	}
	return false;
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i][1];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i][2];
	}
	if (bfs())
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}