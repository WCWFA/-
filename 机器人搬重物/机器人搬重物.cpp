#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 59;
int used[N][N], graph[N][N];
int a[N][N];
int n, m, xx1, yy1, xx, yy;
char ch;
struct node
{
	int x;
	int y;
	char de;
	int step;
};
bool is_e(node& tem)
{
	if (tem.de == 'E')
		return 1;
	return 0;
}
bool is_s(node& tem)
{
	if (tem.de == 'S')
		return 1;
	return 0;
}
bool is_w(node& tem)
{
	if (tem.de == 'W')
		return 1;
	return 0;
}
bool is_n(node& tem)
{
	if (tem.de == 'N')
		return 1;
	return 0;
}
void BFS()
{
	int dx[12] = { 1,2,3,-1,-2,-3,0,0,0,0,0,0 };
	int dy[12] = { 0,0,0,0,0,0,1,2,3,-1,-2,-3 };
	queue<node> que;
	node st;
	st.x = xx;
	st.y = yy;
	st.de = ch;
	st.step = 0;
	used[xx][yy] = 1, graph[xx][yy] = st.step;
	que.push(st);
	while (!que.empty())
	{
		node tmp = que.front();
		for (int i = 0; i < 3; ++i)
		{
			node ret;
			ret.x = tmp.x + dx[i];
			ret.y = tmp.y + dy[i];
			ret.step = tmp.step + 1;
			ret.de = 'S';
			if (is_s(tmp))
			{
			}
			else if (is_n(tmp))
			{
				ret.step += 2;
			}
			else if (is_e(tmp))
			{
				ret.step += 1;
			}
			else if (is_w(tmp))
			{
				ret.step += 1;
			}
			if (ret.x > 0 && ret.x <= n && ret.y > 0 && ret.y <= m && used[ret.x][ret.y] == 0 && a[ret.x][ret.y] != 1)
			{
				graph[ret.x][ret.y] = ret.step;
				que.push(ret);
				used[ret.x][ret.y] = 1;
			}
			else if (a[ret.x][ret.y] == 1)
			{
				break;
			}
			else if (used[ret.x][ret.y] == 1)
			{
				graph[ret.x][ret.y] = min(graph[ret.x][ret.y], ret.step);
			}
			if (ret.x == 3 && ret.y == 6)
			{
				printf("%d %d %d %c\n", tmp.x, tmp.y, tmp.step, tmp.de);
				printf("%d %d %d %c\n", ret.x, ret.y, ret.step, ret.de);
				cout << graph[ret.x][ret.y] << endl;
			}
		}
		for (int i = 3; i < 6; ++i)
		{
			node ret;
			ret.x = tmp.x + dx[i];
			ret.y = tmp.y + dy[i];
			ret.step = tmp.step + 1;
			ret.de = 'N';
			if (is_s(tmp))
			{
				ret.step += 2;
			}
			else if (is_n(tmp))
			{
			}
			else if (is_e(tmp))
			{
				ret.step += 1;
			}
			else if (is_w(tmp))
			{
				ret.step += 1;
			}
			if (ret.x > 0 && ret.x <= n && ret.y > 0 && ret.y <= m && used[ret.x][ret.y] == 0 && a[ret.x][ret.y] != 1)
			{
				graph[ret.x][ret.y] = ret.step;
				que.push(ret);
				used[ret.x][ret.y] = 1;
			}
			else if (a[ret.x][ret.y] == 1)
			{
				break;
			}
			else if (used[ret.x][ret.y] == 1)
			{
				graph[ret.x][ret.y] = min(graph[ret.x][ret.y], ret.step);
			}
			if (ret.x == 3 && ret.y == 6)
			{
				printf("%d %d %d %c\n", tmp.x, tmp.y, tmp.step, tmp.de);
				printf("%d %d %d %c\n", ret.x, ret.y, ret.step, ret.de);
				cout << graph[ret.x][ret.y] << endl;
			}
		}
		for (int i = 6; i < 9; ++i)
		{
			node ret;
			ret.x = tmp.x + dx[i];
			ret.y = tmp.y + dy[i];
			ret.step = tmp.step + 1;
			ret.de = 'E';
			if (is_s(tmp))
			{
				ret.step += 1;
			}
			else if (is_n(tmp))
			{
				ret.step += 1;
			}
			else if (is_e(tmp))
			{
			}
			else if (is_w(tmp))
			{
				ret.step += 2;
			}
			if (ret.x > 0 && ret.x <= n && ret.y > 0 && ret.y <= m && used[ret.x][ret.y] == 0 && a[ret.x][ret.y] != 1)
			{
				graph[ret.x][ret.y] = ret.step;
				que.push(ret);
				used[ret.x][ret.y] = 1;
			}
			else if (a[ret.x][ret.y] == 1)
			{
				break;
			}
			else if (used[ret.x][ret.y] == 1)
			{
				graph[ret.x][ret.y] = min(graph[ret.x][ret.y], ret.step);
			}
			if (ret.x == 3 && ret.y == 6)
			{
				printf("%d %d %d %c\n", tmp.x, tmp.y, tmp.step, tmp.de);
				printf("%d %d %d %c\n", ret.x, ret.y, ret.step, ret.de);
				cout << graph[ret.x][ret.y] << endl;
			}
		}
		for (int i = 9; i < 12; ++i)
		{
			node ret;
			ret.x = tmp.x + dx[i];
			ret.y = tmp.y + dy[i];
			ret.step = tmp.step + 1;
			ret.de = 'W';
			if (is_s(tmp))
			{
				ret.step += 1;
			}
			else if (is_n(tmp))
			{
				ret.step += 1;
			}
			else if (is_e(tmp))
			{
				ret.step += 2;
			}
			else if (is_w(tmp))
			{
			}
			if (ret.x > 0 && ret.x <= n && ret.y > 0 && ret.y <= m && used[ret.x][ret.y] == 0 && a[ret.x][ret.y] != 1)
			{
				graph[ret.x][ret.y] = ret.step;
				que.push(ret);
				used[ret.x][ret.y] = 1;
			}
			else if (a[ret.x][ret.y] == 1)
			{
				break;
			}
			else if (used[ret.x][ret.y] == 1)
			{
				graph[ret.x][ret.y] = min(graph[ret.x][ret.y], ret.step);
			}
			if (ret.x == 3 && ret.y == 6)
			{
				printf("%d %d %d %c\n", tmp.x, tmp.y, tmp.step, tmp.de);
				printf("%d %d %d %c\n", ret.x, ret.y, ret.step, ret.de);
				cout << graph[ret.x][ret.y] << endl;
			}
		}
		que.pop();
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n1, m1;
	cin >> n1 >> m1;
	n = n1 + 1;
	m = m1 + 1;
	memset(graph, -1, sizeof(graph));
	for (int i = 1; i <= n1; ++i)
	{
		for (int j = 1; j <= m1; ++j)
		{
			int tmp;
			cin >> tmp;
			if (tmp == 1)
			{
				a[i][j] = 1, a[i][j + 1] = 1, a[i + 1][j] = 1, a[i + 1][j + 1] = 1;
			}
		}
	}
	cin >> xx >> yy >> xx1 >> yy1 >> ch;
	xx++, yy++, xx1++, yy1++;
	BFS();
	cout << graph[xx1][yy1] << '\n';
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << graph[2][6];
	return 0;
}