#include<bits/stdc++.h>
using namespace std;
bool is_s(int x)
{
	for (int i = 2; i <= sqrt(x); ++i)
	{
		if (x % i == 0)
		{
			if (x == 8923)
				cout << i;
			return false;
		}
	}
	return true;
}
int main()
{
	int t, x;
	cin >> t;
	while (t--)
	{
		cin >> x;
		int tmp = x;
		int flag = 0;
		int ret = 0;
		while (1)
		{
			tmp = tmp * 10;
			for (int i = 1; i <= 9; ++i)
			{
				ret = tmp + i;
				if (ret == 8923)
				{
					cout << 1;
				}
				if (is_s(ret))
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				break;
		}
		cout << ret << endl;
	}
	return 0;
}