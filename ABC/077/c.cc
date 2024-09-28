#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    rep(i, 0, n)
        cin >> a[i];
    rep(i, 0, n)
        cin >> b[i];
    rep(i, 0, n)
        cin >> c[i];

    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    ll res = 0;
    for (auto it = b.begin(); it != b.end(); ++it) {
        auto atmp = lower_bound(a.begin(), a.end(), *it); // begin(a[0])~の個数のため lower_bound
        ll num_a = distance(a.begin(), atmp);

        auto ctmp = upper_bound(c.begin(), c.end(), *it); // ~end(c[n])のため upper_bound
        ll num_c = distance(ctmp, c.end());
        res += num_a * num_c;
    }

    cout << res << endl;

    return 0;
}
