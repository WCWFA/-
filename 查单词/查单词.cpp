#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 9;
int n, m;
struct node
{
	int l, r;
	string s;
	string s_lower;
};
node tree[4 * N];
vector<string> vs_lower;
vector<string> vs;
void buildTree(int left, int right, int u)
{
	tree[u].l = left;
	tree[u].r = right;
	if (left == right)
	{
		tree[u].s = vs[left];
		tree[u].s_lower = vs_lower[left];
		return;
	}
	buildTree(left, (left + right) >> 1, u << 1);
	buildTree(((left + right) >> 1) + 1, right, (u << 1) + 1);
	tree[u].s_lower = tree[u << 1].s_lower > tree[(u << 1) + 1].s_lower ? tree[u << 1].s_lower : tree[(u << 1) + 1].s_lower;
	tree[u].s = tree[u << 1].s_lower > tree[(u << 1) + 1].s_lower ? tree[u << 1].s : tree[(u << 1) + 1].s;
	return;
}
node query(int id, int l, int r, int x, int y)
{
	if (x <= l && r <= y)
	{
		return tree[id];
	}
	int mid = (l + r) / 2;
	node ans;
	if (x <= mid)
	{
		node left_max = query(id * 2, l, mid, x, y);
		if (ans.s_lower < left_max.s_lower)
		{
			ans = left_max;
		}
	}
	if (y > mid)
	{
		node right_max = query(id * 2 + 1, mid + 1, r, x, y);
		if (ans.s_lower <= right_max.s_lower)
		{
			ans = right_max;
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	vs.push_back("\0");
	vs_lower.push_back("\0");
	for (int i = 1; i <= n; ++i)
	{
		string tmp;
		cin >> tmp;
		vs.push_back(tmp);
		transform(tmp.begin(), tmp.end(), tmp.begin(), [](unsigned char c) {return tolower(c); });
		vs_lower.push_back(tmp);
	}
	buildTree(1, n, 1);
	for (int i = 1; i <= m; ++i)
	{
		int ll, rr;
		cin >> ll >> rr;
		node ret = query(1, 1, n, ll, rr);
		cout << ret.s << endl;
	}
	return 0;
}