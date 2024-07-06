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

  vector<int> x(n);
  vector<int> y(n);
  rep (i, 0, n)
    cin >> x[i] >> y[i];

  vector<int> np(n);
  rep (i, 0, n)
    np[i] = i;

  double route = 0;

  do {
    for (int i = 1; i < n; i++) {
      int st_x = x[np[i - 1]];
      int st_y = y[np[i - 1]];
      int ed_x = x[np[i]];
      int ed_y = y[np[i]];

      route += sqrt(pow((ed_x - st_x), 2) + pow((ed_y - st_y), 2));
    }
  } while (next_permutation(np.begin(), np.end()));

  double k = 1;
  for (int i = n; i > 0; i--) {
    k *= i;
  }

  cout << fixed << setprecision(6) <<  route / k << endl;
	return 0;
}
