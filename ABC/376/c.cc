#include <bits/stdc++.h>

#define rep(i, j, n) for (int i = j; i < n; i++)

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, n) {
        cin >> b[i];
    }
    b.push_back(0);

    sort(a.begin(), a.end(), greater<int>{});
    sort(b.begin(), b.end(), greater<int>{});

    int x = 0;
    int cnt = 0;
    int bidx = 0;
    rep(i, 0, n) {
        if (a[i] <= b[bidx]) {
            bidx++;
            continue;
        }
        x = a[i];
        cnt++;
        if (cnt >= 2) {
            x = -1;
            break;
        }
    }

    cout << x << endl;

    return 0;
}