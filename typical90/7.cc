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

    vector<int> a(n);
    rep(i, 0, n)
        cin >> a[i];

    int q;
    cin >> q;

    vector<int> b(q);
    rep(i, 0, q)
        cin >> b[i];

    sort(a.begin(), a.end());

    auto check = [&](int key, int x) -> bool {
        if (b[key] < a[x])
            return true;
        return false;
    };

    rep(i, 0, q) {
        int left = -1;
        int right = n;
        // upper_bound
        while(abs(right - left) > 1) {
            int mid = (right + left) / 2;
            if (check(i, mid))
                right = mid;
            else
                left = mid;
        }
        int res;
        if (left < 0)
            res = abs(a[right] - b[i]);
        else if (right >= n)
            res = abs(a[left] - b[i]);
        else
            res = abs(a[right] - b[i]) < abs(a[left] - b[i]) ? abs(a[right] - b[i]) : abs(a[left] - b[i]);
        cout << res << endl;
    }

    return 0;
}
