#include<bits/stdc++.h>
using namespace std;
const int N = 39;
int dp[N];
//��x=b(b+2z)����ʱ��bΪ��������xΪ��������bΪż������x�ɱ�4������
int main()
{
	int l, r;
	cin >> l >> r;
	int ans = 0;
	for (int i = l; i <= r; ++i)
	{
		if (i % 2 != 0)
			ans++;
		else if (i % 4 == 0)
			ans++;
	}
	cout << ans;
	return 0;
}