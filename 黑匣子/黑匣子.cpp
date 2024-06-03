#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
using ll = long long;
int b[N];//其中a存储add元素，b存储get元素
int s[N];//其中s来做一个value到pos的一个映射，即s[pos]=value的位置
int tree[4 * N];//线段树用来表示此时节点此时有几个数
struct node
{
	ll value;
	ll pos;
};
node a[N];
bool cmp(node& x, node& y)
{
	return x.value < y.value;
}
void pushup(int rtt)
{
	tree[rtt] = tree[rtt * 2] + tree[rtt * 2 + 1];
}
void update(int id, int l, int r, int rtt)
{
	//叶节点+1
	if (l == id && r == id)
	{
		tree[rtt]++;
		return;
	}
	//然后对于经过的每个节点进行加1
	tree[rtt]++;
	int mid = (l + r) / 2;
	if (id <= mid)
		update(id, l, mid, rtt * 2);
	else
		update(id, mid + 1, r, rtt * 2 + 1);
	pushup(rtt);//回溯整理每个节点所表示的数量
}
int query(int k, int l, int r, int rt)
{
	if (l == r) return l;//找到了
	int mid = (l + r) / 2;
	//如果左边的数量要比k大，就直接从左子树找
	if (tree[rt * 2] >= k)
		return query(k, l, mid, rt * 2);
	else
		return query(k - tree[rt * 2], mid + 1, r, rt * 2 + 1);
}
int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; ++i)
	{
		cin >> a[i].value;
		a[i].pos = i;
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> b[i];
	}
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= m; ++i)
	{
		s[a[i].pos] = i;
	}
	//然后边建树边查询
	int cnt = 1;
	for (int i = 1; i <= m; ++i)
	{
		update(s[i], 1, m, 1);
		while (i == b[cnt])
		{
			printf("%lld\n", a[query(cnt, 1, m, 1)].value);
			cnt++;
		}
	}
	return 0;
}