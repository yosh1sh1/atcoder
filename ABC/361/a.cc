#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, x;
    vector<int> a;

    cin >> n >> k >> x;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
        if (i == k - 1)
            a.push_back(x);
    }
    
    for (auto v : a)
        cout << v << " ";
    cout << endl;

    return 0;
}