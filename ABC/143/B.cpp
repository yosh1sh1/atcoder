#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> d(n);
  rep (i, 0, n)
    cin >> d[i];

  ll res = 0;
  rep (i, 0, n) {
    rep (j, i + 1, n) {
      res += (d[i] * d[j]);
    }
  }

  cout << res << endl;
	return 0;
}
