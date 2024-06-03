#include<bits/stdc++.h>
using namespace std;
vector<bool> is_prime(1e8 + 9);
vector<int> prime;
int n, q, k;
void euler_sieve(int n)
{
	for (int i = 2; i <= n; ++i)
	{
		if (!is_prime[i]) prime.push_back(i);
		for (auto& p : prime)
		{
			if (i * p > n) break;
			is_prime[i * p] = true;
			if (i % p == 0) break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	euler_sieve(n);
	for (int i = 1; i <= q; ++i)
	{
		int tmp;
		cin >> tmp;
		cout << prime[tmp - 1] << endl;
	}
	return 0;
}