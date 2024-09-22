#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;
typedef unsigned long long ull;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, q;
    cin >> n;

    vector<pair<int, int>> xp;
    map<int, ll> mp_xp;

    rep(i, 0, n) {
        int x;
        cin >> x;
        xp.push_back(make_pair(x, 0));
    }
    rep(i, 0, n) {
        int p;
        cin >> p;
        xp[i].second = p;
    }

    sort(xp.begin(), xp.end());
    ll sum = 0;
    rep(i, 0, n) {
        sum += xp[i].second;
        mp_xp[xp[i].first] = sum;
    }

    cin >> q;
    int l, r;
    vector<ll> res;
    rep(i, 0, q) {
        cin >> l >> r;

        auto left = mp_xp.lower_bound(l);
        auto right = mp_xp.upper_bound(r);
        if (right == mp_xp.begin())
            res.push_back(0);
        else if (left == mp_xp.begin())
            res.push_back((--right)->second);
        else
            res.push_back((--right)->second - (--left)->second);
    }

    for (auto v : res)
        cout << v << endl;

    return 0;
}
