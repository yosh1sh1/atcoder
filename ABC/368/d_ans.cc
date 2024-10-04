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

    // set -> vector だとTLE(findが遅い)
    vector<set<int>> edge(n);
    rep(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].emplace(b);
        edge[b].emplace(a);
    }

    // set -> vector だとTLE(findが遅い)
    set<int> v;
    rep(i, 0, k) {
        int tmp;
        cin >> tmp;
        tmp--;
        v.emplace(tmp);
    }

    int res = n;

    queue<int> q;
    rep(i, 0, n) {
        if (edge[i].size() == 1)
            q.push(i);
    }

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        if (v.find(p) != v.end())
            continue;

        int u = *edge[p].begin();
        edge[u].erase(p);
        res--;

        if (edge[u].size() == 1)
            q.push(u);
    }

    cout << res << endl;

    return 0;
}
