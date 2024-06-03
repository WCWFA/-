#include<bits/stdc++.h>
using namespace std;
int n;
string ch = "1";
void dfs(int pos, int tmp, int summ)
{
	if (pos == n)
	{
		if (summ == 0)
		{
			cout << ch << endl;
		}
		return;
	}
	//空格
	//空格前为正
	if (tmp > 0)
	{
		ch += " " + to_string(pos + 1);
		dfs(pos + 1, tmp * 10 + (pos + 1), summ - tmp + tmp * 10 + (pos + 1));
		ch.pop_back();
		ch.pop_back();
	}
	//空格前为负
	else
	{
		//summ -= tmp;
		//tmp = tmp * 10 - (pos + 1);
		ch += " " + to_string(pos + 1);
		dfs(pos + 1, tmp * 10 - (pos + 1), summ - tmp + tmp * 10 - (pos + 1));
		ch.pop_back();
		ch.pop_back();
	}
	//加
	ch += "+" + to_string(pos + 1);
	dfs(pos + 1, pos + 1, summ + pos + 1);
	ch.pop_back();
	ch.pop_back();
	//减
	ch += "-" + to_string(pos + 1);
	dfs(pos + 1, -pos - 1, summ - pos - 1);
	ch.pop_back();
	ch.pop_back();
	return;
}
int main()
{
	cin >> n;
	dfs(1, 1, 1);
	return 0;
}