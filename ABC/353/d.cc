#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;
const int MOD = 998244353;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ll> a(n);
    rep(i, 0, n)
        cin >> a[i];
        
    vector<int> digit(n);
    map<int, int> mp;
    rep(i, 0, n) {
        ll tmp = a[i];
        int d = 0;
        while(tmp > 0) {
            tmp /= 10;
            d++;
        }
        digit[i] = d;
        mp[d]++;
    }

    ll res = 0;
    rep(i, 0, n) {
        mp[digit[i]]--;
        res += (a[i] * i) % MOD;
        rep(j, 1, 11) {
            // ll p = (ll)pow(10, j) % MOD;
            res += ((a[i] * ((ll)pow(10, j) % MOD) % MOD) * mp[j]) % MOD;
            // cout << "p : " << p << ", res: " << res << endl;
        }
        // cout << i << ": " << res << endl;
    }
    res %= MOD;

    cout << res << endl;

    return 0;
}
