#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int w = n - k; // 探査する数列の幅
    ll res = LONG_LONG_MAX;
    sort(a.begin(), a.end());
    for (int i = 0; i < n - (w - 1); i++) {
        res = min(res, a[i+w-1] - a[i]);
    }

    cout << res << endl;

    return 0;
}
