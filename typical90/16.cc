#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

/* A, B, C それぞれの枚数を二分探索すれば求まるんじゃないかと思った */
void bs(const int& id, const vector<int>& p, const int& left, vector<int>& res) {
    int l = 0;
    int r = 100000;
    while (abs(l - r) > 1) {
        int mid = (l + r) / 2;
        int sum = p[id] * mid;
        if (sum > left) {
            r = mid;
        } else {
            if (id < 2) {
                bs(id+1, p, left - sum, res);
            }
            l = mid;
        }
    }

    res[id] = l;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    // vector<ll> p(3);
    // cin >> n >> p[0] >> p[1] >> p[2];

    // vector<int> res(3, 0);
    // sort(p.begin(), p.end(), greater<int>());
    // bs(0, p, n, res);

    // cout << res[0] + res[1] + res[2] << endl;

    const int max = 10000;
    int res = max;
    rep(i, 0, max) {
        rep(j, 0, max) {
            ll tmp = i * (ll)a + j * (ll)b;
            if (tmp > n || (n - tmp) % c != 0)
                continue;
            int k = (n - tmp) / c;

            res = min(res, i + j + k);
        }
    }

    cout << res << endl;

    return 0;
}
