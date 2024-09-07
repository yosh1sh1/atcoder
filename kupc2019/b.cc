#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

class UnionFind {
 public:
    UnionFind() = default;
    ~UnionFind() = default;

    UnionFind(int n) : tree(n) {
        rep (i, 0, n)
            tree[i] = i;
    }

    void init(int n) {
        rep(i, 0, n) {
            tree[i] = i;
        }
    }

    int get_root(int x) {
        if (tree[x] != x)
            tree[x] = get_root(tree[x]); // 根をつなぎ直し

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
        return tree[x] == tree[y];
    }

    vector<int> tree;
};

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, m, max_w;
    cin >> n >> m >> max_w;

    vector<int> w(n);
    vector<int> v(n);
    vector<int> a(m);
    vector<int> b(m);

    UnionFind uf(n);

    rep(i, 0, n) {
        cin >> w[i] >> v[i];
    }
    rep(i, 0, m) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--; // 数値をindexに合わせる
        uf.unite(a[i], b[i]);
    }

    // // UnionFindのroot確認
    // rep(i, 0, n) {
    //     cout << "index: " << i << ", root: " << uf.get_root(i) << endl;
    // }

    // UnionFindの内容から、v_i, w_i を作り直す
    vector<int> w2(n);
    vector<int> v2(n);
    rep(i, 0, n) {
        int root = uf.get_root(i);
        w2[root] += w[i];
        v2[root] += v[i];
    }

    // rep(i, 0, n) {
    //     cout << "index: " << i << ", w: " << w2[i] << ", v: " << v2[i] << endl;
    // }

    // ナップザック問題
    int dp[max_w + 1][n + 1];
    // init
    rep (i, 0, max_w + 1) {
        rep (j, 0, n) {
            dp[i][j] = 0;
        }
    }

    rep(i, 1, max_w + 1) { // 重さ最大値 1 からスタート, max_w でも処理が必要なため +1 
        rep(j, 1, n + 1) {  // 1個目の荷物からスタート, index的には-1する
            if (i >= w2[j - 1]) {
                dp[i][j] = max(dp[i][j - 1], dp[i - w2[j - 1]][j - 1] + v2[j - 1]);
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    cout << dp[max_w][n] << endl;

    return 0;
}
