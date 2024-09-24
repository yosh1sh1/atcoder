#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int m_g;
    cin >> m_g;
    vector<vector<int>> edge_g(n);
    rep(i, 0, m_g) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edge_g[u].push_back(v);
        edge_g[v].push_back(u);
    }

    int m_h;
    cin >> m_h;
    vector<vector<int>> edge_h(n);
    rep(i, 0, m_h) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge_h[a].push_back(b);
        edge_h[b].push_back(a);
    }

    vector<vector<int>> cost(n, vector<int>(n, 0));
    rep(i, 0, n) {
        rep(j, i+1, n) {
            cin >> cost[i][j];
            cost[j][i] = cost[i][j];
        }
    }

    vector<int> p(n);
    // 順列の初期化
    rep(i, 0, n)
        p[i] = i;

    int res = INF;
    do {
        int tmp = 0;
        rep(i, 0, n) {
            rep(j, i+1, n) {
                // G上にi-jの辺がある場合
                if (find(edge_g[i].begin(), edge_g[i].end(), j) != edge_g[i].end()) {
                    if (find(edge_h[p[i]].begin(), edge_h[p[i]].end(), p[j]) != edge_h[p[i]].end()) {
                        // do nothing
                    } else {
                        tmp += cost[p[i]][p[j]];
                    }
                } else {
                    if (find(edge_h[p[i]].begin(), edge_h[p[i]].end(), p[j]) != edge_h[p[i]].end()) {
                        tmp += cost[p[i]][p[j]];
                    } else {
                        // do nothing
                    }
                }
            }
        }
        res = min(res, tmp);
    } while (next_permutation(p.begin(), p.end()));

    cout << res << endl;

    return 0;
}
