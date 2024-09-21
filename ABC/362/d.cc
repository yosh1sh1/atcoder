#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    rep(i, 0, n)
        cin >> a[i];

    // vector<vector<pair<int, int>>> e(n, vector<pair<int, int>>(m)); // n*m分の領域を取ってしまってる
    // int u, v, b;
    // rep(i, 0, m) {
    //     cin >> u >> v >> b;
    //     u--; v--;
    //     e[u].emplace_back(make_pair(v, b)); // emplace_backすることで確保した領域を使用していない
    //     e[v].emplace_back(make_pair(u, b));
    // }
    vector<vector<pair<int, int>>> e(n);
    int u, v, b;
    rep(i, 0, m) {
        cin >> u >> v >> b;
        u--; v--;

        e[u].emplace_back(make_pair(v, b));
        e[v].emplace_back(make_pair(u, b));
    }

    vector<ll> res(n, LLONG_MAX);
    queue<pair<int, ll>> q; // first: node, second: weight
    q.emplace(make_pair(0, a[0]));

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        if (res[p.first] > p.second) {
            res[p.first] = p.second;
            for (auto edge : e[p.first]) {
                ll next_w = res[p.first] + edge.second + a[edge.first];
                if (res[edge.first] > next_w)
                    q.emplace(make_pair(edge.first, next_w));
            }
        }
    }

    rep(i, 1, n)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}
