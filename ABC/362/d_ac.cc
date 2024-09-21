#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

namespace {

struct Node {
    int id;
    int cost;

    Node(int i, int c) : id(i), cost(c) {}
    bool operator < (const Node& n) const {
        return (cost > n.cost);
    }
};

} // namespace

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    rep(i, 0, n)
        cin >> a[i];

    // vector<vector<pair<int, int>>> e(n, vector<pair<int, int>>(m));
    vector<vector<pair<int, int>>> e(n);
    int u, v, b;
    rep(i, 0, m) {
        cin >> u >> v >> b;
        u--; v--;

        e[u].emplace_back(make_pair(v, b));
        e[v].emplace_back(make_pair(u, b));
    }

    vector<ll> res(n, LLONG_MAX);
    res[0] = a[0];

    priority_queue<Node> q;
    q.emplace(Node(0, res[0]));

    while (!q.empty()) {
        auto p = q.top();
        q.pop();

        if (res[p.id] < p.cost)
            continue;
        
        // res[p.id] = p.cost;
        for (auto edge : e[p.id]) {
            ll next_w = res[p.id] + edge.second + a[edge.first];
            if (res[edge.first] > next_w) {
                res[edge.first] = next_w;
                q.emplace(Node(edge.first, next_w));
            }
        }
    }

    rep(i, 1, n)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}
