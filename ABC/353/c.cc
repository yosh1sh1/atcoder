#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;
const ll MOD = 1e8;

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<ll> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll sum = 0;
    rep(i, 0, n) {
        sum += (n - 1) * a[i];
    }

    int r = n;
    ll cnt = 0;
    rep(i, 0, n) {
        r = max(r, i + 1);
        while (r - 1 > i && a[i] + a[r - 1] >= 100000000) {
            r--;
        }
        cnt += n - r;
    }

    ll res = sum - (cnt * 100000000);
    cout << res << endl;

    return 0;
}