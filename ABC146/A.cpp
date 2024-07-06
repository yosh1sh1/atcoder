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

  int res = 0;
  if (s == "SUN")
    res = 7;
  else if (s == "MON")
    res = 6;
  else if (s == "TUE")
    res = 5;
  else if (s == "WED")
    res = 4;
  else if (s == "THU")
    res = 3;
  else if (s == "FRI")
    res = 2;
  else
    res = 1;

  cout << res << endl;

	return 0;
}
