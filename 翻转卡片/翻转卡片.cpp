#include<bits/stdc++.h>
using namespace std;
const int N = 109;
int n, m;
int a[N], b[N], flag, dp[N][10009];
char ch[N];

void dfs(int x,int summ) {
    if (flag || dp[x][summ] || summ > m) return; // 如果找到解，或当前状态已访问，或总和超过m，则返回
    dp[x][summ] = 1; // 标记当前状态为已访问
    if (x == n + 1) {
        if (summ == m) {
            cout << "Yes" << endl;
            for (int i = 1; i <= n; ++i) {
                cout << ch[i];
            }
            cout<<endl;
            //for (int i = 1; i <= n; ++i)
            //{
            //    if (ch[i] == 'H')
            //        cout << a[i] << endl;
            //    if (ch[i] == 'T')
            //        cout << b[i] << endl;
            //}
            exit(0); // 找到解后退出程序
            //flag = 1; // 此行无需执行，exit(0)已经终止了程序
        }
        return;
    }
    // 尝试选择a[x]
    ch[x] = 'H';
    dfs(x + 1, summ + a[x]);

    // 尝试选择b[x]
    if (!flag) { // 如果还没有找到解，尝试另一个选项
        ch[x] = 'T';
        dfs(x + 1, summ + b[x]);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    dfs(1, 0);
    if (!flag) cout << "No";
    return 0;
}