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

  if (a > 0 && a < 10 && b > 0 && b < 10)
    cout << a * b << endl;
  else
    cout << -1 << endl;


	return 0;
}
