#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> edge(n); // u -> pair(v, w)
    map<int, ll> mp; // key: node, value: x

    rep(i, 0, m) {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        u--; v--;
        edge[u].push_back(make_pair(v, w));
        edge[v].push_back(make_pair(u, -w));
    }

    stack<int> st;
    rep(i, 0, n) {
        if (mp.find(i) != mp.end())
            continue;
        mp[i] = 0;
        st.push(i);
        while(!st.empty()) {
            int u = st.top();
            st.pop();

            for (auto [v, w] : edge[u]) {
                if (mp.find(v) == mp.end()) {
                    mp[v] = mp[u] + w;
                    st.push(v);
                }
            }
        }
    }

    
    rep(i, 0, n) {
        cout << mp[i] << " ";
    }
    cout << endl;

    return 0;
}
