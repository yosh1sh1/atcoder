#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> edge(n);
    rep(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    vector<int> v(k);
    rep(i, 0, k) {
        cin >> v[i];
        --v[i];
    }

    queue<pair<int, int>> q; // node, tmp_cost
    q.push(make_pair(v[0], 1));

    vector<int> visited(n, 0);
    int res = 0;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        // cout << "p.first: " << p.first << ", p.second: " << p.second << endl;
        visited[p.first] = 1;

        auto it = find(v.begin(), v.end(), p.first);
        if (it != v.end()) {
            res += p.second;
            p.second = 0;
            v.erase(it);

            if (v.size() == 0)
                break;
        }

        for (auto next : edge[p.first]) {
            if (!visited[next]) {
                q.push(make_pair(next, p.second + 1));
            }
        }
    }

    cout << res << endl;

    return 0;
}
