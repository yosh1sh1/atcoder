#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

/* greatest common divisor */
template <typename T> // ll or int
T gcd(T x, T y) {
  T res = 0;
  T mod = x % y;
  if (mod == 0)
    res = y;
  else
    res = gcd(y, mod);

  return res;
}

bool isPrime(ll num)
{
  if (num < 1)
    return false;
  else if (num == 1)
    return true;
  else if (num == 2)
    return true;
  else if (num % 2 == 0)
    return false;

  double limit = sqrt(num);
  for (ll i = 3; i <= limit; i += 2) {
    if (num % i == 0)
      return false;
  }

  return true;
}

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  ll a, b;
  cin >> a >> b;

  ll gcd_v = gcd(a, b);
  vector<ll> gcd_num;
  set<ll> gcd_set;
  // ll res = 0;
  for (ll i = 1; i * i <= gcd_v; i++) {
    if (gcd_v % i == 0) {
      if (isPrime(i))
        gcd_set.insert(i);
      //        gcd_num.push_back(i);
      if (i != 1 && i * i != gcd_v) {
        ll tmp = gcd_v / i;
        if (isPrime(tmp))
          gcd_set.insert(tmp);
        //          gcd_num.push_back(tmp);
      }
    }
  }

  if (isPrime(gcd_v))
    gcd_set.insert(gcd_v);
    //    gcd_num.push_back(gcd_v);


  cout << gcd_set.size() << endl;

	return 0;
}
