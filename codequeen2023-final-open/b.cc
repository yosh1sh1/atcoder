#include <bits/stdc++.h>

#define rep(i, j, n) for(int i = j; i < n; i++)

using namespace std;

const static vector<pair<int, int>> _dist = {
    {-1, -1},
    {-1, 1},
    {1, -1},
    {1, 1}
};

int main () {

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<int> rows(n, 0);
    vector<int> cols(n, 0);
    rep(i, 0, n-1) {
        int r, c;
        cin >> r >> c;
        v[i].first = --r;
        v[i].second = --c;
        m[v[i].first][v[i].second] = 1;
        rows[v[i].first] = 1;
        cols[v[i].second] = 1;
    }

    int x = distance(rows.begin(), find(rows.begin(), rows.end(), 0));
    int y = distance(cols.begin(), find(cols.begin(), cols.end(), 0));

    // auto check = [&](int x, int y, pair<int, int> d) -> bool {
    //     while (x > 0 && x < n - 1 && y > 0 && y < n - 1) {
    //         x += d.first;
    //         y += d.second;
    //         if (m[x][y])
    //             return false;
    //     }
    //     return true;
    // };

    bool res = true;
    // case: _dist[0] (-1, -1)
    rep (i, 1, n) {
        int tmp_x = x+(i*_dist[0].first);
        int tmp_y = y+(i*_dist[0].second);
        if (tmp_x >= 0 && tmp_y >= 0 && m[tmp_x][tmp_y]) {
            res = false;
            break;
        }
    }

    // case: _dist[1] (-1, 1)
    rep (i, 1, n) {
        int tmp_x = x+(i*_dist[1].first);
        int tmp_y = y+(i*_dist[1].second);
        if (tmp_x >= 0 && tmp_y < n && m[tmp_x][tmp_y]) {
            res = false;
            break;
        }
    }

    // case: _dist[2] (1, -1)
    rep (i, 1, n) {
        int tmp_x = x+(i*_dist[2].first);
        int tmp_y = y+(i*_dist[2].second);
        if (tmp_x < n && tmp_y >= 0 && m[tmp_x][tmp_y]) {
            res = false;
            break;
        }
    }

    // case: _dist[2] (1, 1)
    rep (i, 1, n) {
        int tmp_x = x+(i*_dist[3].first);
        int tmp_y = y+(i*_dist[3].second);
        if (tmp_x < n && tmp_y < n && m[tmp_x][tmp_y]) {
            res = false;
            break;
        }
    }
    
    // if (check(x, y, _dist[0]) && check(x, y, _dist[1]) && check(x, y, _dist[2]) && check(x, y, _dist[3])) {
    if (res) {
        cout << x+1 << " " << y+1 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}