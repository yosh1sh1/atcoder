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

    vector<int> x(n);
    vector<int> p(n);
    rep(i, 0, n)
        cin >> x[i];
    rep(i, 0, n)
        cin >> p[i];

    vector<ll> sum(n+1);
    sum[0] = 0;
    rep(i, 0, n)
        sum[i+1] = sum[i] + p[i];

    int q;
    cin >> q;

    vector<ll> res;
    rep(i, 0, q) {
        int l, r;
        cin >> l >> r;

        // int l_id = distance(upper_bound(x.begin(), x.end(), l-1), x.begin()); // upper_boundの結果がx.begin()より進んでいるため負の数が帰ってくる
        // int r_id = distance(upper_bound(x.begin(), x.end(), r), x.begin());
        int l_id = distance(x.begin(), upper_bound(x.begin(), x.end(), l-1));
        int r_id = distance(x.begin(), upper_bound(x.begin(), x.end(), r));
        res.push_back(sum[r_id] - sum[l_id]);
    }

    rep(i, 0, q)
        cout << res[i] << endl;

    return 0;
}
