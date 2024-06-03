#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 55;
ll a[N];
ll n, t;
ll max_summ = 0;

// 辅助函数，用来计算给定数组部分内在限定总量内可以得到的最大和
void dfs(ll start, ll end, ll current_sum, ll remaining_capacity) {
    if (current_sum + remaining_capacity < max_summ) {
        // 剪枝: 如果当前总和加上剩余容量还不如已知最大和大，就不必继续搜索
        return;
    }
    if (start > end) {
        max_summ = max(max_summ, current_sum);
        return;
    }
    if (remaining_capacity >= a[start]) {
        dfs(start + 1, end, current_sum + a[start], remaining_capacity - a[start]);  // 选择当前元素
    }
    dfs(start + 1, end, current_sum, remaining_capacity);  // 不选择当前元素
}

// 将数组分为两半，分别搜索
void splitAndSearch(ll l, ll r) {
    ll mid = (l + r) / 2;
    dfs(l, mid, 0, t);
    ll first_half_max = max_summ;  // 第一半的最大和
    max_summ = 0;
    dfs(mid + 1, r, 0, t);
    ll second_half_max = max_summ;  // 第二半的最大和
    max_summ = first_half_max + second_half_max;  // 合并两部分的结果
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> t;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    splitAndSearch(1, n);
    cout << max_summ;
    return 0;
}
