#include<bits/stdc++.h>
using namespace std;
string s = "12345678012345678";
struct node
{
	int x;
	int step;
};
int used[20], sum;
//"12345678012345678"		"87654321087654321"
void bfs()
{
	queue<node> que;
	int dx[4] = { 1,2,-1,-2 };
	node st;
	st.x = 8;
	st.step = 0;
	que.push(st);
	while (!que.empty())
	{
		node tmp = que.front();
		for (int i = 0; i < 4; ++i)
		{
			node ret;
			ret.x = tmp.x + dx[i];
			ret.step = tmp.step + 1;
			string s1 = s;
			swap(s[ret.x], s[tmp.x]);
			if (s == "87654321087654321")
			{
				return;
			}
			else
			{
				s = s1;
				if (ret.x < 0 && ret.x >= s.size() && used[ret.x] == 0)
				{
					used[ret.x] = 1;
					sum = ret.step;
					que.push(ret);
				}
			}
		}
		que.pop();
	}
}
int main()
{
	bfs();
	cout << sum;
	return 0;
}