#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll c = 10;
    int digit = 1;
    if (n > c) { // 1桁目の処理
        n -= c;
        c = 9;
        ++digit;
    }
    while (n > c) { // 2桁目以降
        n -= c;
        if (++digit % 2) { // odd
            c *= 10;
        }
    }

    if (digit == 1) {
        cout << n - 1 << endl;
        return 0;
    }

    // 回文の上半分、下半分の作成
    ll upper = 1;
    rep (i, 1, (digit+1)/2) // round
        upper *= 10;
    upper += n - 1;

    string upper_str = to_string(upper);
    string lower_str;
    if (digit % 2) { // odd
        lower_str =  to_string(upper / 10);
    } else {
        lower_str = upper_str;
    }
    reverse(lower_str.begin(), lower_str.end());

    string ans = upper_str + lower_str;
    cout << ans << endl;

    return 0;
}
