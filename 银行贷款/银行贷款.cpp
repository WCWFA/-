#include<bits/stdc++.h>
using namespace std;
unsigned int n, m, k;
double func(double num)
{
	return 1.0 * (1 - 1 / pow(1 + num, k)) / num;
}
int main()
{
	cin >> n >> m >> k;
	double ret = 1.0 * n / m;
	double left = 0, right = 3;
	while ((right - left) >= 1e-7)
	{
		double mid = (left + right) / 2;
		double tmp = func(mid);
		//cout << mid;
		if (tmp < ret)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	printf("%.1lf", left * 100);
	return 0;
}