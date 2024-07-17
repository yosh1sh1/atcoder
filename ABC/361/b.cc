#include <bits/stdc++.h>

using namespace std;

int main() {

    int a, b, c, d, e, f;
    int g, h, i, j, k, l;

    cin >> a >> b >> c >> d >> e >> f;
    cin >> g >> h >> i >> j >> k >> l;

    // x
    if (max(a, d) <= min(g, j) || min(a, d) >= max(g, j) ||
        max(b, e) <= min(h, k) || min(b, e) >= max(h, k) ||
        max(c, f) <= min(i, l) || min(c, f) >= max(i, l)) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}