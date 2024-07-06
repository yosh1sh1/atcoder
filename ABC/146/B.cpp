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

  string res;
  rep (i, 0, s.size()) {
    res +=  'A' + (((s[i] - 'A') + n) % 26);
  }

  cout << res << endl;
	return 0;
}
