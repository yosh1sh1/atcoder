#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);
    rep(i, 0, n)
        cin >> a[i];
    rep(i, 0, m)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll res = 0;
    int idx_a = 0;

    auto f = [&](int i, int& j) -> bool {
        for (; j < n; j++) {
            if (b[i] <= a[j]) {
                return true;
            }
        }
        return false;
    };

    rep(i, 0, m) {
        if (idx_a >= n) {
            res = -1;
            break;
        }

        if(f(i, idx_a)) {
            res += a[idx_a];
            idx_a++;
        } else {
            res = -1;
            break;
        }
    }
    cout << res << endl;

    return 0;
}
