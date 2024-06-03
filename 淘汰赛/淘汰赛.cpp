#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 1e3 + 9;
int a[N];
struct node
{
	int left, right, winner, ene;
};
node tree[4 * N];
void buildTree(int id, int l, int r)
{
	tree[id].left = l;
	tree[id].right = r;
	if (l == r)
	{
		tree[id].ene = a[l];
		tree[id].winner = l;
		return;
	}
	buildTree(id << 1, l, (l + r) >> 1);
	buildTree((id << 1) | 1, (l + r >> 1) + 1, r);
	tree[id].ene = tree[id << 1].ene > tree[id << 1 | 1].ene ? tree[id << 1].ene : tree[id << 1 | 1].ene;
	tree[id].winner = tree[id << 1].ene > tree[(id << 1) | 1].ene ? tree[id << 1].winner : tree[(id << 1) | 1].winner;
	return;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= pow(2, n); ++i)
	{
		cin >> a[i];
	}
	buildTree(1, 1, pow(2, n));
	if (tree[2].ene < tree[3].ene)
		cout << tree[2].winner;
	else
		cout << tree[3].winner;
	return 0;
}