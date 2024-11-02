#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

const int NMAX = 110;
const int VMAX = 100010;

using namespace std;

vector<vector<int>> dp(NMAX, vector<int>(VMAX, INF));

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

    // init
    dp[0][0] = 0;

    rep(i, 0, n) {
        rep(j, 0, VMAX) {
            if (v[i] > j) {
                dp[i+1][j] = dp[i][j];
            } else {
                int left = j - v[i];
                dp[i+1][j] = min(dp[i][j], w[i] + dp[i][left]);
            }
        }
    }

    int res = 0;
    rep(j, 0, VMAX) {
        if (dp[n][j] <= limit_w)
            res = max(res, j);
    }

    cout << res << endl;

    return 0;
}
