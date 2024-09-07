#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

    int n;
    string s, t;
    cin >> n >> s >> t;

    int sw = 0;
    int sb = 0;
    int tw = 0;
    int tb = 0;
    rep(i, 0, n) {
        if (s[i] == 'W')
            sw++;
        else
            sb++;
        if (t[i] == 'W')
            tw++;
        else
            tb++;
    }

    if (sw != tw && sb != tb) {
        cout << -1 << endl;
        return 0;
    }

    s += "..";
    t += "..";

    // Prepare dfs
    queue<string> que;
    map<string, int> mp;
    que.push(s);
    mp[s] = 0;

    // Do bfs
    while (!que.empty()) {
        string now = que.front();
        que.pop();
        int idx_dt;
        rep(i, 0, n+1) {
            if (now[i] == '.') {
                idx_dt = i;
                break;
            }
        }

        rep(i, 0, n+1) {
            if (now[i] != '.' && now[i+1] != '.') {
                string tmp = now;
                tmp[idx_dt] = now[i];
                tmp[idx_dt+1] = now[i+1];
                tmp[i] = '.';
                tmp[i+1] = '.';
                if (!mp.count(tmp)) {
                    mp[tmp] = mp[now] + 1;
                    que.push(tmp);
                }
            }
        }
    }

    if (mp.count(t)) {
        cout << mp[t] << endl;
    } else {
        cout << -1 << endl;
    }

	return 0;
}
