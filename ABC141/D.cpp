#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  priority_queue<ll> a;
  rep (i, 0, n) {
    ll tmp;
    cin >> tmp;
    a.push(tmp);
  }


  rep (i, 0, m) {
    ll tmp = a.top();
    a.pop();
    a.push(tmp / 2);
  }

  ll res = 0;
  while (a.size() != 0) {
    res += a.top();
    a.pop();
  }

  cout << res << endl;
	return 0;
}
