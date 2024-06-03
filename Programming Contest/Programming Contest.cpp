#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 55;
ll a[N];
ll n, t;
ll max_summ = 0;

// ������������������������鲿�������޶������ڿ��Եõ�������
void dfs(ll start, ll end, ll current_sum, ll remaining_capacity) {
    if (current_sum + remaining_capacity < max_summ) {
        // ��֦: �����ǰ�ܺͼ���ʣ��������������֪���ʹ󣬾Ͳ��ؼ�������
        return;
    }
    if (start > end) {
        max_summ = max(max_summ, current_sum);
        return;
    }
    if (remaining_capacity >= a[start]) {
        dfs(start + 1, end, current_sum + a[start], remaining_capacity - a[start]);  // ѡ��ǰԪ��
    }
    dfs(start + 1, end, current_sum, remaining_capacity);  // ��ѡ��ǰԪ��
}

// �������Ϊ���룬�ֱ�����
void splitAndSearch(ll l, ll r) {
    ll mid = (l + r) / 2;
    dfs(l, mid, 0, t);
    ll first_half_max = max_summ;  // ��һ�������
    max_summ = 0;
    dfs(mid + 1, r, 0, t);
    ll second_half_max = max_summ;  // �ڶ��������
    max_summ = first_half_max + second_half_max;  // �ϲ������ֵĽ��
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
