#include<bits/stdc++.h>
using namespace std;
const int N = 109;
int n, m;
int a[N], b[N], flag, dp[N][10009];
char ch[N];

void dfs(int x,int summ) {
    if (flag || dp[x][summ] || summ > m) return; // ����ҵ��⣬��ǰ״̬�ѷ��ʣ����ܺͳ���m���򷵻�
    dp[x][summ] = 1; // ��ǵ�ǰ״̬Ϊ�ѷ���
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
            exit(0); // �ҵ�����˳�����
            //flag = 1; // ��������ִ�У�exit(0)�Ѿ���ֹ�˳���
        }
        return;
    }
    // ����ѡ��a[x]
    ch[x] = 'H';
    dfs(x + 1, summ + a[x]);

    // ����ѡ��b[x]
    if (!flag) { // �����û���ҵ��⣬������һ��ѡ��
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