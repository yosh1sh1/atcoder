#include <bits/stdc++.h>

#define rep(i, j, n) for (int i = j; i < n; i++)

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edge(n);
    vector<vector<int>> edge_rev(n);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge_rev[b].push_back(a);
    }

    queue<int> q;
    vector<int> score(n, numeric_limits<int>::max());
    vector<int> searched(n, 0);
    for (auto next: edge[0]) {
        q.push(next);
        score[next] = 1;
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        searched[v] = 1;
        for (auto next : edge[v]) {
            if (searched[next])
                continue;
            q.push(next);
            score[next] = min(score[next], score[v] + 1);
        }
    }

    if (searched[0])
        cout << score[0] << endl;
    else
        cout << -1 << endl;

    return 0;
}