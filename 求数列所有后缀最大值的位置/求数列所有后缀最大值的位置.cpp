#include<bits/stdc++.h>
using namespace std;
struct node
{
	unsigned long long value;
	int pos;
};
stack<node> st;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	unsigned long long fina = 0;
	for (int i = 1; i <= n; ++i)
	{
		unsigned long long tmp;
		cin >> tmp;
		while (!st.empty() && st.top().value <= tmp)
		{
			fina ^= st.top().pos;
			st.pop();
		}
		st.push({ tmp,i });
		fina ^= i;
		cout << fina << endl;
	}
	return 0;
}