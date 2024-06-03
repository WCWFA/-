#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	int a1, a2, n;
	cin >> a1 >> a2 >> n;
	v.push_back(a1);
	v.push_back(a2);
	int m = 0, k = 1;
	while (v.size() < n)
	{
		
		int tmp3 = v[m++] * v[k++];
		string tmp = to_string(tmp3);
		for (int i = 0; i < tmp.size() && v.size() < n; ++i)
		{
			v.push_back(tmp[i] - '0');
		}
	}
	for (int i = 0; i < n; ++i)
		cout << v[i] << ' ';
	return 0;
}