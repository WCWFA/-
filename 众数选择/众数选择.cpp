#include<bits/stdc++.h>
using namespace std;
vector<map<int, int>> vm(6);
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		string tmp;
		cin >> tmp;
		for (int i = tmp.size() - 1; i >= 0; --i)
		{
			vm[tmp.size() - i - 1][tmp[i] - '0'] += 1;
		}
	}
    for (int i = 0; i < m; ++i) 
    {
        int max_key = -1;
        int max_count = -1;
        for (const auto& p : vm[i])
        {
            if (p.second > max_count)
            {
                max_count = p.second;
                max_key = p.first;
            }
        }
        cout << max_key << endl;
    }
	return 0;
}