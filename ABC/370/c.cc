#include <bits/stdc++.h>

using namespace std;

int main() {

    string s, t;
    cin >> s >> t;

    vector<string> x;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] > t[i]) {
            s[i] = t[i];
            x.push_back(s);
        }
    }

    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] < t[i]) {
            s[i] = t[i];
            x.push_back(s);
        }
    }

    cout << x.size() << endl;
    for (auto v : x)
        cout << v << endl;
    
    return 0;
}