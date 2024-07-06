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

  int tmp = 0;
  rep (i, 1, n + 1)
    if (i & 1)
      tmp++;
  cout << (double)tmp / n << endl;




	return 0;
}
