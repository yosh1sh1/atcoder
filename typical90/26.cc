#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

// 隣り合わないノード -> 辺が1以下のノードなのでは？
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> edge(n);
    int a, b;
    rep(i, 0, n - 1) {
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    vector<int> res;
    rep(i, 0, n) {
        if (edge[i].size() == 1)
            res.push_back(i+1);
        if (res.size() >= (n/2))
            break;
    }

    for (auto v : res)
        cout << v << " ";
    cout << endl;

    return 0;
}
