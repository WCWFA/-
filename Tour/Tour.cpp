#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 9;
int n, m, ans;
int visited[N];
map<int, vector<int>>mp;
// DFS函数遍历每条边
void dfs(int v) {
	visited[v] = true; 
	for (int u : mp[v]) { 
		if (!visited[u]) {
			ans++;
			dfs(u); 
		}
	}
}
int main()
{
	cin >> n >> m;
	ans = n;
	for (int i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b;
		mp[a].push_back(b);
	}
	for (int i = 1; i <= n; ++i)
	{
		memset(visited, 0, sizeof(visited));
		if (!visited[i])
			dfs(i);
	}
	cout << ans;
	return 0;
}