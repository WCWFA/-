#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 9;
int ans, dp[N][N];//dp[i][j]��ʾ��i��j�Ƿ�Ҫ���з�ת
int main()
{
	string num;
	cin >> num;
	for (int i = 0; i < num.size(); ++i)//���ȶ��ڽ������ж�
	{
		if (num[i] > num[i + 1])
			dp[i][i + 1] = 1;
	}
	for (int len = 3; len <= num.size(); ++len)//�������dp
	{
		for (int j = 0; j + len - 1 < num.size(); ++j)
		{
			int ends = j + len - 1;
			if (num[j] == num[ends])
				dp[j][ends] = dp[j + 1][ends - 1];
			else if (num[j] > num[ends])
			{
				dp[j][ends] = 1;
			}
		}
	}
	for (int i = 0; i < num.size(); ++i)//�����еĽ�����мӺͣ���Ϊdpֻ��ʾ�Ƿ�Ҫ���з�ת��
	{
		for (int j = 0; j < num.size(); ++j)
		{
			ans += dp[i][j];
		}
	}
	cout << ans;
	return 0;
}