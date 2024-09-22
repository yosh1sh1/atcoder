#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, q;
    string s;
    cin >> n >> q >> s;

    vector<int> x(q);
    vector<char> c(q);
    rep(i, 0, q)
        cin >> x[i] >> c[i];

    string tar = "ABC";
    vector<int> st;
    auto it = s.begin();
    while (it != s.end()) {
        // auto tmp = find(it, s.end(), tar);
        it = search(it, s.end(), tar.begin(), tar.end());
        if (it != s.end()) {
            st.push_back(distance(s.begin(), it));
            it += 3;
        }
    }
    int cnt = st.size();

    // for (int i = 0; i < (int)st.size(); i++) {
    //     cout << st[i] << endl;
    // }
    rep(i, 0, q) {
        if (s[x[i]-1] == 'A' && s[x[i]] == 'B' && s[x[i]+1] == 'C') {
            cnt--;
        } else if (s[x[i]-1] == 'B' && s[x[i]-2] == 'A' && s[x[i]] == 'C') {
            cnt--;
        } else if (s[x[i]-1] == 'C' && s[x[i]-3] == 'A' && s[x[i]-2] == 'B') {
            cnt--;
        }

        s[x[i]-1] = c[i];

        if (s[x[i]-1] == 'A' && s[x[i]] == 'B' && s[x[i]+1] == 'C') {
            cnt++;
        } else if (s[x[i]-1] == 'B' && s[x[i]-2] == 'A' && s[x[i]] == 'C') {
            cnt++;
        } else if (s[x[i]-1] == 'C' && s[x[i]-3] == 'A' && s[x[i]-2] == 'B') {
            cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}
