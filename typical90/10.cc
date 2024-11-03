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

    map<int, pair<int, int>> mp;
    vector<int> c1(n);
    vector<int> c2(n);
    rep(i, 0, n) {
        int c, p;
        cin >> c >> p;

        if (c == 1) {
            c1[i] = p;
        } else {
            c2[i] = p;
        }
    }

    vector<int> sum1(n + 1, 0);
    vector<int> sum2(n + 1, 0);
    rep(i, 0, n) {
        sum1[i+1] = sum1[i] + c1[i];
        sum2[i+1] = sum2[i] + c2[i];
    }

    int q;
    cin >> q;
    rep(i, 0, q) {
        int l, r;
        cin >> l >> r;

        // 1
        cout << sum1[r] - sum1[l-1] << " ";

        // 2
        cout << sum2[r] - sum2[l-1] << endl;
    }

    return 0;
}
