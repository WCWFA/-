#include<bits/stdc++.h>
using namespace std;
double a, b, c, d;
double func(double x)
{
	return a * x * x * x + b * x * x + c * x + d;
}
vector<double> ans;
int main()
{
	cin >> a >> b >> c >> d;
	for (int i = -100; i <= 100; ++i)
	{
		if (func(i) == (double)0)
		{
			ans.push_back(i);
		}
	}
	double left = -100, right = -99;
	while (ans.size() < 3)
	{
		if (func(left) * func(right) < 0)
		{
			double tmp_left = left, tmp_right = right;
			while (tmp_left < tmp_right)
			{
				double mid = (tmp_left + tmp_right) / 2;
				if (abs(func(mid)) < 1e-7)
				{
					ans.push_back(tmp_left);
					break;
				}
				else if (func(mid) * func(tmp_left) < 0)
				{
					tmp_right = mid;
				}
				else if (func(mid) * func(tmp_right) < 0)
				{
					tmp_left = mid;
				}
			}
		}
		left++, right++;
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i)
	{
		printf("%.2lf ", ans[i]);
	}
	return 0;
}