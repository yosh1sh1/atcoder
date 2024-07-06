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

  if (n & 1) {
    cout << "No" << endl;
    return 0;
  }

  string s1, s2;
  s1 = s.substr(0, n / 2);
  s2 = s.substr(n / 2, n / 2);

  if (s1 == s2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
	return 0;
}
