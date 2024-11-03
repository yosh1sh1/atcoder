#include <bits/stdc++.h>

#include <algorithm>
#include <vector>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n%2 != 0)
        return 0;

    vector<char> v;
    rep(i, 0, n) {
        if (i < n/2)
            v.push_back('(');
        else
            v.push_back(')');
    }

    // 有効な(, )の付き方にならない
    /*
        N = 4
        ()()
        ())(
        )(()
        )()(
        ))((
    */
    set<string> st;
    do {
        string tmp;
        for (auto c : v) {
            // cout << c;
            tmp += c;
        }
        // cout << endl;
        st.insert(tmp);
    } while (next_permutation(v.begin(), v.end()));

    for (auto s : st) {
        int open_cnt = 0;
        int close_cnt = 0;
        bool flg = true;
        rep(i, 0, s.size()) {
            if (s[i] == '(')
                open_cnt++;
            else
                close_cnt++;
            if (open_cnt < close_cnt) {
                flg = false;
                break;
            }
        }
        if (flg)
            cout << s << endl;
    }

    return 0;
}
