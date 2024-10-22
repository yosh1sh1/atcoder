#include <bits/stdc++.h>

#include <atcoder/all>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    // using mint = modint998244353;

    ll n;
    cin >> n;

    mint r = 1;
    for (ll tmp = n; tmp > 0; tmp /= 10) {
        r *= 10; // 10^k -> n の桁数乗
    }

    mint res = (r.pow(n) - 1) / (r - 1) * n; // (10^kn - 1) / (10^k - 1) * n
    cout << res.val() << endl;

    return 0;
}
