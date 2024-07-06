#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  string s, t;
  cin >> s >> t;

  int res = 0;
  rep (i, 0, 3) {
    if (s[i] == t[i])
      res++;
  }
  cout << res << endl;

	return 0;
}
