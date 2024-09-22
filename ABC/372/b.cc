#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int m;
    cin >> m;

    vector<double> three_pow;
    rep(i, 0, 21) {
        three_pow.push_back(pow(3, i));
    }

    int tmp = m;
    vector<int> res;
    for (int i = 20; i >= 0; i--) {
        while (tmp >= three_pow[i]) {
            tmp -= three_pow[i];
            res.push_back(i);
        }
    }
    

    cout << res.size() << endl;
    for(auto id : res) {
        cout << id << " ";
    }
    cout << endl;

    return 0;
}
