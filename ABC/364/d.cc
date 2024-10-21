#include <bits/stdc++.h>

#define rep(i, j, n) for (int i = j; i < n; i++)

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    rep(i, 0, n)
        cin >> a[i];

    sort(a.begin(), a.end());

    rep(i, 0, q) {
        int b, k;
        cin >> b >> k;

        auto judge = [&](int x) -> bool {
            auto lb = lower_bound(a.begin(), a.end(), b - x);
            auto ub = upper_bound(a.begin(), a.end(), b + x);
            if (ub - lb >= k)
                return true;
            return false;
        };

        // x の範囲を探索
        int l = -1;
        int r = 2e8 + 1;
        while (abs(l - r) > 1) {
            int mid = (l + r) / 2;
            if (/* 配列Aに対し、b-x, b+xの範囲内の要素数 */ judge(mid))
                r = mid;
            else
                l = mid;
        }

        cout << r << endl;
    }

    return 0;
}
    