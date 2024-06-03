#include<bits/stdc++.h>
using namespace std;
const int N = 59;
char a[N][N];
int used[N][N];
int n;
int stx, sty, enx, eny;
struct node
{
	int x;
	int y;
	bool operator<(const node& tmp)const
	{
		if (tmp.x != x)return x < tmp.x;
		return y < tmp.y;
	}
};
set<node> st1;
set<node> st2;
void bfs1(int xx, int yy)
{
	queue<node> que;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	used[xx][yy] = 1;
	que.push({ xx,yy });
	while (!que.empty())
	{
		node tmp = que.front();
		for (int i = 0; i < 4; ++i)
		{
			node ret;
			ret.x = tmp.x + dx[i];
			ret.y = tmp.y + dy[i];
			if (ret.x > 0 && ret.x <= n
				&& ret.y > 0 && ret.y <= n
				&& used[ret.x][ret.y] == 0
				&& a[ret.x][ret.y] == '0')
			{
				que.push(ret);
				used[ret.x][ret.y] = 1;
				st1.insert(ret);
			}
		}
		que.pop();
	}
}
void bfs2(int xx, int yy)
{
	queue<node> que;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	used[xx][yy] = 1;
	que.push({ xx,yy });
	while (!que.empty())
	{
		node tmp = que.front();
		for (int i = 0; i < 4; ++i)
		{
			node ret;
			ret.x = tmp.x + dx[i];
			ret.y = tmp.y + dy[i];
			if (ret.x > 0 && ret.x <= n
				&& ret.y > 0 && ret.y <= n
				&& used[ret.x][ret.y] == 0
				&& a[ret.x][ret.y] == '0')
			{
				que.push(ret);
				used[ret.x][ret.y] = 1;
				st2.insert(ret);
			}
		}
		que.pop();
	}
}
int main()
{
	cin >> n;
	cin >> stx >> sty >> enx >> eny;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
		}
	}
	st1.insert({ stx,sty });
	bfs1(stx, sty);
	if (st1.find({ enx,eny }) != st1.end())
		cout << 0;
	else
	{
		st2.insert({ enx,eny });
		bfs2(enx, eny);
		int minn = INT_MAX;
		for (auto& e1 : st1)
		{
			for (auto& e2 : st2)
			{
				int tmp = (e1.x - e2.x) * (e1.x - e2.x) + (e1.y - e2.y) * (e1.y - e2.y);
				minn = min(minn, tmp);
			}
		}
		cout << minn;
	}
	return 0;
}