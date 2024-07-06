#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  string s;
  cin >> s;

  rep (i, 0, s.size()) {
    if ((i + 1) & 1) {
      if (s[i] == 'L') {
        cout << "No" << endl;
        return 0;
      }
    } else {
      if (s[i] == 'R') {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;

	return 0;
}

