#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

void f() {
    int n;
    cin >> n;

    set<int> res;
    map<pair<int, int>, int> mp;
    map<pair<int, int>, int> valid;
    vector<pair<int, int>> ac;
    vector<pair<int, int>> ca;
    rep(i, 0, n) {
        int a, c;
        cin >> a >> c;

        mp[make_pair(a, c)] = i + 1;
        valid[make_pair(a, c)] = 1;
        ac.emplace_back(make_pair(a, c));
        ca.emplace_back(make_pair(c, a));
    }

    sort(ac.begin(), ac.end());
    sort(ca.begin(), ca.end());

    int id_a = 0;
    int id_c = 0;
    while (id_a < n && id_c < n) {
        if (ac[id_a].first == ca[id_c].second && ac[id_a].second == ca[id_c].first) {
            res.insert(mp[ac[id_a]]);
            id_a++;
            id_c++;
        } else {
            valid[ac[id_a]] = 0;
            id_a++;
        }
        while (id_a < n && !valid[ac[id_a]]) {
            id_a++;
        }
        while (id_c < n && !valid[ { ca[id_c].second, ca[id_c].first } ]) {
            id_c++;
        }
    }

    int m = (int)res.size();
    cout << m << endl;
    for (auto v : res) {
        cout << v << " ";
    }
    cout << endl;

}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    f();

    return 0;
}
