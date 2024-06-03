#include<bits/stdc++.h>
using namespace std;
map<int, int> mp;
int n, c;
int main()
{
	cin >> n >> c;
	unsigned long long summ = 0;
	for (int i = 1; i <= n; ++i)
	{
		int tmp;
		cin >> tmp;
		mp[tmp] += 1;
	}
	for (auto it = mp.begin(); it != mp.end(); ++it)
	{
		int complement = c + it->first;
		if (mp.count(complement))
		{
			if (complement == it->first)
			{
				// 当 complement 与 it->first 相等时，即在查找的是相同的键，此时需要特殊处理
				summ += ((unsigned long long)it->second * (it->second - 1)) / 2;
			}
			else
			{
				summ += (unsigned long long)it->second * mp[complement];
			}
		}
	}
	cout << summ;
	return 0;
}
