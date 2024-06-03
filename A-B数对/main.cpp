#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long n, c;
vector<long> v;
int A_B(vector<long>& v, long& n, long& c)
{
	int sum = 0;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
	{
		sum += (upper_bound(v.begin(), v.begin() + n, v[i] + c) - v.begin()) - (lower_bound(v.begin(), v.begin() + n, v[i] + c) - v.begin());
	}
	return sum;
}
int main()
{
	cin >> n >> c;
	for (int i = 0; i < n; ++i)
	{
		long k = 0;
		cin >> k;
		v.push_back(k);
	}
	long sum;
	sum = A_B(v, n, c);
	cout << sum;
	return 0;
}