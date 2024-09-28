#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int h, w, q;
    cin >> h >> w >> q;

    // 行と列毎に壁が存在するインデックスを格納した配列
    vector<set<int>> wall_r(h);
    vector<set<int>> wall_c(w);
    rep(i, 0, h) {
        rep(j, 0, w) {
            wall_r[i].insert(j);
            wall_c[j].insert(i);
        }
    }

    auto destroy = [&](int r, int c) {
        wall_r[r].erase(c);
        wall_c[c].erase(r);
    };

    rep(i, 0, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (wall_r[r].find(c) != wall_r[r].end()) {
            destroy(r, c);
            continue;
        }

        // up and down
        {
            auto it = wall_c[c].lower_bound(r);
            if (it != begin(wall_c[c]))
                destroy(*prev(it), c); // up

            if (it != end(wall_c[c]))
                destroy(*it, c); // down
        }

        // left and right
        {
            auto it = wall_r[r].lower_bound(c);
            if (it != begin(wall_r[r]))
                destroy(r, *prev(it)); // left

            if (it != end(wall_r[r]))
                destroy(r, *it); // right
        }
    }

    int res = 0;
    rep(i, 0, h) {
        res += wall_r[i].size();
    }

    cout << res << endl;

    return 0;
}
