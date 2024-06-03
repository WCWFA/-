#include<bits/stdc++.h>
using namespace std;
map<int, int> mp;
int n, m;
const int N = 1e6 + 9;
int a[N];
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch>'9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
void write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
//int main()
//{
//    n = read(), m = read();
//    for (int i = 1; i <= n; ++i)
//    {
//        int tmp;
//        tmp = read();
//        if (mp.count(tmp) == 0)
//        {
//            mp[tmp] = i;
//        }
//    }
//    for (int i = 1; i <= m; ++i)
//    {
//        int tmp;
//        tmp = read();
//        if (mp.count(tmp) == 0)
//        {
//            write(-1);
//            cout << ' ';
//        }
//        else
//        {
//            write(mp[tmp]);
//            cout << ' ';
//        }
//    }
//	return 0;
//}
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 1; i <= m; ++i)
    {
        int x = read();
        int ans = lower_bound(a + 1, a + n + 1, x) - a;
        if (x != a[ans]) printf("-1 ");
        else printf("%d ", ans);
    }
    return 0;
}