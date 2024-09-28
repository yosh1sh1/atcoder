#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    vector<string> town;
    pair<int, int> start;
    rep(i, 0, h) {
        string tmp;
        rep(j, 0, w) {
            char c;
            cin >> c;
            tmp += c;
            if (c == 's') {
                start.first = i;
                start.second = j;
            }
        }
        town.push_back(tmp);
    }

    // 入力確認
    // rep(i, 0, h)
    //     cout << town[i] << endl;

    bool res = false;
    vector<vector<int>> table(h, vector<int>(w, 0));

    stack<pair<int, int>> st;
    st.push(start);
    while(!st.empty()) {
        pair<int, int> p = st.top();
        st.pop();

        // // ここで、pの有効判定したほうが分かりやすい
        // if (p.first < 0 || p.first >= h || p.second < 0 || p.second >= w ||
        //         table[p.first][p.second] == 1 || town[p.first][p.second] == '#')
        //      continue;

        table[p.first][p.second] = 1;

        // cout << format("p.first: {}, p.second: {}", p.first, p.second) << endl;

        if (town[p.first][p.second] == 'g') {
            res = true;
            break;
        }

        if (p.first - 1 >= 0 && table[p.first - 1][p.second] != 1 &&
                town[p.first - 1][p.second] != '#')
            st.push(make_pair(p.first - 1, p.second));
        if (p.first + 1 < h && table[p.first + 1][p.second] != 1 &&
                town[p.first + 1][p.second] != '#')
            st.push(make_pair(p.first + 1, p.second));
        if (p.second - 1 >= 0 && table[p.first][p.second - 1] != 1 &&
                town[p.first][p.second - 1] != '#')
            st.push(make_pair(p.first, p.second - 1));
        if (p.second + 1 < w && table[p.first][p.second + 1] != 1 &&
                town[p.first][p.second + 1] != '#')
            st.push(make_pair(p.first, p.second + 1));
    }

    if (res)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
