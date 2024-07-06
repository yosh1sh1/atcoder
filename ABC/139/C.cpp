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

  vector<int> h(n);
  rep (i, 0, n)
    cin >> h[i];

  int res = 0;
  int tmp = 0;
  rep (i, 0, n-1) {
    if (h[i+1] <= h[i]) {
      tmp++;
    } else {
      res = max(res, tmp);
      tmp = 0;
    }
  }

  res = max(res, tmp);
  cout << res << endl;
	return 0;
}
