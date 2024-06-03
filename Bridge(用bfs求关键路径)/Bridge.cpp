#include<bits/stdc++.h>
using namespace std;
const int N = 55;
int n, m;
int used[N], grapha[N][N];
int summ,all_sum;
struct edge
{
	int u;
	int v;
};
vector<edge> li;
void bfs()
{
	summ++;
	queue<int> que;
	used[1] = 1;
	que.push(1);
	while (!que.empty())
	{
		int tmp = que.front();
		for (int i = 1; i <= n; ++i)
		{
			if (grapha[tmp][i] == 1 && used[i] == 0)
			{
				que.push(i);
				used[i] = 1;
				summ++;
			}
		}
		que.pop();
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b;
		li.push_back({ a,b });
		grapha[a][b] = 1;
		grapha[b][a] = 1;
	}
	for (int i = 0; i < m; ++i)
	{
		edge tmp = li[i];
		summ = 0;
		memset(used, 0, sizeof(used));
		grapha[tmp.u][tmp.v] = 0;
		grapha[tmp.v][tmp.u] = 0;
		bfs();
		if (summ != n)
		{
			all_sum++;
		}
		grapha[tmp.u][tmp.v] = 1;
		grapha[tmp.v][tmp.u] = 1;
	}
	cout << all_sum;
	return 0;
}