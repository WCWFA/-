#include<bits/stdc++.h>
using namespace std;
int n, m;
char ch[1005][1005];
int dx[] = { 1,-1,0,0,-1,1,1,-1 };
int dy[] = { 0,0,1,-1,1,1,-1,-1 };
void bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push({ x,y });
	while (q.size()) {
		auto v = q.front(); q.pop();
		for (int i = 0; i < 8; i++) {
			int xx = v.first + dx[i], yy = v.second + dy[i];
			if (ch[xx][yy] == '#' && xx > 0 && xx <= n && yy > 0 && yy <= m) {
				ch[xx][yy] = '.';
				q.push({ xx,yy });
			}
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> ch[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (ch[i][j] == '#') {
				ans++;
				bfs(i, j);
			}
		}
	}
	cout << ans;
	return 0;
}
//#include<bits/stdc++.h>
//#include<unordered_set>
//using namespace std;
//const int N = 1e3 + 9;
//int used[N][N], graph[N][N], h, w, ans;
//char a[N][N];
//struct node
//{
//	int x;
//	int y;
//	bool operator==(const node& other)const
//	{
//		return x == other.x && y == other.y;
//	}
//	bool operator<(const node& other) const {
//		if (x != other.x) return x < other.x;
//		return y < other.y;
//	}
//};
//set<node> gset;
//void bfs1()
//{
//	int dx[4] = { 0,0,1,-1 };
//	int dy[4] = { 1,-1,0,0 };
//	queue<node> que;
//	node st;
//	st.x = 1;
//	st.y = 1;
//	que.push(st);
//	used[1][1] = 1;
//	while (!que.empty())
//	{
//		node tmp = que.front();
//		if (a[tmp.x][tmp.y] == '#')
//			gset.insert(tmp);
//		for (int i = 0; i < 4; ++i)
//		{
//			node ret;
//			ret.x = tmp.x + dx[i];
//			ret.y = tmp.y + dy[i];
//			if (ret.x > 0 && ret.x <= h && ret.y > 0 && ret.y <= w && used[ret.x][ret.y] == 0)
//			{
//				que.push(ret);
//				used[ret.x][ret.y] = 1;
//			}
//		}
//		que.pop();
//	}
//}
//void bfs2()
//{
//	memset(used, 0, sizeof(used));
//	int dx[8] = { 0,0,1,1,1,-1,-1,-1 };
//	int dy[8] = { 1,-1,1,0,-1,1,0,-1 };
//	queue<node> que;
//	while (!gset.empty())
//	{
//		ans++;
//		node st = *gset.begin();
//		que.push(st);
//		used[st.x][st.y] = 1;
//		gset.erase(st);
//		while (!que.empty())
//		{
//			node tmp = que.front();
//			for (int i = 0; i < 8; ++i)
//			{
//				node ret;
//				ret.x = tmp.x + dx[i];
//				ret.y = tmp.y + dy[i];
//				if (ret.x > 0 && ret.x <= h
//					&& ret.y > 0 && ret.y <= w
//					&& used[ret.x][ret.y] == 0
//					&& a[ret.x][ret.y] == '#')
//				{
//					que.push(ret);
//					used[ret.x][ret.y] = 1;
//					gset.erase(ret);
//				}
//			}
//			que.pop();
//		}
//	}
//}
//int main()
//{
//	cin >> h >> w;
//	for (int i = 1; i <= h; ++i)
//	{
//		for (int j = 1; j <= w; ++j)
//		{
//			cin >> a[i][j];
//		}
//	}
//	bfs1();
//	bfs2();
//	cout << ans;
//	return 0;
//}
