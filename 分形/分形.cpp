#include<bits/stdc++.h>
using namespace std;
typedef vector<string> fa;
fa getFra(int n)
{
	if (n == 1)
	{
		return { "@" };
	}
	fa gtFra = getFra(n - 1);
	int len = gtFra.size();
	fa newgt(len * 3, string(len * 3, ' '));
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			//newgt[i][j] = gtFra[i][j];
			//newgt[i][j + len * 2] = gtFra[i][j];
			//newgt[i + len * 2][j] = gtFra[i][j];
			//newgt[i + len][j + len] = gtFra[i][j];
			//newgt[i + len * 2][j + len * 2] = gtFra[i][j];
			newgt[i + len][j] = gtFra[i][j];
			newgt[i][j + len] = gtFra[i][j];
			newgt[i + len][j + len * 2] = gtFra[i][j];
		}
	}
	return newgt;
}
int main()
{
	while (1)
	{
		int n;
		cin >> n;
		if (n == -1)
		{
			break;
		}
		fa ret = getFra(n);
		for (auto e : ret)
		{
			cout << e << endl;
		}
		cout << '-' << endl;
	}
	return 0;
}