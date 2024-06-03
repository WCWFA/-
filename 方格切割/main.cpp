#include<bits/stdc++.h>
using namespace std;
int summ;
int used[10][10];
struct node
{
	int x;
	int y;
	int all;             
};
void bfs()
{
	queue<node> que;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	node st;
	st.x = 1;
	st.y = 1;
	st.all = 1;
	used[1][1] = 1;
	que.push(st);
	while (!que.empty())
	{
		node tmp = que.front();
		
	}
}
int main()
{
	bfs();
	return 0;
}