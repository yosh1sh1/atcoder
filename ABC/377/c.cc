#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    ll n;
    int m;
    cin >> n >> m;

    vector<pair<int, int>> piece(m);
    rep(i, 0, m) {
        cin >> piece[i].first >> piece[i].second;
    }

    set<pair<int, int>> ng; // unordered_setを使うにはhash関数の実装が必要なためsetを使用する
    vector<pair<int, int>> k = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1},
                                {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
    rep(i, 0, m) {
        ng.insert(make_pair(piece[i].first, piece[i].second));

        for (const auto& [ik, jk] : k) {
            int a = piece[i].first + ik;
            int b = piece[i].second + jk;
            if (a < 1 || b < 1 || a > n || b > n)
                continue;
            ng.insert(make_pair(a, b));
        }
    }

    ll res = n * n - ng.size();
    cout << res << endl;

    return 0;
}
