#include<bits/stdc++.h>
using namespace std;
int h, w;
const int N = 20;
const int M = 1e9 + 1;
int a[N][N], used[N][N], all_sum;
set<int> st;
int dx[] = { 0,1 };
int dy[] = { 1,0 };
bool check(int xx, int yy)
{
    if (st.find(a[xx][yy]) != st.end()) return false;
    return true;
}
void dfs(int xx, int yy)
{
    if (xx == h && yy == w)
    {
        all_sum++;
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        if (used[xx + dx[i]][yy + dy[i]] && a[xx + dx[i]][yy + dy[i]] != -1 && check(xx + dx[i], yy + dy[i]))
        {
            used[xx + dx[i]][yy + dy[i]] = 0;
            st.insert(a[xx + dx[i]][yy + dy[i]]);
            dfs(xx + dx[i], yy + dy[i]);
            st.erase(a[xx + dx[i]][yy + dy[i]]);
            used[xx + dx[i]][yy + dy[i]] = 1;
        }
    }
}
int main()
{
    st.clear();
    memset(a, -1, sizeof(a));
    memset(used, 1, sizeof(used));
    cin >> h >> w;
    for (int i = 1; i <= h; ++i)
    {
        for (int j = 1; j <= w; ++j)
            cin >> a[i][j];
    }
    st.insert(a[1][1]);
    dfs(1, 1);
    cout << all_sum;
    return 0;
}