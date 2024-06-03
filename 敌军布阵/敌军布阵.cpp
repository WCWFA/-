#include<iostream>
#include<string>
#include<string.h>
using namespace std;
const int N = 4e4 + 9;
int n;
int a[N];
struct node
{
	int l, r, len, sum;
};
node tree[4 * N];
int ans[N], cnt;
void buildTree(int left, int right, int u)
{
	tree[u].l = left;
	tree[u].r = right;
	tree[u].len = right - left + 1;
	if (left == right)
	{
		tree[u].sum = a[left];
		return;
	}
	buildTree(left, (left + right) >> 1, u << 1);
	buildTree(((left + right) >> 1) + 1, right, (u << 1) + 1);
	tree[u].sum = tree[u << 1].sum + tree[(u << 1) + 1].sum;
}
int query(int id, int l, int r, int x, int y)
{
	if (x <= l && r <= y)
		return tree[id].sum;
	int mid = (l + r) / 2, ans = 0;
	if (x <= mid) ans += query(id * 2, l, mid, x, y);
	if (y > mid) ans += query(id * 2 + 1, mid + 1, r, x, y);
	return ans;
}
void add(int id, int l, int r, int x, int v)
{
	if (l == r)
	{
		tree[id].sum += v;
		return;
	}
	int mid = (l + r) / 2;
	if (x <= mid) add(id * 2, l, mid, x, v);
	else add(id * 2 + 1, mid + 1, r, x, v);
	tree[id].sum = tree[id * 2].sum + tree[id * 2 + 1].sum;
}
void sub(int id, int l, int r, int x, int v)
{
	if (l == r)
	{
		tree[id].sum -= v;
		return;
	}
	int mid = (l + r) / 2;
	if (x <= mid) sub(id * 2, l, mid, x, v);
	else sub(id * 2 + 1, mid + 1, r, x, v);
	tree[id].sum = tree[id * 2].sum + tree[id * 2 + 1].sum;
}
int main()
{
	int t;
	cin >> t;
	for (int T = 1; T <= t; ++T)
	{
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
		}
		buildTree(1, n, 1);
		while (1)
		{
			string s;
			cin >> s;
			if (s == "End")
			{
				cout << "Case " << T << ":" << '\n';
				for (int i = 0; i < cnt; ++i)
				{
					cout << ans[i] << '\n';
				}
				cnt = 0;
				memset(ans, 0, sizeof(ans));
				break;
			}
			if (s == "Query")
			{
				int tmp1, tmp2;
				cin >> tmp1 >> tmp2;
				ans[cnt++] = query(1, 1, n, tmp1, tmp2);
			}
			else if (s == "Add")
			{
				int tmp1, tmp2;
				cin >> tmp1 >> tmp2;
				add(1, 1, n, tmp1, tmp2);
			}
			else if (s == "Sub")
			{
				int tmp1, tmp2;
				cin >> tmp1 >> tmp2;
				sub(1, 1, n, tmp1, tmp2);
			}
		}
	}
	return 0;
}