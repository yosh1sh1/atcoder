/*
 *  タイムアウトになる回答
 */

#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

    int n, t;
    string s;

    cin >> n >> t >> s;

    vector<int> x(n);
    rep(i, 0, n) {
        cin >> x[i];
    }
    
    int res = 0;    
    rep(i, 0, n) {
        rep(j, i+1, n) {
            if (s[i] != s[j]) {
                if ((s[i] == '0' && x[i] > x[j]) ||
                    (s[i] == '1' && x[i] < x[j])) {
                    // すれ違い判定
                    double tmp = abs(x[i] - x[j])/2.0;
                    if (tmp <= t)
                        res++;
                }
            }
        }
    }

    cout << res << endl;

	return 0;
}
