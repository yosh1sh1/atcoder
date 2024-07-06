#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  int n;
  string s;
  cin >> n >> s;

  char now = s[0];
  int res = 1;
  rep (i, 1, n) {
    if (now != s[i]) {
      res++;
      now = s[i];
    }
  }

  cout << res << endl;
	return 0;
}
