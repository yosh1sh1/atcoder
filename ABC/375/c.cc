#include <bits/stdc++.h>

#define rep(i, j, n) for (int i = j; i < n; i++)

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> table(n, vector<char>(n));

    rep(i, 0, n)
        rep(j, 0, n)
            cin >> table[i][j];

    vector<vector<char>> res(n, vector<char>(n, '.'));

    auto cvt = [&](int x, int y, int c) -> pair<int, int> {
        int tmpx = x;
        int tmpy = y;
        rep(i, 0, c) {
            x = tmpy;
            y = n - 1 - tmpx;

            tmpx = x;
            tmpy = y;
        }
        return {x, y};
    };

    rep(i, 0, n/2) {
        rep(j, i, n-i) {
            // 基準座標
            pair<int, int> p1(i, j);
            pair<int, int> p2(j, n - 1 - i);
            pair<int, int> p3(n - 1 - i, n - 1 - j);
            pair<int, int> p4(n - 1 - j, i);
            
            int cnt = i % 4 + 1; // 変換回数

            auto [x, y] = cvt(p1.first, p1.second, cnt);
            auto [x2, y2] = cvt(p2.first, p2.second, cnt);
            auto [x3, y3] = cvt(p3.first, p3.second, cnt);
            auto [x4, y4] = cvt(p4.first, p4.second, cnt);

            res[x][y] = table[p1.first][p1.second];
            res[x2][y2] = table[p2.first][p2.second];
            res[x3][y3] = table[p3.first][p3.second];
            res[x4][y4] = table[p4.first][p4.second];
        }
    }

    rep(i, 0, n) {
        rep(j, 0, n) {
            cout << res[i][j];
        }
        cout << endl;
    }

    return 0;
}