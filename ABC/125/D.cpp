#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> a(n);
  rep (i, 0, n)
    cin >> a[i];

  ll res = 0;
  int min_v = INT_MAX;
  int count = 0;
  for (int tmp : a) {
    if (tmp < 0) {
      count = ++count % 2;
    }
    min_v = min(min_v, abs(tmp));
    res += abs(tmp);
  }

  if (count)
    res -= (min_v * 2);

  cout << res << endl;

	return 0;
}
