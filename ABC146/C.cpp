#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

ll a, b;

ll bs(ll x) {
  ll n;
  ll min_v = 0;
  ll max_v = 1e9;
  ll value = 0;
  if ((a * max_v) + (b * 10) < x) {
    n = max_v;
  } else if ((a * 1) + (b * 1) > x) {
    n = 0;
  } else {
    while (min_v < max_v) {
      ll tmp = (max_v + min_v) / 2;
      if (tmp == min_v)
        break;
      ll d = (ll)to_string(tmp).length();
      value = (a * tmp + (b * d));
      if (value > x) {
        max_v = tmp;
      } else {
        min_v = tmp;
      }
    }
    n = min_v;
  }

  return n;
}


int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  ll x;
  cin >> a >> b >> x;

  ll res = bs(x);

  cout << res << endl;
	return 0;
}
