#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int sa, sb, na, nb;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		sa = sb = 0;
		cin >> na >> nb;
		int tmp1 = na, tmp2 = nb;
		while (tmp1 != 0)
		{
			sa += tmp1 % 10;
			tmp1 /= 10;
		}
		while (tmp2 != 0)
		{
			sb += tmp2 % 10;
			tmp2 /= 10;
		}
		if (na % sb == 0 && nb % sa == 0 || na % sb != 0 && nb % sa != 0)
		{
			if (na > nb)
				cout << "A" << endl;
			else
				cout << "B" << endl;
		}
		else if (na % sb == 0)
			cout << "A" << endl;
		else if (nb % sa == 0)
			cout << "B" << endl;
	}
	return 0;
}