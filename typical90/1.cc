#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, l, k;
    cin >> n >> l >> k;

    vector<int> a(n);
    rep(i, 0, n)
        cin >> a[i];

    auto check = [&](int x) -> bool {
        int cnt = 0;
        int pre = 0;
        rep(i, 0, n) {
            if (a[i] - pre >= x) {
                cnt++;
                pre = a[i];
            }
        }
        if (l - pre >= x)
            cnt++;

        if (cnt >= k + 1)
            return true;

        return false;
    };

    // 2分探索で切れ目の最大値を探索
    // ピースが k+1 個以上になる最小ピースサイズの境界値を探る
    // -> 2分探索で調査する境界値は最小ピースサイズと同じになる
    int left = -1;
    int right = l + 1;
    while (abs(right - left) > 1) {
        int mid = (right + left) / 2;
        if (check(mid))
            left = mid;
        else
            right = mid;
    }

    cout << left << endl;

    return 0;
}
