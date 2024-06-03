#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
using ll = long long;
int b[N];//����a�洢addԪ�أ�b�洢getԪ��
int s[N];//����s����һ��value��pos��һ��ӳ�䣬��s[pos]=value��λ��
int tree[4 * N];//�߶���������ʾ��ʱ�ڵ��ʱ�м�����
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
	//Ҷ�ڵ�+1
	if (l == id && r == id)
	{
		tree[rtt]++;
		return;
	}
	//Ȼ����ھ�����ÿ���ڵ���м�1
	tree[rtt]++;
	int mid = (l + r) / 2;
	if (id <= mid)
		update(id, l, mid, rtt * 2);
	else
		update(id, mid + 1, r, rtt * 2 + 1);
	pushup(rtt);//��������ÿ���ڵ�����ʾ������
}
int query(int k, int l, int r, int rt)
{
	if (l == r) return l;//�ҵ���
	int mid = (l + r) / 2;
	//�����ߵ�����Ҫ��k�󣬾�ֱ�Ӵ���������
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
	//Ȼ��߽����߲�ѯ
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