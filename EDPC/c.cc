    #include <bits/stdc++.h>

#define rep(i, j, n) for (int i = j; i < n; i++)

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    rep(i, 0, n) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<int> dp(3, 0); // dp[0]: A, dp[1]: B, dp[2]: C
    dp[0] = a[0];
    dp[1] = b[0];
    dp[2] = c[0];
    rep(i, 1, n) {
        vector<int> old(3);
        old.swap(dp);
        dp[0] += max(old[1], old[2]) + a[i];
        dp[1] += max(old[0], old[2]) + b[i];
        dp[2] += max(old[0], old[1]) + c[i];
    }

    int res = max({dp[0], dp[1], dp[2]});
    cout << res << endl;

    return 0;
}