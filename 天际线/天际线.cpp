#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
using ll = long long;
ll a[N], hh = 1, tt = 0, q[N];
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		//���ͷ��βС�����Ҵ�ʱ�����Ѿ�������i��ȥͷ��λ�ñ�k��
		if (hh <= tt && k < i - q[hh] + 1)
		{
			hh++;
		}
		//��ʼѭ����Ѱ�Ҵ�ʱ�����е����ֵ������Сֵ����ʱ����Сֵ��
		while (hh <= tt && a[q[tt]] >= a[i])
			tt--;
		q[++tt] = i;
		//�����ʱ������
		if (i + 1 > k)
			cout << a[q[hh]] << ' ';
	}
	cout << endl;
	memset(q, 0, sizeof(q));
	hh = 1, tt = 0;
	for (int i = 1; i <= n; ++i)
	{
		//���ͷ��βС�����Ҵ�ʱ�����Ѿ�������i��ȥͷ��λ�ñ�k��
		if (hh <= tt && k < i - q[hh] + 1)
		{
			hh++;
		}
		//��ʼѭ����Ѱ�Ҵ�ʱ�����е����ֵ������Сֵ����ʱ�����ֵ��
		while (hh <= tt && a[q[tt]] <= a[i])
			tt--;
		q[++tt] = i;
		//�����ʱ������
		if (i + 1 > k)
			cout << a[q[hh]] << ' ';
	}
	return 0;
}