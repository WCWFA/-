#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 9;
int n, m;
int a[N];
queue<int> que;
int main()
{
	cin >> n >> m;
	int maxx = INT_MIN;
	int summ = 0;
	int fina = INT_MIN;
	for (int i = 1; i <= n; ++i)
	{
		int tmp;

		cin >> tmp;
		//cin >> a[i];
		if (i == 1)
		{
			maxx = tmp;
			que.push(tmp);
			fina = max(fina, maxx);
			continue;
		}
		if (que.size() < m)
		{
			if (maxx + tmp > tmp)
			{
				que.push(tmp);
				maxx = maxx + tmp;
			}
			else
			{
				queue<int> emp;
				swap(emp, que);
				que.push(tmp);
				maxx = tmp;
			}
		}
		else
		{
			if (maxx - que.front() + tmp > tmp)
			{
				maxx = maxx - que.front() + tmp;
				que.pop();
				que.push(tmp);
			}
			else
			{
				queue<int> emp;
				swap(emp, que);
				que.push(tmp);
				maxx = tmp;
			}
		}
		fina = max(fina, maxx);
	}
	cout << fina;
	return 0;
}