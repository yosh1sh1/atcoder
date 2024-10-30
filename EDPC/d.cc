#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, limit_w;
    cin >> n >> limit_w;

    vector<int> w(n);
    vector<ll> v(n);
    rep(i, 0, n) {
        cin >> w[i] >> v[i];
    }

    vector<vector<ll>> dp(limit_w+1, vector<ll>(n+1, 0));

    rep(i, 1, limit_w+1) {
        rep(j, 1, n+1) {
            if (w[j-1] > i) {
                dp[i][j] = dp[i][j-1];
            } else {
                int left_w = i - w[j-1];
                dp[i][j] = max(v[j-1] + dp[left_w][j-1], dp[i][j-1]);
            }
        }
    }

    cout << dp[limit_w][n] << endl;

    return 0;
}
