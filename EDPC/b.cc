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

    vector<int> h(n+1, 0);
    rep(i, 1, n+1)
        cin >> h[i];

    vector<int> dp(n+1, numeric_limits<int>::max());
    dp[1] = 0;
    h[0] = numeric_limits<int>::max(); // dummy
    rep(i, 2, n+1) {
        rep(j, 1, k+1) {
            if (i - j < 1)
                break;
            dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
        }
    }

    cout << dp[n] << endl;

    return 0;
}
