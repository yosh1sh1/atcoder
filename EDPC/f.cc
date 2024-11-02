#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    // LCS (longest common subsequence) 

    string s, t;
    cin >> s >> t;

    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));

    rep(i, 0, s.size()) {
        rep(j, 0, t.size()) {
            if (s[i] == t[j])
                dp[i+1][j+1] = dp[i][j] + 1;
            dp[i+1][j+1] = max( {dp[i+1][j+1], dp[i+1][j], dp[i][j+1]} );
        }
    }

    string res;
    int i = s.size();
    int j = t.size();
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i-1][j]) {
            i--;
        } else if (dp[i][j] == dp[i][j-1]) {
            j--;
        } else {
            i--;
            j--;
            res = s[i] + res; // 逆にする
        }
    }

    cout << res << endl;

    return 0;
}
