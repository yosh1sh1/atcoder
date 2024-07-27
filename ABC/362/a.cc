#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, g, b;
    string c;
    cin >> r >> g >> b >> c;

    int res;
    if (c == "Red")
        res = min(g, b);
    else if (c == "Green")
        res = min(r, b);
    else
        res = min(r, g);

    cout << res << endl;

    return 0;
}