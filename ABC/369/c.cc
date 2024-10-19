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
    rep(i, 0, n) {
        cin >> a[i];
    }

    vector<int> d;
    int pre = a[0];
    rep (i, 1, n) {
        d.push_back(pre - a[i]);
        pre = a[i];
    }

    ll res = n;
    pre = d[0];
    int cnt = 0;
    rep(i, 0, (int)d.size()) {
        cnt++;
        if (pre == d[i]) {
            res += cnt;
        } else {
            cnt = 1;
            res += cnt;
        }
        pre = d[i];
    }

    cout << res << endl;

    return 0;
}
