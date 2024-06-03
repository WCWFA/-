#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll n, m, q;
ll a[N], lazy[4 * N], lazy1[4 * N];
struct node
{
	int l, r;
	ll sum;
};
node tree[4 * N];
void buildTree(int left, int right, int u)
{
	tree[u].l = left;
	tree[u].r = right;
	if (left == right)
	{
		tree[u].sum = a[left];
		return;
	}
	buildTree(left, (left + right) >> 1, u << 1);
	buildTree(((left + right) >> 1) + 1, right, (u << 1) + 1);
	tree[u].sum = tree[u << 1].sum + tree[(u << 1) + 1].sum;
}
void push_up(int id)
{
	tree[id].sum = tree[id * 2].sum + tree[id * 2 + 1].sum;
}
void push_down(int id, int l, int r)
{
	if (lazy[id])
	{
		int mid = (l + r) / 2;
		lazy[id * 2] += lazy[id];
		lazy[id * 2 + 1] += lazy[id];
		tree[id * 2].sum += lazy[id] * (mid - l + 1);
		tree[id * 2 + 1].sum += lazy[id] * (r - mid);
		lazy[id] = 0;
	}
}
void qjgx(int id, int l, int r, int x, int y, int v)
{
	if (l >= x && r <= y)
	{
		lazy[id] += v;
		tree[id].sum += v * (r - l + 1);
		return;
	}
	push_down(id, l, r);
	int mid = (l + r) / 2;
	if (x <= mid) qjgx(id * 2, l, mid, x, y, v);
	if (y > mid) qjgx(id * 2 + 1, mid + 1, r, x, y, v);
	push_up(id);
}
void push_down1(int id, int l, int r)
{
	if (lazy1[id]!=1)
	{
		int mid = (l + r) / 2;
		lazy1[id * 2] = lazy1[id];
		lazy1[id * 2 + 1] = lazy1[id];
		tree[id * 2].sum *= lazy1[id];
		tree[id * 2 + 1].sum *= lazy1[id];
		lazy1[id] = 1;
	}
}
void qjgc(int id, int l, int r, int x, int y, int v)
{
	if (l >= x && r <= y)
	{
		lazy1[id] *= v;
		tree[id].sum *= v;
		return;
	}
	push_down1(id, l, r);
	int mid = (l + r) / 2;
	if (x <= mid) qjgc(id * 2, l, mid, x, y, v);
	if (y > mid) qjgc(id * 2 + 1, mid + 1, r, x, y, v);
	push_up(id);
}
ll ffind(int id, int l, int r, int x, int y)
{
	if (x <= l && r <= y)
		return tree[id].sum;
	push_down(id, l, r);
	ll mid = (l + r) / 2;
	ll ans = 0;
	if (x <= mid) ans = ans + ffind(id * 2, l, mid, x, y);
	if (y > mid) ans = ans + ffind(id * 2 + 1, mid + 1, r, x, y);
	//ans = ans % q;
	return ans;
}
int main()
{
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (ll i = 1; i <= 4 * N; ++i)
	{
		lazy1[i] = 1;
	}
	buildTree(1, n, 1);
	for (int i = 1; i <= m; ++i)
	{
		int s;
		cin >> s;
		if (s == 1)
		{
			int x, y, k;
			cin >> x >> y >> k;
			qjgc(1, 1, n, x, y, k);
		}
		if (s == 2)
		{
			int x, y, k;
			cin >> x >> y >> k;
			qjgx(1, 1, n, x, y, k);
		}
		if (s == 3)
		{
			int x, y;
			cin >> x >> y;
			cout << ffind(1, 1, n, x, y) << '\n';
		}
	}
	return 0;
}