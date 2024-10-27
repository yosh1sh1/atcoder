#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> i2p(n + 1);
    vector<int> p2i(n + 1);
    rep(i, 0, n) {
        cin >> i2p[i + 1];
        p2i[i2p[i + 1]] = i + 1;
    }


    set<int> s;
    rep(i, 0, k) {
        s.insert(p2i[i + 1]);
    }

    int res = INT_MAX;
    res = min(res, *s.rbegin() - *s.begin());

    for (int l = k; l < n; l++) {
        s.erase(p2i[l - k + 1]);
        s.insert(p2i[l + 1]);
        res = min(res, *s.rbegin() - *s.begin());
        // auto it = minmax_element(p2i.begin() + l, p2i.begin() + l + k);
        // res = min(res, *it.second - *it.first);
    }

    cout << res << endl;

    return 0;
}
