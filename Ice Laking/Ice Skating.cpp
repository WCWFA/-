#include<bits/stdc++.h>
using namespace std;
const int N = 109;
int n, ans;
struct node
{
	int x;
	int y;
	bool operator<(const node& other)const
	{
		if (x != other.x) return x < other.x;
		return y < other.y;
	}
};
set<node> gset;
void bfs()
{
	queue<node>que;
	while (!gset.empty())
	{
		node st = *gset.begin();
		gset.erase(st);
		que.push(st);
		while (!que.empty())
		{
			node tmp = que.front();
			auto it = gset.begin();
			while (it != gset.end())
			{
				if (it->x == tmp.x || it->y == tmp.y)
				{
					que.push(*it);
					it = gset.erase(it);
				}
				else
					++it;
			}
			que.pop();
		}
		if (!gset.empty())
			ans++;
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int xx, yy;
		cin >> xx >> yy;
		gset.insert({ xx,yy });
	}
	bfs();
	cout << ans;
	return 0;
}