#include <bits/stdc++.h>
#include <numeric>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<int>> b(h, vector<int>(w));

    rep(i, 0, h) {
        rep(j, 0, w) {
            cin >> a[i][j];
        }
    }

    vector<int> col(h);
    vector<int> row(w);

    rep(i, 0, h) {
        rep(j, 0, w) {
            col[i] += a[i][j];
            row[j] += a[i][j];
        }
    }

    rep(i, 0, h) {
        rep(j, 0, w) {
            cout << col[i] + row[j] - a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
