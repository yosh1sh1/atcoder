#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  double a, b, x;
  cin >> a >> b >> x;

  double h = x / (a * a);

  double rad = atan2(2.0 * (b - h), a);
  double res = rad * (180.0 / M_PI);

  cout << res << endl;
	return 0;
}
