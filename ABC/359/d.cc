#include <bits/stdc++.h>

#include <atcoder/all>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

bool isPalindrome(string x) {
    string tmp = x;
    reverse(tmp.begin(), tmp.end());
    return x == tmp;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    using modint = atcoder::static_modint<998244353>;

    int n, k;
    string s;
    cin >> n >> k >> s;

    map<string, modint> dp; // key: k-1文字, value: 何通りあるか？
    dp[""] = 1;

    rep(i, 0, n) {
        map<string, modint> old;
        swap(old, dp);
        for (auto [key, value] : old) {
            for (char c = 'A'; c <= 'B'; c++) { // k番目の文字について処理を開始
                if (s[i] != '?' && s[i] != c)
                    continue;
                string now = key + c;
                if (now.size() == k && isPalindrome(now))
                    continue;
                if (now.size() == k)
                    now.erase(now.begin());
                dp[now] += value;
            }
        }
    }

    modint res;
    for (auto [key, value] : dp) {
        res += value;
    }
    cout << res.val() << endl;

    return 0;
}
