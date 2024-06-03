#include<bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long n;
	while (cin >> n)
	{
		string s;
		if (n == 0)
			s += '0';
		while (n > 0)
		{
			int tmp = n % 2;
			n = n / 2;
			s += to_string(tmp);
		}
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
	return 0;
}