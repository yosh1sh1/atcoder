#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;

    int n = (int)s.size();
    vector<vector<ll>> cnt(26, vector<ll>(n+1));
    for (int i = 0; i < n; i++) { // cnt[][0] is sentinel.
        for (int j = 0; j < 26; j++)
            cnt[j][i+1] = cnt[j][i];
        cnt[s[i] - 'A'][i+1]++;
    }

    ll res = 0;
    for (int i = 1; i < n - 1; i++) { // leftはn-1未満まで。n-2はSi, n-1はSj, nはSkとなるため
        for (int j = 0; j < 26; j++) {
            res += cnt[j][i] * (cnt[j][n] - cnt[j][i+1]); // 同一の文字に対し、左側の個数 * 右側の個数
        }
    }

    cout << res << endl;

    return 0;
}

