#include <bits/stdc++.h>

using namespace std;

inline int convert(char c) {
    if (c == 'R')
        return 0;
    if (c == 'S')
        return 1;
    if (c == 'P') 
        return 2;
    return -1;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> dp(3, vector<int>(n+1, 0));

    for (int i = 0; i < n; i++) {
        switch (s[i]) {
            case 'R':
                // win
                dp[convert('P')][i+1] = max(dp[convert('R')][i], dp[convert('S')][i]) + 1;
                // draw
                dp[convert('R')][i+1] = max(dp[convert('P')][i], dp[convert('S')][i]);
                break;
            case 'S':
                // win
                dp[convert('R')][i+1] = max(dp[convert('P')][i], dp[convert('S')][i]) + 1;
                // draw
                dp[convert('S')][i+1] = max(dp[convert('P')][i], dp[convert('R')][i]);
                break;
            case 'P':
            default:
                // win
                dp[convert('S')][i+1] = max(dp[convert('P')][i], dp[convert('R')][i]) + 1;
                // draw
                dp[convert('P')][i+1] = max(dp[convert('S')][i], dp[convert('R')][i]);
                break;
        }
    }

    cout << max( { dp[convert('R')][n], dp[convert('S')][n], dp[convert('P')][n] } ) << endl;

    return 0;
}