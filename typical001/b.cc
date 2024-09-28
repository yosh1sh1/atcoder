#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

class UnionFind {
 public:
    UnionFind() = default;
    ~UnionFind() = default;

    UnionFind(int n) {
        init(n);
    }

    void init(int x) {
        tree.resize(x);
        rep(i, 0, x)
            tree[i] = i;
    }

    int get_root(int x) {
        if (tree[x] != x) {
            tree[x] = get_root(tree[x]);
        }
        return tree[x];
    }

    void unite(int x, int y) {
        int root_x = get_root(x);
        int root_y = get_root(y);

        if (root_x != root_y) {
            tree[root_x] = root_y;
        }
    }

    bool is_same(int x, int y) {
        return get_root(x) == get_root(y);
    }

 private:
    vector<int> tree;
};

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    UnionFind uf(n);
    rep (i, 0, q) {
        int p, a, b;
        cin >> p >> a >> b;

        if (!p) {
            uf.unite(a, b);
        } else {
            if (uf.is_same(a, b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}
