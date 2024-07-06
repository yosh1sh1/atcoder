#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  ll res = LLONG_MAX;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ll tmp;
      if (i * i != n) {
        tmp = (i - 1) + (n / i - 1);
      } else {
        tmp = (i - 1) * 2;
      }
      res = min(res, tmp);
    }
  }


  cout << res << endl;
	return 0;
}
