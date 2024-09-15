#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;

    string t = "atcoder";
    vector<vector<int>> dp(n+1, vector<int>((int)t.size()+1, 0));

    dp[0][0] = 1; // init
    rep(i, 0, n) {
        rep(j, 0, (int)t.size()+1) { // j == t.size()のときにdp[i+1]に状態遷移する必要があるため、t.size()+1までループ
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= MOD;

            if (j < t.size() && s[i] == t[j]) { // jがt.size()になるときがあるため、j<t.size()で抑止
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][j+1] %= MOD;
            }
        }
    }

    cout << dp[n][t.size()] << endl;

    return 0;
}
