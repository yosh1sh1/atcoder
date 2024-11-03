#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n, 0));
    rep(i, 0, n)
        rep(j, 0, n)
            cin >> a[i][j];

    int m;
    cin >> m;

    map<int, vector<int>> xy;
    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        xy[x].push_back(y);
        xy[y].push_back(x);
    }

    vector<int> order(n);
    rep(i, 0, n)
        order[i] = i;

    int res = 1e9;
    do {
        int tmp = 0;
        rep(i, 0, n) {
            tmp += a[order[i]][i];
            if (i < n - 1 && find(xy[order[i]].begin(), xy[order[i]].end(), order[i+1]) != xy[order[i]].end()) {
                tmp = 1e9;
                break;
            }
        }
        res = min(res, tmp);
    } while(next_permutation(order.begin(), order.end()));

    if (res == 1e9)
        cout << -1 << endl;
    else
        cout << res << endl;

    return 0;
}
