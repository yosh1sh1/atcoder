#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  int res = 0;
  rep (i, 0, n) {
    int h;
    cin >> h;

    if (h >= k)
      res++;
  }

  cout << res << endl;

	return 0;
}
