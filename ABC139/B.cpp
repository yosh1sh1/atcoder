#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;

  if (b == 1) {
    cout << 0 << endl;
    return 0;
  }

  int res = 1;
  int tmp = a;
  while (tmp < b) {
    tmp += (a - 1);
    res++;
  }

  cout << res << endl;

	return 0;
}
