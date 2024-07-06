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

  vector<int> l(n);
  rep (i, 0, n)
    cin >> l[i];

  sort(l.begin(), l.end());

  int res = 0;
  rep (i, 0, n - 2) {
    rep (j, i + 1, n - 1) {
      int min_v = abs(l[i] - l[j]);
      int max_v = l[i] + l[j];
      auto it_s = upper_bound(l.begin() + j + 1, l.end(), min_v);
      auto it_e = lower_bound(l.begin() + j + 1, l.end(), max_v);
      res += distance(it_s, it_e);
    }
  }


  cout << res << endl;
	return 0;
}
