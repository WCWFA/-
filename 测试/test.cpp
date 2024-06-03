#include<bits/stdc++.h>
using namespace std;
int main()
{
	int all_sum = 0;
	for (int i = 1; i <= 100000000; ++i)
	{
		string s = to_string(i);
		if (s.size() % 2 != 0)
			continue;
		int sum1 = 0;
		int sum2 = 0;
		int len1 = s.size() / 2;
		for (int i = 0; i < len1; ++i)
		{
			sum1 += s[i] - '0';
			sum2 += s[i + len1] - '0';
		}
		if (sum1 == sum2)
		{
			all_sum++;
		}
	}
	cout << all_sum;
	return 0;
}