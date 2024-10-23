#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;
const ll MOD = 998244353;

using namespace std;

ll popcount(ll x) {
    ll ret = 0;
    while(x) {
        if (x & 1)
            ++ret % MOD;
        x >>= 1;
    }
    return ret;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    ll res = 0;
    // rep(i, 0, n) {
    //     res += popcount((i % MOD) & (m % MOD));
    //     res %= MOD;
    // }
    rep(i, 0, 60) { // 60bitまで
        if (m & (1ll << i)) {   // Mのi桁目が1なら
            ll period = 2ll << i;   // 2^i+1 の周期
            ll r = n % period;  // 周期から外れた値
            res += (n - r) / 2;
            if (r >= (1ll << i))
                res += r - (1ll << i) + 1;
            res %= MOD;
        }
    }

    cout << res << endl;

    return 0;
}
