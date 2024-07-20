#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)

using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    string s, t;

    cin >> n;
    cin >> s >> t;

    s += "..";
    t += "..";

    // BFS
    map<string, int> mp;
    queue<string> q;

    mp[s] = 0;
    q.push(s);

    while (!q.empty()) {
        string now = q.front();
        q.pop();

        int dot_id = 0;
        while (now[dot_id] != '.')
            dot_id++;
        rep(i, 0, n+1) {
            if (now[i] != '.' && now[i+1] != '.') {
                string tmp = now;
                swap(tmp[i], tmp[dot_id]);
                swap(tmp[i+1], tmp[dot_id+1]);
                if (mp.count(tmp))
                    continue;
                q.push(tmp);
                mp[tmp] = mp[now] + 1;
            }
        }
    }

    if (mp.find(t) != mp.end()) {
        cout << mp[t] << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}