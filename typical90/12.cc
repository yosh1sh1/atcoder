#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

class UnionFind {
 public:
    UnionFind() = default;
    ~UnionFind() = default;

    UnionFind(int h, int w) {
        tree.resize(h, vector<pair<int, int>>(w));
        init(h, w);
    }

    void init(int h, int w) {
        rep(i, 0, h)
            rep(j, 0, w)
                tree[i][j] = (make_pair(i, j));
    }

    pair<int, int> get_root(pair<int, int> p) {
        if (tree[p.first][p.second] != p) {
            tree[p.first][p.second] = get_root(tree[p.first][p.second]);
        }
        return tree[p.first][p.second];
    }

    void unite(pair<int, int> x, pair<int, int> y) {
        auto root_x = get_root(x);
        auto root_y = get_root(y);

        if (root_x != root_y) {
            tree[root_x.first][root_x.second] = root_y;
        }
    }

    bool is_same(pair<int, int> x, pair<int, int> y) {
        auto root_x = get_root(x);
        auto root_y = get_root(y);

        return root_x == root_y;
    }

 private:
        vector<vector<pair<int, int>>> tree;
};

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<int>> v(h, vector<int>(w, 0));
    UnionFind uf(h, w);

    vector<string> res;
    rep(i, 0, q) {
        int t;
        cin >> t;

        if (t == 1) {
            int ra, ca;
            cin >> ra >> ca;
            --ra; --ca;
            v[ra][ca] = 1;

            // 四隅のチェック & 結合
            if (ra > 0 && v[ra-1][ca])
                uf.unite(make_pair(ra, ca), make_pair(ra-1, ca));
            if (ca > 0 && v[ra][ca-1])
                uf.unite(make_pair(ra, ca), make_pair(ra, ca-1));
            if (ra < h-1 && v[ra+1][ca])
                uf.unite(make_pair(ra, ca), make_pair(ra+1, ca));
            if (ca < w-1 && v[ra][ca+1])
                uf.unite(make_pair(ra, ca), make_pair(ra, ca+1));
        } else {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            --ra; --ca; --rb; --cb;

            // rootが同じであれば"Yes"
            if ((v[ra][ca] && v[rb][cb]) &&
                uf.is_same(make_pair(ra, ca), make_pair(rb, cb)))
                res.push_back("Yes");
            else
                res.push_back("No");
        }
    }

    for (auto s : res)
        cout << s << endl;
    return 0;
}
