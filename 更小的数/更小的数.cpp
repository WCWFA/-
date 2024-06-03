#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 9;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s1;
	int n;
	cin >> s1;
	int summ = 0;
	for (int i = 0; i < s1.size(); ++i)
	{
		for (int j = i + 1; j < s1.size(); ++j)
		{
			string s2 = s1;
			for (int st = i, end = j; st <= end; st++, end--)
			{
				if (s2[st] != s2[end])
				{
					if (s2[st] > s2[end])
					{
						summ++;
						cout << s2 << endl;
					}
					break;

				}
			}
		}
	}
	cout << summ;
	return 0;
}