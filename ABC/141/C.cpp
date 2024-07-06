#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int ans[1000000];

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  int n, k, q;
  cin >> n >> k >> q;

  vector<int> a(q);
  rep (i, 0, q)
    cin >> a[i];

  if (k > q) {
    rep (i, 0, n)
      cout << "Yes" << endl;
    return 0;
  }

  int th = q - k;
  rep (i, 0, q)
    ans[a[i] - 1]++;

  rep (i, 0, n) {
    if (ans[i] > th)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

	return 0;
}
