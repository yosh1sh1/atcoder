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

    vector<ll> a(n);
    rep(i, 0, n)
        cin >> a[i];

    // memory exceeded
    // vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    // rep(i, 1, n+1) {
    //     rep(j, i, n+1) {
    //         if (i % 2)
    //             dp[i][j] = max(dp[i-1][j-1]+a[j-1], max(dp[i-1][j], dp[i][j-1]));
    //         else
    //             dp[i][j] = max(dp[i-1][j-1]+(a[j-1]*2), max(dp[i-1][j], dp[i][j-1]));
    //     }
    // }

    // TLE
    // vector<vector<ll>> dp(2, vector<ll>(n + 1, 0));
    // rep(i, 1, n+1) {
    //     int r = i % 2;
    //     rep(j, i, n+1) {
    //         if (r)
    //             dp[r][j] = max(dp[r-1][j-1]+a[j-1], max(dp[r-1][j], dp[r][j-1]));
    //         else
    //             dp[r][j] = max(dp[r+1][j-1]+(a[j-1]*2), max(dp[r+1][j], dp[r][j-1]));
    //     }
    // }

    // if (n % 2)
    //     cout << dp[1][n] << endl;
    // else
    //     cout << dp[0][n] << endl;

    vector<ll> dp_even(n+1, 0);
    vector<ll> dp_odd(n+1, 0);

    dp_odd[0] = -INF; // dp_even[1] が0より大きくならないように（最初の1匹目を倒すときにA[0]*2ができないため）
    rep(i, 1, n+1) {
        dp_even[i] = max(dp_even[i-1], dp_odd[i-1] + (a[i-1] * 2));
        dp_odd[i] = max(dp_odd[i-1], dp_even[i-1] + a[i-1]);
    }

    cout << max(dp_even[n], dp_odd[n]) << endl;

    return 0;
}
