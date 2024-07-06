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

  bool judge = false;
  rep (i, 1, 10) {
    if (n % i == 0) {
      if (n / i > 0 && n / i < 10) {
        judge = true;
        break;
      }
    }
  }

  if (judge)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

	return 0;
}
