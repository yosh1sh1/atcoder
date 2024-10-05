#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

/*
 *  1 | 2 | 3
 *  4 | 5 | 6
 *  7 | 8 | 9
 * 
 *  累積 テーブル（2次元）
 *  0 | 0 | 0 | 0
 *  0 | 1 | 3 | 6
 *  0 | 5 | 12 | 21
 *  0 | 12 | 27 | 45
 */

void bad() {
    int n;
    cin >> n;
    vector<vector<vector<int>>> a(n, vector<vector<int>>(n, vector<int>(n)));
    vector<int> sum(n*n*n+1, 0);

    rep(i, 0, n) {
        rep(j, 0, n) {
            rep(k, 0, n) {
                cin >> a[i][j][k];
                sum[i*n*n + j*n + k + 1] = a[i][j][k];
            }
        }
    }

    rep(i, 2 , n*n*n+1) {
        sum[i] += sum[i-1];
    }

    int q;
    cin >> q;

    rep(i, 0, q) {
        int res = 0;
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        lx--; rx--; ly--; ry--; lz--; rz--;
        for (int i = lx; i <= rx; i++) {
            for (int j = ly; j <= ry; j++) {
                res += sum[i*n*n + j*n + rz + 1] - sum[i*n*n + j*n + lz];
            }
        }
        cout << res << endl;
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<vector<int>>> a(n, vector<vector<int>>(n, vector<int>(n, 0)));
    vector<vector<vector<int>>> sum(n+2, vector<vector<int>>(n+2, vector<int>(n+2, 0)));

    rep(i, 0, n) {
        rep(j, 0, n) {
            rep(k, 0, n) {
                cin >> a[i][j][k];
            }
        }
    }

    rep(i, 0, n)
        rep(j, 0, n)
            rep(k, 0, n)
                sum[i+1][j+1][k+1] = a[i][j][k];

    rep(i, 0, n+1)
        rep(j, 0, n+1)
            rep(k, 0, n+1)
                sum[i][j][k+1] += sum[i][j][k];

    rep(i, 0, n+1)
        rep(j, 0, n+1)
            rep(k, 0, n+1)
                sum[i][j+1][k] += sum[i][j][k];

    rep(i, 0, n+1)
        rep(j, 0, n+1)
            rep(k, 0, n+1)
                sum[i+1][j][k] += sum[i][j][k];

    // rep(i, 0, n)
    //     rep(j, 0, n)
    //         rep(k, 0, n)
    //             sum[i+1][j+1][k+1] += a[i][j][k];

    // 以下の累積方法だと余分に足しすぎる 
    // A | B
    // C | D -> Dに対し、B+C だけをしており、Aが多く含まれる
    // 一次元ずつのほうが理解しやすい
    // rep(i, 0, n+1) {
    //     rep(j, 0, n+1) {
    //         rep(k, 0, n+1) {
    //             sum[i][j][k+1] += sum[i][j][k]; 
    //             sum[i][j+1][k] += sum[i][j][k];
    //             sum[i+1][j][k] += sum[i][j][k];
    //         }
    //     }
    // }

    int q;
    cin >> q;
    rep(i, 0, q) {
        int res = 0;
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;

        res = sum[rx][ry][rz] - sum[lx-1][ry][rz] - sum[rx][ry][lz-1] - sum[rx][ly-1][rz] + sum[lx-1][ry][lz-1] + sum[lx-1][ly-1][rz] + sum[rx][ly-1][lz-1] - sum[lx-1][ly-1][lz-1];

        cout << res << endl;
    }

    return 0;
}
