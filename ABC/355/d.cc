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

    vector<int> l(n);
    vector<int> r(n);
    rep(i, 0, n) {
        cin >> l[i] >> r[i];
    }

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    ll res = n * ll(n - 1) / 2;

    /* binary search */
    rep(id_l, 0, n) {
        res -= lower_bound(r.begin(), r.end(), l[id_l]) - r.begin();
    }

    // /* other solution */
    // vector<pair<int, int>> section;
    // rep(i, 0, n) {
    //     int l, r;
    //     cin >> l >> r;
    //     section.emplace_back(l, 0);
    //     section.emplace_back(r, 1);
    // }
    // sort(section.begin(), section.end());

    // ll res = n * ll(n - 1) / 2;
    // int rs = 0;
    // for (auto [num, lr] : section) {
    //     if (lr == 0)
    //         res -= rs;
    //     else
    //         rs++;
    // }

    cout << res << endl;

    return 0;
}
